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

class ControlCommandsListener : public SensorDataReaderListener {
    void on_data_available(DDS::DataReader* reader) {
        printf("on_data_available\n");
        ControllerCommands::Seq dataSeq;
        DDS_SampleInfoSeq infoSeq;
        DDS_ReturnCode_t rc;

        /* The following narrow function should never fail in our case, as
         * we have only one reader in the application. It simply performs
         * only a safe cast of the generic data reader into a specific
         * HelloWorldDataReader.
         */
        ControllerCommands::DataReader *dataReader = ControllerCommands::DataReader::narrow(reader);
        if (dataReader == NULL) {
            std::cerr << "! Unable to narrow data reader" << std::endl;
            return;
        }

        rc = dataReader->take(
                dataSeq,
                infoSeq,
                DDS_LENGTH_UNLIMITED,
                DDS_ANY_SAMPLE_STATE,
                DDS_ANY_VIEW_STATE,
                DDS_ANY_INSTANCE_STATE);
        if (rc == DDS_RETCODE_NO_DATA) {
            return;
        } else if (rc != DDS_RETCODE_OK) {
            std::cerr << "! Unable to take data from data reader, error "
                      << rc << std::endl;
            return;
        }

        for (int i = 0; i < dataSeq.length(); ++i) {
            if (infoSeq[i].valid_data) {
                // Process the data
                processData(dataSeq[i]);
            }
        }

        rc = dataReader->return_loan(dataSeq, infoSeq);
        if (rc != DDS_RETCODE_OK) {
            std::cerr << "! Unable to return loan, error "
                      << rc << std::endl;
        }
    }

    void processData(ControllerCommands &commands) {
        printf("on_data_available throttle %d \n", commands.throttle);
    }
};

int main(int argc, char **argv) {
    SensorSubscriber sensorSubscriber;
    ControlCommandsListener commandsListener;
    sensorSubscriber.subscribeData<ControllerCommands>("JsCommands", &commandsListener);

    DDS_Duration_t send_period = {0, DURATION_MS_1};

    while (true) {
        NDDSUtility::sleep(send_period);
    }

    return 0;
}
