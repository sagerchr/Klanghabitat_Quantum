/*
 * dspTask.c
 *
 *  Created on: 07.11.2019
 *      Author: christiansager
 */

#include "main.h"
#include "RelaisControl.h"

void dspTask(void const * argument){

/******************Setting all Relais to default settings**************/
	Bypass(bypass);
	VCASource(RL);
	VCAOutput(NormalOutput, MS_Deconvert_Inactive);
/**********************************************************************/


	for(;;){

		osDelay(1000);
		HAL_GPIO_TogglePin(GPIOB, LD1_Pin);

	}

}
