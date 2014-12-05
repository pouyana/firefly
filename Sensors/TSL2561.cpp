#include "TSL2561.h"
/*
 * TSL2561.cpp
 *
 *  Created on: 22.11.2014
 *      Author: Pouyan Azari
 */

void TSL2561::start() {
	if (!isEnabled) {
		txBuf[0] = TSL2561_COMMAND_BIT | TSL2561_REGISTER_CONTROL;
		txBuf[1] = TSL2561_CONTROL_POWERON;
		if (i2c3.write(TSL2561_ADDR_FLOAT, txBuf, 2) < 0)
			i2c3.init();
		isEnabled = true;
	}
}

void TSL2561::stop(void) {
	if (isEnabled) {
		txBuf[0] = TSL2561_COMMAND_BIT | TSL2561_REGISTER_CONTROL;
		txBuf[1] = TSL2561_CONTROL_POWEROFF;
		if (i2c3.write(TSL2561_ADDR_FLOAT, txBuf, 2) < 0)
			i2c3.init();
		isEnabled = false;
	}
}

void TSL2561::initialize(void) {
	_integration = TSL2561_INTEGRATIONTIME_13MS;
	_gain = TSL2561_GAIN_16X;
	setTiming(_integration);
	setGain(_gain);
	stop();
}

uint32_t TSL2561::calculateLux(uint16_t ch0, uint16_t ch1) {
	unsigned long chScale;
	unsigned long channel1;
	unsigned long channel0;
	switch (_integration) {
	case TSL2561_INTEGRATIONTIME_13MS:
		chScale = TSL2561_LUX_CHSCALE_TINT0;
		break;
	case TSL2561_INTEGRATIONTIME_101MS:
		chScale = TSL2561_LUX_CHSCALE_TINT1;
		break;
	default: // No scaling ... integration time = 402ms
		chScale = (1 << TSL2561_LUX_CHSCALE);
		break;
	}
	// Scale for gain (1x or 16x)
	if (!_gain)
		chScale = chScale << 4;
	// scale the channel values
	channel0 = (ch0 * chScale) >> TSL2561_LUX_CHSCALE;
	channel1 = (ch1 * chScale) >> TSL2561_LUX_CHSCALE;
	// find the ratio of the channel values (Channel1/Channel0)
	unsigned long ratio1 = 0;
	if (channel0 != 0)
		ratio1 = (channel1 << (TSL2561_LUX_RATIOSCALE + 1)) / channel0;
	// round the ratio value
	unsigned long ratio = (ratio1 + 1) >> 1;
	unsigned int b, m;
#ifdef TSL2561_PACKAGE_CS
	if ((ratio >= 0) && (ratio <= TSL2561_LUX_K1C))
	{	b=TSL2561_LUX_B1C; m=TSL2561_LUX_M1C;}
	else if (ratio <= TSL2561_LUX_K2C)
	{	b=TSL2561_LUX_B2C; m=TSL2561_LUX_M2C;}
	else if (ratio <= TSL2561_LUX_K3C)
	{	b=TSL2561_LUX_B3C; m=TSL2561_LUX_M3C;}
	else if (ratio <= TSL2561_LUX_K4C)
	{	b=TSL2561_LUX_B4C; m=TSL2561_LUX_M4C;}
	else if (ratio <= TSL2561_LUX_K5C)
	{	b=TSL2561_LUX_B5C; m=TSL2561_LUX_M5C;}
	else if (ratio <= TSL2561_LUX_K6C)
	{	b=TSL2561_LUX_B6C; m=TSL2561_LUX_M6C;}
	else if (ratio <= TSL2561_LUX_K7C)
	{	b=TSL2561_LUX_B7C; m=TSL2561_LUX_M7C;}
	else if (ratio > TSL2561_LUX_K8C)
	{	b=TSL2561_LUX_B8C; m=TSL2561_LUX_M8C;}
#else
	if ((ratio >= 0) && (ratio <= TSL2561_LUX_K1T)) {
		b = TSL2561_LUX_B1T;
		m = TSL2561_LUX_M1T;
	} else if (ratio <= TSL2561_LUX_K2T) {
		b = TSL2561_LUX_B2T;
		m = TSL2561_LUX_M2T;
	} else if (ratio <= TSL2561_LUX_K3T) {
		b = TSL2561_LUX_B3T;
		m = TSL2561_LUX_M3T;
	} else if (ratio <= TSL2561_LUX_K4T) {
		b = TSL2561_LUX_B4T;
		m = TSL2561_LUX_M4T;
	} else if (ratio <= TSL2561_LUX_K5T) {
		b = TSL2561_LUX_B5T;
		m = TSL2561_LUX_M5T;
	} else if (ratio <= TSL2561_LUX_K6T) {
		b = TSL2561_LUX_B6T;
		m = TSL2561_LUX_M6T;
	} else if (ratio <= TSL2561_LUX_K7T) {
		b = TSL2561_LUX_B7T;
		m = TSL2561_LUX_M7T;
	} else if (ratio > TSL2561_LUX_K8T) {
		b = TSL2561_LUX_B8T;
		m = TSL2561_LUX_M8T;
	}
#endif
	unsigned long temp;
	temp = ((channel0 * b) - (channel1 * m));
	// do not allow negative lux value
	if (temp < 0)
		temp = 0;
	// round lsb (2^(LUX_SCALE-1))
	temp += (1 << (TSL2561_LUX_LUXSCALE - 1));
	// strip off fractional portion
	uint32_t lux = temp >> TSL2561_LUX_LUXSCALE;
	// Signal I2C had no errors
	return lux;
}

void TSL2561::setGain(tsl2561Gain_t gain) {
	if (!isEnabled)
		start();
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	if (!gain) {
		gain = TSL2561_GAIN_16X;
	}
	_gain = gain;
	txBuf[0] = TSL2561_COMMAND_BIT | TSL2561_REGISTER_TIMING;
	txBuf[1] = TSL2561_INTEGRATIONTIME_13MS | gain;
	if (i2c3.write(TSL2561_ADDR_FLOAT, txBuf, 2) < 0)
		i2c3.init();
	stop();
}

void TSL2561::setTiming(tsl2561IntegrationTime_t integration) {
	if (!isEnabled)
		start();
	if (!integration) {
		integration = TSL2561_INTEGRATIONTIME_13MS;
	}
	_integration = integration;
	txBuf[0] = TSL2561_COMMAND_BIT | TSL2561_REGISTER_TIMING;
	txBuf[1] = integration | TSL2561_GAIN_16X;
	if (i2c3.write(TSL2561_ADDR_FLOAT, txBuf, 2) < 0)
		i2c3.init();
	stop();
}

uint8_t* TSL2561::getIRHighLow(void) {
	if (!isEnabled)
		start();
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = TSL2561_COMMAND_BIT | TSL2561_REGISTER_CHAN1_LOW;
	err[0] = i2c3.writeRead(TSL2561_ADDR_FLOAT, txBuf, 1, rxBuf, 2);
	if (misc.printError("TSL2561 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		return 0;
	} else {
		return rxBuf;
	}
}

double TSL2561::getRawIR(void) {
	if (!isEnabled)
		start();
	return misc.leftShift(getIRHighLow());
}

uint32_t TSL2561::getFullLuminosity() {
	start();
	uint32_t x;
	uint16_t y;
	txBuf[0] = TSL2561_COMMAND_BIT | TSL2561_REGISTER_CHAN1_LOW;
	err[0] = i2c3.writeRead(TSL2561_ADDR_FLOAT, txBuf, 1, rxBuf, 2);
	x = rxBuf[1];
	x <<= 8;
	x |= rxBuf[0];
	x <<= 16;
	txBuf[0] = TSL2561_COMMAND_BIT | TSL2561_REGISTER_CHAN0_LOW;
	err[1] = i2c3.writeRead(TSL2561_ADDR_FLOAT, txBuf, 1, rxBuf, 2);
	y = rxBuf[1];
	y <<= 8;
	y |= rxBuf[0];
	x |= y;
	if (misc.printError("TSL2561 ", err, 2) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		return false;
	}
	return x;
}

uint16_t TSL2561::getLuminosity(uint8_t channel) {
	uint32_t x = getFullLuminosity();
	if (channel == 0) {
		// Reads two byte value from channel 0 (visible + infrared)
		return (x & 0xFFFF);
	} else if (channel == 1) {
		// Reads two byte value from channel 1 (infrared)
		return (x >> 16);
	} else if (channel == 2) {
		// Reads all and subtracts out just the visible!
		return ((x & 0xFFFF) - (x >> 16));
	}
// unknown channel!
	return 0;
}

