/*
 * LSM9DS0G.cpp
 *
 *  Created on: 05.12.2014
 *      Author: CanSat-I8L-PC05-G03
 */
#include "LSM9DS0G.h"

void LSM9DS0G::init(void) {
	if (!isOn & gpioGyro.read() == 0) {
		gpioGyro.init(true, 1, 1);
	}
	isOn = true;
	/* CTRL_REG1_G sets output data rate, bandwidth, power-down and enables
	 Bits[7:0]: DR1 DR0 BW1 BW0 PD Zen Xen Yen
	 DR[1:0] - Output data rate selection
	 00=95Hz, 01=190Hz, 10=380Hz, 11=760Hz
	 BW[1:0] - Bandwidth selection (sets cutoff frequency)
	 Value depends on ODR. See datasheet table 21.
	 PD - Power down enable (0=power down mode, 1=normal or sleep mode)
	 Zen, Xen, Yen - Axis enable (o=disabled, 1=enabled) */
	txBuf[0] = CTRL_REG1_G;
	txBuf[1] = 0x0F;
	if (i2c2.write(LSM9DS0G_ADDR, txBuf, 2) < 0)
		i2c2.init();
	/* CTRL_REG2_G sets up the HPF
	 Bits[7:0]: 0 0 HPM1 HPM0 HPCF3 HPCF2 HPCF1 HPCF0
	 HPM[1:0] - High pass filter mode selection
	 00=normal (reset reading HP_RESET_FILTER, 01=ref signal for filtering,
	 10=normal, 11=autoreset on interrupt
	 HPCF[3:0] - High pass filter cutoff frequency
	 Value depends on data rate. See datasheet table 26.
	 */
	txBuf[0] = CTRL_REG2_G;
	txBuf[1] = 0x00;
	if (i2c2.write(LSM9DS0G_ADDR, txBuf, 2) < 0)
		i2c2.init();
	/* CTRL_REG3_G sets up interrupt and DRDY_G pins
	 Bits[7:0]: I1_IINT1 I1_BOOT H_LACTIVE PP_OD I2_DRDY I2_WTM I2_ORUN I2_EMPTY
	 I1_INT1 - Interrupt enable on INT_G pin (0=disable, 1=enable)
	 I1_BOOT - Boot status available on INT_G (0=disable, 1=enable)
	 H_LACTIVE - Interrupt active configuration on INT_G (0:high, 1:low)
	 PP_OD - Push-pull/open-drain (0=push-pull, 1=open-drain)
	 I2_DRDY - Data ready on DRDY_G (0=disable, 1=enable)
	 I2_WTM - FIFO watermark interrupt on DRDY_G (0=disable 1=enable)
	 I2_ORUN - FIFO overrun interrupt on DRDY_G (0=disable 1=enable)
	 I2_EMPTY - FIFO empty interrupt on DRDY_G (0=disable 1=enable)
	 Int1 enabled (pp, active low), data read on DRDY_G:*/
	txBuf[0] = CTRL_REG3_G;
	txBuf[1] = 0x88;
	if (i2c2.write(LSM9DS0G_ADDR, txBuf, 2) < 0)
		i2c2.init();

	/* CTRL_REG4_G sets the scale, update mode
	 Bits[7:0] - BDU BLE FS1 FS0 - ST1 ST0 SIM
	 BDU - Block data update (0=continuous, 1=output not updated until read
	 BLE - Big/little endian (0=data LSB @ lower address, 1=LSB @ higher add)
	 FS[1:0] - Full-scale selection
	 00=245dps, 01=500dps, 10=2000dps, 11=2000dps
	 ST[1:0] - Self-test enable
	 00=disabled, 01=st 0 (x+, y-, z-), 10=undefined, 11=st 1 (x-, y+, z+)
	 SIM - SPI serial interface mode select
	 0=4 wire, 1=3 wire */
	txBuf[0] = CTRL_REG4_G;
	txBuf[1] = 0x00;
	if (i2c2.write(LSM9DS0G_ADDR, txBuf, 2) < 0)
		i2c2.init();
	/* CTRL_REG5_G sets up the FIFO, HPF, and INT1
	 Bits[7:0] - BOOT FIFO_EN - HPen INT1_Sel1 INT1_Sel0 Out_Sel1 Out_Sel0
	 BOOT - Reboot memory content (0=normal, 1=reboot)
	 FIFO_EN - FIFO enable (0=disable, 1=enable)
	 HPen - HPF enable (0=disable, 1=enable)
	 INT1_Sel[1:0] - Int 1 selection configuration
	 Out_Sel[1:0] - Out selection configuration */
	txBuf[0] = CTRL_REG5_G;
	txBuf[1] = 0x00;
	if (i2c2.write(LSM9DS0G_ADDR, txBuf, 2) < 0)
		i2c2.init();
	calcgRes(G_SCALE_2000DPS);

}
void LSM9DS0G::stop(void) {
	if (isOn & gpioGyro.read() == 1) {
		gpioGyro.init(false, 1, 1);
	}
	isOn = false;
}
uint8_t LSM9DS0G::getModel(void) {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = 0x0f; // WHO_AM_I Register
	err[0] = i2c2.writeRead(LSM9DS0G_ADDR, txBuf, 1, rxBuf, 1);
	if (misc.printError("TSL2561 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		return false;
	}
	return rxBuf[0];
}

/**
 * read the bias of the gyro set on the board.
 */
uint8_t LSM9DS0G::readBias(void) {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = CTRL_REG5_G;
	err[0] = i2c2.writeRead(LSM9DS0G_ADDR, txBuf, 1, rxBuf, 1);
	if (misc.printError("TSL2561 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		return false;
	}
	return rxBuf[0];
}

void LSM9DS0G::enableFifo(void) {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = CTRL_REG5_G;
	txBuf[1] = readBias() | 0x40;
	err[0] = i2c2.write(LSM9DS0G_ADDR, txBuf, 2);
	if (misc.printError("TSL2561 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		memset(rxBuf, 0, sizeof(rxBuf));
	}
}

void LSM9DS0G::disableFifo(void) {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = CTRL_REG5_G;
	txBuf[1] = readBias() & ~0x40;
	err[0] = i2c2.write(LSM9DS0G_ADDR, txBuf, 2);
	if (misc.printError("TSL2561 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		memset(rxBuf, 0, sizeof(rxBuf));
	}
}

void LSM9DS0G::enableByPassMode(void) {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = FIFO_CTRL_REG_G;
	txBuf[1] = 0x00;
	err[0] = i2c2.write(LSM9DS0G_ADDR, txBuf, 2);
	if (misc.printError("TSL2561 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		memset(rxBuf, 0, sizeof(rxBuf));
	}
}

void LSM9DS0G::enableStreamMode(void) {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = FIFO_CTRL_REG_G;
	txBuf[1] = 0x20 | 0x1F;
	err[0] = i2c2.write(LSM9DS0G_ADDR, txBuf, 2);
	if (misc.printError("TSL2561 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		memset(rxBuf, 0, sizeof(rxBuf));
	}
}

void LSM9DS0G::calcgRes(gyro_scale gScale) {
// Possible gyro scales (and their register bit settings) are:
// 245 DPS (00), 500 DPS (01), 2000 DPS (10). Here's a bit of an algorithm
// to calculate DPS/(ADC tick) based on that 2-bit value:
	switch (gScale) {
	case G_SCALE_245DPS:
		gRes = 245.0 / 32768.0;
		break;
	case G_SCALE_500DPS:
		gRes = 500.0 / 32768.0;
		break;
	case G_SCALE_2000DPS:
		gRes = 2000.0 / 32768.0;
		break;
	}
}

uint8_t LSM9DS0G::readNumberOfSamples(void) {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = FIFO_SRC_REG_G;
	err[0] = i2c2.writeRead(LSM9DS0G_ADDR, txBuf, 1, rxBuf, 1);
	if (misc.printError("TSL2561 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		return false;
	}
	return rxBuf[0] & 0x1F;
}

void LSM9DS0G::read(void) {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	txBuf[0] = OUT_X_L_G | 0x80;
	err[0] = i2c2.writeRead(LSM9DS0G_ADDR, txBuf, 1, rxBuf, 6);
	if (misc.printError("TSL2561 ", err, 1) > 0) {
		xprintf("Init I2C and all slaves ...\n\n");
		memset(rxBuf, 0, sizeof(rxBuf));
	}
	gx = (rxBuf[1] << 8) | rxBuf[0];
	gy = (rxBuf[3] << 8) | rxBuf[2];
	gz = (rxBuf[5] << 8) | rxBuf[4];
}
