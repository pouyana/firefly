/*
 * TCThread.h
 *
 *  Created on: 17.12.2014
 *      Author: thomas
 */

#ifndef COMMUNICATION_TCTHREAD_H_
#define COMMUNICATION_TCTHREAD_H_

#include <thread.h>
#include <rodos.h>
#include <hal/hal_uart.h>

class TCThread: public RODOS::Thread {
private:
	HAL_UART* blue;
public:
	TCThread();
	virtual ~TCThread();

	void init();
	void run();
};

TCThread myTC;

#endif /* COMMUNICATION_TCTHREAD_H_ */
