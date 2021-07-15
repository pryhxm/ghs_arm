//
// Created by pry on 15.07.21.
//

#include "follow_joint_trajectory_action_controller.h"

FollowJointTrajectoryActionController::FollowJointTrajectoryActionController(ros::NodeHandle &nh) :
        nh_(nh),
        as_f_j_t(nh_, "as_f_j_t",
                 boost::bind(&FollowJointTrajectoryActionController::executeFJT,
                                               this, _1),
                 false) {
    as_f_j_t.start();
}

void FollowJointTrajectoryActionController::executeFJT(
        const control_msgs::FollowJointTrajectoryGoalConstPtr &goal) {
    ROS_INFO_STREAM_NAMED("follow joint trajectory action controller", "receive goal " << "some goal" <<" .");

}


