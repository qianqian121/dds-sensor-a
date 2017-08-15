/*********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: SensorApplicationDP 
	Configuration 	: rti_linux
	Model Element	: SensorSubscriber
//!	Generated Date	: Tue, 8, Aug 2017  
	File Path	: SensorApplicationDP/rti_linux/SensorSubscriber.h
*********************************************************************/

#ifndef SensorSubscriber_H
#define SensorSubscriber_H

//## auto_generated

//##   ignore
#include "ndds/ndds_cpp.h"
#include "ndds/ndds_namespace_cpp.h"
#include <string>
#include <sstream>

//## auto_generated

//## package SubscriberPkg_Listener

//## class SensorSubscriber
// subscriber term is defined in DDS profile and represents a DDS Subscriber.
// This subscriber is using asynchronous model (Listener) to receive updates regarding new DDS data.
class SensorSubscriber {
    ////    Constructors and destructors    ////
    
public :

    //## operation SensorSubscriber()
    SensorSubscriber();
    
    //## auto_generated
    ~SensorSubscriber();
    
    ////    Additional operations    ////
    template <typename T>
	void subscribeData(std::string topicName, DDSDataReaderListener *listener);
    //## auto_generated
//    SensorTopicStructDataReader* getSensorDataReader() const;
    
//#[ ignore
    DDS::Subscriber* getSubscriber();
//#]

private :

//#[ ignore
    void initSubscriber();
    
    void cleanupSubscriber();

	template <typename T>
	DDS::Topic*  createTopic(std::string topicName);
//#]

    ////    Attributes    ////

protected :

//    SensorTopicStructDataReader* SensorDataReader;		//## attribute SensorDataReader
    
    ////    Framework operations    ////
    
    ////    Framework    ////

private :

//#[ ignore
    DDS::Subscriber* subscriber;
//#]
};

#endif
/*********************************************************************
	File Path	: SensorSubscribingApplication_Listener/rti_linux/SensorSubscriber.h
*********************************************************************/
