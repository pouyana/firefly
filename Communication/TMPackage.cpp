/*
 * TMPackage.cpp
 *
 *  Created on: 04.12.2014
 *      Author: thomas
 */

#include "TMPackage.h"

float TMPackage::getAccX() const {
	return accX;
}

void TMPackage::setAccX(float accX) {
	this->accX = accX;
	validRaw = false;
}

float TMPackage::getAccY() const {
	return accY;
}

void TMPackage::setAccY(float accY) {
	this->accY = accY;
	validRaw = false;
}

float TMPackage::getAccZ() const {
	return accZ;
}

void TMPackage::setAccZ(float accZ) {
	this->accZ = accZ;
	validRaw = false;
}

bool TMPackage::isChrg() const {
	return chrg;
}

void TMPackage::setChrg(bool chrg) {
	this->chrg = chrg;
	validRaw = false;
}

bool TMPackage::isDep() const {
	return dep;
}

void TMPackage::setDep(bool dep) {
	this->dep = dep;
	validRaw = false;
}

CommandWord TMPackage::getEchoCmd() const {
	return echoCmd;
}

void TMPackage::setEchoCmd(CommandWord echoCmd) {
	this->echoCmd = echoCmd;
	validRaw = false;
}

uint16_t TMPackage::getEchoParam() const {
	return echoParam;
}

void TMPackage::setEchoParam(uint16_t echoParam) {
	this->echoParam = echoParam;
	validRaw = false;
}

float TMPackage::getErrorOmegaZ() const {
	return errorOmegaZ;
}

void TMPackage::setErrorOmegaZ(float errorOmegaZ) {
	this->errorOmegaZ = errorOmegaZ;
	validRaw = false;
}

float TMPackage::getErrorYaw() const {
	return errorYaw;
}

void TMPackage::setErrorYaw(float errorYaw) {
	this->errorYaw = errorYaw;
	validRaw = false;
}

SoftwareMode TMPackage::getMode() const {
	return mode;
}

void TMPackage::setMode(SoftwareMode mode) {
	this->mode = mode;
	validRaw = false;
}

float TMPackage::getMotor() const {
	return motor;
}

void TMPackage::setMotor(float motor) {
	this->motor = motor;
	validRaw = false;
}

float TMPackage::getOmegaX() const {
	return omegaX;
}

void TMPackage::setOmegaX(float omegaX) {
	this->omegaX = omegaX;
	validRaw = false;
}

float TMPackage::getOmegaY() const {
	return omegaY;
}

void TMPackage::setOmegaY(float omegaY) {
	this->omegaY = omegaY;
	validRaw = false;
}

float TMPackage::getOmegaZ() const {
	return omegaZ;
}

void TMPackage::setOmegaZ(float omegaZ) {
	this->omegaZ = omegaZ;
	validRaw = false;
}

float TMPackage::getPitch() const {
	return pitch;
}

void TMPackage::setPitch(float pitch) {
	this->pitch = pitch;
	validRaw = false;
}

float TMPackage::getQuat1() const {
	return quat1;
}

void TMPackage::setQuat1(float quat1) {
	this->quat1 = quat1;
	validRaw = false;
}

float TMPackage::getQuat2() const {
	return quat2;
}

void TMPackage::setQuat2(float quat2) {
	this->quat2 = quat2;
	validRaw = false;
}

float TMPackage::getQuat3() const {
	return quat3;
}

void TMPackage::setQuat3(float quat3) {
	this->quat3 = quat3;
	validRaw = false;
}

float TMPackage::getQuat4() const {
	return quat4;
}

void TMPackage::setQuat4(float quat4) {
	this->quat4 = quat4;
	validRaw = false;
}

float TMPackage::getRoll() const {
	return roll;
}

void TMPackage::setRoll(float roll) {
	this->roll = roll;
	validRaw = false;
}

float TMPackage::getTempFire1() const {
	return tempFire1;
}

void TMPackage::setTempFire1(float tempFire1) {
	this->tempFire1 = tempFire1;
	validRaw = false;
}

float TMPackage::getTempFire2() const {
	return tempFire2;
}

void TMPackage::setTempFire2(float tempFire2) {
	this->tempFire2 = tempFire2;
	validRaw = false;
}

float TMPackage::getTempFire3() const {
	return tempFire3;
}

void TMPackage::setTempFire3(float tempFire3) {
	this->tempFire3 = tempFire3;
	validRaw = false;
}

float TMPackage::getTempFire4() const {
	return tempFire4;
}

void TMPackage::setTempFire4(float tempFire4) {
	this->tempFire4 = tempFire4;
	validRaw = false;
}

float TMPackage::getTempFire5() const {
	return tempFire5;
}

void TMPackage::setTempFire5(float tempFire5) {
	this->tempFire5 = tempFire5;
	validRaw = false;
}

float TMPackage::getThetaFire1() const {
	return thetaFire1;
}

void TMPackage::setThetaFire1(float thetaFire1) {
	this->thetaFire1 = thetaFire1;
	validRaw = false;
}

float TMPackage::getThetaFire2() const {
	return thetaFire2;
}

void TMPackage::setThetaFire2(float thetaFire2) {
	this->thetaFire2 = thetaFire2;
	validRaw = false;
}

float TMPackage::getThetaFire3() const {
	return thetaFire3;
}

void TMPackage::setThetaFire3(float thetaFire3) {
	this->thetaFire3 = thetaFire3;
	validRaw = false;
}

float TMPackage::getThetaFire4() const {
	return thetaFire4;
}

void TMPackage::setThetaFire4(float thetaFire4) {
	this->thetaFire4 = thetaFire4;
	validRaw = false;
}

float TMPackage::getThetaFire5() const {
	return thetaFire5;
}

void TMPackage::setThetaFire5(float thetaFire5) {
	this->thetaFire5 = thetaFire5;
	validRaw = false;
}

float TMPackage::getThetaSun() const {
	return thetaSun;
}

void TMPackage::setThetaSun(float thetaSun) {
	this->thetaSun = thetaSun;
	validRaw = false;
}

uint16_t TMPackage::getTime() const {
	return time;
}

void TMPackage::setTime(uint16_t time) {
	this->time = time;
	validRaw = false;
}

float TMPackage::getTimeFire1() const {
	return timeFire1;
}

void TMPackage::setTimeFire1(float timeFire1) {
	this->timeFire1 = timeFire1;
	validRaw = false;
}

uint16_t TMPackage::getTimeFire2() const {
	return timeFire2;
}

void TMPackage::setTimeFire2(uint16_t timeFire2) {
	this->timeFire2 = timeFire2;
	validRaw = false;
}

uint16_t TMPackage::getTimeFire3() const {
	return timeFire3;
}

void TMPackage::setTimeFire3(uint16_t timeFire3) {
	this->timeFire3 = timeFire3;
	validRaw = false;
}

uint16_t TMPackage::getTimeFire4() const {
	return timeFire4;
}

void TMPackage::setTimeFire4(uint16_t timeFire4) {
	this->timeFire4 = timeFire4;
	validRaw = false;
}

uint16_t TMPackage::getTimeFire5() const {
	return timeFire5;
}

void TMPackage::setTimeFire5(uint16_t timeFire5) {
	this->timeFire5 = timeFire5;
	validRaw = false;
}

float TMPackage::getBat1() const {
	return vBat1;
}

void TMPackage::setBat1(float bat1) {
	vBat1 = bat1;
	validRaw = false;
}

float TMPackage::getBat2() const {
	return vBat2;
}

void TMPackage::setBat2(float bat2) {
	vBat2 = bat2;
	validRaw = false;
}

float TMPackage::getBat3() const {
	return vBat3;
}

void TMPackage::setBat3(float bat3) {
	vBat3 = bat3;
	validRaw = false;
}

float TMPackage::getSolar1() const {
	return vSolar1;
}

void TMPackage::setSolar1(float solar1) {
	vSolar1 = solar1;
	validRaw = false;
}

float TMPackage::getSolar2() const {
	return vSolar2;
}

void TMPackage::setSolar2(float solar2) {
	vSolar2 = solar2;
	validRaw = false;
}

float TMPackage::getYaw() const {
	return yaw;
}

void TMPackage::setYaw(float yaw) {
	this->yaw = yaw;
	validRaw = false;
}

void TMPackage::encodeMode(SoftwareMode mode) {
	rawData[POSITION_MODE] = (uint8_t) mode;
}

SoftwareMode TMPackage::decodeMode(uint8_t* buffer) {
	return (SoftwareMode) buffer[POSITION_MODE];
}

void TMPackage::encodeEchoCmd(CommandWord cmd) {
	rawData[POSITION_ECHO_CMD] = (uint8_t) cmd;
}

CommandWord TMPackage::decodeEchoCmd(uint8_t* buffer) {
	return (CommandWord) buffer[POSITION_ECHO_CMD];
}

void TMPackage::encodeEchoParam(uint16_t param) {
	rawData[POSITION_ECHO_PARAM] = lowByte(param);
	rawData[POSITION_ECHO_PARAM + 1] = highByte(param);
}

uint16_t TMPackage::decodeEchoParam(uint8_t* buffer) {
	return joinBytes(buffer[POSITION_ECHO_PARAM + 1],
			buffer[POSITION_ECHO_PARAM]);
}

void TMPackage::encodeTime(uint16_t time) {
	rawData[POSITION_TIME] = lowByte(time);
	rawData[POSITION_TIME + 1] = highByte(time);

}

uint16_t TMPackage::decodeTime(uint8_t* buffer) {
	return joinBytes(buffer[POSITION_TIME + 1], buffer[POSITION_TIME]);
}

void TMPackage::encodeOmegaX(float value) {
	uint16_t tmp = float2uint16(value, ANG_VEL_RES, ANG_VEL_OFF);
	rawData[POSITION_OMEGA_X] = lowByte(tmp);
	rawData[POSITION_OMEGA_X + 1] = highByte(tmp);
}

float TMPackage::decodeOmegaX(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_OMEGA_X + 1],
			buffer[POSITION_OMEGA_X]);
	return uint162float(tmp, ANG_VEL_RES, ANG_VEL_OFF);
}

void TMPackage::encodeOmegaY(float value) {
	uint16_t tmp = float2uint16(value, ANG_VEL_RES, ANG_VEL_OFF);
	rawData[POSITION_OMEGA_Y] = lowByte(tmp);
	rawData[POSITION_OMEGA_Y + 1] = highByte(tmp);
}

float TMPackage::decodeOmegaY(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_OMEGA_Y + 1],
			buffer[POSITION_OMEGA_Y]);
	return uint162float(tmp, ANG_VEL_RES, ANG_VEL_OFF);
}

void TMPackage::encodeOmegaZ(float value) {
	uint16_t tmp = float2uint16(value, ANG_VEL_RES, ANG_VEL_OFF);
	rawData[POSITION_OMEGA_Z] = lowByte(tmp);
	rawData[POSITION_OMEGA_Z + 1] = highByte(tmp);
}

float TMPackage::decodeOmegaZ(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_OMEGA_Z + 1],
			buffer[POSITION_OMEGA_Z]);
	return uint162float(tmp, ANG_VEL_RES, ANG_VEL_OFF);
}

void TMPackage::encodeAccX(float value) {
	uint16_t tmp = float2uint16(value, ACC_RES, ACC_OFF);
	rawData[POSITION_ACC_X] = lowByte(tmp);
	rawData[POSITION_ACC_X + 1] = highByte(tmp);
}

float TMPackage::decodeAccX(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_ACC_X + 1],
			buffer[POSITION_ACC_X]);
	return uint162float(tmp, ACC_RES, ACC_OFF);
}

void TMPackage::encodeAccY(float value) {
	uint16_t tmp = float2uint16(value, ACC_RES, ACC_OFF);
	rawData[POSITION_ACC_Y] = lowByte(tmp);
	rawData[POSITION_ACC_Y + 1] = highByte(tmp);
}

float TMPackage::decodeAccY(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_ACC_Y + 1],
			buffer[POSITION_ACC_Y]);
	return uint162float(tmp, ACC_RES, ACC_OFF);
}

void TMPackage::encodeAccZ(float value) {
	uint16_t tmp = float2uint16(value, ACC_RES, ACC_OFF);
	rawData[POSITION_ACC_Z] = lowByte(tmp);
	rawData[POSITION_ACC_Z + 1] = highByte(tmp);
}

float TMPackage::decodeAccZ(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_ACC_Z + 1],
			buffer[POSITION_ACC_Z]);
	return uint162float(tmp, ACC_RES, ACC_OFF);
}

void TMPackage::encodeRoll(float value) {
	uint16_t tmp = float2uint16(value, ANGLE_RES, ANGLE_OFF);
	rawData[POSITION_ROLL] = lowByte(tmp);
	rawData[POSITION_ROLL + 1] = highByte(tmp);
}

float TMPackage::decodeRoll(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_ROLL + 1], buffer[POSITION_ROLL]);
	return uint162float(tmp, ANGLE_RES, ANGLE_OFF);
}

void TMPackage::encodePitch(float value) {
	uint16_t tmp = float2uint16(value, ANGLE_RES, ANGLE_OFF);
	rawData[POSITION_PITCH] = lowByte(tmp);
	rawData[POSITION_PITCH + 1] = highByte(tmp);
}

float TMPackage::decodePitch(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_PITCH + 1],
			buffer[POSITION_PITCH]);
	return uint162float(tmp, ANGLE_RES, ANGLE_OFF);
}

void TMPackage::encodeYaw(float value) {
	uint16_t tmp = float2uint16(value, ANGLE_RES, ANGLE_OFF);
	rawData[POSITION_YAW] = lowByte(tmp);
	rawData[POSITION_YAW + 1] = highByte(tmp);
}

float TMPackage::decodeYaw(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_YAW + 1], buffer[POSITION_YAW]);
	return uint162float(tmp, ANGLE_RES, ANGLE_OFF);
}

void TMPackage::encodeQuat1(float value) {
	uint16_t tmp = float2uint16(value, QUAT_RES, QUAT_OFF);
	rawData[POSITION_QUAT_1] = lowByte(tmp);
	rawData[POSITION_QUAT_1 + 1] = highByte(tmp);
}

float TMPackage::decodeQuat1(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_QUAT_1 + 1],
			buffer[POSITION_QUAT_1]);
	return uint162float(tmp, QUAT_RES, QUAT_OFF);
}

void TMPackage::encodeQuat2(float value) {
	uint16_t tmp = float2uint16(value, QUAT_RES, QUAT_OFF);
	rawData[POSITION_QUAT_2] = lowByte(tmp);
	rawData[POSITION_QUAT_2 + 1] = highByte(tmp);
}

float TMPackage::decodeQuat2(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_QUAT_2 + 1],
			buffer[POSITION_QUAT_2]);
	return uint162float(tmp, QUAT_RES, QUAT_OFF);
}

void TMPackage::encodeQuat3(float value) {
	uint16_t tmp = float2uint16(value, QUAT_RES, QUAT_OFF);
	rawData[POSITION_QUAT_3] = lowByte(tmp);
	rawData[POSITION_QUAT_3 + 1] = highByte(tmp);
}

float TMPackage::decodeQuat3(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_QUAT_3 + 1],
			buffer[POSITION_QUAT_3]);
	return uint162float(tmp, QUAT_RES, QUAT_OFF);
}

void TMPackage::encodeQuat4(float value) {
	uint16_t tmp = float2uint16(value, QUAT_RES, QUAT_OFF);
	rawData[POSITION_QUAT_4] = lowByte(tmp);
	rawData[POSITION_QUAT_4 + 1] = highByte(tmp);
}

float TMPackage::decodeQuat4(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_QUAT_4 + 1],
			buffer[POSITION_QUAT_4]);
	return uint162float(tmp, QUAT_RES, QUAT_OFF);
}

void TMPackage::encodeVBat1(float value) {
	uint16_t tmp = float2uint16(value, VOLT_RES, VOLT_OFF);
	rawData[POSITION_V_BAT_1] = lowByte(tmp);
	rawData[POSITION_V_BAT_1 + 1] = highByte(tmp);
}

float TMPackage::decodeVBat1(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_V_BAT_1 + 1],
			buffer[POSITION_V_BAT_1]);
	return uint162float(tmp, VOLT_RES, VOLT_OFF);
}

void TMPackage::encodeVBat2(float value) {
	uint16_t tmp = float2uint16(value, VOLT_RES, VOLT_OFF);
	rawData[POSITION_V_BAT_2] = lowByte(tmp);
	rawData[POSITION_V_BAT_2 + 1] = highByte(tmp);
}

float TMPackage::decodeVBat2(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_V_BAT_2 + 1],
			buffer[POSITION_V_BAT_2]);
	return uint162float(tmp, VOLT_RES, VOLT_OFF);
}

void TMPackage::encodeVBat3(float value) {
	uint16_t tmp = float2uint16(value, VOLT_RES, VOLT_OFF);
	rawData[POSITION_V_BAT_3] = lowByte(tmp);
	rawData[POSITION_V_BAT_3 + 1] = highByte(tmp);
}

float TMPackage::decodeVBat3(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_V_BAT_3 + 1],
			buffer[POSITION_V_BAT_3]);
	return uint162float(tmp, VOLT_RES, VOLT_OFF);
}

void TMPackage::encodeVSolar1(float value) {
	uint16_t tmp = float2uint16(value, VOLT_RES, VOLT_OFF);
	rawData[POSITION_V_SOLAR_1] = lowByte(tmp);
	rawData[POSITION_V_SOLAR_1 + 1] = highByte(tmp);
}

float TMPackage::decodeVSolar1(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_V_SOLAR_1 + 1],
			buffer[POSITION_V_SOLAR_1]);
	return uint162float(tmp, VOLT_RES, VOLT_OFF);
}

void TMPackage::encodeVSolar2(float value) {
	uint16_t tmp = float2uint16(value, VOLT_RES, VOLT_OFF);
	rawData[POSITION_V_SOLAR_2] = lowByte(tmp);
	rawData[POSITION_V_SOLAR_2 + 1] = highByte(tmp);
}

float TMPackage::decodeVSolar2(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_V_SOLAR_2 + 1],
			buffer[POSITION_V_SOLAR_2]);
	return uint162float(tmp, VOLT_RES, VOLT_OFF);
}

void TMPackage::encodeMotor(float value) {
	uint16_t tmp = float2uint16(value, MOTOR_RES, MOTOR_OFF);
	rawData[POSITION_MOTOR] = lowByte(tmp);
	rawData[POSITION_MOTOR + 1] = highByte(tmp);
}

float TMPackage::decodeMotor(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_MOTOR + 1],
			buffer[POSITION_MOTOR]);
	return uint162float(tmp, MOTOR_RES, MOTOR_OFF);
}

void TMPackage::encodeDep(bool value) {
	rawData[POSITION_DEP] = bool2uint8(value);
}

bool TMPackage::decodeDep(uint8_t* buffer) {
	return uint82bool(buffer[POSITION_DEP]);
}

void TMPackage::encodeChrg(bool value) {
	rawData[POSITION_CHRG] = bool2uint8(value);
}

bool TMPackage::decodeChrg(uint8_t* buffer) {
	return uint82bool(buffer[POSITION_CHRG]);
}

void TMPackage::encodeErrYaw(float value) {
	uint16_t tmp = float2uint16(value, ANGLE_RES, ANGLE_OFF);
	rawData[POSITION_ERR_YAW] = lowByte(tmp);
	rawData[POSITION_ERR_YAW + 1] = highByte(tmp);
}

float TMPackage::decodeErrYaw(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_ERR_YAW + 1],
			buffer[POSITION_ERR_YAW]);
	return uint162float(tmp, ANGLE_RES, ANGLE_OFF);
}

void TMPackage::encodeErrOmegaZ(float value) {
	uint16_t tmp = float2uint16(value, ANG_VEL_RES, ANG_VEL_OFF);
	rawData[POSITION_ERR_OMEGA_Z] = lowByte(tmp);
	rawData[POSITION_ERR_OMEGA_Z + 1] = highByte(tmp);
}

float TMPackage::decodeErrOmegaZ(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_ERR_OMEGA_Z + 1],
			buffer[POSITION_ERR_OMEGA_Z]);
	return uint162float(tmp, ANG_VEL_RES, ANG_VEL_OFF);
}

void TMPackage::encodeThetaFire1(float value) {
	uint16_t tmp = float2uint16(value, ANGLE_RES, ANGLE_OFF);
	rawData[POSITION_THETA_FIRE_1] = lowByte(tmp);
	rawData[POSITION_THETA_FIRE_1 + 1] = highByte(tmp);
}

float TMPackage::decodeThetaFire1(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_THETA_FIRE_1 + 1],
			buffer[POSITION_THETA_FIRE_1]);
	return uint162float(tmp, ANGLE_RES, ANGLE_OFF);
}

void TMPackage::encodeThetaFire2(float value) {
	uint16_t tmp = float2uint16(value, ANGLE_RES, ANGLE_OFF);
	rawData[POSITION_THETA_FIRE_2] = lowByte(tmp);
	rawData[POSITION_THETA_FIRE_2 + 1] = highByte(tmp);
}

float TMPackage::decodeThetaFire2(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_THETA_FIRE_2 + 1],
			buffer[POSITION_THETA_FIRE_2]);
	return uint162float(tmp, ANGLE_RES, ANGLE_OFF);
}

void TMPackage::encodeThetaFire3(float value) {
	uint16_t tmp = float2uint16(value, ANGLE_RES, ANGLE_OFF);
	rawData[POSITION_THETA_FIRE_3] = lowByte(tmp);
	rawData[POSITION_THETA_FIRE_3 + 1] = highByte(tmp);
}

float TMPackage::decodeThetaFire3(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_THETA_FIRE_3 + 1],
			buffer[POSITION_THETA_FIRE_3]);
	return uint162float(tmp, ANGLE_RES, ANGLE_OFF);
}

void TMPackage::encodeThetaFire4(float value) {
	uint16_t tmp = float2uint16(value, ANGLE_RES, ANGLE_OFF);
	rawData[POSITION_THETA_FIRE_4] = lowByte(tmp);
	rawData[POSITION_THETA_FIRE_4 + 1] = highByte(tmp);
}

float TMPackage::decodeThetaFire4(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_THETA_FIRE_4 + 1],
			buffer[POSITION_THETA_FIRE_4]);
	return uint162float(tmp, ANGLE_RES, ANGLE_OFF);
}

void TMPackage::encodeThetaFire5(float value) {
	uint16_t tmp = float2uint16(value, ANGLE_RES, ANGLE_OFF);
	rawData[POSITION_THETA_FIRE_5] = lowByte(tmp);
	rawData[POSITION_THETA_FIRE_5 + 1] = highByte(tmp);
}

float TMPackage::decodeThetaFire5(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_THETA_FIRE_5 + 1],
			buffer[POSITION_THETA_FIRE_5]);
	return uint162float(tmp, ANGLE_RES, ANGLE_OFF);
}

void TMPackage::encodeTimeFire1(uint16_t value) {
	rawData[POSITION_TIME_FIRE_1] = lowByte(value);
	rawData[POSITION_TIME_FIRE_1 + 1] = highByte(value);
}

uint16_t TMPackage::decodeTimeFire1(uint8_t* buffer) {
	return joinBytes(buffer[POSITION_TIME_FIRE_1 + 1],
			buffer[POSITION_TIME_FIRE_1]);
}

void TMPackage::encodeTimeFire2(uint16_t value) {
	rawData[POSITION_TIME_FIRE_2] = lowByte(value);
	rawData[POSITION_TIME_FIRE_2 + 1] = highByte(value);
}

uint16_t TMPackage::decodeTimeFire2(uint8_t* buffer) {
	return joinBytes(buffer[POSITION_TIME_FIRE_2 + 1],
			buffer[POSITION_TIME_FIRE_2]);
}

void TMPackage::encodeTimeFire3(uint16_t value) {
	rawData[POSITION_TIME_FIRE_3] = lowByte(value);
	rawData[POSITION_TIME_FIRE_3 + 1] = highByte(value);
}

uint16_t TMPackage::decodeTimeFire3(uint8_t* buffer) {
	return joinBytes(buffer[POSITION_TIME_FIRE_3 + 1],
			buffer[POSITION_TIME_FIRE_3]);
}

void TMPackage::encodeTimeFire4(uint16_t value) {
	rawData[POSITION_TIME_FIRE_4] = lowByte(value);
	rawData[POSITION_TIME_FIRE_4 + 1] = highByte(value);
}

uint16_t TMPackage::decodeTimeFire4(uint8_t* buffer) {
	return joinBytes(buffer[POSITION_TIME_FIRE_4 + 1],
			buffer[POSITION_TIME_FIRE_4]);
}

void TMPackage::encodeTimeFire5(uint16_t value) {
	rawData[POSITION_TIME_FIRE_5] = lowByte(value);
	rawData[POSITION_TIME_FIRE_5 + 1] = highByte(value);
}

uint16_t TMPackage::decodeTimeFire5(uint8_t* buffer) {
	return joinBytes(buffer[POSITION_TIME_FIRE_5 + 1],
			buffer[POSITION_TIME_FIRE_5]);
}

void TMPackage::encodeTempFire1(float value) {
	uint16_t tmp = float2uint16(value, TEMP_RES, TEMP_OFF);
	rawData[POSITION_TEMP_FIRE_1] = lowByte(tmp);
	rawData[POSITION_TEMP_FIRE_1 + 1] = highByte(tmp);
}

float TMPackage::decodeTempFire1(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_TEMP_FIRE_1 + 1],
			buffer[POSITION_TEMP_FIRE_1]);
	return uint162float(tmp, TEMP_RES, TEMP_OFF);
}

void TMPackage::encodeTempFire2(float value) {
	uint16_t tmp = float2uint16(value, TEMP_RES, TEMP_OFF);
	rawData[POSITION_TEMP_FIRE_2] = lowByte(tmp);
	rawData[POSITION_TEMP_FIRE_2 + 1] = highByte(tmp);
}

float TMPackage::decodeTempFire2(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_TEMP_FIRE_2 + 1],
			buffer[POSITION_TEMP_FIRE_2]);
	return uint162float(tmp, TEMP_RES, TEMP_OFF);

}

void TMPackage::encodeTempFire3(float value) {
	uint16_t tmp = float2uint16(value, TEMP_RES, TEMP_OFF);
	rawData[POSITION_TEMP_FIRE_3] = lowByte(tmp);
	rawData[POSITION_TEMP_FIRE_3 + 1] = highByte(tmp);
}

float TMPackage::decodeTempFire3(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_TEMP_FIRE_3 + 1],
			buffer[POSITION_TEMP_FIRE_3]);
	return uint162float(tmp, TEMP_RES, TEMP_OFF);
}

void TMPackage::encodeTempFire4(float value) {
	uint16_t tmp = float2uint16(value, TEMP_RES, TEMP_OFF);
	rawData[POSITION_TEMP_FIRE_4] = lowByte(tmp);
	rawData[POSITION_TEMP_FIRE_4 + 1] = highByte(tmp);

}

float TMPackage::decodeTempFire4(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_TEMP_FIRE_4 + 1],
			buffer[POSITION_TEMP_FIRE_4]);
	return uint162float(tmp, TEMP_RES, TEMP_OFF);
}

void TMPackage::encodeTempFire5(float value) {
	uint16_t tmp = float2uint16(value, TEMP_RES, TEMP_OFF);
	rawData[POSITION_TEMP_FIRE_5] = lowByte(tmp);
	rawData[POSITION_TEMP_FIRE_5 + 1] = highByte(tmp);
}

float TMPackage::decodeTempFire5(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_TEMP_FIRE_5 + 1],
			buffer[POSITION_TEMP_FIRE_5]);
	return uint162float(tmp, TEMP_RES, TEMP_OFF);
}

void TMPackage::encodeThetaSun(float value) {
	uint16_t tmp = float2uint16(value, ANGLE_RES, ANGLE_OFF);
	rawData[POSITION_THETA_SUN] = lowByte(tmp);
	rawData[POSITION_THETA_SUN + 1] = highByte(tmp);
}

float TMPackage::decodeThetaSun(uint8_t* buffer) {
	uint16_t tmp = joinBytes(buffer[POSITION_THETA_SUN + 1],
			buffer[POSITION_THETA_SUN]);
	return uint162float(tmp, ANGLE_RES, ANGLE_OFF);
}

TMPackage::TMPackage() :
		DataPackage(TM_PACKAGE_SIZE, TM_PACKAGE) {

	//all other fields initialized with 0
	stop = STOP_BYTE;
	build();
}

TMPackage::~TMPackage() {
}

TMPackage::TMPackage(uint8_t* buffer, unsigned int bufferSize) :
		DataPackage(TM_PACKAGE_SIZE, TM_PACKAGE) {

	//if invalid package is in buffer an empty one is created
	if (bufferSize != TM_PACKAGE_SIZE || buffer[POSITION_SYNC] != TM_PACKAGE
			|| buffer[POSITION_STOP] != STOP_BYTE) {
		//all fields stay initialized with 0

	} else {
		decodeMode(buffer);
		decodeEchoCmd(buffer);
		decodeEchoParam(buffer);
		decodeTime(buffer);
		decodeOmegaX(buffer);
		decodeOmegaY(buffer);
		decodeOmegaZ(buffer);
		decodeAccX(buffer);
		decodeAccY(buffer);
		decodeAccZ(buffer);
		decodeRoll(buffer);
		decodePitch(buffer);
		decodeYaw(buffer);
		decodeQuat1(buffer);
		decodeQuat2(buffer);
		decodeQuat3(buffer);
		decodeQuat4(buffer);
		decodeVBat1(buffer);
		decodeVBat2(buffer);
		decodeVBat3(buffer);
		decodeVSolar1(buffer);
		decodeVSolar2(buffer);
		decodeMotor(buffer);
		decodeDep(buffer);
		decodeChrg(buffer);
		decodeErrYaw(buffer);
		decodeErrOmegaZ(buffer);
		decodeThetaFire1(buffer);
		decodeThetaFire2(buffer);
		decodeThetaFire3(buffer);
		decodeThetaFire4(buffer);
		decodeThetaFire5(buffer);
		decodeTimeFire1(buffer);
		decodeTimeFire2(buffer);
		decodeTimeFire3(buffer);
		decodeTimeFire4(buffer);
		decodeTimeFire5(buffer);
		decodeTempFire1(buffer);
		decodeTempFire2(buffer);
		decodeTempFire3(buffer);
		decodeTempFire4(buffer);
		decodeTempFire5(buffer);
		decodeThetaSun(buffer);
	}

	stop = STOP_BYTE;
	build();
}

TMPackage::TMPackage(SoftwareMode mode, CommandWord echoCmd, float echoParam,
		uint16_t time, float omegaX, float omegaY, float omegaZ, float accX,
		float accY, float accZ, float roll, float pitch, float yaw, float quat1,
		float quat2, float quat3, float quat4, float vBat1, float vBat2,
		float vBat3, float vSolar1, float vSolar2, float motor, bool dep,
		bool chrg, float errorYaw, float errorOmegaZ, float thetaFire1,
		float thetaFire2, float thetaFire3, float thetaFire4, float thetaFire5,
		float timeFire1, float timeFire2, float timeFire3, float timeFire4,
		float timeFire5, float tempFire1, float tempFire2, float tempFire3,
		float tempFire4, float tempFire5, float thetaSun) : DataPackage(TM_PACKAGE_SIZE, TM_PACKAGE){

	this->mode = mode;	this->echoCmd = echoCmd;	this->echoParam = echoParam;	this->time = time;	this->omegaX = omegaX;	this->omegaY = omegaY;	this->omegaZ = omegaZ;	this->accX = accX;
	this->accY = accY;	this->accZ = accZ;	this->roll = roll;	this->pitch = pitch;	this->yaw = yaw;	this->quat1 = quat1;	this->quat2 = quat2;	this->quat3 = quat3;	this->quat4 = quat4;	this->vBat1 = vBat1;	this->vBat2 = vBat2;	this->vBat3 = vBat3;	this->vSolar1 = vSolar1;	this->vSolar2 = vSolar2;	this->motor = motor;	this->dep = dep;	this->chrg = chrg;
	this->errorYaw = errorYaw;
	this->errorOmegaZ = errorOmegaZ;
	this->thetaFire1 = thetaFire1;
	this->thetaFire2 = thetaFire2;
	this->thetaFire3 = thetaFire3;
	this->thetaFire4 = thetaFire4;
	this->thetaFire5 = thetaFire5;
	this->timeFire1 = timeFire1;
	this->timeFire2 = timeFire2;
	this->timeFire3 = timeFire3;
	this->timeFire4 = timeFire4;
	this->timeFire5 = timeFire5;
	this->tempFire1 = tempFire1;
	this->tempFire2 = tempFire2;
	this->tempFire3 = tempFire3;
	this->tempFire4 = tempFire4;
	this->tempFire5 = tempFire5;
	this->thetaSun = thetaSun;

	build();

}

void TMPackage::build() {

	validRaw = true;

	encodeMode(mode);
	encodeEchoCmd(echoCmd);
	encodeEchoParam(echoParam);
	encodeTime(time);
	encodeOmegaX(omegaX);
	encodeOmegaY(omegaY);
	encodeOmegaZ(omegaZ);
	encodeAccX(accX);
	encodeAccY(accY);
	encodeAccZ(accZ);
	encodeRoll(roll);
	encodePitch(pitch);
	encodeYaw(yaw);
	encodeQuat1(quat1);
	encodeQuat2(quat2);
	encodeQuat3(quat3);
	encodeQuat4(quat4);
	encodeVBat1(vBat1);
	encodeVBat2(vBat2);
	encodeVBat3(vBat3);
	encodeVSolar1(vSolar1);
	encodeVSolar2(vSolar2);
	encodeMotor(motor);
	encodeDep(dep);
	encodeChrg(chrg);
	encodeErrYaw(errorYaw);
	encodeErrOmegaZ(errorOmegaZ);
	encodeThetaFire1(thetaFire1);
	encodeThetaFire2(thetaFire2);
	encodeThetaFire3(thetaFire3);
	encodeThetaFire4(thetaFire4);
	encodeThetaFire5(thetaFire5);
	encodeTimeFire1(timeFire1);
	encodeTimeFire2(timeFire2);
	encodeTimeFire3(timeFire3);
	encodeTimeFire4(timeFire4);
	encodeTimeFire5(timeFire5);
	encodeTempFire1(tempFire1);
	encodeTempFire2(tempFire2);
	encodeTempFire3(tempFire3);
	encodeTempFire4(tempFire4);
	encodeTempFire5(tempFire5);
	encodeThetaSun(thetaSun);



}

