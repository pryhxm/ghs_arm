//
// Created by pry on 29.07.21.
//

#ifndef GHS_ARM_CONTROLLER_SINGLE_JOINT_CONTROLLER_H
#define GHS_ARM_CONTROLLER_SINGLE_JOINT_CONTROLLER_H


#include <ros/ros.h>
#include <ghs_arm_msgs/JointCommand.h>
#include <ghs_arm_motor_driver.h>

using namespace std;

class SingleJointController {
public:
    SingleJointController(ros::NodeHandle &nh, string controller_namespace);

private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_command;
    ros::Publisher pub_state;

    string controller_namespace_;

    void cb_command(const ghs_arm_msgs::JointCommandConstPtr &msg);

//    GhsArmMotorDriver ghsArmMotorDriver;

};


#endif //GHS_ARM_CONTROLLER_SINGLE_JOINT_CONTROLLER_H
