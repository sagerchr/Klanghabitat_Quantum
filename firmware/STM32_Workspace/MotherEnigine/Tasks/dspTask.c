/*
 * dspTask.c
 *
 *  Created on: 07.11.2019
 *      Author: christiansager
 */

#include "main.h"
#include "RelaisControl.h"

TIM_HandleTypeDef htim5;
ADC_HandleTypeDef hadc1;
void dspTask(void const * argument){

	HAL_ADC_Start(&hadc1);
	HAL_TIM_Base_Start(&htim5);

/******************Setting all Relais to default settings**************/
	Bypass(bypass);
	VCASource(RL);
	VCAOutput(NormalOutput, MS_Deconvert_Inactive);
/**********************************************************************/

	for(;;){

		if(HAL_ADC_PollForConversion(&hadc1, 0) == HAL_OK){
			conv_ADC1 = HAL_ADC_GetValue(&hadc1);
		}

		HAL_GPIO_TogglePin(GPIOB, LD1_Pin);
		HAL_GPIO_TogglePin(GPIOG, Relais1_Pin);

		  while (__HAL_TIM_GET_COUNTER(&htim5) < 10){
		  }
		  __HAL_TIM_SET_COUNTER(&htim5 , 0);

	}

}