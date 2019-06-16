#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>

#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

#include "kocheng/mission_status.h"
#include "kocheng/drone_kocheng.h"
#include "kocheng/decode_status.h"
#include "kocheng/communication.h"

#include "mavros_msgs/SetMode.h"
#include "mavros_msgs/State.h"

#include "sensor_msgs/NavSatFix.h"

#include "geometry_msgs/PoseStamped.h"

using namespace std;
using namespace cv;

void rc_mission_cb		(const kocheng::mission_status& data);
void drone_status_cb	(const kocheng::drone_kocheng& data);

bool changeFlightMode		(const char* flight_mode);
bool changeFlightModeDebug	(string fm);

string flag_number;

kocheng::mission_status	mission;
kocheng::drone_kocheng drone;
kocheng::decode_status flag_status_decode;
kocheng::communication flag_payload_string;

ros::ServiceClient client_set_flightmode;

geometry_msgs::PoseStamped rc_pos;

string receive_mission;
string drone_status;

string flag_1;
string flag_2;
string flag_3;
string flag_4;

Mat image;
int flag_num;
FlagMission flag_protocol(server_ip, server_port, course_type, team_code);

void imageCallback(const sensor_msgs::CompressedImageConstPtr& msg)
{
  try
  {
    image = cv::imdecode(cv::Mat(msg->data),1);//convert compressed image data to cv::Mat
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert to image!");
  }
}

int main(int argc, char **argv){
	getTime time_lord;
	ros::init(argc, argv, "navigation");
	ros::NodeHandle nh;
	
	ROS_WARN("NC : flag.cpp active");
	
	ros::Publisher pub_mission_rc 	= nh.advertise<kocheng::mission_status>("/auvsi/rc/mission", 1);
	ros::Publisher pub_drone_status = nh.advertise<kocheng::drone_kocheng>("/auvsi/drone/status", 8);
	ros::Publisher pub_rc_pos 		= nh.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 1000);
	
	ros::Publisher pub_run_status		= nh.advertise<kocheng::decode_status>("/auvsi/run_course/status", 16);
	ros::Publisher pub_payload_status	= nh.advertise<kocheng::communication>("/auvsi/communication/status", 16);
	
	ros::Subscriber sub_drone_status 	= nh.subscribe("/auvsi/drone/status", 8, drone_status_cb);	
	ros::Subscriber sub_mission_rc 		= nh.subscribe("/auvsi/rc/mission", 1, rc_mission_cb);
	ros::Subscriber sub_drone_image 	= nh.subscribe("/camera/drone/image", 1, imageCallback);
	
	client_set_flightmode 			= nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
	
	flag_1 = "rosrun mavros mavwp load ~/flag_1_"+course_type+".waypoints";
	flag_2 = "rosrun mavros mavwp load ~/flag_2_"+course_type+".waypoints";
	flag_3 = "rosrun mavros mavwp load ~/flag_3_"+course_type+".waypoints";
	flag_4 = "rosrun mavros mavwp load ~/flag_4_"+course_type+".waypoints";

	while (ros::ok()) {
		ros::spinOnce();
		while(receive_mission=="flag.start"){
			changeFlightModeDebug("HOLD");
			ros::spinOnce();
			drone.drone_status="flag_drone";
			pub_drone_status.publish(drone);
			ros::spinOnce();
			mission.mission_makara == "flag_wait";
			ros::spinOnce();
		}
		while(receive_mission=="flag_wait"){
			ros::spinOnce();
			if(drone_status=="flag_landing"){
				ros::spinOnce();
				
				flag_num = 1;
				
				flag_protocol.setPayloadCommunication(time_lord.getYMD(), time_lord.getHMS(), flag_num);
				flag_protocol.sendTCP();
				
				flag_payload_string.flag_payload = flag_protocol.getPayload();
				flag_status_decode.flag_status = flag_protocol.decodeResponeStatus();
				pub_run_status.publish(flag_status_decode);
				pub_payload_status.publish(flag_payload_string);
				
				sleep(8);
    
				changeFlightModeDebug("HOLD");
				system("rosrun mavros mavwp clear");
				if(flag_num==1){
					system(flag_1.c_str());
					system("rosrun mavros mavsys mode -c AUTO");
					sleep(5);
				}
				else if(flag_num==1){
					system(flag_2.c_str());
					system("rosrun mavros mavsys mode -c AUTO");
					sleep(5);
				}
				else if(flag_num==1){
					system(flag_3.c_str());
					system("rosrun mavros mavsys mode -c AUTO");
					sleep(5);	
				}
				else if(flag_num==1){
					system(flag_4.c_str());
					system("rosrun mavros mavsys mode -c AUTO");
					sleep(5);
				}
				else{
					system(flag_1.c_str());
					system("rosrun mavros mavsys mode -c AUTO");
					sleep(5);
				}
				
				rc_pos.header.stamp = ros::Time::now();
				rc_pos.header.frame_id = "1";
				rc_pos.pose.position.x = x_flag_crash; 
				pub_rc_pos.publish(rc_pos);
					
				mission.mission_makara="flag.end";
				pub_mission_rc.publish(mission);
			}
		}
	}
}

void rc_mission_cb	(const kocheng::mission_status& data){
	receive_mission = data.mission_makara;
}

void drone_status_cb	(const kocheng::drone_kocheng& data){
	drone_status=data.drone_status;
}

bool changeFlightMode(const char* flight_mode){
	mavros_msgs::SetMode flightmode;
	flightmode.request.base_mode 	= 0;				
	flightmode.request.custom_mode 	= flight_mode;		
	bool success = client_set_flightmode.call(flightmode);

	if(success){
		return true;
	}
	else {
		return  false;
	}
}

bool changeFlightModeDebug(string fm){
	changeFlightMode(fm.c_str());
}

