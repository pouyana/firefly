/*
 * PWMThread.cpp
 *
 *  Created on: 16.12.2014
 *      Author: thomas
 */

#include "PWMThread.h"


HAL_GPIO powerPin(GPIO_066);

PWMThread::PWMThread(const char* name, HAL_PWM* pwm, uint64_t sample,
		HAL_GPIO* signA, HAL_GPIO* signB, Topic<float>* topic) :
		Thread(name), SubscriberReceiver<float>(*topic, name) {

	this->pwm = pwm;
	this->sample = sample;
	this->signA = signA;
	this->signB = signB;

}

PWMThread::~PWMThread() {

}

void PWMThread::init() {
	pwm->init();
	powerPin.init(true, 1, 1);
	powerPin.setPins(1);
	signA->init(true, 1, 1);
	signB->init(true, 1, 0);

}

void PWMThread::run() {

	//TIME_LOOP(0,sample) {

	if (duty > 0) {
		signA->setPins(1);
		signB->setPins(0);
	} else {
		signA->setPins(0);
		signB->setPins(1);
	}

	pwm->write((int) std::abs(duty * increments));
	//pwm->write(0);
//		suspendCallerUntil(NOW() + 5*SECONDS);
//		pwm->write(50);
//		suspendCallerUntil(NOW() + 5*SECONDS);
//		pwm->write(0);

//Debug
	duty += 0.1;
	if (duty > 1.0) {
		duty = -1.0;
	}
	//powerPin.setPins(0);
}

void PWMThread::put(long & data) {
	this->duty = data;
	xprintf("Duty Put: %f", duty);
}
