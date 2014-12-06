/*
 * LSM9DS0GT.cpp
 *
 *  Created on: 05.12.2014
 *      Author: CanSat-I8L-PC05-G03
 */

#include "LSM9DS0GT.h"

Topic<GyroPosition> gyroPositionTopic(-1, "position");

LSM9DS0GT::LSM9DS0GT(const char* name) :
		Thread(name) {
}

void LSM9DS0GT::init() {
	lsm9ds0.init();
	gyro.init();

}
void LSM9DS0GT::run() {
	memset(rxBuf, 0, sizeof(rxBuf));
	memset(txBuf, 0, sizeof(txBuf));
	memset(gyroBias, 0, sizeof(gyroBias));
	uint8_t data[6] = { 0, 0, 0, 0, 0, 0 };
	int16_t gyro_bias[3] = { 0, 0, 0 };
	int samples, ii;
	uint8_t c = gyro.readBias();
	gyro.enableFifo();
	suspendCallerUntil(NOW()+20*MILLISECONDS);
	gyro.enableStreamMode();
	suspendCallerUntil(NOW()+1000*MILLISECONDS);
	samples = gyro.readNumberOfSamples();

	for (ii = 0; ii < samples; ii++) { // Read the gyro data stored in the FIFO
		gyro.read();
		gyro_bias[0] += gyro.gx;
		gyro_bias[1] += gyro.gy;
		gyro_bias[2] += gyro.gz;
	}

	gyro_bias[0] /= samples; // average the data
	gyro_bias[1] /= samples;
	gyro_bias[2] /= samples;
	gyroBias[0] = (float) gyro_bias[0] * gyro.gRes; // Properly scale the data to get deg/s
	gyroBias[1] = (float) gyro_bias[1] * gyro.gRes;
	gyroBias[2] = (float) gyro_bias[2] * gyro.gRes;
	gyro.disableFifo();
	gyro.enableByPassMode();
	while (1) {
		uint8_t gyroModel = gyro.getModel();
//		if (gyroModel) {
//			xprintf("LSM9DS0G \"Who am I\" reg (0xD4):0x%x", gyroModel);
//		}

		gyro.read();
		gyroPos.x = gyro.gx * gyro.gRes - gyroBias[0];
		gyroPos.y = gyro.gy * gyro.gRes - gyroBias[1];
		gyroPos.z = gyro.gz * gyro.gRes - gyroBias[2];
//		xprintf("Gyro Bias gx:%d, gy:%d, gz:%d", gyroBias[0], gyroBias[1],
//				gyroBias[2]);
//		xprintf("LSM9DS0G  x,y,z: %d, %d, %d\n", gyro.gx, gyro.gy, gyro.gz); // LSB first
		gyroPositionTopic.publish(gyroPos);
		suspendCallerUntil(NOW()+1*SECONDS);
	}
}

