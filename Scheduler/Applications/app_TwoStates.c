/*
 * app_TwoStates.c
 *
 *  Created on: 17 abr. 2020
 *      Author: dario
 */
void app_TwoStates_Task(void);

#include "app_TwoStates.h"
T_UBYTE rub_pressLenght_milliSeconds = 0u;
char x = 0u;
void app_TwoStates(void)
{
	while(GPIO_ReadPinInput(GPIOD, 0) == FALSE)
	{
		rub_pressLenght_milliSeconds = rub_pressLenght_milliSeconds + 200;
		printf("ms = %d\n",rub_pressLenght_milliSeconds);
	}
}

void app_TwoStates_Task(void)
{
	if((rub_pressLenght_milliSeconds > 4) && (rub_pressLenght_milliSeconds < 200))
		{
			TrackGPORT->PDOR=x;
			x++;
		}
		else if(rub_pressLenght_milliSeconds >= 200)
		{
			TrackGPORT->PDOR=0u;
		}
		rub_pressLenght_milliSeconds = 0u;
}
