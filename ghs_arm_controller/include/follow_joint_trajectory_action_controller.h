//
// Created by pry on 15.07.21.
//

#ifndef GHS_ARM_CONTROLLER_FOLLOW_JOINT_TRAJECTORY_ACTION_CONTROLLER_H
#define GHS_ARM_CONTROLLER_FOLLOW_JOINT_TRAJECTORY_ACTION_CONTROLLER_H

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
//#include <trajectory_msgs/>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <ghs_arm_motor_driver.h>
#include <thread>

using namespace std;

const string ROS_LOG_NAME = "fjt action controller";

class FollowJointTrajectoryActionController {
private:
    ros::NodeHandle nh_;
    void executeFJT(const control_msgs::FollowJointTrajectoryGoalConstPtr &goal);
    control_msgs::FollowJointTrajectoryFeedback fjtc_fb;
    std::vector<GhsArmMotorDriver> ghsArmMotorDrivers_;

    void updateState();

public:
    FollowJointTrajectoryActionController(ros::NodeHandle &nh, std::vector<GhsArmMotorDriver> &ghs_arm_motor_drivers);
    actionlib::SimpleActionServer<control_msgs::FollowJointTrajectoryAction> as_fjt;
};

struct Segment {
    double start_time = 0;
    double duration = 0;
    double angs[5] = {0};
    double vels[5] = {0};
    double accs[5] = {0};
};


#endif //GHS_ARM_CONTROLLER_FOLLOW_JOINT_TRAJECTORY_ACTION_CONTROLLER_H
