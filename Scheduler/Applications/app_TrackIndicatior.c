/*
 * app_TrackIndicatior.c
 *
 *  Created on: 28 mar. 2020
 *      Author: dario
 */

#include "app_TrackIndicator.h"
#include "app_ReadInput.h"

T_UBYTE lub_ActualTrack = 0u;

extern T_UBYTE lub_ButtonState[NUMBERS_BUTTON];

	void app_NEXT(void) {
		app_TrackIndicatorOutput(lub_ActualTrack);
		if (lub_ActualTrack > 3) {
			lub_ActualTrack = 0;
			app_TrackIndicatorOutput(lub_ActualTrack);
		}
		else {
			lub_ActualTrack = lub_ActualTrack + 1;
			app_TrackIndicatorOutput(lub_ActualTrack);
		}

	}

	void app_BACK(void) {
		app_TrackIndicatorOutput(lub_ActualTrack);
				if (lub_ActualTrack < 0) {
					lub_ActualTrack =3;
					app_TrackIndicatorOutput(lub_ActualTrack);
				}
				else {
					lub_ActualTrack = lub_ActualTrack - 1;
					app_TrackIndicatorOutput(lub_ActualTrack);
				}

	}

void app_TrackIndicatorOutput(T_UBYTE OutputVAlue)
{
	TrackGPORT->PDOR=OutputVAlue;

}
