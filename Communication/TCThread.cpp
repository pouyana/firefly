/*
 * TCThread.cpp
 *
 *  Created on: 17.12.2014
 *      Author: thomas
 */

#include "TCThread.h"


HAL_UART deiBlue(UART_IDX2);


TCThread::TCThread() : Thread("TC"){
	blue = &deiBlue;

}

TCThread::~TCThread() {
	// TODO Auto-generated destructor stub
}

void TCThread::init() {

	blue->init(19200);
}

void TCThread::run() {

	char buffer[100];
	int status = 0;

	while(1) {

		status = blue->read(buffer, 12);
		if(status != 12) {
			xprintf("suspend");
			blue->suspendUntilReadFinished(NOW() + 100*MILLISECONDS);
		} else {
			xprintf("yay 12 bytes read");
			status = 0;
		}



	}

}



