/*
 * PWMThread.h
 *
 *  Created on: 16.12.2014
 *      Author: thomas
 */

#ifndef PWMTHREAD_H_
#define PWMTHREAD_H_

#include <rodos.h>
#include <thread.h>
#include "hal/hal_pwm.h"
#include <cmath>

HAL_PWM myPWM(PWM_IDX12);
HAL_GPIO mySignA(GPIO_036);
HAL_GPIO mySignB(GPIO_017);

class PWMThread: public RODOS::Thread {
private:
	uint64_t sample = 0;;
	float duty = 0;
	HAL_PWM* pwm;
	HAL_GPIO* signA;
	HAL_GPIO* signB;
	uint16_t freq = 1000;
	uint16_t increments = 100;



public:
	PWMThread(const char* name, HAL_PWM* pwm, uint64_t sample, HAL_GPIO* signA, HAL_GPIO* signB);
	~PWMThread();

	void init();
	void run();

};

//PWMThread testPWM("testPWM", &myPWM, 5*SECONDS, &mySignA, &mySignB);

#endif /* PWMTHREAD_H_ */
