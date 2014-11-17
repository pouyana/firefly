#include "rodos.h"
#include <stdio.h>
#include "hal.h"
#include "math.h"

HAL_I2C i2c1(I2C_IDX1);

class I2CTest: public Thread {
public:
	I2CTest(const char* name) :
			Thread(name) {
	}


	void init() {
        uint8_t txBuf[2]={0};

		i2c1.init();
	}

	void run() {
		while(1) {
			xprintf("hallo World");
		}
	}

};

I2CTest myTest("pouyan");
