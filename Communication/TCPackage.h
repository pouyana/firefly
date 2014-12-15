/*
 * TCPackage.h
 *
 *  Created on: 15.12.2014
 *      Author: thomas
 */

#ifndef COMMUNICATION_TCPACKAGE_H_
#define COMMUNICATION_TCPACKAGE_H_

#include "DataPackage.h"
#include "CommandWord.h"

class TCPackage : DataPackage {

private:
	//data fields (containing raw data)
	//sync inherited from DataPackage
	CommandWord cmd;
	uint16_t param;
	//stop inherited from DataPackage

	void encodeCmd(CommandWord cmd);
	CommandWord decodeCmd(uint8_t* buffer);

	void encodeParam(uint16_t param);
	uint16_t decodeParam(uint8_t* buffer);

	void encodeStop(uint8_t stop);

	//bytePositions
	static const unsigned int POSITION_CMD = 1;
	static const unsigned int POSITION_PARAM = 2;
	static const unsigned int POSITION_STOP = 4; //must be equal size-1


public:
	/*
	 * creates an empty but well formatted TCPackage
	 */
	TCPackage();

	~TCPackage();

	/*
	 * creates TC package from raw data
	 */
	TCPackage(uint8_t* buffer, unsigned int bufferSize);

	/*
	 * creates TC package from values
	 */
	TCPackage(CommandWord cmd, uint16_t param);

	void build();

	CommandWord getCmd() const;
	void setCmd(CommandWord cmd);
	uint16_t getParam() const;
	void setParam(uint16_t param);
};


#endif /* COMMUNICATION_TCPACKAGE_H_ */
