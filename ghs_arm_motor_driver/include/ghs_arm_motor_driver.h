//
// Created by pry on 12.07.21.
//

#ifndef GHS_ARM_GHS_ARM_MOTOR_DRIVER_H
#define GHS_ARM_GHS_ARM_MOTOR_DRIVER_H

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include "ghs_arm_msgs/TurnMotorAction.h"
#include "ghs_arm_msgs/TurnMultipleMotorsAction.h"

class GhsArmMotorDriver {
private:
    uint8_t id_;
    bool someThingsA;

public:
    GhsArmMotorDriver(uint8_t id);
//    GhsArmMotorDriver(ros::NodeHandle &nh);
//    ~GhsArmMotorDriver();
//    actionlib::SimpleActionServer<ghs_arm_msgs::TurnMotorAction> as_turn_single_motor;
//    actionlib::SimpleActionServer<ghs_arm_msgs::TurnMultipleMotorsAction> as_turn_multiple_motor;
    // todo: publish angles, velocities, the message of which has to be defined


    bool setPosition(double pos);
    bool setVelocity(double vel);
    bool setAcceleration(double acc);

    double getPosition();
    double getVelocity();
    double getAcceleration();

//    bool setPosition()
};


#endif //GHS_ARM_GHS_ARM_MOTOR_DRIVER_H
