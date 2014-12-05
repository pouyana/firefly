#include "rodos.h"
#include "../Misc/Misc.h"

extern HAL_I2C i2c3;

/*
 * TMP007.h
 *
 *  Created on: 21.11.2014
 *      Author: Pouyan Azari
 */

/**
 * Using Address 0x40 SET( ADRR0, ADDR1 ) To GND
 */
#ifndef SENSORS_TMP007_H_
#define SENSORS_TMP007_H_

#define TMP007_ADDR 0x40

#define TMP007_VOBJ 0x00
#define TMP007_TDIE 0x01
#define TMP007_CONFIG 0x02
#define TMP007_TOBJ 0x03
#define TMP007_STATUS 0x04
#define TMP007_STATMASK 0x05
#define TMP007_CFG_RESET 0x8000
#define TMP007_CFG_MODEON 0x1000
#define TMP007_CFG_1SAMPLE 0x0000
#define TMP007_CFG_2SAMPLE 0x0200
#define TMP007_CFG_4SAMPLE 0x0400
#define TMP007_CFG_8SAMPLE 0x0600
#define TMP007_CFG_16SAMPLE 0x0800
#define TMP007_CFG_ALERTEN 0x0100
#define TMP007_CFG_ALERTF 0x0080
#define TMP007_CFG_TRANSC 0x0040
#define TMP007_STAT_ALERTEN 0x8000
#define TMP007_STAT_CRTEN 0x4000
#define TMP007_DEVID 0x1F

class TMP007 {
private:
	uint8_t txBuf[3];
	uint16_t txBuf16[3];
	uint8_t rxBuf[6];
	int32_t err[1];
	uint16_t result;
	Misc misc;
public:
	void start(void);
	uint16_t getModel(void);
	uint16_t getRawObjTemp(void);
	uint16_t getRawDieTemp(void);
	double getDieTemp(void);
	double getObjTemp(void);
};

#endif /* SENSORS_TMP007_H_ */
