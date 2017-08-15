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

//----------------subscribeData() to subscrbe a specific Topic and attach to an instance of listener
// topic template T should be a typesupport class and listener needs an instance 
//before calling this function 

//next update, add in QOS,may return datareader pointer to user
template <typename T>
void SensorSubscriber::subscribeData(std::string topicName, DDSDataReaderListener *listener) {
    DDS::Topic *topic = createTopic<T>( topicName );

    DDS::Subscriber *subscriber = getSubscriber();

    /* Create the data reader. Since we are using waitsets to receive
       samples the listener will only be enabled for status. On data
       available will handeled by the waitset in the main loop
     */
    DDS::DataReader *_reader = subscriber->create_datareader(
            topic, DDS_DATAREADER_QOS_DEFAULT, listener,
            DDS_STATUS_MASK_ALL);
//            DDS_STATUS_MASK_NONE & ~DDS_DATA_AVAILABLE_STATUS);

    if (NULL == _reader) {
        std::stringstream errss;
        errss << "Failed to create DataReader object";
    }
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

	// --- Create a Topic --- 
	
		// Creates a Topic.  Templatized with the type name to 
		// allow storage and deletion of the data type at 
		// shutdown.
template <typename T>
	DDS::Topic*  SensorSubscriber::createTopic(std::string topicName){
		
			// Register the data type with the DomainParticipant - this
			// tells the DomainParticipant how to create/destroy/
			// serialize/deserialize this data type.
			const char *typeName = T::TypeSupport::get_type_name();

	
			//next update, search type in domain participant first, 
			//if already registered then directly get the top desc
			// DDS::Topic* SensorTopic = dynamic_cast<DDS::Topic*>( publisher->get_participant() )->lookupTopicDescription(topicName.c_str()));
			//if (SensorTopic!= NULL)   then create datawritter on this topic. skip the register_type call

			DDS_ReturnCode_t retcode = T::TypeSupport::register_type(
					subscriber->get_participant(), typeName);
			if (retcode != DDS_RETCODE_OK) 
			{
				std::stringstream errss;
				errss << "Failure to register type. Regisetered twice?";
				throw errss.str();
			}
	
			// Create the Topic object, using the associated data type that
			// was registered above.
			DDS::Topic *topic = ( subscriber->get_participant() )->create_topic(
				topicName.c_str(),
				typeName, DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
				DDS_STATUS_MASK_NONE);
			if (topic == NULL) 
			{
				std::stringstream errss;
				errss << "CreateTopic(): failure to create Topic. Created twice?";
				throw errss.str();
			}
	
			return topic;
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
