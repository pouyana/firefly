#include "rodos.h"
#include "TMP007.h"
/*
 * TMP007.cpp
 *
 *  Created on: 21.11.2014
 *      Author: Pouyan Azari
 */
void TMP007::start() {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = TMP007_CONFIG;
	if (i2c3.write(TMP007_ADDR, txBuf, 1) < 0)
		i2c3.init();
	txBuf16[0] = TMP007_CFG_MODEON | TMP007_CFG_ALERTEN | TMP007_CFG_TRANSC
			| TMP007_CFG_16SAMPLE;
	txBuf[0] = (uint8_t) (txBuf16[0] & 0xFF);
	if (i2c3.write(TMP007_ADDR, txBuf, 1) < 0)
		i2c3.init();
	txBuf[0] = (uint8_t) ((txBuf16[0] >> 8) & 0xFF);
	if (i2c3.write(TMP007_ADDR, txBuf, 1) < 0)
		i2c3.init();
	txBuf[0] = TMP007_STATMASK;
	if (i2c3.write(TMP007_ADDR, txBuf, 1) < 0)
		i2c3.init();
	txBuf16[0] = TMP007_STAT_ALERTEN | TMP007_STAT_CRTEN;
	txBuf[0] = (uint8_t) (txBuf16[0] & 0xFF);
	if (i2c3.write(TMP007_ADDR, txBuf, 1) < 0)
		i2c3.init();
	txBuf[0] = (uint8_t) ((txBuf16[0] >> 8) & 0xFF);
	if (i2c3.write(TMP007_ADDR, txBuf, 1) < 0)
		i2c3.init();

}
uint16_t TMP007::getModel() {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = TMP007_DEVID;
	err[0] = i2c3.writeRead(TMP007_ADDR, txBuf, 1, rxBuf, 2);
	if (misc.printError("TMP006 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		return false;
	} else {
		result = misc.leftShift(rxBuf);
		return result;
	}

}

uint16_t TMP007::getRawObjTemp() {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = TMP007_TOBJ;
	err[0] = i2c3.writeRead(TMP007_ADDR, txBuf, 1, rxBuf, 2);
	result = misc.leftShift(rxBuf);
	if (misc.printError("TMP006 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		return false;
	} else {
		return result;
	}
}

uint16_t TMP007::getRawDieTemp() {
	txBuf[0] = TMP007_TDIE;
	err[0] = i2c3.writeRead(TMP007_ADDR, txBuf, 1, rxBuf, 2);
	result = misc.leftShift(rxBuf);
	if (misc.printError("TMP006 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		return false;
	} else {
		return result;
	}
}
double TMP007::getObjTemp() {
	result = TMP007::getRawObjTemp();
	result >>= 2;
	double v = result;
	v *= 0.03125;
	return v;
}

double TMP007::getDieTemp() {
	result = TMP007::getRawObjTemp();
	float v = result;
	v = v / 4;
	v *= 0.03125;
	return v;
}

