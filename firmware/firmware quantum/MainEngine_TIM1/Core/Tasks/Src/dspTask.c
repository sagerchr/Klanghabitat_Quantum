/*
 * dspTask.c
 *
 *  Created on: 07.11.2019
 *      Author: christiansager
 */

#include "main.h"
#include "RelaisControl.h"
#include "DAC_Control.h"
#include "stm32f7xx.h"
#include "UART_correction.h"
#include "ValueTableMotherEngine.h"
TIM_HandleTypeDef htim5;
TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim7;
DAC_HandleTypeDef hdac;
SPI_HandleTypeDef hspi2;

int errorcount;

void dspTask(void const * argument){



/******************Setting all Relais to default settings**************/
	BypassLeft(activate);
	BypassRight(activate);
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
	  HAL_Delay(10);
	  //**************RESET the ADC7606*******************//
	  HAL_GPIO_WritePin(GPIOG, RESET_Pin,GPIO_PIN_SET);
	  HAL_Delay(10);
	  HAL_GPIO_WritePin(GPIOG, RESET_Pin,GPIO_PIN_RESET);
	  HAL_Delay(10);

	  //**************************************************//
	  	HAL_TIM_Base_Start(&htim5);
		HAL_TIM_Base_Start(&htim6);
		HAL_TIM_Base_Start_IT(&htim7);

		int toggle = 0;

	for(;;){

			//vTaskSuspend(NULL);

			HAL_Delay(1000);
			HAL_GPIO_WritePin(GPIOD, DEBUG2_Pin,GPIO_PIN_SET);

			calculateDB();


			HAL_GPIO_TogglePin(GPIOB, LD2_Pin); //blaue LED an
			HAL_GPIO_WritePin(GPIOD, DEBUG2_Pin,GPIO_PIN_RESET);

	}

}







