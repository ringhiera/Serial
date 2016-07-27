#include "RingBuffer.h"

RingBuffer::RingBuffer(size_t len):len(len)
{
	head=0;
	tail=0;

	buf = new uint8_t[len];
}

RingBuffer::~RingBuffer()
{
}

uint8_t RingBuffer::pop(){
	if (size()>0){
		char c = buf[head];
		head = (head+1)%len;
		return c;
	}else{
		
		// figure out what to do with it
		throw -1;
	}
		
}
size_t RingBuffer::push(uint8_t c){
	if(tail!=head){
		buf[tail]=c;
		tail = (tail+1)%len;
		return 1;
	}else{
		return 0;
	}
}

size_t RingBuffer::size(){
	return (tail-head) % len;

}