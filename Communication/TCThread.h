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
#include "DataPackage.h"
#include "TCPackage.h"
#include "../Misc/SimpleRing.h"
#include "PackageType.h"


class TCThread: public RODOS::Thread {
private:
	HAL_UART* blue;
	SimpleRing<TCPackage>* packageBuffer;

	//Debug only
	Topic<float>* motorDuty;

public:
	TCThread(SimpleRing<TCPackage>* packageBuffer);
	virtual ~TCThread();

	uint8_t execute(TCPackage* package);

	void init();
	void run();
};



#endif /* COMMUNICATION_TCTHREAD_H_ */
