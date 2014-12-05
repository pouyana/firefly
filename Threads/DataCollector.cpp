/*
 * DataCollector.cpp
 *
 *  Created on: 05.12.2014
 *      Author: CanSat-I8L-PC05-G03
 */
#include "DataCollector.h"

DataCollector::DataCollector(const char* name) :
		Thread(name) {
}

void DataCollector::run(void) {
	while (1) {
		GyroPosition pos;
		gyroBuffer.get(pos);
		xprintf("GX %d GY %d GZ %d\n", pos.x, pos.y, pos.z);
		suspendCallerUntil(NOW()+1*SECONDS);
	}

}
void DataCollector::init(void) {

}

