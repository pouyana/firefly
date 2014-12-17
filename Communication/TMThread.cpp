/*
 * TMThread.cpp
 *
 *  Created on: 16.12.2014
 *      Author: thomas
 */


#include "TMThread.h"
#include "semaphore.h"

Semaphore testSemaphore;
SimpleRing<int> myBuffer(20, &testSemaphore);
HAL_UART myBlue(UART_IDX2);


TMThread::TMThread() : Thread("TM") {
	//buffer = new SimpleRing<int>(20);
	buffer = &myBuffer;
	blue = &myBlue;

}

TMThread::~TMThread() {
	//delete buffer;
}

void TMThread::init() {

	// Test simpleRing
		xprintf("Hello World");
		buffer = &myBuffer;
		xprintf("buffer init");

		buffer->push(1);
		buffer->push(2);
		buffer->push(3);
		buffer->push(4);

		xprintf("Size (20, 4): %d", buffer->size());

		xprintf("Pop (1): %d", buffer->pop());
		xprintf("New Size(3) %d", buffer->size());


		//init bluetooth
		blue->init(19200);

}

void TMThread::run() {
char* buffer = "Hello World";
int status = 0;

blue->write(buffer, 1);

while(1) {

		status = blue->write(buffer, 11);
		if(status != 11) {
			blue->suspendUntilWriteFinished(NOW()+1*SECONDS);
		}


}


}

//TMThread test();

