/*********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: SensorSubscribingApplication_Listener 
	Configuration 	: rti_linux
	Model Element	: SensorDataReaderListener
//!	Generated Date	: Tue, 8, Aug 2017  
	File Path	: SensorApplicationDP/rti_linux/SensorDataReaderListener.h
*********************************************************************/

#ifndef SensorDataReaderListener_H
#define SensorDataReaderListener_H

//## auto_generated

//##   ignore
#include "ndds/ndds_cpp.h"
#include "ndds/ndds_namespace_cpp.h"

//##   ignore

//## class SensorDataReaderListener
// The class overrides DDS DataReaderListener interface and defines bus events handlers as virtual functions for user to reload .
class SensorDataReaderListener : public DDS::DataReaderListener {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    SensorDataReaderListener();
    
    //## auto_generated
    ~SensorDataReaderListener();
    
    ////    Operations    ////
    
    //## operation on_data_available(DataReader)
    virtual void on_data_available(DDS::DataReader* reader);
    
    //## operation on_liveliness_changed(DataReader,LivelinessChangedStatus)
    virtual void on_liveliness_changed(DDS::DataReader* reader, const DDS::LivelinessChangedStatus& status);
    
    //## operation on_requested_deadline_missed(DataReader,RequestedDeadlineMissedStatus)
    virtual void on_requested_deadline_missed(DDS::DataReader* reader, const DDS::RequestedDeadlineMissedStatus& status);
    
    //## operation on_requested_incompatible_qos(DataReader,RequestedIncompatibleQosStatus)
    virtual void on_requested_incompatible_qos(DDS::DataReader* reader, const DDS::RequestedIncompatibleQosStatus& status);
    
    //## operation on_sample_lost(DataReader,SampleLostStatus)
    virtual void on_sample_lost(DDS::DataReader* reader, const DDS::SampleLostStatus& status);
    
    //## operation on_sample_rejected(DataReader,SampleRejectedStatus)
    virtual void on_sample_rejected(DDS::DataReader* reader, const DDS::SampleRejectedStatus& status);
    
    //## operation on_subscription_matched(DataReader,SubscriptionMatchedStatus)
    virtual void on_subscription_matched(DDS::DataReader* reader, const DDS::SubscriptionMatchedStatus& status);
};

#endif
/*********************************************************************
	File Path	: SensorSubscribingApplication_Listener/rti_linux/SensorDataReaderListener.h
*********************************************************************/
