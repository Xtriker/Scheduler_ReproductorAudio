/*
 * app_Debounce.h
 *
 *  Created on: 31 mar. 2020
 *      Author: Darío
 */

#ifndef APP_DEBOUNCE_H_
#define APP_DEBOUNCE_H_

#include "app_ReadInput.h"
#include "app_RotabitCounter.h"
#include "app_TrackIndicator.h"
#include "../drivers/fsl_gpio.h"
#include "../source/periodic_tasks_init.h"
#include <stdio.h>

extern unsigned char lub_ButtonState[NUMBERS_BUTTON];
extern T_UBYTE rub_PausePlay;
extern T_UBYTE rub_StopRotabit;
extern T_UBYTE lub_o[NUMBERS_BUTTON];
extern T_UBYTE lub_i;
extern T_UBYTE rub_LongPress;
extern void app_DebounceTask(void);
extern void app_DebounceValues(void);
extern void app_DebounceCondition(void);
extern void app_DebounceSelecction(void);
extern void app_DebounceStages_NormalPress(void);
extern void app_DebounceStages_LongPress(void);
extern void app_FowardRewind(void);

enum {
	NOTPRESS,
	PRESS,
	LONGPRESS
};

//S_Button_Options ButtonOptions= NOTPRESS;
/* | BACK	|	0	|
 * | NEXT	|	1	|
 * | PLAY	|	2	|
 */

enum{
	BACK,
	PAUSE,
	NEXT
};

enum{
	FOWARD,
	STOP,
	REWIND
};

#endif /* APP_DEBOUNCE_H_ */
