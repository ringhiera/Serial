#ifndef RINGBUFFER_H
#define RINGBUFFER_H
#include "stdlib.h"
#include "stdint.h"

class RingBuffer
{
	
private:
	uint8_t* buf;
	size_t len;
	size_t head;
	size_t tail;
	
public:
	RingBuffer(size_t len);
	~RingBuffer();
	uint8_t pop();
	size_t push(uint8_t c);
	size_t size();

};

#endif // RINGBUFFER_H
