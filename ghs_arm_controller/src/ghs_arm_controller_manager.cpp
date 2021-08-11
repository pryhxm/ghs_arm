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
        fjtActionController(nh, ghsArmMotorDrivers){
    nh_.getParam("/ghs_arm/controllers/arm_controller/type", controller_name);
    for (int i = 0; i < 5; ++i) {
        ghsArmMotorDrivers.emplace_back(i);
//        singleJointControllers.emplace_back(nh_, "joint" + to_string(i + 1) + "_controller");
    }
    pub_joint_state = nh_.advertise<sensor_msgs::JointState>("/ghs_arm/joint_state", 10);
    publishJointStates();

}

void GhsArmControllerManager::publishJointStates() {
    ros::Rate rate(200);
    sensor_msgs::JointState msg_joint_state;

    // todo: add corresponding header
//    msg_joint_state.header =
    msg_joint_state.name = {"joint1", "joint2", "joint3", "joint4", "joint5"};

    while (ros::ok()) {
        for (int i = 0; i < 5; ++i) {
            msg_joint_state.position[i] = ghsArmMotorDrivers[i].getPosition();
            msg_joint_state.velocity[i] = ghsArmMotorDrivers[i].getVelocity();
            msg_joint_state.effort[i] = ghsArmMotorDrivers[i].getAcceleration();
        }
        pub_joint_state.publish(msg_joint_state);
        rate.sleep();
    }
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
//        singleJointControllers[i] = SingleJointController(nh_, "joint" + to_string(i+1) + "_controller");
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
