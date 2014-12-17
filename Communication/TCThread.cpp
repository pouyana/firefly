/*
 * TCThread.cpp
 *
 *  Created on: 17.12.2014
 *      Author: thomas
 */

#include "TCThread.h"

HAL_UART deiBlue(UART_IDX2);

TCThread::TCThread(SimpleRing<TCPackage>* packageBuffer) :
		Thread("TC") {
	blue = &deiBlue;
	this->packageBuffer = packageBuffer;

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
	TCPackage tempPackage;

	while (1) {

		//reading of one TC-package
		status = blue->read(buffer, 1);
		if (status == 1) {
			status = blue->read(buffer + 1, DataPackage::TC_PACKAGE_SIZE - 1);

			if (buffer[0] != TC_PACKAGE) {
				break;
			} else if (status != DataPackage::TC_PACKAGE_SIZE - 1) {
				blue->suspendUntilReadFinished(NOW()+ 10*MILLISECONDS);
				tempPackage = TCPackage((uint8_t*) buffer, DataPackage::TC_PACKAGE_SIZE);

				//TODO: depricated should not be executed here, testing only
				execute(&tempPackage);
			}

		} else {
			blue->suspendUntilReadFinished(NOW()+ 10*MILLISECONDS);
		}

//		status = blue->read(buffer, 12);
//		if(status != 12) {
//			xprintf("suspend");
//			blue->suspendUntilReadFinished(NOW() + 100*MILLISECONDS);
//		} else {
//			xprintf("yay 12 bytes read");
//			status = 0;
//		}

	}

}

uint8_t TCThread::execute(TCPackage* package) {

	float param = 0;

	switch(package->getCmd()) {

	case EMPTY:
		break;

	case SET_MOTOR:
		param = DataPackage::uint162float(package->getParam(), DataPackage::MOTOR_RES, DataPackage::MOTOR_OFF);
		motorDuty->publish(param,false);
		break;

	case DEPLOY:

	default:
		break;
	};

	return 0;
}

