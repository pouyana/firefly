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

class DataPackage {

private:
	unsigned int byteSize;
	uint8_t* rawData;

	//actual data fields, common for all DataPackages
	uint8_t sync;
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

	static uint16_t float2uint16(float value, float res, float offset);/* {
		return (short) ((value+offset)/res);
	};*/


	DataPackage(unsigned int size);
	virtual ~DataPackage();

public:

	/**
	 * abstract method which forms the rawData-field from the actual data fields
	 */
	virtual void build() = 0;

	/**
	 * abstract method which calculates the actual data fields from rawData
	 */
	//virtual DataPackage parse(uint8_t* rawData, unsigned int rawDataSize);

};

class TMPackage : DataPackage {

private:
	//actual data fields (still contain raw data only)

	//sync inherited by DataPackage
	uint8_t  mode;     //soft-ware-mode
	uint8_t  echoCmd;  //echo of the last received TC-command word
	uint16_t echoParam;//echo of the param of last received TC
	uint16_t time;
	uint16_t omegaX;   //angular velocity in x direction [deg/sec]
	uint16_t omegaY;
	uint16_t omegaZ;
	uint16_t accX;	   //acceleration in x direction [multiples of g]
	uint16_t accY;
	uint16_t accZ;
	uint16_t roll;     //roll angle [deg]
	uint16_t pitch;    //pitch angle [deg]
	uint16_t yaw;      //yaw angle [deg]
	uint16_t quat1;    //first vector comp. of quaternion representation
	uint16_t quat2;
	uint16_t quat3;
	uint16_t quat4;    //scalar comp. of quaternion
	uint16_t vBat;     //battery voltage [V]
	uint16_t vSolar1;  //1st solar panel voltage [V]
	uint16_t vSolar2;  //2nd solar panel voltage [V]
	uint8_t  dep;      //binary indicator for solar panel deployment
	uint8_t  chrg;     //binary indicator for battery charging
	uint16_t errorYaw; //control-error of yaw [deg]
	uint16_t errorOmegaZ; //control-error of angular velocity in z direction
	uint16_t thetaFire1; //yaw angle of fire #1
	uint16_t thetaFire2;
	uint16_t thetaFire3;
	uint16_t thetaFire4;
	uint16_t thetaFire5;
	uint16_t timeFire1; //MET of the detection of fire #1
	uint16_t timeFire2;
	uint16_t timeFire3;
	uint16_t timeFire4;
	uint16_t timeFire5;
	uint16_t thetaSun;  //yaw angle of the sun
	//10 bytes for misc (not yet defined) purposes reserved
	//stop-byte inherited by DataPackage

public:
	/*
	 * creates an empty well formatted TM Package
	 */
	TMPackage();

	~TMPackage();

	/**
	 * build a TMPackage out of raw data stream
	 */
	TMPackage(uint8_t* buffer, unsigned int bufferSize);

	/**
	 * build TMPackage based on actual values
	 */
	TMPackage(
			uint8_t  mode,
				uint8_t  echoCmd,
				float echoParam,
				uint16_t time,
				float omegaX,
				float omegaY,
				float omegaZ,
				float accX,
				float accY,
				float accZ,
				float roll,
				float pitch,
				float yaw,
				float quat1,
				float quat2,
				float quat3,
				float quat4,
				float vBat,
				float vSolar1,
				float vSolar2,
				uint8_t dep,
				uint8_t chrg,
				float errorYaw,
				float errorOmegaZ,
				float thetaFire1,
				float thetaFire2,
				float thetaFire3,
				float thetaFire4,
				float thetaFire5,
				float timeFire1,
				float timeFire2,
				float timeFire3,
				float timeFire4,
				float timeFire5,
				float thetaSun
		);


};

class TCPackage : DataPackage {

private:
	//data fields (containing raw data)
	//sync inherited from DataPackage
	uint8_t cmd;
	uint16_t param;
	//stop inherited from DataPackage

public:
	/*
	 * creates an empty but well formatted TCPackage
	 */
	TCPackage();

	~TCPackage();

	/*
	 * creates TC package from raw data
	 */
	TCPackage(uint8_t buffer, unsigned int bufferSize);

	/*
	 * creates TC package from values
	 */
	TCPackage(uint8_t cmd, float param);
};




#endif /* DATAPACKAGE_H_ */
