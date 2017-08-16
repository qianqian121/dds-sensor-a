/*!
 * \copyright	2017 (c) Samsung Semiconductor, Inc. - Strategy & Innovation Center, Smart Machines
 * \brief 		This file contains the implementation of the joystick controller
 *
 * \author      Mike Qi
 * \date        08/05/2017
 * \file        JsControlMain.cpp
 */
#include <SensorSubscriber.h>
#include <SensorDataReaderListener.h>
#include <iostream>
#include "control.h"
#include "controlSupport.h"
#include "SensorPublisher.h"

const int DURATION_MS_1 = 1000000;
const int DURATION_MS_10 = 10000000;

#if 0
void test_publisher() {
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
}

void test_sub() {
    SensorSubscriber sensorSubscriber;
    ControlCommandsListener commandsListener;
    sensorSubscriber.subscribeData<ControllerCommands>("JsCommands", &commandsListener);

    SensorSubscriber sensorSubscriber1;
    ControlCommandsListener commandsListener1;
    sensorSubscriber1.subscribeData<ControllerCommands>("JsCommands1", &commandsListener1);

    DDS_Duration_t send_period = {0, DURATION_MS_1};

    SensorPublisher sensorPublisher;
    //controlcmd msgdata
    DDS::DataWriter *dataWriter = sensorPublisher.addDatawriter<ControllerCommands>("JsCommands2");
    //populate data



    DdsAutoType<ControllerCommands> controlCommand;


    while (true) {
        controlCommand.throttle = 90;
        sensorPublisher.publishData(dataWriter, controlCommand );
        NDDSUtility::sleep(send_period);
    }
}
#endif


void processData(void* data) {
    ControllerCommands *commands = (ControllerCommands *)data;


//        printf("on_data_available throttle\n");
    printf("on_data_available throttle %d \n", commands->throttle);
}


int main(int argc, char **argv) {
    SensorSubscriber sensorSubscriber;
//    ControlCommandsListener commandsListener;
    sensorSubscriber.subscribeData<ControllerCommands>("JsCommands", processData);

    DDS_Duration_t send_period = {0, DURATION_MS_1};

    while (true) {
        NDDSUtility::sleep(send_period);
    }

    return 0;
}
