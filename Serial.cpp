#include "Serial.h"

#include <errno.h>
#include <fcntl.h> 
#include <string.h>
#include <termios.h>
#include <unistd.h>
//#include <iostream>
#include <string>

Serial::Serial(const char* port, unsigned long speed)
{
//		 The values for speed are B115200, B230400, B9600, B19200, B38400, B57600, B1200, B2400, B4800, etc. 
//		 The values for parity are 0 (meaning no parity), PARENB|PARODD (enable parity and use odd), 
//		 PARENB (enable parity and use even), PARENB|PARODD|CMSPAR (mark parity), and PARENB|CMSPAR (space parity).
	status = false;
	parity =0;
	int should_block =0;
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


//		f = fdopen(fd, "w+");
		status = true;

}

Serial::~Serial()
{
		close(fd);
}
    size_t  Serial::read_(uint8_t* buf, size_t len){
		int n = read (fd, buf, len);
		return n;
	}
	size_t Serial::write_(uint8_t* buf){
		int n = write(fd, buf, sizeof(buf));
		return n;
	} 

