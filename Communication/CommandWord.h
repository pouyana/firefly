/*
 * CommandWord.h
 *
 *  Created on: 15.12.2014
 *      Author: thomas
 */

#ifndef COMMUNICATION_COMMANDWORD_H_
#define COMMUNICATION_COMMANDWORD_H_


enum CommandWord {
	SWITCH_MODE = 0x0F,
	TAKE_PIC 	= 0x10,
	SET_THETA	= 0x11,
	SET_OMEGA	= 0x12,


	EMPTY		= 0x00
};




#endif /* COMMUNICATION_COMMANDWORD_H_ */
