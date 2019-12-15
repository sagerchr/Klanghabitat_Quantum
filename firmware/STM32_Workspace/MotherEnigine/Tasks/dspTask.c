/*
 * dspTask.c
 *
 *  Created on: 07.11.2019
 *      Author: christiansager
 */

#include "main.h"
#include "RelaisControl.h"

TIM_HandleTypeDef htim6;

void dspTask(void const * argument){


	HAL_TIM_Base_Start(&htim6);

/******************Setting all Relais to default settings**************/
	Bypass(bypass);
	VCASource(RL);
	VCAOutput(NormalOutput, MS_Deconvert_Inactive);
/**********************************************************************/

	  //******Define Oversampling ADC7606*****************//
	  HAL_GPIO_WritePin(GPIOC, OS0_Pin,GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC, OS1_Pin,GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC, OS2_Pin,GPIO_PIN_RESET);
	  //**************************************************//

	  //**********Define Range ADC7606********************//
	  HAL_GPIO_WritePin(GPIOC, RANGE_Pin,GPIO_PIN_SET); // +/- 10V Range select
	  //**************************************************//

	  //**********Default State ControlPins***************//
	  HAL_GPIO_WritePin(GPIOC, CV_A_B_Pin,GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOD, CS_Pin,GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOD, RD_Pin,GPIO_PIN_SET);
	  //**************************************************//

	  //**************RESET the ADC7606*******************//
	  HAL_GPIO_WritePin(GPIOG, RESET_Pin,GPIO_PIN_SET);
	  microDelay(1);
	  HAL_GPIO_WritePin(GPIOG, RESET_Pin,GPIO_PIN_RESET);
	  //**************************************************//



	for(;;){



	    //*************Start Measurement********************//
	    HAL_GPIO_WritePin(GPIOC, CV_A_B_Pin,GPIO_PIN_RESET);
	    microDelay(1);
	    HAL_GPIO_WritePin(GPIOC, CV_A_B_Pin,GPIO_PIN_SET);

	    microDelay(5); //CONVERSION FINISHED!!!


	    HAL_GPIO_WritePin(GPIOF, DEBUG1_Pin, GPIO_PIN_SET);
	    for (int i = 0; i<8; i++){

	    	HAL_GPIO_WritePin(GPIOD, RD_Pin,GPIO_PIN_SET);
	        HAL_GPIO_WritePin(GPIOD, CS_Pin,GPIO_PIN_SET);

	        HAL_GPIO_WritePin(GPIOD, RD_Pin,GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(GPIOD, CS_Pin,GPIO_PIN_RESET);
	        analogIN[i] = GPIOE->IDR;

	    }
	    HAL_GPIO_WritePin(GPIOF, DEBUG1_Pin, GPIO_PIN_RESET);

	    HAL_GPIO_WritePin(GPIOD, CS_Pin,GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOD, RD_Pin,GPIO_PIN_SET);

		HAL_GPIO_TogglePin(GPIOD, DEBUG2_Pin);
		microDelay(1);
	}

}






void microDelay (int time){
	  while (__HAL_TIM_GET_COUNTER(&htim6) < time){

	  }
	  __HAL_TIM_SET_COUNTER(&htim6 , 0);
}
