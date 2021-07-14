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
    bool someThingsA;

protected:
    bool someThingsB;

public:
    GhsArmMotorDriver(ros::NodeHandle &nh);
    ~GhsArmMotorDriver();
    actionlib::SimpleActionServer<ghs_arm_msgs::TurnMotorAction> as_turn_single_motor;
    actionlib::SimpleActionServer<ghs_arm_msgs::TurnMultipleMotorsAction> as_turn_multiple_motor;
//    bool turnMotor(int motor_number, double angle, double velocity, double duration);
    bool someThingsC;
};


#endif //GHS_ARM_GHS_ARM_MOTOR_DRIVER_H