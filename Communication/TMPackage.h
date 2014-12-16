/*
 * TMPackage.h
 *
 *  Created on: 15.12.2014
 *      Author: thomas
 */

#ifndef COMMUNICATION_TMPACKAGE_H_
#define COMMUNICATION_TMPACKAGE_H_

#include "DataPackage.h"
#include "../SoftwareMode.h"
#include "CommandWord.h"

class TMPackage: DataPackage {

private:
	//actual data fields (still contain raw data only)

	//sync inherited by DataPackage
	SoftwareMode mode = SAFE;     //soft-ware-mode 	1byte
	CommandWord echoCmd = EMPTY;  //echo of the last received TC-command word	1byte
	uint16_t echoParam = 0;  //echo of the param of last received TC	2b
	uint16_t time = 0;
	float omegaX = 0.0;   //angular velocity in x direction [deg/sec]
	float omegaY = 0.0;
	float omegaZ = 0.0;
	float accX = 0.0;	   //acceleration in x direction [multiples of g]
	float accY = 0.0;
	float accZ = 0.0;
	float roll = 0.0;     //roll angle [deg]
	float pitch = 0.0;    //pitch angle [deg]
	float yaw = 0.0;      //yaw angle [deg]
	float quat1 = 0.0;    //first vector comp. of quaternion representation
	float quat2 = 0.0;
	float quat3 = 0.0;
	float quat4 = 0.0;    //scalar comp. of quaternion
	float vBat1 = 0.0;     //battery voltage [V]
	float vBat2 = 0.0;
	float vBat3 = 0.0;
	float vSolar1 = 0.0;  //1st solar panel voltage [V]
	float vSolar2 = 0.0;  //2nd solar panel voltage [V]
	float motor = 0.0;	//duty cycle of motor
	bool dep = false;      //binary indicator for solar panel deployment
	bool chrg = false;     //binary indicator for battery charging
	float errorYaw = 0.0; //control-error of yaw [deg]
	float errorOmegaZ = 0.0; //control-error of angular velocity in z direction
	float thetaFire1 = 0.0; //yaw angle of fire #1
	float thetaFire2 = 0.0;
	float thetaFire3 = 0.0;
	float thetaFire4 = 0.0;
	float thetaFire5 = 0.0;
	float timeFire1 = 0.0; //MET of the detection of fire #1
	uint16_t timeFire2 = 0;
	uint16_t timeFire3 = 0;
	uint16_t timeFire4 = 0;
	uint16_t timeFire5 = 0;
	float tempFire1 = 0.0;
	float tempFire2 = 0.0;
	float tempFire3 = 0.0;
	float tempFire4 = 0.0;
	float tempFire5 = 0.0;
	float thetaSun = 0.0;  //yaw angle of the sun
	//10 bytes for misc (not yet defined) purposes reserved
	//stop-byte inherited by DataPackage

	//bytePositions
	static const unsigned int POSITION_MODE = 1;
	static const unsigned int POSITION_ECHO_CMD = 2;
	static const unsigned int POSITION_ECHO_PARAM = 3;
	static const unsigned int POSITION_TIME = 5;
	static const unsigned int POSITION_OMEGA_X = 7;
	static const unsigned int POSITION_OMEGA_Y = 9;
	static const unsigned int POSITION_OMEGA_Z = 11;
	static const unsigned int POSITION_ACC_X = 13;
	static const unsigned int POSITION_ACC_Y = 15;
	static const unsigned int POSITION_ACC_Z = 17;
	static const unsigned int POSITION_ROLL = 19;
	static const unsigned int POSITION_PITCH = 21;
	static const unsigned int POSITION_YAW = 23;
	static const unsigned int POSITION_QUAT_1 = 25;
	static const unsigned int POSITION_QUAT_2 = 27;
	static const unsigned int POSITION_QUAT_3 = 29;
	static const unsigned int POSITION_QUAT_4 = 31;
	static const unsigned int POSITION_V_BAT_1 = 33;
	static const unsigned int POSITION_V_BAT_2 = 35;
	static const unsigned int POSITION_V_BAT_3 = 37;
	static const unsigned int POSITION_V_SOLAR_1 = 39;
	static const unsigned int POSITION_V_SOLAR_2 = 41;
	static const unsigned int POSITION_MOTOR = 43;
	static const unsigned int POSITION_DEP = 45;
	static const unsigned int POSITION_CHRG = 46;
	static const unsigned int POSITION_ERR_YAW = 47;
	static const unsigned int POSITION_ERR_OMEGA_Z = 49;
	static const unsigned int POSITION_THETA_FIRE_1 = 51;
	static const unsigned int POSITION_THETA_FIRE_2 = 53;
	static const unsigned int POSITION_THETA_FIRE_3 = 55;
	static const unsigned int POSITION_THETA_FIRE_4 = 57;
	static const unsigned int POSITION_THETA_FIRE_5 = 59;
	static const unsigned int POSITION_TIME_FIRE_1 = 61;
	static const unsigned int POSITION_TIME_FIRE_2 = 63;
	static const unsigned int POSITION_TIME_FIRE_3 = 65;
	static const unsigned int POSITION_TIME_FIRE_4 = 67;
	static const unsigned int POSITION_TIME_FIRE_5 = 69;
	static const unsigned int POSITION_TEMP_FIRE_1 = 71;
	static const unsigned int POSITION_TEMP_FIRE_2 = 73;
	static const unsigned int POSITION_TEMP_FIRE_3 = 75;
	static const unsigned int POSITION_TEMP_FIRE_4 = 77;
	static const unsigned int POSITION_TEMP_FIRE_5 = 79;
	static const unsigned int POSITION_THETA_SUN = 81;
	//83-92 empty for misc
	static const unsigned int POSITION_STOP = 93; //must be size - 1

	//decode encode
	void encodeMode(SoftwareMode mode);
	SoftwareMode decodeMode(uint8_t* buffer);

	void encodeEchoCmd(CommandWord cmd);
	CommandWord decodeEchoCmd(uint8_t* buffer);

	void encodeEchoParam(uint16_t param);
	uint16_t decodeEchoParam(uint8_t* buffer);

	void encodeTime(uint16_t time);
	uint16_t decodeTime(uint8_t* buffer);

	void encodeOmegaX(float value);
	float decodeOmegaX(uint8_t* buffer);

	void encodeOmegaY(float value);
	float decodeOmegaY(uint8_t* buffer);

	void encodeOmegaZ(float value);
	float decodeOmegaZ(uint8_t* buffer);

	void encodeAccX(float value);
	float decodeAccX(uint8_t* buffer);

	void encodeAccY(float value);
	float decodeAccY(uint8_t* buffer);

	void encodeAccZ(float value);
	float decodeAccZ(uint8_t* buffer);

	void encodeRoll(float value);
	float decodeRoll(uint8_t* buffer);

	void encodePitch(float value);
	float decodePitch(uint8_t* buffer);

	void encodeYaw(float value);
	float decodeYaw(uint8_t* buffer);

	void encodeQuat1(float value);
	float decodeQuat1(uint8_t* buffer);

	void encodeQuat2(float value);
	float decodeQuat2(uint8_t* buffer);

	void encodeQuat3(float value);
	float decodeQuat3(uint8_t* buffer);

	void encodeQuat4(float value);
	float decodeQuat4(uint8_t* buffer);

	void encodeVBat1(float value);
	float decodeVBat1(uint8_t* buffer);

	void encodeVBat2(float value);
	float decodeVBat2(uint8_t* buffer);

	void encodeVBat3(float value);
	float decodeVBat3(uint8_t* buffer);

	void encodeVSolar1(float value);
	float decodeVSolar1(uint8_t* buffer);

	void encodeVSolar2(float value);
	float decodeVSolar2(uint8_t* buffer);

	void encodeMotor(float value);
	float decodeMotor(uint8_t* buffer);

	void encodeDep(bool value);
	bool decodeDep(uint8_t* buffer);

	void encodeChrg(bool value);
	bool decodeChrg(uint8_t* buffer);

	void encodeErrYaw(float value);
	float decodeErrYaw(uint8_t* buffer);

	void encodeErrOmegaZ(float value);
	float decodeErrOmegaZ(uint8_t* buffer);

	void encodeThetaFire1(float value);
	float decodeThetaFire1(uint8_t* buffer);

	void encodeThetaFire2(float value);
	float decodeThetaFire2(uint8_t* buffer);

	void encodeThetaFire3(float value);
	float decodeThetaFire3(uint8_t* buffer);

	void encodeThetaFire4(float value);
	float decodeThetaFire4(uint8_t* buffer);

	void encodeThetaFire5(float value);
	float decodeThetaFire5(uint8_t* buffer);

	void encodeTimeFire1(uint16_t value);
	uint16_t decodeTimeFire1(uint8_t* buffer);

	void encodeTimeFire2(uint16_t value);
	uint16_t decodeTimeFire2(uint8_t* buffer);

	void encodeTimeFire3(uint16_t value);
	uint16_t decodeTimeFire3(uint8_t* buffer);

	void encodeTimeFire4(uint16_t value);
	uint16_t decodeTimeFire4(uint8_t* buffer);

	void encodeTimeFire5(uint16_t value);
	uint16_t decodeTimeFire5(uint8_t* buffer);

	void encodeTempFire1(float value);
	float decodeTempFire1(uint8_t* buffer);

	void encodeTempFire2(float value);
	float decodeTempFire2(uint8_t* buffer);

	void encodeTempFire3(float value);
	float decodeTempFire3(uint8_t* buffer);

	void encodeTempFire4(float value);
	float decodeTempFire4(uint8_t* buffer);

	void encodeTempFire5(float value);
	float decodeTempFire5(uint8_t* buffer);

	void encodeThetaSun(float value);
	float decodeThetaSun(uint8_t* buffer);

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
	TMPackage(SoftwareMode mode, CommandWord echoCmd, float echoParam,
			uint16_t time, float omegaX, float omegaY, float omegaZ, float accX,
			float accY, float accZ, float roll, float pitch, float yaw,
			float quat1, float quat2, float quat3, float quat4, float vBat1,
			float vBat2, float vBat3, float vSolar1, float vSolar2, float motor,
			bool dep, bool chrg, float errorYaw, float errorOmegaZ,
			float thetaFire1, float thetaFire2, float thetaFire3,
			float thetaFire4, float thetaFire5, float timeFire1,
			float timeFire2, float timeFire3, float timeFire4, float timeFire5,
			float tempFire1, float tempFire2, float tempFire3, float tempFire4,
			float tempFire5, float thetaSun);

	void build();

	//getters and setters
	float getAccX() const;
	void setAccX(float accX);
	float getAccY() const;
	void setAccY(float accY);
	float getAccZ() const;
	void setAccZ(float accZ);
	bool isChrg() const;
	void setChrg(bool chrg);
	bool isDep() const;
	void setDep(bool dep);
	CommandWord getEchoCmd() const;
	void setEchoCmd(CommandWord echoCmd);
	uint16_t getEchoParam() const;
	void setEchoParam(uint16_t echoParam);
	float getErrorOmegaZ() const;
	void setErrorOmegaZ(float errorOmegaZ);
	float getErrorYaw() const;
	void setErrorYaw(float errorYaw);
	SoftwareMode getMode() const;
	void setMode(SoftwareMode mode);
	float getMotor() const;
	void setMotor(float motor);
	float getOmegaX() const;
	void setOmegaX(float omegaX);
	float getOmegaY() const;
	void setOmegaY(float omegaY);
	float getOmegaZ() const;
	void setOmegaZ(float omegaZ);
	float getPitch() const;
	void setPitch(float pitch);
	float getQuat1() const;
	void setQuat1(float quat1);
	float getQuat2() const;
	void setQuat2(float quat2);
	float getQuat3() const;
	void setQuat3(float quat3);
	float getQuat4() const;
	void setQuat4(float quat4);
	float getRoll() const;
	void setRoll(float roll);
	float getTempFire1() const;
	void setTempFire1(float tempFire1);
	float getTempFire2() const;
	void setTempFire2(float tempFire2);
	float getTempFire3() const;
	void setTempFire3(float tempFire3);
	float getTempFire4() const;
	void setTempFire4(float tempFire4);
	float getTempFire5() const;
	void setTempFire5(float tempFire5);
	float getThetaFire1() const;
	void setThetaFire1(float thetaFire1);
	float getThetaFire2() const;
	void setThetaFire2(float thetaFire2);
	float getThetaFire3() const;
	void setThetaFire3(float thetaFire3);
	float getThetaFire4() const;
	void setThetaFire4(float thetaFire4);
	float getThetaFire5() const;
	void setThetaFire5(float thetaFire5);
	float getThetaSun() const;
	void setThetaSun(float thetaSun);
	uint16_t getTime() const;
	void setTime(uint16_t time);
	float getTimeFire1() const;
	void setTimeFire1(float timeFire1);
	uint16_t getTimeFire2() const;
	void setTimeFire2(uint16_t timeFire2);
	uint16_t getTimeFire3() const;
	void setTimeFire3(uint16_t timeFire3);
	uint16_t getTimeFire4() const;
	void setTimeFire4(uint16_t timeFire4);
	uint16_t getTimeFire5() const;
	void setTimeFire5(uint16_t timeFire5);
	float getBat1() const;
	void setBat1(float bat1);
	float getBat2() const;
	void setBat2(float bat2);
	float getBat3() const;
	void setBat3(float bat3);
	float getSolar1() const;
	void setSolar1(float solar1);
	float getSolar2() const;
	void setSolar2(float solar2);
	float getYaw() const;
	void setYaw(float yaw);
};

#endif /* COMMUNICATION_TMPACKAGE_H_ */
