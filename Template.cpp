/*!
 * \file    i2cExample.cpp
 *
 * \date    03. 06. 2013
 * \author  Michael Ruffer
 *
 * \brief   To run this example you must connect the pololu module "imu01a"
 *          to I2C bus 1 according to the hal_i2c.cpp of your target
 *          -> e.g. STM32F4 pin PD6 & PD9
 */

#include "rodos.h"
#include "hal/hal_i2c.h"
#include "Misc/Misc.h"
#include "Sensors/TMP007.h"
#include "Sensors/TSL2561.h"
#include "Template.h"

static Application APP_I2CTest("APP_I2CTest", 2000);

#define L3G4200D_TEST       0
#define LSM303_ACC_TEST     0
#define LSM303_MAG_TEST     0
#define TSL2561_TEST		1
#define TMP006_TEST 		0


#define LSM303DLH_ACC_ADDR  0x18
#define LSM303DLH_MAG_ADDR  0x1D
#define L3G4200D_GYR_ADDR   0x68
#define TSL2561_ADDR 0x39
#define TMP006_ADDR 0x40

/*************TSL2561**************/
#define TSL2561_COMMAND_BIT 0x80
#define TSL2561_CLEAR_BIT 0x40
#define TSL2561_WORD_BIT 0x20
#define TSL2561_BLOCK_BIT 0x10
#define TSL2561_CONTROL_POWERON 0x03
#define TSL2561_CONTROL_POWEROFF 0x00
#define TSL2561_REGISTER_CHAN1_LOW 0x0E
#define TSL2561_CONTROL_POWERON 0x03
#define TSL2561_REGISTER_CONTROL 0x00

/**************TMP006**************/
#define TMP006_CONFIG 0x02
#define TMP006_CFG_RESET 0x8000
#define TMP006_CFG_MODEON 0x7000
#define TMP006_CFG_1SAMPLE 0x0000
#define TMP006_CFG_2SAMPLE 0x0200
#define TMP006_CFG_4SAMPLE 0x0400
#define TMP006_CFG_8SAMPLE 0x0600
#define TMP006_CFG_16SAMPLE 0x0800
#define TMP006_CFG_DRDYEN 0x0100
#define TMP006_CFG_DRDY 0x0080
#define TMP006_MANID 0xFE
#define TMP006_DEVID 0xFF
#define TMP006_VOBJ 0x0
#define TMP006_TAMB 0x01

/*************TMP0007*************/

#define TMP007_VOBJ 0x00
#define TMP007_TDIE 0x01
#define TMP007_CONFIG 0x02
#define TMP007_TOBJ 0x03
#define TMP007_STATUS 0x04
#define TMP007_STATMASK 0x05
#define TMP007_CFG_RESET 0x8000
#define TMP007_CFG_MODEON 0x1000
#define TMP007_CFG_1SAMPLE 0x0000
#define TMP007_CFG_2SAMPLE 0x0200
#define TMP007_CFG_4SAMPLE 0x0400
#define TMP007_CFG_8SAMPLE 0x0600
#define TMP007_CFG_16SAMPLE 0x0800
#define TMP007_CFG_ALERTEN 0x0100
#define TMP007_CFG_ALERTF 0x0080
#define TMP007_CFG_TRANSC 0x0040
#define TMP007_STAT_ALERTEN 0x8000
#define TMP007_STAT_CRTEN 0x4000
#define TMP007_I2CADDR 0x40
#define TMP007_DEVID 0x1F

class I2CTest: public Thread {
public:
	I2CTest(const char* name) :
			Thread(name) {
	}

	void init() {
		uint8_t txBuf[3] = { 0 };
		uint16_t txBuf16[2] = { 0 };
		int32_t err[10] = { 0 };

		i2c1.init();

#if L3G4200D_TEST
		txBuf[0] = 0x20; // address of CTRL_REG1
		txBuf[1] = 0x0F;// value of CTRL_REG1 -> normal mode, x,y,z enable
		if (i2c1.write(L3G4200D_GYR_ADDR, txBuf, 2) < 0)
		i2c1.init();
		txBuf[0] = 0x23;// address of CTRL_REG4_A
		txBuf[1] = 0x40;// value of CTRL_REG4_A -> MSB first
		//txBuf[1] = 0x00; // value of CTRL_REG4_A -> LSB first
		if (i2c1.write(L3G4200D_GYR_ADDR, txBuf, 2) < 0)
		i2c1.init();
#endif
#if LSM303_ACC_TEST
		txBuf[0] = 0x20; // address of CTRL_REG1_A
		txBuf[1] = 0x27;// value of CTRL_REG1_A -> normal mode, x,y,z enable
		if (i2c1.write(LSM303DLH_ACC_ADDR,txBuf,2) < 0) i2c1.init();
		txBuf[0] = 0x23;// address of CTRL_REG4_A
		txBuf[1] = 0x40;// value of CTRL_REG4_A -> MSB first
		//txBuf[1] = 0x00; // value of CTRL_REG4_A -> LSB first
		if (i2c1.write(LSM303DLH_ACC_ADDR,txBuf,2) < 0) i2c1.init();
#endif
#if LSM303_MAG_TEST
		txBuf[0] = 0x02; // address of MR_REG
		txBuf[1] = 0x00;// value of MR_REG -> continuous mode
		if (i2c1.write(LSM303DLH_MAG_ADDR, txBuf, 2) < 0)
		i2c1.init();
#endif
#if TSL2561_TEST
		TSL2561 tsl2561;
		tsl2561.start();
#endif
#if TMP006_TEST
		TMP007 tmp7;
		tmp7.start();
#endif
	}

	void run() {
		uint8_t rxBuf[6] = { 0 };
		uint8_t txBuf[3] = { 0 };
		int32_t err[10] = { 0 };

		while (1) {
			/** check out L3G4200D (extern) **/
#if L3G4200D_TEST
			memset(rxBuf, 0, sizeof(rxBuf));
			memset(txBuf, 0, sizeof(txBuf));
			txBuf[0] = 0x28 | 0x80; // start reading with x-low register, read multiple register
			err[0] = i2c1.writeRead(L3G4200D_GYR_ADDR, txBuf, 1, rxBuf, 6);
			txBuf[0] = 0x0f;// WHO_AM_I Register
			err[1] = i2c1.writeRead(L3G4200D_GYR_ADDR, txBuf, 1, &rxBuf[6], 1);
			if (printError("L3G4200D GYRO", err, 2) > 0) {
				xprintf("Init I2C and all slaves ...\n\n");
				init(); // init i2c1/i2c2 and all slaves
			} else {
				PRINTF("L3G4200D \"Who am I\" reg (0xD3):0x%x\n", rxBuf[6]);
				//PRINTF("L3G4200D GYRO x,y,z: %d, %d, %d\n",rxBuf[0]|(rxBuf[1]<<8), rxBuf[2]|(rxBuf[3]<<8), rxBuf[4]|(rxBuf[5]<<8)); // LSB first
				xprintf("L3G4200D GYRO x,y,z: %d, %d, %d\n\n",
						rxBuf[1] | (rxBuf[0] << 8), rxBuf[3] | (rxBuf[2] << 8),
						rxBuf[5] | (rxBuf[4] << 8));// MSB first
			}

#endif

			/** check out LSM303 (extern) **/
#if LSM303_ACC_TEST
			// ACC
			memset(rxBuf,0,sizeof(rxBuf));
			memset(txBuf,0,sizeof(txBuf));
			txBuf[0] = 0x28 | 0x80;// start reading with x-low register, read multiple register
			err[0] = i2c1.writeRead(LSM303DLH_ACC_ADDR,txBuf,1,rxBuf,6);
			if (printError("LSM303 ACC", err, 1) > 0) {
				xprintf("Init I2C and all slaves ...\n\n");
				init(); // init i2c1/i2c2 and all slaves
			} else {
				//PRINTF("LSM303 ACC x,y,z: %d, %d, %d\n\n",rxBuf[0]|(rxBuf[1]<<8), rxBuf[2]|(rxBuf[3]<<8), rxBuf[4]|(rxBuf[5]<<8)); // LSB first
				xprintf("LSM303 ACC x,y,z: %d, %d, %d\n\n",rxBuf[1]|(rxBuf[0]<<8), rxBuf[3]|(rxBuf[2]<<8), rxBuf[5]|(rxBuf[4]<<8));// MSB first
			}
#endif

#if TSL2561_TEST
			// ILUM
//			memset(rxBuf, 0, sizeof(rxBuf));
//			memset(txBuf, 0, sizeof(txBuf));
//			txBuf[0] = TSL2561_COMMAND_BIT | TSL2561_REGISTER_CHAN1_LOW;
//			err[0] = i2c1.writeRead(TSL2561_ADDR, txBuf, 1, rxBuf, 2);
//			if (printError("TSL2561 ", err, 2) > 0) {
//				xprintf("Init I2C and all slaves ...\n\n");
//				init();
//			} else {
				TSL2561 tsl2561;
				uint16_t result = tsl2561.getRawIR();
				xprintf("TSL2561 Low: %d", result);
//			}
#endif

#if TMP006_TEST
			// IR
			memset(rxBuf, 0, sizeof(rxBuf));
			memset(txBuf, 0, sizeof(txBuf));
			uint16_t mod;
			double objT;
			double objDie;
			TMP007 tmp7;
			mod = tmp7.getModel();
			if(!mod){
				init();
			}
			xprintf("TMP Model: %x", mod);
			objT = tmp7.getObjTemp();
			if(!objT){
				init();
			}
			xprintf("TMP OBJ: %f", objT);
			objDie = tmp7.getDieTemp();
			if(!objDie){
				init();
			}
			xprintf("TMP DIE: %f", objDie);
#endif

			// MAG
#if LSM303_MAG_TEST
			memset(rxBuf, 0, sizeof(rxBuf));
			memset(txBuf, 0, sizeof(txBuf));
			txBuf[0] = 0x03; // start reading with x-high register, read multiple register
			err[0] = i2c1.writeRead(LSM303DLH_MAG_ADDR, txBuf, 1, rxBuf, 6);
			if (printError("LSM303 MAG", err, 1) > 0) {
				xprintf("Init I2C and all slaves ...\n\n");
				init(); // init i2c1/i2c2 and all slaves
			} else {
				xprintf("LSM303 MAG x,y,z: %d, %d, %d\n\n",
						rxBuf[1] | rxBuf[0] << 8, rxBuf[3] | rxBuf[2] << 8,
						rxBuf[5] | rxBuf[4] << 8); // MSB first
			}
#endif

			suspendCallerUntil(NOW()+1*SECONDS);
		}
	}

	int32_t printError(const char* dev, int32_t *err, uint32_t size) {
		uint32_t i=0;
		uint32_t errCnt = 0;

		for (i=0;i<size;i++) {
			if (err[i] < 0) {
				xprintf("%s I2C error:\n",dev);
				break;
			}
		}

		for (i=0;i<size;i++) {
			if (err[i] < 0) {
				errCnt++;
				xprintf(" %d. %d\n",(int)i+1,(int)err[i]);
			}
		}

		return errCnt;
	}
};

I2CTest i2cTest("I2CTest");
