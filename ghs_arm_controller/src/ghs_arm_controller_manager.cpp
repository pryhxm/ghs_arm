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
        fjtActionController(nh){
    nh_.getParam("/ghs_arm/controllers/arm_controller/type", controller_name);
    for (int i = 0; i < 5; ++i) {
        jointAngVelAccControllers.emplace_back(nh_, "joint" + to_string(i+1) + "_controller");
    }
//    startControllers();

//    startFollowJointTrajectoryActionController();
}

//bool GhsArmControllerManager::startFollowJointTrajectoryActionController() {
//    bool success = false;
//    nh_.getParam("/ghs_arm/controllers/arm_controller/joint_controllers", fjt_joint_controllers_);
//    if (fjt_joint_controllers_.empty()) {
//        ROS_FATAL_STREAM_NAMED("init", "no joints found for controller");
//    }

//    return success;
//}

//bool GhsArmControllerManager::startControllers() {
//    for (int i = 0; i < 5; ++i) {
//        jointAngVelAccControllers[i] = JointAngVelAccController(nh_, "joint" + to_string(i+1) + "_controller");
//    }
////    fjtActionController = FollowJointTrajectoryActionController(nh_);
////    vector<string> controllers_list;
////    nh_.getParam("/ghs_arm/controllers", controllers_list);
////    for (const auto& single_controller: controllers_list) {
////        cout << single_controller << endl;
////    }
////    cout << "asdf" << endl;
//    return false;
//};
