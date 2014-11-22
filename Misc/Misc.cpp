#include "rodos.h"
#include "Misc.h"
/*
 * Misc.cpp
 *
 *  Created on: 21.11.2014
 *      Author: Pouyan Azari
 */

uint16_t Misc::shifted(uint8_t *rxBuf) {
	uint16_t result = rxBuf[1] | (rxBuf[0] << 8);
	return result;
}
int32_t Misc::printError(const char* dev, int32_t *err, uint32_t size) {
	uint32_t i = 0;
	uint32_t errCnt = 0;

	for (i = 0; i < size; i++) {
		if (err[i] < 0) {
			xprintf("%s I2C error:\n", dev);
			break;
		}
	}

	for (i = 0; i < size; i++) {
		if (err[i] < 0) {
			errCnt++;
			xprintf(" %d. %d\n", (int) i + 1, (int) err[i]);
		}
	}

	return errCnt;
}
