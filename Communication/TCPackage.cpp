/*
 * TCPackage.cpp
 *
 *  Created on: 15.12.2014
 *      Author: thomas
 */

#include "TCPackage.h"

void TCPackage::encodeCmd(CommandWord cmd) {
	rawData[POSITION_CMD] = (uint8_t) cmd;
}

CommandWord TCPackage::decodeCmd(uint8_t* buffer) {
	return (CommandWord) buffer[POSITION_CMD];
}

void TCPackage::encodeParam(uint16_t param) {

	rawData[POSITION_PARAM] 	= lowByte(param);
	rawData[POSITION_PARAM + 1] = highByte(param);

}

void TCPackage::encodeStop(uint8_t stop) {
	rawData[POSITION_STOP] = stop;
}

uint16_t TCPackage::decodeParam(uint8_t* buffer) {
	return joinBytes(buffer[POSITION_PARAM], buffer[POSITION_PARAM + 1]);
}

TCPackage::TCPackage() : DataPackage(TC_PACKAGE_SIZE, TC_PACKAGE){
	cmd = EMPTY;
	param = 0;
	stop = STOP_BYTE;
	validRaw = true;
}

TCPackage::~TCPackage() {
}

TCPackage::TCPackage(uint8_t* buffer, unsigned int bufferSize) : DataPackage(TC_PACKAGE_SIZE, TC_PACKAGE) {

	//if invalid package is in buffer an empty one is created
	if(bufferSize != TC_PACKAGE_SIZE || buffer[POSITION_SYNC] != TC_PACKAGE || buffer[POSITION_STOP] != STOP_BYTE ) {
		cmd = EMPTY;
		param = 0;

	} else {
		cmd = decodeCmd(buffer);
		param = decodeParam(buffer);
	}

	stop = STOP_BYTE;

	encodeType(TC_PACKAGE);
	encodeCmd(cmd);
	encodeParam(param);
	encodeStop(stop);
	validRaw = true;

}

CommandWord TCPackage::getCmd() const {
	return cmd;
}

void TCPackage::setCmd(CommandWord cmd) {
	this->cmd = cmd;
	validRaw = false;
}

uint16_t TCPackage::getParam() const {
	return param;
}

void TCPackage::setParam(uint16_t param) {
	this->param = param;
	validRaw = false;
}

TCPackage::TCPackage(CommandWord cmd, uint16_t param) : DataPackage(TC_PACKAGE_SIZE, TC_PACKAGE) {
	this->cmd = cmd;
	this->param = param;
	this->stop = STOP_BYTE;

	encodeType(TC_PACKAGE);
	encodeCmd(this->cmd);
	encodeParam(this->param);
	encodeStop(this->stop);
	validRaw = true;

}

void TCPackage::build() {
	encodeType(sync);
	encodeCmd(cmd);
	encodeParam(param);
	encodeStop(stop);
}

