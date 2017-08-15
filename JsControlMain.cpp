/*!
 * \copyright	2017 (c) Samsung Semiconductor, Inc. - Strategy & Innovation Center, Smart Machines
 * \brief 		This file contains the implementation of the joystick controller
 *
 * \author      Mike Qi
 * \date        08/05/2017
 * \file        JsControlMain.cpp
 */
#include "control.h"
#include "controlSupport.h"
#include "SensorPublisher.h"

const int DURATION_MS_1 = 1000000;
const int DURATION_MS_10 = 10000000;

int main(int argc, char **argv) {

    SensorPublisher sensorPublisher;
    //controlcmd msgdata
    DDS::DataWriter *dataWriter = sensorPublisher.addDatawriter<ControllerCommands>("JsCommands");
    //populate data



    DdsAutoType<ControllerCommands> controlCommand;

    DDS_Duration_t send_period = {0, DURATION_MS_1};

    while (true) {
        controlCommand.throttle = 100;
        sensorPublisher.publishData(dataWriter, controlCommand );
        NDDSUtility::sleep(send_period);
    }

    return 0;
}
