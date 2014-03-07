#ifndef DDSMANAGER_H
#define DDSMANAGER_H

#include <map>

#include "checkStatus.h"
#include "singleton.h"

#include <assert.h>

using namespace DDS;
using namespace Templates;

/*!
 * This class is a singleton and exists only once in each application. It creates 
 * a domain participant for each dds domain. Additionally it creates subscribes and
 * publishers for each dds partition. You can also register types and topics using 
 * this class. Afterwards you can create data reades and writers for the registered
 * topics and use it in your component.
 */
class DDSManager : public Singleton<DDSManager>
{
	/*!
	 * Singleton class must be a friend, because only it can call protected constructor.
	 */
	friend class Singleton<DDSManager>;
	private:
	/*!
	 * private constructor called by base singleton class.
	 */
	DDSManager() {
		std::cout<<std::endl<<"DDSManager singelton constructor called"<<std::endl<<std::endl;
	};

	/*!
	 * private constructor to prevent object creation without calling static
	 * instance function.
	 */
	DDSManager(const DDSManager &){}

	/*!
	 * private method to create a dds domain participant. Called by
	 * lookupOrCreateParticipant if no domain participant was created yet for
	 * the given domain_name and stored in m_participants
	 * @param domain_name the name to create a participant for
	 * @return true if creation was successful
	 */
	virtual bool createParticipant(std::string domain_name) {
		bool bSuccess = false;
		//std::cout<<"ddsManager add participant for domain "<<domain_name<<std::endl;
		//DomainId_t m_domain = NULL;//(DomainId_t)domain_name.c_str();
		DomainId_t m_domain = DDS::DOMAIN_ID_DEFAULT; // since v6
		// for v5
		//DomainId_t m_domain = "IMPERA";
		m_dpf = DomainParticipantFactory::get_instance();
		bSuccess = checkHandle(m_dpf.in(), "DDS::DomainParticipantFactory::get_instance"); assert(bSuccess);
		DomainParticipant_var participant = m_dpf->create_participant(m_domain, PARTICIPANT_QOS_DEFAULT, NULL,
				DDS::DATA_AVAILABLE_STATUS); //TODO replace NULL with domain id
		bSuccess = checkHandle(participant.in(),
				"DDS::DomainParticipantFactory::create_participant"); assert(bSuccess);
		m_participants[domain_name] = participant;
		return true;
	}

	/*!
	 * private method to create a dds subscriber. Called by
	 * lookupOrCreateSubscriber if no subscriber was created yet in
	 * the given domain_name for the given partition. The subscriber is stored
	 * in m_subscribers.
	 * @param domain_name the domain name in which the subscriber should be created
	 * @param partition_name the partition for the subscriber
	 * @return true if creation was successful
	 */
	virtual bool createSubscriber(std::string domain_name, std::string partition_name) {
		bool bSuccess = false;
		//std::cout<<"ddsManager creating dds subscriber"<<std::endl;
		SubscriberQos sub_qos;
		ReturnCode_t status = m_participants[domain_name]->get_default_subscriber_qos(sub_qos);
		bSuccess = checkStatus(status, "DDS::DomainParticipant::get_default_subscriber_qos"); assert(bSuccess);
		sub_qos.partition.name.length(1);
		sub_qos.partition.name[0] = partition_name.c_str();
		Subscriber_var sub = m_participants[domain_name]->create_subscriber(sub_qos, NULL, STATUS_MASK_NONE);
		bSuccess = checkHandle(sub.in(), "DDS::DomainParticipant::create_subscriber"); assert(bSuccess);
		m_subscribers[domain_name][partition_name] = sub;
		return true;
	}

	/*!
	 * private method to create a dds publisher. Called by
	 * lookupOrCreatePublisher if no publisher was created yet in
	 * the given domain_name for the given partition. The publisher is stored
	 * in m_publishers.
	 * @param domain_name the domain name in which the subscriber should be created
	 * @param partition_name the partition for the subscriber
	 * @return true if creation was successful
	 */
	virtual bool createPublisher(std::string domain_name, std::string partition_name) {
		bool bSuccess = false;
		//std::cout<<"ddsmanager creating dds publisher"<<std::endl;
		PublisherQos pub_qos;
		ReturnCode_t status = m_participants[domain_name]->get_default_publisher_qos(pub_qos);
		bSuccess = checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos"); assert(bSuccess);
		pub_qos.partition.name.length(1);
		pub_qos.partition.name[0] = partition_name.c_str();
		Publisher_var pub = m_participants[domain_name]->create_publisher(pub_qos, NULL, STATUS_MASK_NONE);
		bSuccess = checkHandle(pub.in(), "DDS::DomainParticipant::create_publisher"); assert(bSuccess);
		m_publishers[domain_name][partition_name] = pub;
		return true;
	}

	public:
	/*!
	 * destructer called if the application ends.
	 * @TODO clean up dds cloud
	 */
	virtual ~DDSManager(){};

	/*!
	 * This method is called to create a domain participant. If the participant
	 * already exists no additional participant is created. This ensures that only one
	 * domain participant exists per application for each domain.
	 * @param domain_name the name of the domain
	 * @return true on success
	 */
	virtual bool lookupOrCreateParticipant(std::string domain_name) {
		//if (m_initialized) return false;
		if (m_participants.find(domain_name) == m_participants.end()) {
			return createParticipant(domain_name);
		}
		//m_initialized = true;
		return true;
	}

	/*!
	 * This method is called to create a subscriber in the given domain for the
	 * given partition. If the subscriber already exists no additional subscriber
	 * is created. This ensures that only one subscriber exists for each domain
	 * and partition.
	 * @param domain_name the name of the subscriber domain
	 * @param partition_name the name of the subscriber partition
	 * @return true on success
	 */
	bool lookupOrCreateSubscriber(std::string domain_name, std::string partition_name) {
		if(lookupOrCreateParticipant(domain_name) == false) {
			return false;
		}
		if (m_subscribers[domain_name].find(partition_name) == m_subscribers[domain_name].end()) {
			return createSubscriber(domain_name, partition_name);
		}
		return true;
	}

	/*!
	 * This method is called to create a publisher in the given domain for the
	 * given partition. If the publisher already exists no additional publisher
	 * is created. This ensures that only one publisher exists for each domain
	 * and partition.
	 * @param domain_name the name of the subscriber domain
	 * @param partition_name the name of the publisher partition
	 * @return true on success
	 */
	bool lookupOrCreatePublisher(std::string domain_name, std::string partition_name) {
		if(lookupOrCreateParticipant(domain_name) == false) {
			return false;
		}
		if (m_publishers[domain_name].find(partition_name) == m_publishers[domain_name].end()) {
			return createPublisher(domain_name, partition_name);
		}
		return true;
	}

	/*!
	 * This method registeres the given type in the given domain.
	 * @param the domain_name for the type
	 * @return true if registration was successful
	 */
	bool registerType(std::string domain_name, TypeSupport *ts) {
		bool bSuccess = false;
		//make sure participant exists
		if(lookupOrCreateParticipant(domain_name) == false) {
			return false;
		}
		//std::cout<<"ddsManager registerType ";
		//std::cout<<ts->get_type_name()<<std::endl;
		ReturnCode_t status = ts->register_type(m_participants[domain_name].in(), ts->get_type_name());
		bSuccess = checkStatus(status, "register_type"); assert(bSuccess);
		return true;
	}

	/*!
	 * This method creates a topic in the given domain_name.
	 * @param the domain_name for the type
	 * @param topic_name the name of the topic
	 * @param type_name the name of the topic
	 * @return true if creation was successful
	 */
	Topic_var createTopic(std::string domain_name, const char* topic_name, const char* type_name) {
		bool bSuccess = false;
		//std::cout<<"ddsManager createTopic "<<topic_name<<" with type "<<type_name<<std::endl;
		if(lookupOrCreateParticipant(domain_name) == false) {
			return 0;
		}
		Topic_var topic;
		TopicQos topic_qos;
		ReturnCode_t status = m_participants[domain_name]->get_default_topic_qos(topic_qos);
		bSuccess = checkStatus(status, "DDS::DomainParticipant::get_default_topic_qos"); assert(bSuccess);
		topic_qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
		topic_qos.durability.kind = TRANSIENT_DURABILITY_QOS;
		topic_qos.history.kind = KEEP_ALL_HISTORY_QOS;
		m_reliable_topic_qos[domain_name] = topic_qos;
		// Make the tailored QoS the new default.
		status = m_participants[domain_name]->set_default_topic_qos(m_reliable_topic_qos[domain_name]);
		bSuccess = checkStatus(status, "DDS::DomainParticipant::set_default_topic_qos"); assert(bSuccess);

		// Use the changed policy when defining the HelloWorld topic
		topic = m_participants[domain_name]->create_topic(topic_name, type_name,
				m_reliable_topic_qos[domain_name], NULL, STATUS_MASK_NONE);
		bSuccess = checkHandle(topic.in(), "DDS::DomainParticipant::create_topic ()"); assert(bSuccess);
		return topic;
	}

	/*!
	 * This method creates a reader for the given domain, partition and topic.
	 * @param the domain_name for the reader
	 * @param the partition of the reader
	 * @param the topic of the reader
	 * @return the reader
	 */
	DataReader_ptr createReader(std::string domain_name, std::string partition_name, Topic_var topic) {
		//std::cout<<"ddsManager createReader  for topic ";
		//std::cout<<topic->get_name()<<std::endl;
		if(lookupOrCreateSubscriber(domain_name, partition_name) == false) {
			return false;
		}
		return m_subscribers[domain_name][partition_name]->create_datareader(topic.in(),
				DATAREADER_QOS_USE_TOPIC_QOS, NULL,
				STATUS_MASK_NONE);
	}

	/*!
	 * This method creates a writer for the given domain, partition and topic.
	 * @param the domain_name for the writer
	 * @param the partition of the writer
	 * @param the topic of the writer
	 * @return the writer
	 */
	DataWriter_ptr createWriter(std::string domain_name, std::string partition_name, Topic_var topic) {
		bool bSuccess = false;
		//std::cout<<"ddsManager createWriter  for topic ";
		//std::cout<<topic->get_name()<<std::endl;
		if(lookupOrCreatePublisher(domain_name, partition_name) == false) {
			return 0;
		}
		DataWriterQos dw_qos;
		ReturnCode_t status = m_publishers[domain_name][partition_name]->get_default_datawriter_qos(dw_qos);
		bSuccess = checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos"); assert(bSuccess);
		status = m_publishers[domain_name][partition_name]->copy_from_topic_qos(dw_qos, m_reliable_topic_qos[domain_name]);
		bSuccess = checkStatus(status, "DDS::Publisher::copy_from_topic_qos"); assert(bSuccess);
		// If autodispose_unregistered_instances is set to true (default value),
		// you will have to start the subscriber before the publisher
		// Set autodispose to false so that you can start
		// the subscriber after the publisher
		bool autodispose_unregistered_instances = false;
		dw_qos.writer_data_lifecycle.autodispose_unregistered_instances = autodispose_unregistered_instances;
		DataWriter_ptr writer = m_publishers[domain_name][partition_name]->create_datawriter(topic.in(), dw_qos, NULL,
				STATUS_MASK_NONE);
		bSuccess = checkHandle(writer, "DDS::Publisher::create_datawriter"); assert(bSuccess);
		return writer;
	}
	public:
	///reference to the dds DomainParticipantFactory singelton
	DomainParticipantFactory_var m_dpf;
	/// a map holding the domain names and the corresponding default topic qos in this domain
	std::map<std::string, TopicQos> m_reliable_topic_qos;
	//bool m_initialized;
	/// a map holding the domain names and the corresponding dds domain participants
	std::map<std::string, DomainParticipant_var> m_participants;
	/// a map of maps that holds the domain names, partition_names and the corresponding subscribers
	std::map< std::string, std::map< std::string, Subscriber_var > > m_subscribers;
	/// a map of maps that holds the domain names, partition_names and the corresponding publishers
	std::map< std::string, std::map< std::string, Publisher_var > > m_publishers;
};

#endif // BASECOMPONENTDDS_H
