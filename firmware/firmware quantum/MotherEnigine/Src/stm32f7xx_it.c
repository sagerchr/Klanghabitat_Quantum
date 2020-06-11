/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f7xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f7xx_it.h"
#include "FreeRTOS.h"
#include "task.h"



#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "math.h"
#include "stdlib.h"
#include "UART_correction.h"
#include "../Tasks/Functions/dBu.h"
#include "ValueTableMotherEngine.h"
#include "stm32f7xx.h"
#include "arm_math.h"
#include "arm_const_structs.h"
#include "dspTask.h"
/* USER CODE END Includes */
  
/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

int16_t analogINSigned[8];
float volt;
float voltageRMStemp[8];
int RMS_index=0;

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

uint8_t DSProundtrip = 10; //Defines the RoundTrip time of the DSP
extern osThreadId dspTaskHandle;

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern ETH_HandleTypeDef heth;
extern DAC_HandleTypeDef hdac;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim10;
extern DMA_HandleTypeDef hdma_usart6_rx;
extern DMA_HandleTypeDef hdma_usart6_tx;
extern UART_HandleTypeDef huart6;
extern TIM_HandleTypeDef htim1;

/* USER CODE BEGIN EV */
SPI_HandleTypeDef hspi2;

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M7 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/******************************************************************************/
/* STM32F7xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f7xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM1 update interrupt and TIM10 global interrupt.
  */
void TIM1_UP_TIM10_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 0 */

  /* USER CODE END TIM1_UP_TIM10_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  HAL_TIM_IRQHandler(&htim10);
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 1 */

  /* USER CODE END TIM1_UP_TIM10_IRQn 1 */
}

/**
  * @brief This function handles TIM5 global interrupt.
  */
void TIM5_IRQHandler(void)
{
  /* USER CODE BEGIN TIM5_IRQn 0 */

  /* USER CODE END TIM5_IRQn 0 */
  HAL_TIM_IRQHandler(&htim5);
  /* USER CODE BEGIN TIM5_IRQn 1 */

  /* USER CODE END TIM5_IRQn 1 */
}

/**
  * @brief This function handles TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts.
  */
void TIM6_DAC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_DAC_IRQn 0 */

  /* USER CODE END TIM6_DAC_IRQn 0 */
  HAL_DAC_IRQHandler(&hdac);
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */

  /* USER CODE END TIM6_DAC_IRQn 1 */
}


/**
  * @brief This function handles TIM7 global interrupt.
  */
void TIM7_IRQHandler(void)
{
  /* USER CODE BEGIN TIM7_IRQn 0 */


  /* USER CODE END TIM7_IRQn 0 */
  HAL_TIM_IRQHandler(&htim7);
  /* USER CODE BEGIN TIM7_IRQn 1 */

	//__HAL_TIM_SET_COUNTER(&htim7 , 0);
  HAL_GPIO_WritePin(GPIOF, DEBUG1_Pin, GPIO_PIN_SET);

  //***********************Start Measurement*********************//
  HAL_GPIO_WritePin(GPIOC, CV_A_B_Pin,GPIO_PIN_RESET);
  microDelay(0);
  HAL_GPIO_WritePin(GPIOC, CV_A_B_Pin,GPIO_PIN_SET);
  //***************************ÜUpdate DACs**********************//



  //*******************GET NEW DATA FROM ADC*********************//
  //***Wait Time to be sure new data is ready to grab from ADC***//
  //microDelay(5);
  //If just 6 Channels are selected for READ then it is possible to read while Aquiering


  //*******************Get new samples from ADC******************//
	//*******************this takes around 5µSec*******************//
  for (int i = 0; i<6; i++){
  	HAL_GPIO_WritePin(GPIOD, RD_Pin,GPIO_PIN_SET);


      HAL_GPIO_WritePin(GPIOD, RD_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD, CS_Pin,GPIO_PIN_RESET);


      microDelay(0);
       //At least something... to get Ports updated

      analogIN[i] = GPIOE->IDR;

  }


  HAL_GPIO_WritePin(GPIOD, CS_Pin,GPIO_PIN_SET);

  HAL_GPIO_WritePin(GPIOF, DEBUG1_Pin, GPIO_PIN_RESET);






 //HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R,UART_reciveCorrected[7]+150); //Update ADC1
 //HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R,UART_reciveCorrected[9]+171); //Update ADC2 +171

  HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R,UART_IN[7]+150); //Update ADC1
  HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R,UART_IN[9]+171); //Update ADC2 +171


  //This will push to the dspTASK
    BaseType_t checkIfYieldRequired;
    checkIfYieldRequired = xTaskResumeFromISR(dspTaskHandle);
    portYIELD_FROM_ISR(checkIfYieldRequired);
  //

/////Get all 6 Channels from the ADC converted to voltage and put to voltageCHn Array///


  voltageCH1[indexing]=(int16_t)analogIN[0]*(10.0/32767);
  if (voltageCH1[indexing]<0){voltageCH1[indexing] = voltageCH1[indexing]*(-1.0);}
  sum_CH1 = sum_CH1 + (voltageCH1[indexing]*voltageCH1[indexing]);

  voltageCH2[indexing]=(int16_t)analogIN[1]*(10.0/32767);
  if (voltageCH2[indexing]<0){voltageCH2[indexing] = voltageCH2[indexing]*(-1.0);}
  sum_CH2 = sum_CH2 + (voltageCH2[indexing]*voltageCH2[indexing]);

  voltageCH3[indexing]=(int16_t)analogIN[2]*(10.0/32767);
  if (voltageCH3[indexing]<0){voltageCH3[indexing] = voltageCH3[indexing]*(-1.0);}
  sum_CH3 = sum_CH3 + (voltageCH3[indexing]*voltageCH3[indexing]);

  voltageCH4[indexing]=(int16_t)analogIN[3]*(10.0/32767);
  if (voltageCH4[indexing]<0){voltageCH4[indexing] = voltageCH4[indexing]*(-1.0);}
  sum_CH4 = sum_CH4 + (voltageCH4[indexing]*voltageCH4[indexing]);

  voltageCH5[indexing]=(int16_t)analogIN[4]*(10.0/32767);
  if (voltageCH5[indexing]<0){voltageCH5[indexing] = voltageCH5[indexing]*(-1.0);}
  sum_CH5 = sum_CH5 + (voltageCH5[indexing]*voltageCH5[indexing]);

  voltageCH6[indexing]=(int16_t)analogIN[5]*(10.0/32767);
  if (voltageCH6[indexing]<0){voltageCH6[indexing] = voltageCH6[indexing]*(-1.0);}
  sum_CH6 = sum_CH6 + (voltageCH6[indexing]*voltageCH6[indexing]);

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////



  	  switch (channel){
  case 1:

	  MaxCH1=0.0;

	  for (int i=0; i<6;i++){
//Exception on overflow when indexing is exact 0 for Channel1//////////////////////////


			  if(MaxCH1 < voltageCH1[indexing-5+i]){MaxCH1 = voltageCH1[indexing-5+i];}


	  }

	  tmp_decibelMaxCH1  = 20*log10(MaxCH1/1.095); //1.5 µsec!!!

	  if (voltageIn1MAX < MaxCH1){voltageIn1MAX=MaxCH1;}
	  if (voltageIn2MAX < MaxCH2){voltageIn2MAX=MaxCH2;}
	  if (voltageIn3MAX < MaxCH3){voltageIn3MAX=MaxCH3;}
	  if (voltageIn4MAX < MaxCH4){voltageIn4MAX=MaxCH4;}
	  if (voltageIn5MAX < MaxCH5){voltageIn5MAX=MaxCH5;}
	  if (voltageIn6MAX < MaxCH6){voltageIn6MAX=MaxCH6;}

	  if (dbuMAX[0]<tmp_decibelMaxCH1){dbuMAX[0]=tmp_decibelMaxCH1;}
	  if (dbuMAX[1]<tmp_decibelMaxCH2){dbuMAX[1]=tmp_decibelMaxCH2;}
	  if (dbuMAX[2]<tmp_decibelMaxCH3){dbuMAX[2]=tmp_decibelMaxCH3;}
	  if (dbuMAX[3]<tmp_decibelMaxCH4){dbuMAX[3]=tmp_decibelMaxCH4;}
	  if (dbuMAX[4]<tmp_decibelMaxCH5){dbuMAX[4]=tmp_decibelMaxCH5;}
	  if (dbuMAX[5]<tmp_decibelMaxCH6){dbuMAX[5]=tmp_decibelMaxCH6;}
	  channel=2;

	  break;
  case 2:
	  MaxCH2=0.0;
	  for (int i=0; i<6;i++){
//Exception on overflow when indexing is exact 0 for Channel2//////////////////////////
		if(indexing == 0){
				if(i<1){
					if(MaxCH2 < voltageCH2[i]){MaxCH1 = voltageCH2[i];}
				}else{
					if(MaxCH2 < voltageCH2[1200-i]){MaxCH2 = voltageCH2[1200-i];}
				}
			}
///////////////////////////////////////////////////////////////////////////////////////
			else {
				if(MaxCH2 < voltageCH2[indexing-6+i]){MaxCH2 = voltageCH2[indexing-6+i];}
			}
		}

	  tmp_decibelMaxCH2  = 20*log10(MaxCH2/1.095); //1.5 µsec!!!


	  channel=3;

	  break;
  case 3:
	  MaxCH3=0.0;
	  for (int i=0; i<6;i++){
//Exception on overflow when indexing is exact 1 for Channel3//////////////////////////
		if(indexing == 1){
				if(i<2){
					if(MaxCH3 < voltageCH3[i]){MaxCH3 = voltageCH3[i];}
				}else{
					if(MaxCH3 < voltageCH3[1201-i]){MaxCH3 = voltageCH3[1201-i];}
				}
			}
///////////////////////////////////////////////////////////////////////////////////////
			else {
				if(MaxCH3 < voltageCH3[indexing-6+i]){MaxCH3 = voltageCH3[indexing-6+i];}
			}
		}

	  tmp_decibelMaxCH3  = 20*log10(MaxCH3/1.095); //1.5 µsec!!!


	  channel=4;

	  break;
  case 4:
	  MaxCH4=0.0;
	  for (int i=0; i<6;i++){
//Exception on overflow when indexing is exact 2 for Channel4//////////////////////////
		if(indexing == 2){
				if(i<3){
					if(MaxCH4 < voltageCH4[i]){MaxCH4 = voltageCH4[i];}
				}else{
					if(MaxCH4 < voltageCH4[1202-i]){MaxCH4 = voltageCH4[1202-i];}
				}
			}
///////////////////////////////////////////////////////////////////////////////////////
			else {
				if(MaxCH4 < voltageCH4[indexing-6+i]){MaxCH4 = voltageCH4[indexing-6+i];}
			}
		}


	  tmp_decibelMaxCH4  = 20*log10(MaxCH4/1.095); //1.5 µsec!!!


	  channel=5;

	  break;
  case 5:
	  MaxCH5=0.0;
	  for (int i=0; i<6;i++){
//Exception on overflow when indexing is exact 3 for Channel5//////////////////////////
		if(indexing == 3){
				if(i<4){
					if(MaxCH5 < voltageCH5[i]){MaxCH5 = voltageCH5[i];}
				}else{
					if(MaxCH5 < voltageCH5[1203-i]){MaxCH5 = voltageCH5[1203-i];}
				}
			}
///////////////////////////////////////////////////////////////////////////////////////
			else {
				if(MaxCH5 < voltageCH5[indexing-6+i]){MaxCH5 = voltageCH5[indexing-6+i];}
			}
		}

	  tmp_decibelMaxCH5  = 20*log10(MaxCH5/1.095); //1.5 µsec!!!


	  channel=6;
	  break;
  case 6:
	  MaxCH6=0.0;
	  for (int i=0; i<6;i++){
//Exception on overflow when indexing is exact 4 for Channel6//////////////////////////
		if(indexing == 4){
				if(i<5){
					if(MaxCH6 < voltageCH6[i]){MaxCH6 = voltageCH6[i];}
				}else{
					if(MaxCH6 < voltageCH6[1204-i]){MaxCH6 = voltageCH6[1204-i];}
				}
			}
///////////////////////////////////////////////////////////////////////////////////////
			else {
				if(MaxCH6 < voltageCH6[indexing-6+i]){MaxCH6 = voltageCH6[indexing-6+i];}
			}
		}

	  tmp_decibelMaxCH6  = 20*log10(MaxCH6/1.095); //1.5 µsec!!!




	  channel=1;
	  break;
  }

  indexing++;
  if (indexing > 1199) {
	  indexing = 0;
	  RMS_CH1 = (20*log10((sqrt (sum_CH1/1200))/1.095))+3;
	  RMS_CH2 = (20*log10((sqrt (sum_CH2/1200))/1.095))+3;
	  RMS_CH3 = (20*log10((sqrt (sum_CH3/1200))/1.095))+3;
	  RMS_CH4 = (20*log10((sqrt (sum_CH4/1200))/1.095))+3;
	  RMS_CH5 = (20*log10((sqrt (sum_CH5/1200))/1.095))+3;
	  RMS_CH6 = (20*log10((sqrt (sum_CH6/1200))/1.095))+3;

	  sum_CH1_RMS_long[3]=RMS_CH1;
	  sum_CH2_RMS_long[3]=RMS_CH2;
	  sum_CH3_RMS_long[3]=RMS_CH3;
	  sum_CH4_RMS_long[3]=RMS_CH4;
	  sum_CH5_RMS_long[3]=RMS_CH5;
	  sum_CH6_RMS_long[3]=RMS_CH6;

	  for(int i=0;i<3;i++){
		  sum_CH1_RMS_long[i] = sum_CH1_RMS_long[i+1];
		  sum_CH1_RMS = sum_CH1_RMS + sum_CH1_RMS_long[i];

		  sum_CH2_RMS_long[i] = sum_CH2_RMS_long[i+1];
		  sum_CH2_RMS = sum_CH2_RMS + sum_CH2_RMS_long[i];

		  sum_CH3_RMS_long[i] = sum_CH3_RMS_long[i+1];
		  sum_CH3_RMS = sum_CH3_RMS + sum_CH3_RMS_long[i];

		  sum_CH4_RMS_long[i] = sum_CH4_RMS_long[i+1];
		  sum_CH4_RMS = sum_CH4_RMS + sum_CH4_RMS_long[i];

		  sum_CH5_RMS_long[i] = sum_CH5_RMS_long[i+1];
		  sum_CH5_RMS = sum_CH5_RMS + sum_CH5_RMS_long[i];

		  sum_CH6_RMS_long[i] = sum_CH6_RMS_long[i+1];
		  sum_CH6_RMS = sum_CH6_RMS + sum_CH6_RMS_long[i];

	  }
	  RMS_CH1_long=sum_CH1_RMS/3;
	  RMS_CH2_long=sum_CH2_RMS/3;
	  RMS_CH3_long=sum_CH3_RMS/3;
	  RMS_CH4_long=sum_CH4_RMS/3;
	  RMS_CH5_long=sum_CH5_RMS/3;
	  RMS_CH6_long=sum_CH6_RMS/3;

	  sum_CH1=0.0;
	  sum_CH2=0.0;
	  sum_CH3=0.0;
	  sum_CH4=0.0;
	  sum_CH5=0.0;
	  sum_CH6=0.0;

	  sum_CH1_RMS=0.0;
	  sum_CH2_RMS=0.0;
	  sum_CH3_RMS=0.0;
	  sum_CH4_RMS=0.0;
	  sum_CH5_RMS=0.0;
	  sum_CH6_RMS=0.0;



  }





  if (resetMax==1){
  	resetMax=0;
  	voltageIn1MAX=0;
  	voltageIn2MAX=0;
  	voltageIn3MAX=0;
  	voltageIn4MAX=0;
  	voltageIn5MAX=0;
  	voltageIn6MAX=0;
  	for (int i=0; i<8;i++){
  		dbuMAX[i] = -130.0;
  	}


}




  /* USER CODE END TIM7_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream1 global interrupt.
  */
void DMA2_Stream1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream1_IRQn 0 */

  /* USER CODE END DMA2_Stream1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart6_rx);
  /* USER CODE BEGIN DMA2_Stream1_IRQn 1 */

  /* USER CODE END DMA2_Stream1_IRQn 1 */
}

/**
  * @brief This function handles Ethernet global interrupt.
  */
void ETH_IRQHandler(void)
{
  /* USER CODE BEGIN ETH_IRQn 0 */

  /* USER CODE END ETH_IRQn 0 */
  HAL_ETH_IRQHandler(&heth);
  /* USER CODE BEGIN ETH_IRQn 1 */

  /* USER CODE END ETH_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream6 global interrupt.
  */
void DMA2_Stream6_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream6_IRQn 0 */

  /* USER CODE END DMA2_Stream6_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart6_tx);
  /* USER CODE BEGIN DMA2_Stream6_IRQn 1 */
  HAL_UART_GetError(&huart6);
  /* USER CODE END DMA2_Stream6_IRQn 1 */

}

/**
  * @brief This function handles USART6 global interrupt.
  */
void USART6_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */

  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart6);

}

/* USER CODE BEGIN 1 */
void microDelay (int time){

	 while (__HAL_TIM_GET_COUNTER(&htim6) < time){

	  }
	__HAL_TIM_SET_COUNTER(&htim6 , 0);
}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
