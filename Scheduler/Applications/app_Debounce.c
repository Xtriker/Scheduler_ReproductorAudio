/*
 * app_Debounce.c
 *
 *  Created on: 31 mar. 2020
 *      Author: Darío
 */
#include "app_Debounce.h"



/* Variables globales */
T_UBYTE rub_Timer = 0u;

/* Banderas */

T_UBYTE rub_LongPress = FALSE;
T_UBYTE rub_Button[NUMBERS_BUTTON] = {1,1,1};
T_UBYTE rub_ButtonsStates[NUMBERS_BUTTON];
T_UBYTE rub_States[3];
T_UBYTE lub_o[NUMBERS_BUTTON] = {0,0,0};
T_UBYTE rub_PausePlay = FALSE;
T_UBYTE lub_i = 0u;
T_UBYTE rub_StopRotabit = FALSE;

T_UBYTE lub_FlancoDebounce[NUMBERS_BUTTON] = {0,0,0};

void app_DebounceTask(void)
{
	app_DebounceValues();
	app_DebounceSelecction();
}

void app_DebounceValues(void)
{
	lub_i = 0u;
	/* Seleciona el estado de NOTPRESS, PRESS & LONGPRESS */
				/*	| NOTPRESS	| 0	| */
				/*	| PRESS 	| 1	| */
				/*	| LONGPRESS	| 2 | */
	while(lub_i < NUMBERS_BUTTON)
	{
		if(lub_ButtonState[lub_i] == 0u)
		{
			lub_o[lub_i] = lub_o[lub_i] + 1;
		}
		if((lub_o[lub_i] > 200))
		{

			if(lub_ButtonState[lub_i] == 1)
			{
				lub_FlancoDebounce[lub_i] = TRUE;
				rub_States[lub_i] = LONGPRESS;
				lub_i = lub_i + 1;
				rub_LongPress = TRUE;
			}
			else
			{
				lub_i = lub_i + 1;
				rub_LongPress = TRUE;
				rub_States[lub_i] = LONGPRESS;
			}

		}
		if((lub_o[lub_i] > 20) && (lub_o[lub_i] < 200))
		{
				lub_i = lub_i + 1;
				rub_LongPress = FALSE;
				rub_States[lub_i] = PRESS;
		}
		else
		{
			lub_i = lub_i + 1;
			/* Boton no presionado */
			rub_States[lub_i] = NOTPRESS;
		}
	}

}

void app_DebounceSelecction(void)
{
	lub_i = 0;
		while(lub_i < NUMBERS_BUTTON)
		{
				if(rub_States[lub_i] == LONGPRESS)
				{
					if(lub_FlancoDebounce[lub_i] == TRUE)
					{
						/* Seleciona el estado de STOP, FOWARD & REWIND */
						/*	| STOP		| 0	| */
						/*	| FOWARD 	| 1	| */
						/*	| REWIND	| 2 | */
						rub_ButtonsStates[lub_i] = lub_i;
						lub_FlancoDebounce[lub_i] = FALSE;
					}
				}
				if(rub_States[lub_i] == PRESS)
				{
					/* Seleciona el estado de NEXT & BACK */
					/*	| BACK	| 0	| */
					/*	| NEXT	| 1	| */
					rub_ButtonsStates[lub_i] = lub_i;
				}
				else if(rub_States[lub_i] == NOTPRESS)
				{
					/* No realiza ninguna función*/
				}
				lub_i = lub_i + 1;
		}
}

void app_DebounceStages(void)
{
	lub_i = 0;
	while(lub_i < 3)
	{
			if(rub_States[lub_i] == NOTPRESS)
			{

			}
			if(rub_States[lub_i] == PRESS)
			{
				switch (rub_ButtonsStates[lub_i])
				{
					case BACK: {
//						if((rub_PausePlay == TRUE) && (rub_LongPress == FALSE))
//						{
							lub_o[lub_i] = 0u;
							app_BACK();
							rub_States[lub_i] = NOTPRESS;
//						}
					}
						break;
					case NEXT: {
//						if((rub_PausePlay == TRUE) && (rub_LongPress == FALSE))
//						{
							lub_o[lub_i] = 0u;
							app_NEXT();
							rub_States[lub_i] = NOTPRESS;
//						}
					}
						break;
					case PAUSE:
					{
						lub_o[lub_i] = 0u;
						if (rub_StopRotabit == FALSE)
						{
							lub_o[1] = 0u;
							lub_o[0] = 0u;
							lub_o[2] = 0u;
							rub_PausePlay = TRUE;
							rub_States[lub_i] = NOTPRESS;
						}
						else if (rub_PausePlay == TRUE)
						{
							rub_PausePlay = FALSE;
							rub_StopRotabit = FALSE;
							lub_o[lub_i] = 0u;
							rub_States[lub_i] = NOTPRESS;
						}
					}
					break;
				}
			}
		if (rub_States[lub_i] == LONGPRESS)
		{
			switch (rub_ButtonsStates[lub_i])
			{
				case FOWARD: {
//				if ((rub_PausePlay == TRUE) && (rub_LongPress == FALSE))
//					{
						app_FOWARD();
						lub_o[lub_i] = 0u;
						rub_States[lub_i] = NOTPRESS;
//					}
				}
				break;
				case REWIND: {
//					if (rub_PausePlay == TRUE)
//					{
						app_REWIND();
						rub_LongPress = FALSE;
						lub_o[lub_i] = 0u;
						rub_States[lub_i] = NOTPRESS;
//					}
				}
				break;
				case STOP: {
					GPIOB->PDOR = 0u;
					app_TrackIndicatorOutput(0u);
					lub_o[1] = 0u;
					lub_o[0] = 0u;
					lub_o[2] = 0u;
					rub_PausePlay = FALSE;
					rub_States[lub_i] = NOTPRESS;
				}break;
				default:
				{
				GPIOB->PDOR = 0u;
				app_TrackIndicatorOutput(0u);
				lub_o[1] = 0u;
				lub_o[0] = 0u;
				lub_o[2] = 0u;
				rub_PausePlay = FALSE;
				rub_States[lub_i] = NOTPRESS;
				}
			}
		}
		lub_i = lub_i + 1;
	}
}

