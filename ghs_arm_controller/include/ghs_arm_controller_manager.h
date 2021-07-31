//
// Created by pry on 14.07.21.
//

#ifndef GHS_ARM_CONTROLLER_GHS_ARM_CONTROLLER_MANAGER_H
#define GHS_ARM_CONTROLLER_GHS_ARM_CONTROLLER_MANAGER_H

#include "ros/ros.h"
#include <ghs_arm_motor_driver.h>
#include "../include/joint_ang_vel_acc_controller.h"

using namespace std;

class GhsArmControllerManager {
private:
    ros::NodeHandle nh_;
    string controller_name;
    vector<string> fjt_joint_controllers_;
    JointAngVelAccController jointAngVelAccController;

public:
    GhsArmControllerManager(ros::NodeHandle &nh);
//    ~GhsArmControllerManager();
    bool startFollowJointTrajectoryActionController();




};


#endif //GHS_ARM_CONTROLLER_GHS_ARM_CONTROLLER_MANAGER_H
