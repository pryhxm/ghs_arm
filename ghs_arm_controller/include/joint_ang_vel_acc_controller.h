//
// Created by pry on 29.07.21.
//

#ifndef GHS_ARM_CONTROLLER_JOINT_ANG_VEL_ACC_CONTROLLER_H
#define GHS_ARM_CONTROLLER_JOINT_ANG_VEL_ACC_CONTROLLER_H


#include <ros/ros.h>
#include <ghs_arm_msgs/JointCommand.h>

using namespace std;

class JointAngVelAccController {
public:
    JointAngVelAccController(ros::NodeHandle &nh, string controller_namespace);

private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_command_;

    string controller_namespace_;

    void cb_command(const ghs_arm_msgs::JointCommandConstPtr &msg);
};


#endif //GHS_ARM_CONTROLLER_JOINT_ANG_VEL_ACC_CONTROLLER_H
