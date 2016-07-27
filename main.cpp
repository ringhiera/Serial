#include <stdio.h>
#include "stdint.h"
#include <termios.h>
#include "Serial.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	
	Serial *serial = new Serial("/dev/ttyUSB0",B9600);
	uint8_t *buf = new uint8_t[100];
	while(1){
		int n = serial->read_(buf, sizeof(buf));
		printf("%.*s",n,buf);
//		sleep(2);
	}

	return 0;
}
