//
// Created by pry on 15.07.21.
//

#include "follow_joint_trajectory_action_controller.h"

//const string ROS_LOG_NAME = "fjt action controller";

FollowJointTrajectoryActionController::FollowJointTrajectoryActionController(ros::NodeHandle &nh) :
        nh_(nh),
        as_fjt(nh_, "as_fjt",
                 boost::bind(&FollowJointTrajectoryActionController::executeFJT,this, _1),
                 false) {
    as_fjt.start();
    for (int i = 0; i < 5; i++) {
        ghsArmMotorDrivers.push_back(GhsArmMotorDriver());
    }
}

void FollowJointTrajectoryActionController::executeFJT(
        const control_msgs::FollowJointTrajectoryGoalConstPtr &goal) {
    ROS_INFO_STREAM_NAMED(ROS_LOG_NAME, "receive goal " << "some goal" <<" .");

    uint64_t num_points = goal->trajectory.points.size();

    // todo: if num_pints == 0

    // todo:
    //  currently the joints in the action msg are considered configured as "joint1 ... joint5"
    //  But may not.

    vector<uint64_t> durations(num_points, 0);
    durations[0] = goal->trajectory.points[0].time_from_start.toSec();

    for (int i = 0; i < num_points; ++i) {
        durations[i] = (goal->trajectory.points[i].time_from_start -
                goal->trajectory.points[i - 1].time_from_start).toSec();
    }

    // todo: if points[0] doesn't exist

    vector<Segment> segments;
    ros::Time start_time = ros::Time::now() + ros::Duration(0.01);

    for (int i = 0; i < num_points; ++i) {
        struct Segment segment;
        if (goal->trajectory.header.stamp == ros::Time(0.0)) {
            segment.start_time = (start_time + goal->trajectory.points[i].time_from_start).toSec() - durations[i];
        } else {
            segment.start_time = (goal->trajectory.header.stamp + goal->trajectory.points[i].time_from_start).toSec() - durations[i];
        }
        segment.duration = durations[i];

        for (int j = 0; j < 5; ++j) {
            if (! goal->trajectory.points[i].positions.empty()) {
                segment.angs[j] = goal->trajectory.points[i].positions[j];
            }
        }
        segments.push_back(segment);
    }

//    ROS_INFO_STREAM_NAMED("fjt action controller", "Trajectory ")
    ros::Rate rate(200);

    while (goal->trajectory.header.stamp > start_time) {
        start_time = ros::Time::now();
        rate.sleep();
    }

    double duration_sum = 0;
    for (auto &duration : durations) {
         duration_sum += duration;
    }

    ros::Time end_time = goal->trajectory.header.stamp + ros::Duration(duration_sum);
    vector<double> seg_end_times(num_points, 0);

    for (int i = 0; i < segments.size(); ++i) {
        double seg_end_time = segments[i].start_time + durations[i];
        seg_end_times.push_back(seg_end_time);
    }

    for (int i = 0; i < segments.size(); ++i) {
        ROS_DEBUG_STREAM_NAMED(
                ROS_LOG_NAME, "Current segment is " << to_string(i) << ". Time left: "
                << to_string(durations[i] - (start_time.toNSec() - segments[i].start_time))
                << ". Current time: " << to_string(start_time.toSec())
        );

        ROS_DEBUG_STREAM_NAMED(ROS_LOG_NAME, "Goal positions are :");

        if (durations[i] == 0) {
            ROS_DEBUG_STREAM_NAMED(ROS_LOG_NAME, "Segment " << to_string(i) << " with a duration of 0 is skipped");

        } else {
            for (int j = 0; j < 5; ++j) {
                bool success = ghsArmMotorDrivers[j].setAngle(j, segments[j].angs[j]);
//                ghsArmMotorDrivers[j].setVelocity(j, segments[j].vels[j]);
//                ghsArmMotorDrivers[j].setAcceleration(j, segments[j].accs[j]);
            }

            double cur_time = ros::Time::now().toSec();
            while (cur_time < seg_end_times[i]) {
                rate.sleep();
                cur_time = ros::Time::now().toSec();
            }
        }
    }

    // todo: check constraints

}


