/*
 * DataPackage.cpp
 *
 *  Created on: 04.12.2014
 *      Author: thomas
 */

#include "DataPackage.h"

DataPackage::DataPackage(unsigned int size) {
	byteSize = size;
	this->rawData[size] = 0;
	sync = 0;
	stop = 0;
};

DataPackage::~DataPackage(){

};

//DataPackage::parse(uint8_t* rawData, unsigned int rawDataSize) {
//
//	//TODO check type and size to call corresponding child classes parser
//	return 0;
//}


