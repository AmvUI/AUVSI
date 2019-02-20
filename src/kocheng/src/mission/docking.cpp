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

string docking_number;

kocheng::mission_status	mission;
kocheng::drone_kocheng drone;
kocheng::decode_status docking_status_decode;
kocheng::communication docking_payload_string;

ros::ServiceClient client_set_flightmode;

geometry_msgs::PoseStamped rc_pos;

string receive_mission;
string drone_status;

string docking_1;
string docking_2;
string docking_3;

Mat image;
DockingMission docking_protocol(server_ip, server_port, course_type, team_code);

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
	ros::init(argc, argv, "navigation");
	ros::NodeHandle nh;
	
	ROS_WARN("NC : docking.cpp active");
	
	ros::Publisher pub_mission_rc 	= nh.advertise<kocheng::mission_status>("/auvsi/rc/mission", 1);
	ros::Publisher pub_drone_status = nh.advertise<kocheng::drone_kocheng>("/auvsi/drone/status", 8);
	ros::Publisher pub_rc_pos 		= nh.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 1000);
	
	ros::Publisher pub_run_status		= nh.advertise<kocheng::decode_status>("/auvsi/run_course/status", 16);
	ros::Publisher pub_payload_status	= nh.advertise<kocheng::communication>("/auvsi/communication/status", 16);
	
	ros::Subscriber sub_drone_status 	= nh.subscribe("/auvsi/drone/status", 8, drone_status_cb);	
	ros::Subscriber sub_mission_rc 		= nh.subscribe("/auvsi/rc/mission", 1, rc_mission_cb);
	ros::Subscriber sub_drone_image 	= nh.subscribe("/camera/drone/image", 1, imageCallback);
	
	client_set_flightmode 				= nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
	
	docking_1 = "rosrun mavros mavwp load ~/docking_1_"+course_type+".waypoints";
	docking_2 = "rosrun mavros mavwp load ~/docking_2_"+course_type+".waypoints";
	docking_3 = "rosrun mavros mavwp load ~/docking_3_"+course_type+".waypoints";
	
	while (ros::ok()) {
		ros::spinOnce();
		while(receive_mission=="docking.start"){
			//get ping docking_number
			
			if(docking_number=="1"){
				system(docking_1.c_str());
				changeFlightModeDebug("AUTO");
			}
			else if(docking_number=="2"){
				system(docking_2.c_str());
				changeFlightModeDebug("AUTO");
			}
			else if(docking_number=="3"){
				system(docking_3.c_str());
				changeFlightModeDebug("AUTO");
			}
			else{
				system(docking_1.c_str());
				changeFlightModeDebug("AUTO");
			}
		
			changeFlightModeDebug("HOLD");
			ros::spinOnce();
			drone.drone_status="docking_drone";
			pub_drone_status.publish(drone);
			ros::spinOnce();
			mission.mission_makara == "docking_wait";
			ros::spinOnce();
		}
		while(receive_mission=="docking_wait"){
			ros::spinOnce();
			if(drone_status=="docking_landing"){
				ros::spinOnce();
				
				vector<int> compression_params; 
				compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
				compression_params.push_back(98); 
				bool cSuccess = imwrite("../docking.jpg", image, compression_params); 
			
				docking_protocol.setPayloadCommunication(follow);
				docking_protocol.sendTCP();
		
				docking_payload_string.docking_payload = docking_protocol.getPayload();
				docking_status_decode.docking_status = docking_protocol.decodeResponeStatus();
				pub_run_status.publish(docking_status_decode);
				pub_payload_status.publish(docking_payload_string);
				
				Mat im_gray = imread("../docking.jpg",CV_LOAD_IMAGE_GRAYSCALE);
				Mat img_bw = im_gray > 128;
				imwrite("../docking_bw.jpg", img_bw);
				sleep(8);
    
				system ("tesseract docking_bw.jpg docking_out -l letsgodigital");
				//################################################# get number from docking_out.txt
				
				changeFlightModeDebug("HOLD");
				system("rosrun mavros mavwp clear");
				if(docking_number=="1"){
					system(docking_1.c_str());
					changeFlightModeDebug("AUTO");
				}
				else if(docking_number=="2"){
					system(docking_2.c_str());
					changeFlightModeDebug("AUTO");
				}
				else if(docking_number=="3"){
					system(docking_3.c_str());
					changeFlightModeDebug("AUTO");
				}
				else{
					system(docking_1.c_str());
					changeFlightModeDebug("AUTO");
				}
				
				rc_pos.header.stamp = ros::Time::now();
				rc_pos.header.frame_id = "1";
				rc_pos.pose.position.x = x_docking_crash; 
				pub_rc_pos.publish(rc_pos);
					
				mission.mission_makara="docking.end";
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

