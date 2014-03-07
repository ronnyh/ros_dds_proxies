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
* 	FILE ---  ddsproxyposewithcovariancestamped.h
*
*  Created on: Aug 6, 2012
*/
#ifndef _DDSPROXYPOSEWITHCOVARIANCESTAMPED_H_
#define _DDSPROXYPOSEWITHCOVARIANCESTAMPED_H_

// DDS includes
#include "ddsProxy.h"

// Message specific includes
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include "../idl_gen/proxyPoseWithCovarianceStamped.h"
#include "../idl_gen/ccpp_proxyPoseWithCovarianceStamped.h"

class DDSProxyPoseWithCovarianceStamped: public DDSProxy {
public:
	DDSProxyPoseWithCovarianceStamped();
	~DDSProxyPoseWithCovarianceStamped();
	template <class T> void messageCallback(const ros::MessageEvent<T const>& event);
	void update();
	void registerProxy();
private:
	proxyPoseWithCovarianceStampedDataWriter_var m_data_writer;
	proxyPoseWithCovarianceStampedDataReader_var m_data_reader;
};

#endif // _DDSPROXYPOSEWITHCOVARIANCESTAMPED_H_
