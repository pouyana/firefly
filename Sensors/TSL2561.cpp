#include "TSL2561.h"
/*
 * TSL2561.cpp
 *
 *  Created on: 22.11.2014
 *      Author: Pouyan Azari
 */

void TSL2561::start() {
	txBuf[0] = TSL2561_COMMAND_BIT | TSL2561_REGISTER_CONTROL;
	txBuf[1] = TSL2561_CONTROL_POWERON;
	if (i2c1.write(TSL2561_ADDR_FLOAT, txBuf, 2) < 0)
		i2c1.init();
}

uint16_t TSL2561::getRawLux(void) {

}
uint16_t TSL2561::getRawIR(void) {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = TSL2561_COMMAND_BIT | TSL2561_REGISTER_CHAN1_LOW;
	err[0] = i2c1.writeRead(TSL2561_ADDR_FLOAT, txBuf, 1, rxBuf, 2);
	if (misc.printError("TSL2561 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		return false;
	} else {
		return misc.shifted(rxBuf);
	}

}
double TSL2561::getHuLux(void) {

}
double TSL2561::getHuIR(void) {

}
double TSL2561::getData(void) {

}

