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
#include <iostream>

#include "ndds/ndds_cpp.h"
#include "ndds/ndds_namespace_cpp.h"

//##   ignore
typedef void (*onDataAvailableCallbackType)(void *) ;
//## class SensorDataReaderListener
// The class overrides DDS DataReaderListener interface and defines bus events handlers as virtual functions for user to reload .
template<typename T>
class SensorDataReaderListener : public DDS::DataReaderListener {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    SensorDataReaderListener();
    
    //## auto_generated
    ~SensorDataReaderListener();

    ///>    Operations    ////
    void on_data_available(DDS::DataReader* reader);

    virtual void processData(void* data);

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

public:
    void setOnDataAvailableCallback(onDataAvailableCallbackType f){
        on_data_available_callback_ = f;
    }

private:
    onDataAvailableCallbackType on_data_available_callback_;
};

//## class SensorDataReaderListener
template<typename T>
SensorDataReaderListener<T>::SensorDataReaderListener() : on_data_available_callback_(nullptr) {
}
template<typename T>
SensorDataReaderListener<T>::~SensorDataReaderListener() {
}

template <typename T>
void SensorDataReaderListener<T>::on_data_available(DDS::DataReader* reader) {
    //#[ operation on_data_available(DataReader)
    printf("on_data_available\n");

    typename T::Seq dataSeq;
    DDS_SampleInfoSeq infoSeq;
    DDS_ReturnCode_t rc;

    /* The following narrow function should never fail in our case, as
     * we have only one reader in the application. It simply performs
     * only a safe cast of the generic data reader into a specific
     * HelloWorldDataReader.
     */
    typename T::DataReader *dataReader = T::DataReader::narrow(reader);
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
            if (on_data_available_callback_)
                on_data_available_callback_(&dataSeq[i]);
        }
    }

    rc = dataReader->return_loan(dataSeq, infoSeq);
    if (rc != DDS_RETCODE_OK) {
        std::cerr << "! Unable to return loan, error "
                  << rc << std::endl;
    }
    //#]
}

template<typename T>
void SensorDataReaderListener<T>::processData(void* data)
{
    printf("data under processing");

}
template<typename T>
void SensorDataReaderListener<T>::on_liveliness_changed(DDS::DataReader* reader, const DDS::LivelinessChangedStatus& status) {
    //#[ operation on_liveliness_changed(DataReader,LivelinessChangedStatus)
    printf("on_liveliness_changed\n");
    //#]
}
template<typename T>
void SensorDataReaderListener<T>::on_requested_deadline_missed(DDS::DataReader* reader, const DDS::RequestedDeadlineMissedStatus& status) {
    //#[ operation on_requested_deadline_missed(DataReader,RequestedDeadlineMissedStatus)
    printf("on_requested_deadline_missed\n");
    //#]
}
template<typename T>
void SensorDataReaderListener<T>::on_requested_incompatible_qos(DDS::DataReader* reader, const DDS::RequestedIncompatibleQosStatus& status) {
    //#[ operation on_requested_incompatible_qos(DataReader,RequestedIncompatibleQosStatus)
    printf("on_requested_incompatible_qos\n");
    //#]
}
template<typename T>
void SensorDataReaderListener<T>::on_sample_lost(DDS::DataReader* reader, const DDS::SampleLostStatus& status) {
    //#[ operation on_sample_lost(DataReader,SampleLostStatus)
    printf("sample lost\n");
    //#]
}
template<typename T>
void SensorDataReaderListener<T>::on_sample_rejected(DDS::DataReader* reader, const DDS::SampleRejectedStatus& status) {
    //#[ operation on_sample_rejected(DataReader,SampleRejectedStatus)
    printf("sample rejected\n");
    //#]
}
template<typename T>
void SensorDataReaderListener<T>::on_subscription_matched(DDS::DataReader* reader, const DDS::SubscriptionMatchedStatus& status) {
    //#[ operation on_subscription_matched(DataReader,SubscriptionMatchedStatus)
    printf("on_subscription_matched\n");
    //#]
}


#endif
/*********************************************************************
	File Path	: SensorSubscribingApplication_Listener/rti_linux/SensorDataReaderListener.h
*********************************************************************/
