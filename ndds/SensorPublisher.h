/*********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: SensorPublishingApplication 
	Configuration 	: rti_linux
	Model Element	: SensorPublisher
//!	Generated Date	: Tue, 8, Aug 2017  
	File Path	: SensorPublishingApplication/rti_linux/SensorPublisher.h
*********************************************************************/

#ifndef SensorPublisher_H
#define SensorPublisher_H

//## auto_generated

#include <stdio.h>
#include <string>
#include <sstream>
#include "ndds/ndds_cpp.h"
#include "ndds/ndds_namespace_cpp.h"
#include "DDSTypeWrapper.h"


//## package PublisherPkg

class string;

//## class SensorPublisher
// publisher term is defined in DDS profile and represents a DDS Publisher.
class SensorPublisher {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    SensorPublisher();
    
    //## auto_generated
    ~SensorPublisher();
    
	template <typename T>
	DDS::DataWriter* addDatawriter(std::string topicName);
	
	template <typename T>
	void publishData(DDS::DataWriter *writer, DdsAutoType<T> msg_data) ;

	
    ////    Operations    ////
    
 
    
    //## auto_generated
    
//#[ ignore
    DDS::Publisher* getPublisher();
//#]

private :

//#[ ignore
    void initPublisher();
    
    
    void cleanupPublisher();

	template <typename T>
	DDS::Topic*  createTopic(std::string topicName);

//#]

    ////    Attributes    ////

protected :

 //   SensorTopicStructDataWriter* SensorDataWriter;		//## attribute SensorDataWriter
    
    ////    Framework operations    ////
    
    ////    Framework    ////

private :

//#[ ignore
    DDS::Publisher* publisher;
//#]
};

#endif
/*********************************************************************
	File Path	: SensorPublishingApplication/rti_linux/SensorPublisher.h
*********************************************************************/
