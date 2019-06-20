#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>
#include <netinet/in.h>
#include <ctype.h>
#include <iomanip>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/reader.h"

using namespace std;

//#############################################################################################  MAIN VARIABLE  ###############
string	challenge_status	= "idle";
string 	server_ip			= "ROBOT.SERVER";
int 	server_port			= 9000;
string 	team_code			= "UI"; //UI
string	course_type 		= "courseA"; //courseA courseB courseC courseUI kolam

#define STEERING 0
#define THROTTLE 2
#define SIMPLE_PIN 3
#define CAMERA_SERVO 1
#define MOTOR_PIN 4

#define MAX_THROTTLE 1900//1750
#define MIN_THROTTLE 1100
#define MAX_STEERING 1900
#define MIN_STEERING 1100

#define PWM_UP 	1700
#define PWM_LOW 1300
#define MIDDLE_PWM 	1520

#define CAM_INIT_PWM 1500

string mission_idle = "no_mission";

float update_time=0.01;
float delta_t = 0.01;
float initial_time = 0; 

int number_camera=0;

int zero_flag 		= 0;
int first_simple 	= 1;
int second_simple 	= 2;

//################################################################################################  FLAG  ###############
#define THROT_FLAG 1650
#define CAM_FLAG_PWM 1700

int x_flag_crash = 1;
int x_docking_crash = 1;

//################################################################################################  DRONE  #################
int alt_threshold = 1;
float kp_drone = 1.65;//1.5
float ki_drone = 1;//1
float kd_drone = 0.5;//0.5
int setpoint_drone=160;
int x_drone=0;
int y_drone=180;
int width_drone=280; //width 400 for simple
int height_drone=180;
int LowH_drone	= 0; 		//0  
int HighH_drone 	= 184;		//184 
int LowS_drone 	= 130;      //130  65
int HighS_drone 	= 248;      //248  246
int LowV_drone 	= 49;		//49   242
int HighV_drone 	= 230;		//230  255
int Noise_drone 	= 15;

float kp_drone_x = 1.65;//1.5
float ki_drone_x = 1;//1
float kd_drone_x = 0.5;//0.5
int setpoint_drone_x=160;

float kp_drone_y = 1.65;//1.5
float ki_drone_y = 1;//1
float kd_drone_y = 0.5;//0.5
int setpoint_drone_y=160;

//############################################################################################# COMMUNICATION ####################################################
using namespace rapidjson;
int nmea0138_checksum(const char *nmea_data);

enum communicationType {docking, flag, return_dock,};

// ######################################################################################## JSONHandler struct ########################################## //
struct JSONHandler {
	vector<string> json_element;
	void clearJSONVector(){this->json_element.clear();}
	bool Null() {return true; }
	bool Bool(bool b) {
		if(b)this->json_element.push_back("true");
		else this->json_element.push_back("false");
		return true; 
	}
    bool Int(int i) {return true; }
    bool Uint(unsigned u) {return true; }
    bool Int64(int64_t i) {return true; }
    bool Uint64(uint64_t u) {return true; }
    bool Double(double d) {return true; }
    bool RawNumber(const char* str, SizeType length, bool copy) {return true;}
    bool String(const char* str, SizeType length, bool copy) {
		string buffer_string;
		buffer_string.append(str);
		this->json_element.push_back(buffer_string);
		return true;
    }
    bool StartObject() {return true; }
    bool Key(const char* str, SizeType length, bool copy) {
		string buffer_string;
		buffer_string.append(str);
		this->json_element.push_back(buffer_string);
		return true;
    }
    bool EndObject(SizeType memberCount) {return true; }
    bool StartArray() {return true; }
    bool EndArray(SizeType elementCount) {return true; }
};
 // ####################################################################################### AUVSICommunication class ########################################## //
class AUVSICommunication {

	protected:
		string payload;
		string response_message = "No data";
		string hostname;
		int port_number;
		string course_type;
		string team_code;
		int receive_timeout = 10;

	public:
		JSONHandler json_handler;
		AUVSICommunication                    (string hostname_input, int port_number_input, string course_type, string team_code);
		int sendTCP                           ();
		string getPayload                     ();
		string getResponse                    ();
		bool setRemoteTarget                  (string hostname_input, int port_number_input);
		bool setPayload                       (string input_data);
		void setReceiveTimeout                (int receive_timeout);
		void setCourseType                    (string course_type);
		void setTeamCode                      (string team_code);
		int decodeResponeStatus               ();
		int decodedResponse                   ();
		int decodedResponse                   (string response_message);
		int decodeJSON                        (string parsed_http_response);
};

AUVSICommunication::AUVSICommunication(string hostname, int port_number, string course_type, string team_code){
    this->hostname = hostname;
    this->port_number = port_number;
    this->payload = "No data";
    this->course_type = course_type;
    this->team_code = team_code;
}

bool AUVSICommunication::setRemoteTarget(string hostname_input, int port_number_input){
    hostname = hostname_input;
    port_number = port_number_input;
}

bool AUVSICommunication::setPayload (string input_data){
    payload = input_data;
}

int AUVSICommunication::sendTCP(){
	// ################## create socket ################## //
    int socket_desc;
    struct sockaddr_in server;
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1){
		//cout << "Could not create socket";
		response_message = "No data";
		return -1;
    }
    server.sin_addr.s_addr = inet_addr(hostname.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons( port_number );
    // ################## create socket ################## //

    // ################## connect to remote server ################## //
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0){
		//cout << "connect error\n";
		response_message = "No data";
		return -1;
    }

    //cout << "Connected\n";
    // ################## connect to remote server ################## //

    // ################## Send some data ################## //
    //cout << "Message size " << payload.size() << endl;
    if( send(socket_desc , payload.c_str() , payload.size(), 0) < 0){
		//cout << "Send failed";
		response_message = "No data";
		return -1;
    }
    //cout << "Data Send\n";
    // ################## Send some data ################## //

    // ################## Receive some data ################## //
    // ################## set receive timout ################## //
    struct timeval tv;
    tv.tv_sec 	= receive_timeout;  /* 30 Secs Timeout */
    tv.tv_usec 	= 0;  // Not init'ing this can cause strange errors
    setsockopt(socket_desc, SOL_SOCKET, SO_RCVTIMEO, &tv,sizeof(tv));
    errno = 0;	// reset errno
    // ################## set receive timout ################## //

    // create the buffer with space for the data
    const unsigned int MAX_BUF_LENGTH = 4096;
    std::vector<char> buffer(MAX_BUF_LENGTH);
    std::string rcv;
    int bytesReceived = 0;
    do {
		bytesReceived = recv(socket_desc, buffer.data(), buffer.size(), 0);
		// append string from buffer.
		if ( bytesReceived == -1 ) {
			//cout << "recv failed
			response_message = "No data";
			return -1;

		} 
		else {
			rcv.append( buffer.cbegin(), buffer.cend() );
		}
    } 
    while ( bytesReceived == MAX_BUF_LENGTH );

    if (errno == EAGAIN){
		response_message = "No data";
		return -1;
    }

    //cout << "Reply received\n";
    // ################## Receive some data ################## //

    // ################## Convert to string ################## //
    std::stringstream ss;
    for(size_t i = 0; i < buffer.size(); ++i){
		ss << buffer[i];
    }
    // ################## Convert to string ################## //

    close(socket_desc);

    response_message = ss.str();
    return 1;
}

string AUVSICommunication::getPayload (){
    return payload;
}

string AUVSICommunication::getResponse(){
	return response_message;
}

void AUVSICommunication::setReceiveTimeout(int receive_timeout){
    this->receive_timeout = receive_timeout;
}

void AUVSICommunication::setTeamCode(string team_code){
    this->team_code = team_code;
}

void AUVSICommunication::setCourseType(string course_type){
    this->course_type = course_type;
}

int AUVSICommunication::decodeResponeStatus(){
    if (response_message.find("success") != std::string::npos) {
		return 200;
    }
    else if (response_message.find("Invalid checksum") != std::string::npos) {
		return 400;
    }
    else if (response_message.find("Invalid") != std::string::npos) {
		return 404;
    }
    else {
		return -1;
    }
}

int AUVSICommunication::decodeJSON(string parsed_http_response){
    Reader reader;
    StringStream ss(parsed_http_response.c_str());
    json_handler.clearJSONVector();
    reader.Parse(ss, json_handler);
    if (reader.HasParseError()) {
		return -1;
    }
    return 1;
}
 
int AUVSICommunication::decodedResponse(){
    return this->decodedResponse(this->response_message);
}
  
int AUVSICommunication::decodedResponse(string response_message){
    string parsed_http_response;
    try{
		std::size_t pos =   response_message.find("\r\n\r\n");      // position of "live" in str

		parsed_http_response =   response_message.substr (pos);     // get from "live" to the end
		parsed_http_response.erase(0, 4);
		parsed_http_response.erase(parsed_http_response.length()-2,2);
    }
    catch (exception x){
		return 0;
    }

    return this->decodeJSON(parsed_http_response);
}


  // ################################################################################# HEARTBEAT CLASS ########################################## //

class HeartbeatMessage : public AUVSICommunication {

	private:

		int gps_precision = 9;

	public:

		HeartbeatMessage(string hostname, int port_number, string course_type, string team_code);
		void setPayloadCommunication(string timestamp_mission, string timestamp_hours, string challenge, float latitude, float longitude, int system_mode);
		void setGPSPrecision          (int gps_precision);
};

HeartbeatMessage::HeartbeatMessage(string hostname, int port_number, string course_type, string team_code)
  : AUVSICommunication(hostname, port_number, course_type, team_code){}


void HeartbeatMessage::setGPSPrecision(int gps_precision){
    this->gps_precision = gps_precision;
}

void HeartbeatMessage::setPayloadCommunication(string timestamp_mission, string timestamp_hours, string challenge, float latitude, float longitude, int system_mode){
    std::stringstream ss_lat;
    ss_lat << latitude;
    std::stringstream ss_long;
    ss_long << longitude;
	std::stringstream ss_system_mode;
	ss_system_mode << system_mode;
	
    string payload_msg;
    string all_payload;
	string send_payload;
	
    payload_msg = "RBHRB," + timestamp_mission + "," + timestamp_hours + "," + ss_lat.str() + ",N," + ss_long.str() + ",W," + team_code + "," + ss_system_mode.str();
    
    int crc = payload_msg[0];
	for(int i = 1 ;i < payload_msg.size();i++){
		crc =  crc ^ payload_msg[i];
	}
	std::stringstream stream;
	stream << std::hex << crc;
	std::string ss_check_sum( stream.str() );
	
    all_payload = "$" + payload_msg + "*" + ss_check_sum + "\r\n";
    
    payload = all_payload;
}

// ################################################################################################ DockingMessage class ########################################## //
class DockingMission : public AUVSICommunication {

	public:
		DockingMission(string hostname, int port_number, string course_type, string team_code);
		void setPayloadCommunication (string timestamp_mission, string timestamp_hours, int dock_number);
};

DockingMission::DockingMission(string hostname, int port_number, string course_type, string team_code)
  : AUVSICommunication(hostname, port_number, course_type, team_code){}

void DockingMission::setPayloadCommunication(string timestamp_mission, string timestamp_hours, int dock_number){
	string payload_msg;
    string all_payload;
	string send_payload;
	
	
	std::stringstream ss_dock_number;
	ss_dock_number << dock_number;
	
    payload_msg = "RBDOK," + timestamp_mission + "," + timestamp_hours + "," + team_code + "," + ss_dock_number.str();
    
    int crc = payload_msg[0];
	for(int i = 1 ;i < payload_msg.size();i++){
		crc =  crc ^ payload_msg[i];
	}
	std::stringstream stream;
	stream << std::hex << crc;
	std::string ss_check_sum( stream.str() );
	
    all_payload = "$" + payload_msg + "*" + ss_check_sum + "\r\n";
	
    payload = all_payload;
}

// ################################################################################################ FlagMessage class ########################################## //
class FlagMission : public AUVSICommunication {
	public:
		FlagMission(string hostname, int port_number, string course_type, string team_code);
		void setPayloadCommunication (string timestamp_mission, string timestamp_hours, int flag_number);
};

FlagMission::FlagMission(string hostname, int port_number, string course_type, string team_code)
  : AUVSICommunication(hostname, port_number, course_type, team_code){}

void FlagMission::setPayloadCommunication(string timestamp_mission, string timestamp_hours, int flag_number){
	string payload_msg;
    string all_payload;
	string send_payload;
	
	std::stringstream ss_flag_number;
	ss_flag_number << flag_number;
	
    payload_msg = "RBFLG," + timestamp_mission + "," + timestamp_hours + "," + team_code + "," + ss_flag_number.str();
    
    int crc = payload_msg[0];
	for(int i = 1 ;i < payload_msg.size();i++){
		crc =  crc ^ payload_msg[i];
	}
	std::stringstream stream;
	stream << std::hex << crc;
	std::string ss_check_sum( stream.str() );
	
    all_payload = "$" + payload_msg + "*" + ss_check_sum + "\r\n";
	
    payload = all_payload;
}

// ####################################################################################################### start of getTime class ########################################## //
class getTime {

	private:
		time_t t;
		struct tm * now;

	public:

		getTime ();
		void refreshTime();
		string getYear();
		string getMonth();
		string getDay();
		string getHour();
		string getMinute();
		string getSecond();
		string getYMD();
		string getHMS();
};

getTime::getTime(){
    t = time(0);   // get time now
    now = localtime( & t );
}

void getTime::refreshTime(){
    t = time(0);   // get time now
    now = localtime( & t );
}

string getTime::getYear(){
    this->refreshTime();
    int year = now->tm_year + 1900;
    return to_string(year);
}

string getTime::getMonth(){
    this->refreshTime();
    int month = now->tm_mon + 1;
    if(month < 10){
      return "0" + to_string(month);
    }
    else {
      return to_string(month);
    }
}

string getTime::getDay(){
    this->refreshTime();
    int day = now->tm_mday;
    if(day < 10){
		return "0" + to_string(day);
    }
    else {
		return to_string(day);
    }
}
  
string getTime::getHour(){
    this->refreshTime();
    int hour = now->tm_hour;
    if(hour < 10){
		return "0" + to_string(hour);
    }
    else {
		return to_string(hour);
    }
}
  
string getTime::getMinute(){
    this->refreshTime();
    int minute = now->tm_min;
    if(minute < 10){
		return "0" + to_string(minute);
    }
    else {
		return to_string(minute);
    }
}
  
string getTime::getSecond(){
    this->refreshTime();
    int second = now->tm_sec;
    if(second < 10){
		return "0" + to_string(second);
    }
    else {
		return to_string(second);
    }
}

string getTime::getYMD(){
    string complete_ymd = this->getYear() + this->getMonth() + this->getDay() + this->getHour() + this-> getMinute() + this->getSecond();
    return complete_ymd;
}

string getTime::getHMS(){
    string complete_hms = this->getHour() + this-> getMinute() + this->getSecond();
    return complete_hms;
}
