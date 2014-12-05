/*
 * LSM9DS0.h
 *
 *  Created on: 05.12.2014
 *      Author: CanSat-I8L-PC05-G03
 */

#include "rodos.h"
#include "hal/hal_gpio.h"
#include "../Misc/Misc.h"

#ifndef SENSORS_LSM9DS0_H_
#define SENSORS_LSM9DS0_H_

extern HAL_GPIO gpioIMU;

class LSM9DS0 {
private:
	bool isOn;
public:
	void init(void);
	void stop(void);
};
#endif /* SENSORS_LSM9DS0_H_ */
