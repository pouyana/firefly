/*
 * DataPackage.h
 *
 *  Created on: 04.12.2014
 *      Author: thomas
 *
 * Description: This header-file defines the abstract DataPackage-class and all its child-classes
 */

#ifndef DATAPACKAGE_H_
#define DATAPACKAGE_H_

#include "rodos.h"
#include "PackageType.h"
#include <stdlib.h>

class DataPackage {

protected:
	unsigned int byteSize;
	uint8_t* rawData;
	bool validRaw;
	//Semaphore protect;

	//actual data fields, common for all DataPackages
	PackageType sync;
	uint8_t stop;

	//static final constants for raw-data conversion


	//RES = resolution, equals the least significant digit
	//MIN = lower bound of valid range of values
	//MAX = upper bound of valid range of values
	//OFF = offset which the complete range is shifted (to achive non-negative values)
	static const float TIME_RES = 0.1; //sec
	static const float TIME_MIN = 0;
	static const float TIME_MAX = 1200;
	static const float TIME_OFF = 0;

	static const float ANG_VEL_RES = 0.01; //deg/sec
	static const float ANG_VEL_MIN = -180.0;
	static const float ANG_VEL_MAX = 180.0;
	static const float ANG_VEL_OFF = 180.0;

	static const float ACC_RES = 0.001;//g
	static const float ACC_MIN = -5.0;
	static const float ACC_MAX = 5.0;
	static const float ACC_OFF = 5.0;

	static const float ANGLE_RES = 0.01;//deg
	static const float ANGLE_MIN = -180.0;
	static const float ANGLE_MAX = 180.0;
	static const float ANGLE_OFF = 180.0;

	static const float QUAT_RES = 0.0001;
	static const float QUAT_MIN = -1.0;
	static const float QUAT_MAX = 1.0;
	static const float QUAT_OFF = 1.0;

	static const float VOLT_RES = 0.001;//V
	static const float VOLT_MIN = -12.0;
	static const float VOLT_MAX = 12.0;
	static const float VOLT_OFF = 12.0;

	static const float MOTOR_RES = 0.0001; //%
	static const float MOTOR_MIN = -1.0;
	static const float MOTOR_MAX = 1.0;
	static const float MOTOR_OFF = 1.0;

	static const float TEMP_RES = 1.0; //°C TODO
	static const float TEMP_MIN = -100.0; //TODO
	static const float TEMP_MAX = 100.0; //TODO
	static const float TEMP_OFF = 100.0; //TODO;


	static const unsigned int TC_PACKAGE_SIZE = 5;
	static const unsigned int TM_PACKAGE_SIZE = 94;
	static const unsigned int VIDEO_PACKAGE_SIZE = 0; //TODO

	//byteFields
	static const unsigned int POSITION_SYNC = 0;

	//StopByte
	static const uint8_t STOP_BYTE = (uint8_t) '#';


	static uint16_t float2uint16(float value, float res, float offset) {
		return (uint16_t) ((value+offset)/res);
	};

	static float uint162float(uint16_t value, float res, float offset) {

		return (float) ((value*res) - offset);
	}

public:
	static uint8_t highByte(uint16_t value) {
		return (uint8_t) value >> 8;
	}

	static uint8_t lowByte(uint16_t value) {
		return (uint8_t) (value && 0x00FF);
	}

protected:
	static uint16_t joinBytes(uint8_t high, uint8_t low) {
		return (uint16_t) (high << 8) + low;
	}

	static uint8_t bool2uint8(bool value) {
		if(value) {
			return 0xFF;
		} else {
			return 0x00;
		}
	}

	static bool uint82bool(uint8_t value) {
		if(value == 0xFF) {
			return true;
		}
		return false;
	}

	void encodeType(PackageType type);
	PackageType decodeType();

	virtual void encodeStop(uint8_t stop) = 0;

public:


	/**
	 * abstract method which forms the rawData-field from the actual data fields
	 */
	virtual void build() = 0;

	uint8_t* getRaw();


//	DataPackage parse(uint8_t* rawData, unsigned int rawDataSize);

	PackageType getType();

	DataPackage(unsigned int size, PackageType type);
	virtual ~DataPackage();


};



#endif /* DATAPACKAGE_H_ */
