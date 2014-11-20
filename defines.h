/*
 * defines.h
 *
 *  Created on: 19.11.2014
 *      Author: thomas
 */

#ifndef DEFINES_H_
#define DEFINES_H_

/****************************************************
 * SENSORS											*
 ***************************************************/

/* addresses of I2C slave devices */
#define LSM303DLH_ACC_ADDR  0x18
#define LSM303DLH_MAG_ADDR  0x1D
#define L3G4200D_GYR_ADDR   0x68
#define TSL2561_ADDR 		0x39 // default address, ADDR select pin floating

////////////////////////////////////////////////////////
//TSL2561 (Lumination & IR)
#define TSL2561_COMMAND_BIT       (0x80)    // Must be 1
#define TSL2561_WORD_BIT          (0x20)    // 1 = read/write word (rather than byte)

//Registers
enum {
TSL2561_REGISTER_ID			= 0x0A,
TSL2561_REGISTER_CHAN0_LOW  = 0x0C,
TSL2561_REGISTER_CHAN0_HIGH = 0x0D,
TSL2561_REGISTER_CHAN1_LOW  = 0x0E,
TSL2561_REGISTER_CHAN1_HIGH = 0x0F,

TSL2561_REGISTER_CONTROL	= 0x00,
TSL2561_ON 					= 0x03
};


#endif /* DEFINES_H_ */
