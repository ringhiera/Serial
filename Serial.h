#ifndef SERIAL_H
#define SERIAL_H
#include "stdint.h"
#include "stdlib.h"
#include <stdio.h>

//#include "SerialException.h"


class Serial
{
private:
	char* port;
	size_t baud;
	bool status;
	int fd;
	int parity;
	int should_block;
	FILE* f;
	
public:
	Serial(const char* port, unsigned long speed);
	~Serial();
	
public:
    void end();
    size_t read_(uint8_t* buf, size_t len);
	size_t write_(uint8_t* str); 
};

#endif // SERIAL_H
