//
// Created by pry on 14.07.21.
//

#ifndef GHS_ARM_CONTROLLER_GHS_ARM_CONTROLLER_MANAGER_H
#define GHS_ARM_CONTROLLER_GHS_ARM_CONTROLLER_MANAGER_H

#include "ros/ros.h"
#include <ghs_arm_motor_driver.h>
#include "../include/single_joint_controller.h"
#include "../include/follow_joint_trajectory_action_controller.h"
#include <thread>
#include <sensor_msgs/JointState.h>

using namespace std;

class GhsArmControllerManager {
private:
    ros::NodeHandle nh_;
    string controller_name;
    vector<GhsArmMotorDriver> ghsArmMotorDrivers;

    // Publishers and Subscribers:
    ros::Publisher pub_joint_state;

    // Controllers:
    vector<SingleJointController> singleJointControllers;
    FollowJointTrajectoryActionController fjtActionController;


    void publishJointStates();

public:
    GhsArmControllerManager(ros::NodeHandle &nh);
//    ~GhsArmControllerManager();
//    bool startFollowJointTrajectoryActionController();
//    bool startControllers();

};


#endif //GHS_ARM_CONTROLLER_GHS_ARM_CONTROLLER_MANAGER_H
