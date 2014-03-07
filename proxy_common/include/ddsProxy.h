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
*
*  Author: Ronny Hartanto (ronny.hartanto@dfki.de)
*  
* FILE --- ddsProxy.h
*
*  Created on: Aug 4, 2012
*/

#ifndef DDSPROXY_H_
#define DDSPROXY_H_

// DDS includes
#include "ddsManager.h"

#include <iostream>
#include <string>
#include <iostream>

// ROS includes
#include <ros/ros.h>

class DDSProxy{
protected:
	ros::NodeHandle nh_;
    ros::Subscriber sub;
	ros::Publisher pub;

	Topic_var m_data_topic;
    std::string dds_domain_name;
    std::string ros_message_name;
    std::string dds_message_name;
    std::string ros_message_type;
    std::string node_name;
    std::string robot_name;
    int ros_frequency;
public:
	DDSProxy() {};
	~DDSProxy() {};
	template <class T> void messageCallback(const ros::MessageEvent<T const>& event);
	virtual void update() = 0;
	void initialize(std::string domain, std::string ros_topic, std::string dds_topic, std::string ros_msg_type) {
		// Read parameters
		node_name = ros::this_node::getName();
		ROS_INFO("Node name : %s", node_name.c_str());
		std::string param_domain_name = node_name.c_str();
		param_domain_name.append("/domain_name");
		std::string param_ros_msg_name = node_name.c_str();
		param_ros_msg_name.append("/ros_msg_name");
		std::string param_dds_msg_name = node_name.c_str();
		param_dds_msg_name.append("/dds_msg_name");
		std::string param_frequency_name = node_name.c_str();
		param_frequency_name.append("/frequency");
		std::string param_robot_name = node_name.c_str();
		param_robot_name.append("/robot_name");
		nh_.param(param_domain_name, dds_domain_name, domain);
		nh_.param(param_ros_msg_name, ros_message_name, ros_topic);
		nh_.param(param_dds_msg_name, dds_message_name, dds_topic);
		nh_.param(param_frequency_name, ros_frequency, 1);
		nh_.param(param_robot_name, robot_name, node_name);
		ros_message_type = ros_msg_type;
		ROS_INFO("DDS domain name: %s", dds_domain_name.c_str());
		ROS_INFO("ROS message name: %s", ros_message_name.c_str());
		ROS_INFO("DDS message name: %s", dds_message_name.c_str());
		ROS_INFO("ROS message type: %s", ros_message_type.c_str());
		ROS_INFO("ROS message freq: %d", ros_frequency);
		ROS_INFO("Robot name: %s", robot_name.c_str());
		registerProxy();
	}
	virtual void registerProxy() = 0;
	int getFrequency() {return ros_frequency;};
};

#endif /* DDSPROXY_H_ */
