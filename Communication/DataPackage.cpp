/*
 * DataPackage.cpp
 *
 *  Created on: 04.12.2014
 *      Author: thomas
 */

#include "DataPackage.h"

DataPackage::DataPackage(unsigned int size, PackageType type) {
	byteSize = size;
	this->rawData = (uint8_t*) malloc(size*sizeof(uint8_t));
	sync = type;
	stop = 0;
	validRaw = false;
};



DataPackage::~DataPackage(){

};

PackageType DataPackage::getType(){
	return sync;
}

void DataPackage::encodeType(PackageType enumPackageType) {
	rawData[POSITION_SYNC] = (uint8_t) enumPackageType;
}

PackageType DataPackage::decodeType() {
	return (PackageType) rawData[POSITION_SYNC];
}

uint8_t* DataPackage::getRaw() {
	if (!validRaw) {
		build();
	}

	return rawData;
}


