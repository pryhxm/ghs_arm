//
// Created by pry on 14.07.21.
//

#ifndef GHS_ARM_CONTROLLER_GHS_ARM_CONTROLLER_MANAGER_H
#define GHS_ARM_CONTROLLER_GHS_ARM_CONTROLLER_MANAGER_H

#include "ros/ros.h"

using namespace std;

class GhsArmControllerManager {
private:
    ros::NodeHandle nh_;
    std::string controller_name;

public:
    GhsArmControllerManager(ros::NodeHandle &nh);
//    ~GhsArmControllerManager();
    bool startFollowJointTrajectoryActionController();
};


#endif //GHS_ARM_CONTROLLER_GHS_ARM_CONTROLLER_MANAGER_H
