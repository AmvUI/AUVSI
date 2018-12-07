#include "../../include/kocheng/hehe.hpp"
#include "ros/ros.h"
#include "mavros_msgs/OverrideRCIn.h"
#include "mavros_msgs/RCIn.h"
#include "std_msgs/Bool.h"

#include "kocheng/rc_number.h"
#include "kocheng/mission_status.h"

#include <string>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int rc_in_data_channel[8];
int number_flight = 0;
bool override_flag = false;

void rcinReceiver(const mavros_msgs::RCIn& rc_in_data);

kocheng::rc_number rc_action; 
kocheng::mission_status	mission;

int main(int argc, char **argv){

	ros::init(argc, argv, "remote_monitor");
	ros::NodeHandle ovrd_mon;
	ros::Publisher pub_rc_flag 		= ovrd_mon.advertise<kocheng::rc_number>("/auvsi/rc/number", 8);
	ros::Publisher pub_mission_rc 	= ovrd_mon.advertise<kocheng::mission_status>("/auvsi/rc/mission", 1);
	ros::Subscriber rc_in_sub 		= ovrd_mon.subscribe("/mavros/rc/in", 8, rcinReceiver);
		
	ROS_WARN("NC : remote_monitor.cpp active");
	
	while(ros::ok()){
		sleep(0.2);
		ros::spinOnce();
		if(rc_in_data_channel[SIMPLE_PIN] < PWM_LOW ){
			override_flag = true;
			number_flight = first_simple;
		}
		else if(rc_in_data_channel[SIMPLE_PIN] > PWM_UP){
			override_flag = true;
			number_flight = second_simple;
		}
		else{
			override_flag 			= false;
			mission.mission_makara	= mission_idle;
			pub_mission_rc.publish(mission);
		}
		
		rc_action.override_status = override_flag;
		rc_action.rc_number = number_flight;
		pub_rc_flag.publish(rc_action);
	}
}

void rcinReceiver(const mavros_msgs::RCIn& rc_in_data){
	int x;
	for (x=0; x<8;x++){
		rc_in_data_channel[x] = rc_in_data.channels[x];
	}
}


