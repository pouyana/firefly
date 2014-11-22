#include "rodos.h"
/*
 * Misc.h
 *
 *  Created on: 21.11.2014
 *      Author: Pouyan Azari
 */

#ifndef MISC_MISC_H_
#define MISC_MISC_H_

class Misc {
public:
	uint16_t shifted(uint8_t *rxBuf);
	int32_t printError(const char* dev, int32_t *err, uint32_t size);

};
#endif /* MISC_MISC_H_ */
