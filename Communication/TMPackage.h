/*
 * TMPackage.h
 *
 *  Created on: 15.12.2014
 *      Author: thomas
 */

#ifndef COMMUNICATION_TMPACKAGE_H_
#define COMMUNICATION_TMPACKAGE_H_

#import "DataPackage.h"

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



#endif /* COMMUNICATION_TMPACKAGE_H_ */
