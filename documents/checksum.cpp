#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

std::string nmea0138_checksum(std::string& nmea_data);
std::string haha = "RBHRB,101218,161233,21.31198,N,157.88972,W,AUVSI,2";

int main(){
	std::string checksum = nmea0138_checksum(haha);
	cout << checksum << endl;
}

std::string nmea0138_checksum(std::string& nmea_data){
	int crc = nmea_data[0];
	for(int i = 1 ;i < nmea_data.size();i++){
		crc =  crc ^ nmea_data[i];
	}
	std::stringstream stream;
	stream << std::hex << crc;
	std::string result( stream.str() );
	return result;
}
