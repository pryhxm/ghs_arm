//
// Created by pry on 29.07.21.
//

#include "../include/joint_ang_vel_acc_controller.h"

JointAngVelAccController::JointAngVelAccController(ros::NodeHandle &nh, string controller_namespace) :
        nh_(nh),
        controller_namespace_(controller_namespace) {
    sub_command_ = nh_.subscribe(controller_namespace + "/command", 10, &JointAngVelAccController::cb_command, this);
}

void JointAngVelAccController::cb_command(const ghs_arm_msgs::JointCommandConstPtr &msg) {
    double angle = msg->angle;
    double vel = msg->vel;
    double acc = msg->acc;
    double duration = msg->duration;

    ROS_INFO_STREAM_NAMED("ros_arm_controller", "angle " << angle << ". vel " << vel);
}
