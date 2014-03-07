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
* 	FILE --- ddsproxyposestamped.h
*
*  Created on: Sep 10, 2012
*/
#ifndef _DDSPROXYPOSESTAMPED_H_
#define _DDSPROXYPOSESTAMPED_H_

// DDS includes
#include "ddsProxy.h"

// Message specific includes
#include <geometry_msgs/PoseStamped.h>
#include "../idl_gen/proxyPoseStamped.h"
#include "../idl_gen/ccpp_proxyPoseStamped.h"

class DDSProxyPoseStamped: public DDSProxy {
public:
	DDSProxyPoseStamped();
	~DDSProxyPoseStamped();
	template <class T> void messageCallback(const ros::MessageEvent<T const>& event);
	void update();
	void registerProxy();
private:
	proxyPoseStampedDataWriter_var m_data_writer;
	proxyPoseStampedDataReader_var m_data_reader;
};

#endif // _DDSPROXYPOSESTAMPED_H_
