//
// Created by pry on 14.07.21.
//

#include "ghs_arm_controller_manager.h"


//GhsArmControllerManager::~GhsArmControllerManager() {
////    deinit();
//
//}

GhsArmControllerManager::GhsArmControllerManager(ros::NodeHandle &nh) :
        nh_(nh),
        jointAngVelAccController(nh, "joint1_controller") {
    nh_.getParam("/ghs_arm/controllers/arm_controller/type", controller_name);
    startFollowJointTrajectoryActionController();
}

bool GhsArmControllerManager::startFollowJointTrajectoryActionController() {
    bool success = false;
    nh_.getParam("/ghs_arm/controllers/arm_controller/joint_controllers", fjt_joint_controllers_);
//    if (fjt_joint_controllers_.empty()) {
//        ROS_FATAL_STREAM_NAMED("init", "no joints found for controller");
//    }

    return success;
};
