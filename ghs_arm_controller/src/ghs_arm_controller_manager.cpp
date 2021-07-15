//
// Created by pry on 14.07.21.
//

#include "ghs_arm_controller_manager.h"


//GhsArmControllerManager::~GhsArmControllerManager() {
////    deinit();
//
//}

GhsArmControllerManager::GhsArmControllerManager(ros::NodeHandle &nh) : nh_(nh) {
    nh_.getParam("/ghs_arm/controllers/arm_controller/type", controller_name);
    startFollowJointTrajectoryActionController();
}

bool GhsArmControllerManager::startFollowJointTrajectoryActionController() {
    bool success = false;

    return success;
};
