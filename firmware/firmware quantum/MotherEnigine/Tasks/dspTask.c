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
#include "arm_math.h"
#include "arm_const_structs.h"

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

 		float32_t Output[256];
		float32_t IN[512];
		 arm_cfft_radix4_instance_f32 S;


	for(;;){


		for(int i=0; i<512; i+=2){
			IN[i]=voltRingIn1[i];
			IN[i+1]=0.0;
		}


		//https://stm32f4-discovery.net/2014/10/stm32f4-fft-example/
		arm_cfft_radix4_init_f32(&S, 256, 0, 1);
		arm_cfft_radix4_f32(&S, IN);
		arm_cmplx_mag_f32(IN, Output, 256);


		HAL_Delay(1);
		HAL_GPIO_TogglePin(GPIOB, LD1_Pin); //grüne LED an
		for(int i = 0; i<100; i++){
			FFT_result[i] = Output[i];
		}

	}

}







