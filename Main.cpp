/*
 * Main.cpp
 *
 *  Created on: 17.12.2014
 *      Author: thomas
 */

#include "rodos.h"
#include "hal_pwm.h"
#include "Communication/TCThread.h"
#include "Communication/TMThread.h"
#include "PWMThread.h"

//PWM
HAL_PWM myPWM(PWM_IDX12);
HAL_GPIO mySignA(GPIO_036);
HAL_GPIO mySignB(GPIO_017);
extern Topic<float> motorDuty(1234, "motorDuty");

PWMThread testPWM("testPWM", &myPWM, 5*SECONDS, &mySignA, &mySignB, &motorDuty);


//TC
Semaphore testSem;
SimpleRing<TCPackage> buffer(20, &testSem);
TCThread myTC(&buffer);


//TM
TMThread myTM;
