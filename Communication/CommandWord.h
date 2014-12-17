/*
 * CommandWord.h
 *
 *  Created on: 15.12.2014
 *      Author: thomas
 */

#ifndef COMMUNICATION_COMMANDWORD_H_
#define COMMUNICATION_COMMANDWORD_H_


enum CommandWord {

	EMPTY		= 0x00,
	SWITCH_MODE = 0x01,
	TAKE_PIC 	= 0x02,
	SET_THETA	= 0x03,
	SET_OMEGA	= 0x04,

	SET_MOTOR	= 0x05,
	DEPLOY		= 0x06



};




#endif /* COMMUNICATION_COMMANDWORD_H_ */
