/*
* Copyright (c) 2012  DFKI GmbH, Bremen, Germany
*
*  This file is free software: you may copy, redistribute and/or modify it
*  under the terms of the GNU General Public License as published by the
*  Free Software Foundation, either version 3 of the License, or (at your
*  option) any later version.
*
*  This file is distributed in the hope that it will be useful, but
*  WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*
*   Author: Ronny Hartanto (ronny.hartanto@dfki.de)
*
*	FILE --- ddsproxyjoy.cpp
*
*  Created on: Aug 3, 2012
*/

#include "ddsproxyjoy.h"
#include "ros/ros.h"

DDSProxyJoy::DDSProxyJoy() {
}

DDSProxyJoy::~DDSProxyJoy() {

}

void DDSProxyJoy::registerProxy() {
	// Init participant for DDS. And typesupport for ddsJoy
	ddsJoyTypeSupport_var data = new ddsJoyTypeSupport();
	DDSManager::instance().registerType(dds_domain_name, data.in());
	m_data_topic = DDSManager::instance().createTopic(dds_domain_name.c_str(),
			dds_message_name.c_str(), data->get_type_name());
	DataWriter_ptr writer = DDSManager::instance().createWriter(
			dds_domain_name.c_str(), ros_message_type.c_str(), m_data_topic);
	DataReader_ptr reader = DDSManager::instance().createReader(
			dds_domain_name.c_str(), ros_message_type.c_str(),
			m_data_topic.in());
	m_data_writer = ddsJoyDataWriter::_narrow(writer);
	m_data_reader = ddsJoyDataReader::_narrow(reader);
	// Init ROS
	pub = nh_.advertise<sensor_msgs::Joy>("joy", 10);
	sub = nh_.subscribe("joy", 1, &DDSProxyJoy::messageCallback <sensor_msgs::Joy>, this);
	ROS_INFO("DDSJoy Initialization completed.");
}

template <class T> void DDSProxyJoy::messageCallback(
		const ros::MessageEvent<T const>& event) {
	ROS_DEBUG("[Debug]: Received message event of type sensor_msgs::Joy\n");
	if ((event.getPublisherName() != node_name) && (event.getPublisherName() != local_publisher_node_name)) {
		ROS_DEBUG("Received message from %s", event.getPublisherName().c_str());
		ros::Time receipt_time = event.getReceiptTime();
		const sensor_msgs::JoyConstPtr& msg = event.getMessage();
		ddsJoy *ddsJoy_msg = new ddsJoy();

		// Filling in data for *ddsJoy.idl*
		ddsJoy_msg->header.frame_id = std::string(msg->header.frame_id).c_str();
		ddsJoy_msg->header.seq = msg->header.seq;
		ddsJoy_msg->header.stamp.nsec = msg->header.stamp.nsec;
		ddsJoy_msg->header.stamp.sec = msg->header.stamp.sec;
		ddsJoy_msg->axes.length(msg->axes.size());

		for (int i = 0; i < msg->axes.size(); i++) {
			ddsJoy_msg->axes[i] = msg->axes[i];
		}

		ddsJoy_msg->buttons.length(msg->buttons.size());

		for (int i = 0; i < msg->buttons.size(); i++) {
			ddsJoy_msg->buttons[i] = msg->buttons[i];
		}

		ReturnCode_t ret = m_data_writer->write(*ddsJoy_msg, NULL);
		checkStatus(ret, "ddsJoy::Write");
		// ROS_INFO("Print return code %d", ret);
	}
}

void DDSProxyJoy::update() {
	ddsJoySeq_var ddsJoy_msgSeq = new ddsJoySeq();
	SampleInfoSeq_var infoSeq = new SampleInfoSeq();

	//ROS_INFO_ONCE("while inner loop");
	//ReportStatus_t status
	m_data_reader->take(*ddsJoy_msgSeq, *infoSeq, LENGTH_UNLIMITED,
			ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
	//checkStatus(status, "MsgDataReader::take");
	//ROS_INFO("Reading data %d", ddsJoy_msgSeq->length());
	//ROS_INFO("Reading info %d",infoSeq->length());
	for (ULong i = 0; i < ddsJoy_msgSeq->length(); ++i) {
		//ROS_INFO("publishing message");
		sensor_msgs::Joy ddsJoy_msg;
		ddsJoy *ROS_ddsJoy_msg;
		ROS_ddsJoy_msg = &(ddsJoy_msgSeq[i]);
		ddsJoy_msg.header.stamp.sec = ROS_ddsJoy_msg->header.stamp.sec;
		ddsJoy_msg.header.stamp.nsec = ROS_ddsJoy_msg->header.stamp.nsec;
		ddsJoy_msg.header.seq = ROS_ddsJoy_msg->header.seq;
		ddsJoy_msg.header.frame_id = ROS_ddsJoy_msg->header.frame_id;

		ddsJoy_msg.axes.resize(ROS_ddsJoy_msg->axes.length());
		for (int i = 0; i < ROS_ddsJoy_msg->axes.length(); i++) {
			ddsJoy_msg.axes[i] = ROS_ddsJoy_msg->axes[i];
		}

		ddsJoy_msg.buttons.resize(ROS_ddsJoy_msg->buttons.length());
		for (int i = 0; i < ROS_ddsJoy_msg->buttons.length(); i++) {
			ddsJoy_msg.buttons[i] = ROS_ddsJoy_msg->buttons[i];
		}
		pub.publish(ddsJoy_msg);
		m_data_reader->return_loan(*ddsJoy_msgSeq, *infoSeq);
		//checkStatus(status, "MsgDataReader::return_loan");
	}
}


