/*
 * DataCollector.h
 *
 *  Created on: 05.12.2014
 *      Author: CanSat-I8L-PC05-G03
 */
#include "rodos.h"
#include "LSM9DS0GT.h"

#ifndef THREADS_DATACOLLECTOR_H_
#define THREADS_DATACOLLECTOR_H_

static CommBuffer<GyroPosition> gyroBuffer;
static Subscriber gyroPositionSubscriber(gyroPositionTopic, gyroBuffer, "gyroPosition");

class DataCollector: public Thread {
public:
	DataCollector(const char* name);
	void run(void);
	void init(void);
};

#endif /* THREADS_DATACOLLECTOR_H_ */
