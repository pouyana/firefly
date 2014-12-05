#include "rodos.h"
/*
 * Template.h
 *
 *  Created on: 21.11.2014
 *      Author: Pouyan Azari
 */

#ifndef TEMPLATE_H_
#define TEMPLATE_H_

/**
 * Define all Hardware singletons here. so they can be used systemwide.
 * GPIO/I2C and UART can be defined here.
 */

/**
 * PINS To Connect on The Board (0x40)
 * ADDR1 => GND
 * ADDR0 => GND
 * SDA => PC9
 * SCL => PA8
 * VCC => 3V
 */
HAL_I2C i2c3(I2C_IDX3);

/**
 * The IMU is connected to this board.
 */
/**
 * SDA => PB11
 * SCL => PB10
 * VCC => 3V
 */
HAL_I2C i2c2(I2C_IDX2);

/**
 * GPIO PIN for IMU.
 * PD7 => GPIO_055
 */

HAL_GPIO gpioIMU(GPIO_055);

/**
 * GPIO PIN for Gyro.
 * PB2 => GPIO_018
 */

HAL_GPIO gpioGyro(GPIO_018);

#endif /* TEMPLATE_H_ */
