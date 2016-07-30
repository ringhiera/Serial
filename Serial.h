#ifndef SERIAL_H
#define SERIAL_H
#include <cstdint>
#include <cstdlib>
#include <cstdio>

//#include "SerialException.h"


class Serial
{
private:
	char* port;
	size_t baud;
	bool status;
	int parity;
	int should_block;
	FILE* f;
	
public:
	Serial(const char* port, unsigned long speed);
	~Serial();
	
public:
    void end();
    std::size_t read(void* buffer, std::size_t size, std::size_t count);
	std::size_t write(const void* buffer, std::size_t size, std::size_t count); 
};

#endif // SERIAL_H
