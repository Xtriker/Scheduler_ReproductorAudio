/*
 * app_ReadInput.h
 *
 *  Created on: Mar 27, 2020
 *      Author: dario
 */

#ifndef APP_READINPUT_H_
#define APP_READINPUT_H_

#define NUMBERS_BUTTON 		3
#include "../drivers/fsl_gpio.h"
#include "stdtypedef.h"
#include "app_Debounce.h"


extern unsigned char lub_ButtonState[NUMBERS_BUTTON];
extern void app_ReadInputValue(void);

#endif /* APP_READINPUT_H_ */
