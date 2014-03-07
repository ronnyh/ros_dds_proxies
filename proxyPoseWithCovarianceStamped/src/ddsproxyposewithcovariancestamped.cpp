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
* 	FILE ---  ddsproxyposewithcovariancestamped.cpp
*
*  Created on: Aug 6, 2012
*/

#include "ddsproxyposewithcovariancestamped.h"
#include "ros/ros.h"

DDSProxyPoseWithCovarianceStamped::DDSProxyPoseWithCovarianceStamped() {
}

DDSProxyPoseWithCovarianceStamped::~DDSProxyPoseWithCovarianceStamped() {

}

void DDSProxyPoseWithCovarianceStamped::registerProxy() {
	// Init participant for DDS. And typesupport for ddsProxyWithCovarianceStamped
	proxyPoseWithCovarianceStampedTypeSupport_var data = new proxyPoseWithCovarianceStampedTypeSupport();
	DDSManager::instance().registerType(dds_domain_name, data.in());
	m_data_topic = DDSManager::instance().createTopic(dds_domain_name.c_str(),
			dds_message_name.c_str(), data->get_type_name());
	DataWriter_ptr writer = DDSManager::instance().createWriter(
			dds_domain_name.c_str(), ros_message_type.c_str(), m_data_topic);
	DataReader_ptr reader = DDSManager::instance().createReader(
			dds_domain_name.c_str(), ros_message_type.c_str(),
			m_data_topic.in());
	m_data_writer = proxyPoseWithCovarianceStampedDataWriter::_narrow(writer);
	m_data_reader = proxyPoseWithCovarianceStampedDataReader::_narrow(reader);
	// Init ROS
	pub = nh_.advertise<geometry_msgs::PoseWithCovarianceStamped>("amcl_pose", 10);
	sub = nh_.subscribe("amcl_pose", 1, &DDSProxyPoseWithCovarianceStamped::messageCallback <geometry_msgs::PoseWithCovarianceStamped>, this);
	ROS_INFO("DDSPosePoseWithCovarianceStamped Initialization completed.");
}

template <class T> void DDSProxyPoseWithCovarianceStamped::messageCallback(
		const ros::MessageEvent<T const>& event) {
	ROS_DEBUG("[Debug]: Received message event of type geometry_msgs::PoseWithCovarianceStamped\n");
	if (event.getPublisherName() != node_name) {
		ROS_DEBUG("Received message from %s", event.getPublisherName().c_str());
		ros::Time receipt_time = event.getReceiptTime();
		const geometry_msgs::PoseWithCovarianceStampedConstPtr& msg = event.getMessage();
		proxyPoseWithCovarianceStamped *proxyPoseWithCovarianceStamped_msg = new proxyPoseWithCovarianceStamped();

		// Filling in data for *proxyPoseWithCovarianceStamped.idl*
		std::string frame_id = std::string(msg->header.frame_id).c_str();
		frame_id.append("/");
		frame_id.append(robot_name.c_str());
		proxyPoseWithCovarianceStamped_msg->header.frame_id = frame_id.c_str();
		proxyPoseWithCovarianceStamped_msg->header.seq = msg->header.seq;
		proxyPoseWithCovarianceStamped_msg->header.stamp.nsec = msg->header.stamp.nsec;
		proxyPoseWithCovarianceStamped_msg->header.stamp.sec = msg->header.stamp.sec;

        // fill pose/position
		proxyPoseWithCovarianceStamped_msg->pose.pose.position.x = msg->pose.pose.position.x;
		proxyPoseWithCovarianceStamped_msg->pose.pose.position.y = msg->pose.pose.position.y;
		proxyPoseWithCovarianceStamped_msg->pose.pose.position.z = msg->pose.pose.position.z;

        // fill pose/orientation
		proxyPoseWithCovarianceStamped_msg->pose.pose.orientation.x = msg->pose.pose.orientation.x;
		proxyPoseWithCovarianceStamped_msg->pose.pose.orientation.y = msg->pose.pose.orientation.y;
		proxyPoseWithCovarianceStamped_msg->pose.pose.orientation.z = msg->pose.pose.orientation.z;
		proxyPoseWithCovarianceStamped_msg->pose.pose.orientation.w = msg->pose.pose.orientation.w;

        // fill pose/covariance
		proxyPoseWithCovarianceStamped_msg->pose.covariance.length(msg->pose.covariance.size());
		for (unsigned int i=0; i < msg->pose.covariance.size(); i++) {
        	proxyPoseWithCovarianceStamped_msg->pose.covariance[i] = msg->pose.covariance[i];
        }

		ReturnCode_t ret = m_data_writer->write(*proxyPoseWithCovarianceStamped_msg, NULL);
		checkStatus(ret, "proxyPoseWithCovarianceStamped::Write");
		// ROS_INFO("Print return code %d", ret);
	}
}

void DDSProxyPoseWithCovarianceStamped::update() {
	proxyPoseWithCovarianceStampedSeq_var proxyPoseWithCovarianceStamped_msgSeq = new proxyPoseWithCovarianceStampedSeq();
	SampleInfoSeq_var infoSeq = new SampleInfoSeq();

	//ROS_INFO_ONCE("while inner loop");
	//ReportStatus_t status
	m_data_reader->take(*proxyPoseWithCovarianceStamped_msgSeq, *infoSeq, LENGTH_UNLIMITED,
			ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
	//checkStatus(status, "MsgDataReader::take");
	//ROS_INFO("Reading data %d", proxyPoseWithCovarianceStamped_msgSeq->length());
	//ROS_INFO("Reading info %d",infoSeq->length());
	for (ULong i = 0; i < proxyPoseWithCovarianceStamped_msgSeq->length(); ++i) {
		//ROS_INFO("publishing message");
		ROS_DEBUG("receiving message via DDS!");
		//ROS_INFO("Sender info %d", proxyPoseWithCovarianceStamped_msgSeq[i]->)
		geometry_msgs::PoseWithCovarianceStamped ddsPoseWithCovarianceStamped_msg;
		proxyPoseWithCovarianceStamped *ROS_proxyPoseWithCovarianceStamped_msg;
		ROS_proxyPoseWithCovarianceStamped_msg = &(proxyPoseWithCovarianceStamped_msgSeq[i]);
		ddsPoseWithCovarianceStamped_msg.header.stamp.sec = ROS_proxyPoseWithCovarianceStamped_msg->header.stamp.sec;
		ddsPoseWithCovarianceStamped_msg.header.stamp.nsec = ROS_proxyPoseWithCovarianceStamped_msg->header.stamp.nsec;
		ddsPoseWithCovarianceStamped_msg.header.seq = ROS_proxyPoseWithCovarianceStamped_msg->header.seq;
		ddsPoseWithCovarianceStamped_msg.header.frame_id = ROS_proxyPoseWithCovarianceStamped_msg->header.frame_id;

		//position
		ddsPoseWithCovarianceStamped_msg.pose.pose.position.x = ROS_proxyPoseWithCovarianceStamped_msg->pose.pose.position.x;
		ddsPoseWithCovarianceStamped_msg.pose.pose.position.y = ROS_proxyPoseWithCovarianceStamped_msg->pose.pose.position.y;
		ddsPoseWithCovarianceStamped_msg.pose.pose.position.z = ROS_proxyPoseWithCovarianceStamped_msg->pose.pose.position.z;

		//orientation
		ddsPoseWithCovarianceStamped_msg.pose.pose.orientation.x = ROS_proxyPoseWithCovarianceStamped_msg->pose.pose.orientation.x;
		ddsPoseWithCovarianceStamped_msg.pose.pose.orientation.y = ROS_proxyPoseWithCovarianceStamped_msg->pose.pose.orientation.y;
		ddsPoseWithCovarianceStamped_msg.pose.pose.orientation.z = ROS_proxyPoseWithCovarianceStamped_msg->pose.pose.orientation.z;
		ddsPoseWithCovarianceStamped_msg.pose.pose.orientation.w = ROS_proxyPoseWithCovarianceStamped_msg->pose.pose.orientation.w;

		//covariance
		for (int i = 0; i < ROS_proxyPoseWithCovarianceStamped_msg->pose.covariance.length(); i++) {
			ddsPoseWithCovarianceStamped_msg.pose.covariance[i] = ROS_proxyPoseWithCovarianceStamped_msg->pose.covariance[i];
		}

		//ROS_INFO("Find robot name at %d", ddsPoseWithCovarianceStamped_msg.header.frame_id.find(robot_name.c_str()));
		if (ddsPoseWithCovarianceStamped_msg.header.frame_id.find(robot_name.c_str()) == -1 )
			pub.publish(ddsPoseWithCovarianceStamped_msg);
	}
	m_data_reader->return_loan(*proxyPoseWithCovarianceStamped_msgSeq, *infoSeq);
	//checkStatus(status, "MsgDataReader::return_loan");

}


