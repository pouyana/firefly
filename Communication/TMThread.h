/*
 * TMThread.h
 *
 *  Created on: 16.12.2014
 *      Author: thomas
 */

#ifndef COMMUNICATION_TMTHREAD_H_
#define COMMUNICATION_TMTHREAD_H_

#include "rodos.h"
#include <thread.h>
#include "../Misc/SimpleRing.h"


class TMThread: public Thread {

private:

	SimpleRing<int>* buffer;
	HAL_UART* blue;

public:
	TMThread();
	~TMThread();
	void init();
	void run();
};



#endif /* COMMUNICATION_TMTHREAD_H_ */
