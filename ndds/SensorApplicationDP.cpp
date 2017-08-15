/********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: SensorApplicationDP 
	Configuration 	: rti_linux
	Model Element	: rti_linux
//!	Generated Date	: Tue, 8, Aug 2017  
	File Path	: SensorApplicationDP/rti_linux/SensorApplicationDP.cpp
*********************************************************************/

//## auto_generated
#include "SensorApplicationDP.h"
//## auto_generated

//#[ ignore
SensorApplicationDP::SensorApplicationDP() {
    DDS::DomainParticipantFactory* dpf = DDS::DomainParticipantFactory::get_instance();
    if (dpf != NULL)
    {
    	domainParticipant = dpf->create_participant( MAGIC_DOMAIN_ID, DDS::PARTICIPANT_QOS_DEFAULT, NULL, STATUS_MASK_NONE);
    	if (domainParticipant != NULL) 
    		{
    		//log_success
            printf("domainParticipant created\n");
    		}
		else
			{
			//log_error
            printf("domainParticipant creation failed\n");
            }
    }
}

/* TODO : optional
SensorApplicationDP::SensorApplicationDP(long domain) {
    DDS::DomainParticipantFactory* dpf = DDS::DomainParticipantFactory::get_instance();
    if (dpf != NULL)
    {
    	domainParticipant = dpf->create_participant(domain, DDS::PARTICIPANT_QOS_DEFAULT, NULL, STATUS_MASK_NONE);
    	if (domainParticipant = NULL) 
    	{
    		//log_error
    	}
    }
}
*/


SensorApplicationDP::~SensorApplicationDP() {
    if (domainParticipant != NULL) {
    	domainParticipant->delete_contained_entities();
    }
}

DDS::DomainParticipant* SensorApplicationDP::getDomainParticipant() {
    return domainParticipant;
}

DDS::TopicDescription* SensorApplicationDP::lookupTopicDescription(char* topicName) {
    DDS::TopicDescription* retVal = NULL;
    if (domainParticipant != NULL)
    {
    	retVal = domainParticipant->lookup_topicdescription(topicName);
    }
    return retVal;
}

SensorApplicationDP* SensorApplicationDP::instance() {
    static SensorApplicationDP rhpDomainParticipant;
    return &rhpDomainParticipant;
}
//#]


/*********************************************************************
	File Path	: SensorPublishingApplication/rti_linux/MainSensorPublishingApplication.cpp
*********************************************************************/
