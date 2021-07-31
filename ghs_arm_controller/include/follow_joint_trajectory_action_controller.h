//
// Created by pry on 15.07.21.
//

#ifndef GHS_ARM_CONTROLLER_FOLLOW_JOINT_TRAJECTORY_ACTION_CONTROLLER_H
#define GHS_ARM_CONTROLLER_FOLLOW_JOINT_TRAJECTORY_ACTION_CONTROLLER_H

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
//#include <trajectory_msgs/>
#include <control_msgs/FollowJointTrajectoryAction.h>

class FollowJointTrajectoryActionController {
private:
    ros::NodeHandle nh_;
    void executeFJT(const control_msgs::FollowJointTrajectoryGoalConstPtr &goal);
    control_msgs::FollowJointTrajectoryFeedback fjtc_fb;

public:
    FollowJointTrajectoryActionController(ros::NodeHandle &nh);
    actionlib::SimpleActionServer<control_msgs::FollowJointTrajectoryAction> as_fjt;
};


#endif //GHS_ARM_CONTROLLER_FOLLOW_JOINT_TRAJECTORY_ACTION_CONTROLLER_H
