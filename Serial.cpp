#include "Serial.h"

#include <cerrno>
#include <fcntl.h> 
#include <string.h>
#include <termios.h>
#include <unistd.h>
//#include <iostream>
#include <string>

Serial::Serial(const char* port, unsigned long speed)
{
//		 The values for speed are B1200, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, etc. 
//		 The values for parity are 0 (meaning no parity), PARENB|PARODD (enable parity and use odd), 
//		 PARENB (enable parity and use even), PARENB|PARODD|CMSPAR (mark parity), and PARENB|CMSPAR (space parity).
	
	status = false;
	parity =0;
	should_block =0;
	
	int fd;
	fd = open (port, O_RDWR | O_NOCTTY | O_SYNC);
	if (fd < 0){
		throw "error "+std::to_string(errno)+" opening "+port+": "+strerror (errno);
	}
	struct termios tty;
	memset (&tty, 0, sizeof tty);
	if (tcgetattr (fd, &tty) != 0)
	{
		throw "error "+std::to_string(errno)+(" from tcgetattr");
	}

	cfsetospeed (&tty, speed);
	cfsetispeed (&tty, speed);

	tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
	// disable IGNBRK for mismatched speed tests; otherwise receive break
	// as \000 chars
	tty.c_iflag &= ~IGNBRK;         // disable break processing
	tty.c_lflag = 0;                // no signaling chars, no echo,
									// no canonical processing
	tty.c_oflag = 0;                // no remapping, no delays
	tty.c_cc[VMIN]  = should_block ? 1 : 0;            // 0: read doesn't block
	tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

	tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

	tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
									// enable reading
	tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
	tty.c_cflag |= parity;
	tty.c_cflag &= ~CSTOPB;	
	tty.c_cflag &= ~CRTSCTS;

	if (tcsetattr (fd, TCSANOW, &tty) != 0)
	{
			throw "error "+std::to_string(errno)+(" from tcgetattr");
	}		


	f = fdopen(fd, "w+");	// transform file descriptior in FILE, the latter has better support in C++
	status = true;

}

Serial::~Serial()
{
		fclose(f);
}
    std::size_t  Serial::read(void* buffer, std::size_t size, std::size_t count){
		return std::fread (buffer,size, count, f);
	}
	std::size_t Serial::write(const void* buffer, std::size_t size, std::size_t count){
		return fwrite(buffer, size, count, f);
	} 

