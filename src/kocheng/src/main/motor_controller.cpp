#include "../../include/kocheng/hehe.hpp"
#include "ros/ros.h"
#include "mavros_msgs/OverrideRCIn.h"
#include "kocheng/override_value.h"
#include "kocheng/rc_number.h"
#include <iostream>

bool override_status = false;
bool last_override_status = true;

ros::Publisher pub_override_rc;

mavros_msgs::OverrideRCIn override_out;

void override_input_cb(const kocheng::override_value& override_recv);
void override_status_cb(const kocheng::rc_number& override_status_recv);

int main(int argc, char **argv)
{
  ros::init(argc, argv, "motor_controller");
  ros::NodeHandle n;

  pub_override_rc = n.advertise<mavros_msgs::OverrideRCIn>("/mavros/rc/override", 10);
  
  ros::Subscriber sub_override_motor = n.subscribe("/auvsi/rc/value", 8, override_input_cb);
  ros::Subscriber sub_override_status = n.subscribe("/auvsi/rc/number", 8, override_status_cb);
  
  ROS_WARN("NC : motor_controller.cpp active");
  
	override_out.channels[CAMERA_SERVO] = CAM_INIT_PWM;
	pub_override_rc.publish(override_out);
	while(ros::ok()){
		sleep(0.2);
		ros::spin();
	}
}

void override_status_cb(const kocheng::rc_number& override_status_recv){
	override_status = override_status_recv.override_status;
}

void override_input_cb(const kocheng::override_value& override_recv){
	for(int i=0; i < 8; i++) override_out.channels[i] = 0;
	if(override_status == true){
		//ROS_ERROR("1");
		if (override_recv.throttle > MAX_THROTTLE){
			override_out.channels[THROTTLE] = MAX_THROTTLE;
		}
		else if (override_recv.throttle < MIN_THROTTLE){
			override_out.channels[THROTTLE] = MIN_THROTTLE;
		}
		else {
			override_out.channels[THROTTLE] = override_recv.throttle;
		}

		if (override_recv.steering > MAX_STEERING){
			override_out.channels[STEERING] = MAX_STEERING;
		}
		else if (override_recv.steering < MIN_STEERING){
			override_out.channels[STEERING] = MIN_STEERING;
		}
		else {
			override_out.channels[STEERING] = override_recv.steering;
		}
	}
	override_out.channels[CAMERA_SERVO] = CAM_INIT_PWM;
	
	pub_override_rc.publish(override_out);
}
