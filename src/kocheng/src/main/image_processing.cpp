#include "../../include/kocheng/hehe.hpp"
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

#include "pid/plant_msg.h"

#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

#include "kocheng/image_in.h"
#include "kocheng/image_out.h"

using namespace std;
using namespace cv;

void imageProcessing	(Mat input_image);

Mat receive_image;

int x_init=25;
int y_init=25;
int width=200; //width 400 for simple
int height=200;
int LowH=0; 		//0  
int HighH=184;		//184 
int LowS=130;      //130  65
int HighS=248;      //248  246
int LowV=49;		//49   242
int HighV=230;		//230  255
int Noise=15;

int state_x;
int state_y;

int setpoint_x;
int setpoint_y=200;

kocheng::image_out image_out; 


void pid_in_x_cb(const pid::plant_msg& pid);
void pid_in_y_cb(const pid::plant_msg& pid);
void image_in_cb(const kocheng::image_in& in);

ros::Publisher pub_image_out; 

void imageCallback(const sensor_msgs::CompressedImageConstPtr& msg){
  try{
    receive_image = cv::imdecode(cv::Mat(msg->data),1);//convert compressed image data to cv::Mat
    imageProcessing(receive_image);
    waitKey(10);
  }
  catch (cv_bridge::Exception& e){
    ROS_ERROR("Could not convert to image!");
  }
}

int main(int argc, char **argv){
	ros::init(argc, argv, "image processing");
	ros::NodeHandle nh;
	cv::startWindowThread();
	
	ROS_WARN("NC : image_processing.cpp active");
	image_transport::ImageTransport it(nh);
	
	pub_image_out 	= nh.advertise<kocheng::image_out>("/auvsi/image/out", 10);
	
	ros::Subscriber sub_image_cb	= nh.subscribe("camera/image/compressed", 1, imageCallback);
	ros::Subscriber sub_image_in	= nh.subscribe("/auvsi/image/in", 1, image_in_cb);
	ros::Subscriber sub_pid_in_x 	= nh.subscribe("/auvsi/pid/inX", 1, pid_in_x_cb);
	ros::Subscriber sub_pid_in_y 	= nh.subscribe("/auvsi/pid/inY", 1, pid_in_y_cb);
	 
	namedWindow("panel", CV_WINDOW_AUTOSIZE);
	
	createTrackbar("LowH", "panel", &LowH, 255);
	createTrackbar("HighH", "panel", &HighH, 255);
	createTrackbar("LowS", "panel", &LowS, 255); 
	createTrackbar("HighS", "panel", &HighS, 255);
	createTrackbar("LowV", "panel", &LowV, 255);
	createTrackbar("HighV", "panel", &HighV, 255);
	createTrackbar("x_init", "panel", &x_init, 700); //Hue (0 - 255)
	createTrackbar("y_init", "panel", &y_init, 700);
	createTrackbar("width", "panel", &width, 700); //Saturation (0 - 255)
	createTrackbar("hight", "panel", &height, 700);
	createTrackbar("noise", "panel", &Noise, 255);
	
	while (ros::ok()) {
		ros::spinOnce();
	}
}

void imageProcessing(Mat input_image){
	
	Mat imgOriginal, imgHSV, imgThresholded, imgErode, imgDilate, imgDebug;
	
	imgDebug = input_image.clone();
	medianBlur(imgDebug, imgDebug, 5);
	cvtColor(imgDebug, imgDebug, COLOR_BGR2HSV);
	inRange(imgDebug, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), imgDebug);//range threshold
	
	
	erode(imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise, Noise)) );
	dilate( imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise, Noise)) ); 
	dilate(imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise, Noise)) ); 
	erode(imgDebug, imgDebug, getStructuringElement(MORPH_ELLIPSE, Size(Noise, Noise)) ); 
	
	Rect region_of_interest = Rect(x_init, y_init, width, height);
	Mat Original = input_image(region_of_interest);
	
	Size sz = Original.size();
	int original_height = sz.height; 
	int original_width	= sz.width;
	
	Size sx = input_image.size();
	int input_height 	= sx.height;
	int input_width 	= sx.width; 
	
	imgOriginal = Original.clone();
	
	medianBlur(imgOriginal, imgOriginal, 5);
		
	cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);
	inRange(imgHSV, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), imgThresholded);//range threshold
	
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise, Noise)) );
	dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise, Noise)) ); 
		
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise, Noise)) ); 
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(Noise, Noise)) ); 
	
	Moments mu=moments(imgThresholded);
	int area = mu.m00; // sum of zero'th moment is area
	int posX = mu.m10/area; // center of mass = w*x/weight
	int posY = mu.m01/area;
	area 	/= 255; // scale from bytes to pixels	
	
	state_x = posX;
	state_y = posY;
	
	if(state_x<=0){
		state_x=0;
	}
	if(state_y<=0){
		state_y=0;
	}
	image_out.state_x=state_x;
	image_out.state_y=state_y;
	
	pub_image_out.publish(image_out);
	
	line( Original, Point( setpoint_x, 0 ), Point( setpoint_x, original_height), Scalar( 50, 50, 50 ), 2, 8 );
	line( Original, Point( state_x, 0 ), Point( state_x, original_height), Scalar( 150, 150, 150 ), 2, 8 );
	line( Original, Point( 0, setpoint_y ), Point( original_width, setpoint_y), Scalar( 50, 50, 50 ), 2, 8 );
	line( Original, Point( 0, state_y ), Point( original_width, state_y), Scalar( 150, 150, 150 ), 2, 8 );
	
	line( input_image, Point( setpoint_x, 0 ), Point( setpoint_x, input_height), Scalar( 50, 50, 50 ), 2, 8 );
	//line( input_image, Point( state_x, 0 ), Point( state_x, input_height), Scalar( 150, 150, 150 ), 2, 8 );
	line( input_image, Point( 0, setpoint_y ), Point( input_width, setpoint_y), Scalar( 50, 50, 50 ), 2, 8 );
	//line( input_image, Point( 0, state_y ), Point( original_width, state_y), Scalar( 150, 150, 150 ), 2, 8 );
	
	line( input_image, Point( x_init, y_init ), Point( x_init+original_width, y_init), Scalar( 100, 100, 100 ), 2, 8 );
	line( input_image, Point( x_init, y_init+original_height ), Point( x_init+original_width, y_init+original_height), Scalar( 100, 100, 100 ), 2, 8 );	
	line( input_image, Point( x_init, y_init ), Point( x_init, y_init+original_height), Scalar( 100, 100, 100 ), 2, 8 );
	line( input_image, Point( x_init+original_width, y_init ), Point( x_init+original_width, y_init+original_height), Scalar( 100, 100, 100 ), 2, 8 );
	
	imshow("Threshold", imgThresholded);
	imshow("All", imgDebug);
	imshow("Input", input_image);
}

void pid_in_x_cb(const pid::plant_msg& pid){
	setpoint_x = pid.setpoint;
}

void pid_in_y_cb(const pid::plant_msg& pid){
	setpoint_y = pid.setpoint;
}

void image_in_cb(const kocheng::image_in& in){
	x_init	= in.x_init;
	y_init	= in.y_init;
	width	= in.width; //width 400 for simple
	height	= in.height;
	LowH	= in.LowH; 		//0  
	HighH	= in.HighH;		//184 
	LowS	= in.LowS;      //130  65
	HighS	= in.HighS;      //248  246
	LowV	= in.LowV;		//49   242
	HighV	= in.HighV;		//230  255
	Noise	= in.Noise;
}
