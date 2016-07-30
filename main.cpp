
#include <string>
#include <iostream>
#include <unistd.h>
#include <termios.h>

#include "Serial.h"


#define BUF_LEN 100

int main(int argc, char **argv)
{
	Serial *serial;
	try{
		serial = new Serial("/dev/ttyUSB0",B9600);
	}catch(std::string e){
		std::cout << "Exception: "<<e<<'\n';
		return -1;
	}
	uint8_t *buf = new uint8_t[BUF_LEN];
	printf("buf: %d, uint8_t: %d",sizeof(uint8_t), BUF_LEN );
	while(1){
		int n = serial->read(buf, sizeof(uint8_t), BUF_LEN);
		printf("%.*s",n,buf);
		sleep(2);
	}
	return 0;

//	PingPong *pingPong;
//	try{
//		pingPong = new PingPong();
//	}catch(std::string e){
//		std::cout << "Exception: "<<e<<'\n';
//	}
//	try{
//		pingPong = new PingPong();
//	}catch(std::string e){
//		pingPong->receive();	//always start the receiver first as the sender is blocking
//	}
//	try{
//		pingPong = new PingPong();
//	}catch(std::string e){
//		pingPong->send();
//	}
	
	
	return 0;
}
