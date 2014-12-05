/*
 * LSM9DS0G.h
 *
 *  Created on: 05.12.2014
 *      Author: CanSat-I8L-PC05-G03
 */
#include "rodos.h"
#include "hal/hal_gpio.h"
#include "../Misc/Misc.h"

#ifndef SENSORS_LSM9DS0G_H_
#define SENSORS_LSM9DS0G_H_

#define LSM9DS0G_ADDR 0X6B

#define WHO_AM_I_G	0x0F
#define CTRL_REG1_G	0x20
#define CTRL_REG2_G	0x21
#define CTRL_REG3_G	0x22
#define CTRL_REG4_G	0x23
#define CTRL_REG5_G	0x24
#define REFERENCE_G	0x25
#define STATUS_REG_G	0x27
#define OUT_X_L_G	0x28
#define OUT_X_H_G	0x29
#define OUT_Y_L_G	0x2A
#define OUT_Y_H_G	0x2B
#define OUT_Z_L_G	0x2C
#define OUT_Z_H_G	0x2D
#define FIFO_CTRL_REG_G	0x2E
#define FIFO_SRC_REG_G	0x2F
#define INT1_CFG_G	0x30
#define INT1_SRC_G	0x31
#define INT1_THS_XH_G	0x32
#define INT1_THS_XL_G	0x33
#define INT1_THS_YH_G	0x34
#define INT1_THS_YL_G	0x35
#define INT1_THS_ZH_G	0x36
#define INT1_THS_ZL_G	0x37
#define INT1_DURATION_G	0x38

extern HAL_GPIO gpioGyro;
extern HAL_I2C i2c2;

class LSM9DS0G {
public:
	enum gyro_scale {
		G_SCALE_245DPS, // 00: 245 degrees per second
		G_SCALE_500DPS, // 01: 500 dps
		G_SCALE_2000DPS, // 10: 2000 dps
	};
	void init(void);
	void stop(void);
	void enableFifo(void);
	void disableFifo(void);
	void read(void);
	void enableStreamMode(void);
	void enableByPassMode(void);
	void calcgRes(gyro_scale gScale);
	uint8_t readNumberOfSamples(void);
	uint8_t getModel(void);
	uint8_t readBias(void);

	float gRes;
	uint16_t gx;
	uint16_t gy;
	uint16_t gz;
private:
	bool isOn;
	uint8_t txBuf[3];
	uint8_t rxBuf[6];
	uint16_t txBuf16[3];
	int32_t err[2];
	uint16_t result;
	Misc misc;
};

#endif /* SENSORS_LSM9DS0G_H_ */
