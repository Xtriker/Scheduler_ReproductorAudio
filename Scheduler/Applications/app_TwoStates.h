/*
 * app_TwoStates.h
 *
 *  Created on: 17 abr. 2020
 *      Author: dario
 */

#ifndef APP_TWOSTATES_H_
#define APP_TWOSTATES_H_

#include "../drivers/fsl_gpio.h"
#include "stdtypedef.h"
#include "../Applications/app_RotabitCounter.h"
#include "../Applications/app_TrackIndicator.h"

#define TIME 		5u
#define MIN_TIME	20u
#define MAX_TIME	200u

extern void app_TwoStates(void);
extern void app_TwoStates_Task(void);
#endif /* APP_TWOSTATES_H_ */
