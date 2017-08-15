/********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: SensorPublishingApplication 
	Configuration 	: rti_linux
	Model Element	: SensorPublisher
//!	Generated Date	: Tue, 8, Aug 2017  
	File Path	: SensorApplicationDP/rti_linux/SensorPublisher.cpp
*********************************************************************/

//##   ignore
#include "SensorApplicationDP.h"
//## auto_generated
#include "SensorPublisher.h"
//## attribute SensorDataWriter

SensorPublisher::SensorPublisher() {
    initPublisher();
}

SensorPublisher::~SensorPublisher() {
    cleanupPublisher();
}


// --- create datawriter into this publisher --- 
	
		// template type T should be a specific Typesupport class 
		//   and the topic name should be matched with the type T
		//  
//next update, add in QOS support,

//#[ ignore
DDS::Publisher* SensorPublisher::getPublisher() {
    return publisher;
}

void SensorPublisher::initPublisher() {
    DDS::DomainParticipant* domainParticipant = SensorApplicationDP::instance()->getDomainParticipant();
    if (domainParticipant != NULL)
    {
    	publisher = domainParticipant->create_publisher(DDS::PUBLISHER_QOS_DEFAULT, NULL, 0);
    	if (publisher != NULL)
    	{
            
    		//log_success
    	}
		else
			{
			//log_error
			}
    }
}

void SensorPublisher::cleanupPublisher() {
    if (publisher != NULL) 
    {
    	publisher->delete_contained_entities();
    	DDS::DomainParticipant* domainParticipant = publisher->get_participant();
    	domainParticipant->delete_publisher(publisher);
    	publisher = NULL;
    }
}
//#]

/*********************************************************************
	File Path	: SensorPublishingApplication/rti_linux/SensorPublisher.cpp
*********************************************************************/
