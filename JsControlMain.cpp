/*!
 * \copyright	2017 (c) Samsung Semiconductor, Inc. - Strategy & Innovation Center, Smart Machines
 * \brief 		This file contains the implementation of the joystick controller
 *
 * \author      Mike Qi
 * \date        08/05/2017
 * \file        JsControlMain.cpp
 */
#include "JsControlFactory.h"
#include <GamePad.h>
#include <GamePadSupport.h>
#include <DDSNodeInterface.h>

const int DURATION_MS_1 = 1000000;
const int DURATION_MS_10 = 10000000;

int main(int argc, char **argv) {
    Joystick joystick;
    JsControl *jsControl = JsControlFactory::createJsControl(joystick);
    if (jsControl == nullptr)
        return -1;

    DDSNodeInterface nodeInterface;
    DDS::DataWriter *twist_pub = nodeInterface.advertise<ControllerCommands>("JsCommands");
    DdsAutoType<ControllerCommands> controlCommand;

    DDS_Duration_t send_period = {0, DURATION_MS_1};

    std::cout <<"waiting game controller safety switch " << std::endl;
    while(jsControl->singleLoop() == JsControlState::AUTO_OFF)
        NDDSUtility::sleep(send_period);
    std::cout <<"waiting game controller safety switch [done] " << std::endl;


    JsControlState state;
    while (true) {
        state = jsControl->singleLoop();
        if (state == JsControlState::AUTO_OFF) {
            controlCommand.auto_on = false;
            nodeInterface.pub<ControllerCommands>(twist_pub, controlCommand);
        }
        else if (state == JsControlState::AUTO_ESTOP) {
            // brake
            controlCommand.throttle = -20;
            // Write the data to the network.
            nodeInterface.pub<ControllerCommands>(twist_pub, controlCommand);
//            NDDSUtility::sleep(send_period);
        }
        else
        {
            controlCommand.auto_on = true;
//            std::cout << "Steering: " << jsControl->getSteer_angle_() << std::endl;
//            std::cout << "Throttle: " << jsControl->getThrottle_() << std::endl;
            // publish topic
            controlCommand.steer_angle = (short)jsControl->getSteer_angle_();
            controlCommand.throttle = (short)jsControl->getThrottle_();
            controlCommand.desired_speed = (short)jsControl->getCruise_speed_();
            // Write the data to the network.
            nodeInterface.pub<ControllerCommands>(twist_pub, controlCommand);

//            NDDSUtility::sleep(send_period);
        }
        NDDSUtility::sleep(send_period);
    }

    std::cout <<"exit " << std::endl;

    return 0;
}
