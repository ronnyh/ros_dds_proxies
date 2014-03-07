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
*	FILE --- proxyJoy.cpp
*
*  Created on: Aug 3, 2012
*/

#include "ddsproxyjoy.h"
#include <ros/callback_queue.h>

int main(int argc, char *argv[]){

    ros::init(argc, argv, "ddsProxyJoy");

    DDSProxyJoy  *proxy_node = new DDSProxyJoy();

    ROS_INFO("Initialized DDS <-Joy-> ROS ");
    proxy_node->initialize("IMPERA", "joy", "ddsJoy", "sensor_msgs.joy");

    ros::Rate loop_rate(proxy_node->getFrequency());

    while(ros::ok())
    {
    	ros::getGlobalCallbackQueue()->callAvailable(ros::WallDuration(0.1));
    	proxy_node->update();
        loop_rate.sleep();
    }

    return 0;
}

