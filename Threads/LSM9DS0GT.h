/*
 * LSM9DS0GT.h
 *
 *  Created on: 05.12.2014
 *      Author: CanSat-I8L-PC05-G03
 */

#ifndef THREADS_LSM9DS0GT_H_
#define THREADS_LSM9DS0GT_H_

#include "rodos.h"
#include "topic.h"

struct Position {
	uint16_t x, y, z;
};

class LSM9DS0GT: public Thread {

public:
	void init();
	void run();
	void calibrate(float * bias);
};

#endif /* THREADS_LSM9DS0GT_H_ */
