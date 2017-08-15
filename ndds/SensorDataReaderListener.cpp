/********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: SensorSubscribingApplication_Listener 
	Configuration 	: rti_linux
	Model Element	: SensorDataReaderListener
//!	Generated Date	: Tue, 8, Aug 2017  
	File Path	: SensorApplicationDP/rti_linux/SensorDataReaderListener.cpp
*********************************************************************/

//## auto_generated
#include "SensorDataReaderListener.h"
//## package SubscriberPkg_Listener

//## class SensorDataReaderListener
SensorDataReaderListener::SensorDataReaderListener() {
}

SensorDataReaderListener::~SensorDataReaderListener() {
}

void SensorDataReaderListener::on_data_available(DDS::DataReader* reader) {
    //#[ operation on_data_available(DataReader)
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
    //#]
}

void SensorDataReaderListener::on_liveliness_changed(DDS::DataReader* reader, const DDS::LivelinessChangedStatus& status) {
    //#[ operation on_liveliness_changed(DataReader,LivelinessChangedStatus)
    printf("on_liveliness_changed\n");
    //#]
}

void SensorDataReaderListener::on_requested_deadline_missed(DDS::DataReader* reader, const DDS::RequestedDeadlineMissedStatus& status) {
    //#[ operation on_requested_deadline_missed(DataReader,RequestedDeadlineMissedStatus)
    printf("on_requested_deadline_missed\n");
    //#]
}

void SensorDataReaderListener::on_requested_incompatible_qos(DDS::DataReader* reader, const DDS::RequestedIncompatibleQosStatus& status) {
    //#[ operation on_requested_incompatible_qos(DataReader,RequestedIncompatibleQosStatus)
    printf("on_requested_incompatible_qos\n");
    //#]
}

void SensorDataReaderListener::on_sample_lost(DDS::DataReader* reader, const DDS::SampleLostStatus& status) {
    //#[ operation on_sample_lost(DataReader,SampleLostStatus)
    printf("sample lost\n");
    //#]
}

void SensorDataReaderListener::on_sample_rejected(DDS::DataReader* reader, const DDS::SampleRejectedStatus& status) {
    //#[ operation on_sample_rejected(DataReader,SampleRejectedStatus)
    printf("sample rejected\n");
    //#]
}

void SensorDataReaderListener::on_subscription_matched(DDS::DataReader* reader, const DDS::SubscriptionMatchedStatus& status) {
    //#[ operation on_subscription_matched(DataReader,SubscriptionMatchedStatus)
    printf("on_subscription_matched\n");
    //#]
}

/*********************************************************************
	File Path	: SensorSubscribingApplication_Listener/rti_linux/SensorDataReaderListener.cpp
*********************************************************************/
