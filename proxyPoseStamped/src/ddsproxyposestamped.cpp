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
*   Author: Ronny Hartanto (ronny.hartanto@dfki.de)
*
* 	FILE --- ddsproxyposestamped.cpp
*
*  Created on: Sep 10, 2012
*/

#include "ddsproxyposestamped.h"
#include "ros/ros.h"


DDSProxyPoseStamped::DDSProxyPoseStamped() {
}

DDSProxyPoseStamped::~DDSProxyPoseStamped() {

}

void DDSProxyPoseStamped::registerProxy() {
	// Init participant for DDS. And typesupport for ddsProxyStamped
	proxyPoseStampedTypeSupport_var data = new proxyPoseStampedTypeSupport();
	DDSManager::instance().registerType(dds_domain_name, data.in());
	m_data_topic = DDSManager::instance().createTopic(dds_domain_name.c_str(),
			dds_message_name.c_str(), data->get_type_name());
	DataWriter_ptr writer = DDSManager::instance().createWriter(
			dds_domain_name.c_str(), ros_message_type.c_str(), m_data_topic);
	DataReader_ptr reader = DDSManager::instance().createReader(
			dds_domain_name.c_str(), ros_message_type.c_str(),
			m_data_topic.in());
	m_data_writer = proxyPoseStampedDataWriter::_narrow(writer);
	m_data_reader = proxyPoseStampedDataReader::_narrow(reader);
	// Init ROS
	std::string topic_name = "/shared_";
	topic_name.append(ros_message_name.c_str());
	pub = nh_.advertise<geometry_msgs::PoseStamped>(topic_name.c_str(), 10);
	sub = nh_.subscribe(ros_message_name.c_str(), 1, &DDSProxyPoseStamped::messageCallback <geometry_msgs::PoseStamped>, this);
	ROS_INFO("DDSProxyPoseStamped Initialization completed.");
}

template <class T> void DDSProxyPoseStamped::messageCallback(
		const ros::MessageEvent<T const>& event) {
		ROS_DEBUG("[Debug]: Received message event of type geometry_msgs::PoseStamped\n");
	//	if (event.getPublisherName() != node_name) {
		ROS_DEBUG("Received message from %s", event.getPublisherName().c_str());
		ros::Time receipt_time = event.getReceiptTime();
		const geometry_msgs::PoseStampedConstPtr& msg = event.getMessage();
		proxyPoseStamped *proxyPoseStamped_msg = new proxyPoseStamped();

		// Filling in data for *proxyPoseStamped.idl*
		std::string frame_id = "/";
		frame_id.append(robot_name.c_str());
		frame_id.append(std::string(msg->header.frame_id).c_str());

		proxyPoseStamped_msg->header.frame_id = frame_id.c_str();
		proxyPoseStamped_msg->header.seq = msg->header.seq;
		proxyPoseStamped_msg->header.stamp.nsec = msg->header.stamp.nsec;
		proxyPoseStamped_msg->header.stamp.sec = msg->header.stamp.sec;

        // fill pose/position
		proxyPoseStamped_msg->pose.position.x = msg->pose.position.x;
		proxyPoseStamped_msg->pose.position.y = msg->pose.position.y;
		proxyPoseStamped_msg->pose.position.z = msg->pose.position.z;

        // fill pose/orientation
		proxyPoseStamped_msg->pose.orientation.x = msg->pose.orientation.x;
		proxyPoseStamped_msg->pose.orientation.y = msg->pose.orientation.y;
		proxyPoseStamped_msg->pose.orientation.z = msg->pose.orientation.z;
		proxyPoseStamped_msg->pose.orientation.w = msg->pose.orientation.w;

		ReturnCode_t ret = m_data_writer->write(*proxyPoseStamped_msg, NULL);
		checkStatus(ret, "proxyPoseStamped::Write");
		// ROS_INFO("Print return code %d", ret);
		//}
}

void DDSProxyPoseStamped::update() {
	proxyPoseStampedSeq_var proxyPoseStamped_msgSeq = new proxyPoseStampedSeq();
	SampleInfoSeq_var infoSeq = new SampleInfoSeq();

	//ROS_INFO_ONCE("while inner loop");
	//ReportStatus_t status
	m_data_reader->take(*proxyPoseStamped_msgSeq, *infoSeq, LENGTH_UNLIMITED,
			ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
	//checkStatus(status, "MsgDataReader::take");
	//ROS_INFO("Reading data %d", proxyPoseStamped_msgSeq->length());
	//ROS_INFO("Reading info %d",infoSeq->length());
	for (ULong i = 0; i < proxyPoseStamped_msgSeq->length(); ++i) {
		//ROS_INFO("publishing message");
		ROS_DEBUG("receiving message via DDS!");
		//ROS_INFO("Sender info %d", proxyPoseStamped_msgSeq[i]->)

		geometry_msgs::PoseStamped ddsPoseStamped_msg;
		proxyPoseStamped *ROS_proxyPoseStamped_msg;
		ROS_proxyPoseStamped_msg = &(proxyPoseStamped_msgSeq[i]);

		// An empty message makes the program crash
		if(ROS_proxyPoseStamped_msg->header.seq == 0 && 
			ROS_proxyPoseStamped_msg->header.stamp.sec == 0){
			ROS_INFO("[Message %u] is empty. I ignore it.", i);
		//	nEmptyItems++;
			continue;
		}

		ddsPoseStamped_msg.header.stamp.sec = ROS_proxyPoseStamped_msg->header.stamp.sec;
		ddsPoseStamped_msg.header.stamp.nsec = ROS_proxyPoseStamped_msg->header.stamp.nsec;
		ddsPoseStamped_msg.header.seq = ROS_proxyPoseStamped_msg->header.seq;
		ddsPoseStamped_msg.header.frame_id = ROS_proxyPoseStamped_msg->header.frame_id;

		//position
		ddsPoseStamped_msg.pose.position.x = ROS_proxyPoseStamped_msg->pose.position.x;
		ddsPoseStamped_msg.pose.position.y = ROS_proxyPoseStamped_msg->pose.position.y;
		ddsPoseStamped_msg.pose.position.z = ROS_proxyPoseStamped_msg->pose.position.z;

		//orientation
		ddsPoseStamped_msg.pose.orientation.x = ROS_proxyPoseStamped_msg->pose.orientation.x;
		ddsPoseStamped_msg.pose.orientation.y = ROS_proxyPoseStamped_msg->pose.orientation.y;
		ddsPoseStamped_msg.pose.orientation.z = ROS_proxyPoseStamped_msg->pose.orientation.z;
		ddsPoseStamped_msg.pose.orientation.w = ROS_proxyPoseStamped_msg->pose.orientation.w;


		//ROS_INFO("Find robot name at %d", ddsPoseStamped_msg.header.frame_id.find(robot_name.c_str()));
		//if (ddsPoseStamped_msg.header.frame_id.find(robot_name.c_str()) == -1 )
			pub.publish(ddsPoseStamped_msg);
	}
	m_data_reader->return_loan(*proxyPoseStamped_msgSeq, *infoSeq);
	//checkStatus(status, "MsgDataReader::return_loan");

}


