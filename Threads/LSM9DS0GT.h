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
#include "../Sensors/LSM9DS0G.h"
#include "../Sensors/LSM9DS0.h"

struct GyroPosition {
	uint16_t x, y, z;
};

extern Topic<GyroPosition> gyroPositionTopic;

class LSM9DS0GT: public Thread {
public:
	LSM9DS0GT(const char* name);
	void init();
	void run();
	LSM9DS0 lsm9ds0;
	LSM9DS0G gyro;
	float * gyroBias;
private:
	GyroPosition gyroPos;
	uint8_t txBuf[3];
	uint8_t rxBuf[6];
};

#endif /* THREADS_LSM9DS0GT_H_ */
