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
*	FILE --- ddsproxyjoy.h
*
*  Created on: Aug 3, 2012
*/
#ifndef _DDSPROXYJOY_H_
#define _DDSPROXYJOY_H_

// DDS includes
#include "ddsProxy.h"

// Message specific includes
#include <sensor_msgs/Joy.h>
#include "../idl_gen/ddsJoy.h"
#include "../idl_gen/ccpp_ddsJoy.h"

class DDSProxyJoy: public DDSProxy {
public:
	DDSProxyJoy();
	~DDSProxyJoy();
	template <class T> void messageCallback(const ros::MessageEvent<T const>& event);
	void update();
	void registerProxy();
private:
	ddsJoyDataWriter_var m_data_writer;
    ddsJoyDataReader_var m_data_reader;
};

#endif // _DDSPROXYJOY_H_
