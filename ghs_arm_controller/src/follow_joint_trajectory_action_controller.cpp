//
// Created by pry on 15.07.21.
//

#include "follow_joint_trajectory_action_controller.h"

FollowJointTrajectoryActionController::FollowJointTrajectoryActionController(ros::NodeHandle &nh) :
        nh_(nh),
        as_fjt(nh_, "as_fjt",
                 boost::bind(&FollowJointTrajectoryActionController::executeFJT,this, _1),
                 false) {
    as_fjt.start();
}

void FollowJointTrajectoryActionController::executeFJT(
        const control_msgs::FollowJointTrajectoryGoalConstPtr &goal) {
    ROS_INFO_STREAM_NAMED("follow joint trajectory action controller", "receive goal " << "some goal" <<" .");

}


