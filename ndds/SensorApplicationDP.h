/*********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: SensorApplicationDP 
	Configuration 	: rti_linux
	Model Element	: rti_linux
//!	Generated Date	: Tue, 8, Aug 2017  
	File Path	: SensorPublishingApplication/rti_linux/SensorApplicationDP.h
*********************************************************************/

#ifndef SensorApplicationDP_H
#define SensorApplicationDP_H

//## auto_generated
#include <stdio.h>

#include "ndds/ndds_cpp.h"
#include "ndds/ndds_namespace_cpp.h"

//#[ ignore

#define MAGIC_DOMAIN_ID 	( 0 )
#define STATUS_MASK_NONE 	( 0 )

class SensorApplicationDP {
    ////    Constructors and destructors    ////
    
private :

    SensorApplicationDP();

public :

    virtual ~SensorApplicationDP();
    
    ////    Framework operations    ////
    
    DDS::DomainParticipant* getDomainParticipant();
    
    DDS::TopicDescription* lookupTopicDescription(char* topicName);
    
    static SensorApplicationDP* instance();

    ////    Framework    ////

private :

    DDS::DomainParticipant* domainParticipant;
};
//#]

#endif
/*********************************************************************
	File Path	: SensorApplicationDP/rti_linux/SensorApplicationDP.h
*********************************************************************/
