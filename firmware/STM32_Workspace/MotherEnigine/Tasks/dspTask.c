/*
 * dspTask.c
 *
 *  Created on: 07.11.2019
 *      Author: christiansager
 */

#include "main.h"
#include "RelaisControl.h"
#include "DAC_Control.h"
#include "tm_stm32f4_fft.h"


TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim7;
DAC_HandleTypeDef hdac;
SPI_HandleTypeDef hspi2;

//uint8_t DSProundtrip = 10; //Defines the RoundTrip time of the DSP
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

		HAL_TIM_Base_Start(&htim6);
		HAL_TIM_Base_Start_IT(&htim7);


		TM_FFT_F32_t FFT;    /*!< FFT structure */
		uint16_t i;
		uint16_t max;
		float32_t Output[FFT_SIZE];

		TM_FFT_Init_F32(&FFT, FFT_SIZE, 0);
		TM_FFT_SetBuffers_F32(&FFT, voltRingIn1,Output);

	for(;;){


		TM_FFT_Process_F32(&FFT);

		HAL_Delay(10);

		HAL_GPIO_TogglePin(GPIOB, LD1_Pin); //grüne LED an
		for(int i = 0; i<100; i++){
			FFT_result[i] = Output[i];
		}

	}

}







