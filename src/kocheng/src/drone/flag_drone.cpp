#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>

#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

#include "kocheng/drone_kocheng.h"
#include "kocheng/image_in.h"
#include "kocheng/image_out.h"

#include "mavros_msgs/SetMode.h"
#include "mavros_msgs/State.h"

#include "sensor_msgs/NavSatFix.h"

#include "geometry_msgs/TwistStamped.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/opencv.hpp"
#include "opencv/cv.h"

#include "std_msgs/Float64.h"

using namespace std;
using namespace cv;

void drone_status_cb	(const kocheng::drone_kocheng& data);
void altReceiver	(const std_msgs::Float64& alt_msg);

bool changeFlightMode		(const char* flight_mode);
bool changeFlightModeDebug	(string fm);

void image_out_cb(const kocheng::image_out& image);

kocheng::drone_kocheng drone;
kocheng::image_in image_in;

int state_x, state_y, throttle_pwm, steer_pwm, control_effort_x, control_effort_y;

ros::ServiceClient client_set_flightmode;

string drone_status;

string flag_picture;
string flag_landing;

Mat Original;

float alt_now;

geometry_msgs::TwistStamped quad_vel;

void imageCallback(const sensor_msgs::CompressedImageConstPtr& msg){
  try{
    Original = cv::imdecode(cv::Mat(msg->data),1);//convert compressed image data to cv::Mat
  }
  catch (cv_bridge::Exception& e){
    ROS_ERROR("Could not convert to image!");
  }
}

int main(int argc, char **argv){
	ros::init(argc, argv, "flag drone");
	ros::NodeHandle nh;
	cv::startWindowThread();
	
	ROS_WARN("NC : flag_drone.cpp active");
	image_transport::ImageTransport it(nh);
	image_transport::Publisher pub = it.advertise("/camera/drone/image", 1, true);
	
	ros::Publisher pub_drone_status = nh.advertise<kocheng::drone_kocheng>("/auvsi/drone/status", 8);
	ros::Publisher pub_quad_vel 	= nh.advertise<geometry_msgs::TwistStamped>("mavros/setpoint_velocity/cmd_vel", 1000);
	
	ros::Publisher pub_image_in 	= nh.advertise<kocheng::image_in>("/auvsi/image/in", 1);
	
	ros::Subscriber sub_image_cb		= nh.subscribe("camera/drone/compressed", 1, imageCallback);
	ros::Subscriber sub_drone_status 	= nh.subscribe("/auvsi/drone/status", 8, drone_status_cb);	
	ros::Subscriber sub_rel_alt 		= nh.subscribe("mavros/global_position/rel_alt", 1, altReceiver );
	
	client_set_flightmode 				= nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
	
	flag_picture 	= "rosrun mavros mavwp load ~/flag_pic_"+course_type+".waypoints";
	flag_landing	= "rosrun mavros mavwp load ~/flag_landing_"+course_type+".waypoints";
	
	while (ros::ok()) {
		ros::spinOnce();
		while(drone_status=="flag_drone"){
			changeFlightModeDebug("LOITER");
			system("rosrun mavros mavwp clear"); //clear wp
			system(flag_picture.c_str());
			system("rosrun mavros mavsys mode -c AUTO");
			sleep(10);
			changeFlightModeDebug("LOITER");
			
			namedWindow("Original", CV_WINDOW_AUTOSIZE);
    
			vector<int> compression_params; 
			compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
			compression_params.push_back(98); 
			bool cSuccess = imwrite("../flag.jpg", Original, compression_params); 
			if(!Original.empty()){	
				sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", Original).toImageMsg();
				pub.publish(msg);
			}
			
			system("rosrun mavros mavwp clear"); 
			system(flag_landing.c_str());
			system("rosrun mavros mavsys mode -c AUTO");
			sleep(10);
			changeFlightModeDebug("LOITER");
			sleep(1);
			changeFlightModeDebug("LANDING");
			drone.drone_status=="flag_landing";
			pub_drone_status.publish(drone);			
			ros::spinOnce();
		}
	}
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

void altReceiver(const std_msgs::Float64& alt_msg){
	alt_now = alt_msg.data;
}
