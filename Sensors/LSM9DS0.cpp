/*
 * LSM9DS0.cpp
 *
 *  Created on: 05.12.2014
 *      Author: CanSat-I8L-PC05-G03
 */
#include "LSM9DS0.h"

void LSM9DS0::init(void) {
	if (!isOn & gpioIMU.read() == 0) {
		gpioIMU.init(true, 1, 1);
	}
	isOn = true;
}
void LSM9DS0::stop(void) {
	if (isOn & gpioIMU.read() == 1) {
		gpioIMU.init(false, 1, 1);
	}
	isOn = false;
}

