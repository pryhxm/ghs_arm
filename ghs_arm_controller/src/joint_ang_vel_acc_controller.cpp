//
// Created by pry on 29.07.21.
//

#include "../include/joint_ang_vel_acc_controller.h"

JointAngVelAccController::JointAngVelAccController(ros::NodeHandle &nh, string controller_namespace) :
        nh_(nh),
        controller_namespace_(controller_namespace) {
    sub_command = nh_.subscribe(controller_namespace + "/command", 10, &JointAngVelAccController::cb_command, this);
    // todo: defien joint state and publish
    //    pub_state = nh_.advertise<>()
}

void JointAngVelAccController::cb_command(const ghs_arm_msgs::JointCommandConstPtr &msg) {
    double angle = msg->angle;
    double vel = msg->vel;
    double acc = msg->acc;
    double duration = msg->duration;

    ROS_INFO_STREAM_NAMED(controller_namespace_, "angle " << angle << ". vel " << vel);

    // todo: *** movement plan
    // todo: configure motor with a proper definition of id
    ghsArmMotorDriver.setAngle(1, angle);
}
