/********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: SensorApplicationDP 
	Configuration 	: rti_linux
	Model Element	: SensorSubscriber
//!	Generated Date	: Tue, 8, Aug 2017  
	File Path	: SensorApplicationDP/rti_linux/SensorSubscriber.cpp
*********************************************************************/

//##   ignore
#include <stdio.h>

#include "SensorApplicationDP.h"
//##   ignore
//## auto_generated
#include "SensorSubscriber.h"
//## attribute SensorDataReader

SensorSubscriber::SensorSubscriber() {
    initSubscriber();
    //#[ operation SensorSubscriber()
    printf("ready to receive data\n");
    //#]
}

SensorSubscriber::~SensorSubscriber() {
    cleanupSubscriber();
}

//#[ ignore
DDS::Subscriber* SensorSubscriber::getSubscriber() {
    return subscriber;
}

void SensorSubscriber::initSubscriber() {
    DDS::DomainParticipant* domainParticipant = SensorApplicationDP::instance()->getDomainParticipant();
    if (domainParticipant != NULL)
    {
    	subscriber = domainParticipant->create_subscriber(DDS::SUBSCRIBER_QOS_DEFAULT, NULL, 0);
    	if (subscriber != NULL)
    		{		

    		//log_success
    		printf("subscriber created");
    		}
		else
			{
			//log_error
			printf("subscriber creation failed");
			}
    }
}


void SensorSubscriber::cleanupSubscriber() {
    if (subscriber != NULL) 
    {
    	subscriber->delete_contained_entities();
    	DDS::DomainParticipant* domainParticipant = subscriber->get_participant();
    	domainParticipant->delete_subscriber(subscriber);
    	subscriber = NULL;
    }
}
//#]

/*********************************************************************
	File Path	: SensorSubscribingApplication_Listener/rti_linux/SensorSubscriber.cpp
*********************************************************************/
