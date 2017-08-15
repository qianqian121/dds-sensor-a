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


template <typename T>
DDS::DataWriter* SensorPublisher::addDatawriter(std::string topicName) {
	// This topic has the name AIRCRAFT_TOPIC - a constant
	// string that is defined in the .idl file.  (It is not required that
	// you define your topic name in IDL, but it is a best practice for
	// ensuring the data interface of an application is all defined in one
	// place. You can register all topics and types up-front, if you nee
	DDS::Topic *topic = createTopic<T>( topicName );


	// Create a DataWriter.
	// This creates a single DataWriter that writes data, with QoS
	// that is used for State Data. Note: The string constants with the QoS
	// library name and the QoS profile name are configured as constants in the
	// .idl file.  The profiles themselves are configured in the .xml file.
	DDS::DataWriter *_writer = getPublisher()->create_datawriter(topic,
																 DDS_DATAWRITER_QOS_DEFAULT,
																 NULL, DDS_STATUS_MASK_NONE);

	if (_writer == NULL)
	{
		std::stringstream errss;
		errss <<
			  "Failure to create  writer. Inconsistent Qos?";
		throw errss.str();
	}

	//	  return T::DataWriter::narrow(_writer);
	return _writer;
}

// --- publish data for specific typestruct and corresponding datawriter ---

// user should add datawriter then populate data
//   before call this function
//
template <typename T>
void SensorPublisher::publishData(DDS::DataWriter *writer, DdsAutoType<T> msg_data) {
	// Write the data to the network.  This is a thin wrapper
	// around the RTI Connext DDS DataWriter that writes data to
	// the network.
	DDS_ReturnCode_t retcode = DDS_RETCODE_OK;
	DDS_InstanceHandle_t handle = DDS_HANDLE_NIL;

	retcode = T::DataWriter::narrow(writer)->write(msg_data, handle);

	if (retcode != DDS_RETCODE_OK)
	{
		std::stringstream errss;
		errss <<
			  "Failure to write data";
		throw errss.str();
	}
}

// --- Create a Topic ---

// Creates a Topic.  Templatized with the type name to
// allow storage and deletion of the data type at
// shutdown.
template <typename T>
DDS::Topic*  SensorPublisher::createTopic(std::string topicName){

	// Register the data type with the DomainParticipant - this
	// tells the DomainParticipant how to create/destroy/
	// serialize/deserialize this data type.
	const char *typeName = T::TypeSupport::get_type_name();


	//next update, search type in domain participant first,
	//if already registered then directly get the top desc
	// DDS::Topic* SensorTopic = dynamic_cast<DDS::Topic*>( publisher->get_participant() )->lookupTopicDescription(topicName.c_str()));
	//if (SensorTopic!= NULL)   then create datawritter on this topic. skip the register_type call

	DDS_ReturnCode_t retcode = T::TypeSupport::register_type(
			publisher->get_participant(), typeName);
	if (retcode != DDS_RETCODE_OK)
	{
		std::stringstream errss;
		errss << "Failure to register type. Regisetered twice?";
		throw errss.str();
	}

	// Create the Topic object, using the associated data type that
	// was registered above.
	DDS::Topic *topic = ( publisher->get_participant() )->create_topic(
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



#endif
/*********************************************************************
	File Path	: SensorPublishingApplication/rti_linux/SensorPublisher.h
*********************************************************************/
