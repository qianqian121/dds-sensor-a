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
