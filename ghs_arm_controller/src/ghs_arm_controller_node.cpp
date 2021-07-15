//
// Created by pry on 14.07.21.
//

#include "ghs_arm_controller_manager.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "ghs_arm_controller");
    ros::NodeHandle nh;

    ros::AsyncSpinner spinner(4);
    spinner.start();

    GhsArmControllerManager ghsArmControllerManager(nh);
    ros::waitForShutdown();

    return 0;
}