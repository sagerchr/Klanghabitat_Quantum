/*
 * dspTask.c
 *
 *  Created on: 07.11.2019
 *      Author: christiansager
 */

#include "main.h"


void dspTask(void const * argument){
	for(;;){
		osDelay(1000);
		HAL_GPIO_TogglePin(GPIOB, LD1_Pin);
	}

}
