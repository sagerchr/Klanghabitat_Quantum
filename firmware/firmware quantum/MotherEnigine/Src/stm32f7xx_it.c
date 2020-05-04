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
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "math.h"
#include "UART_correction.h"
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

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

uint8_t DSProundtrip = 10; //Defines the RoundTrip time of the DSP


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
    HAL_GPIO_WritePin(GPIOD, CS_Pin,GPIO_PIN_SET);

      HAL_GPIO_WritePin(GPIOD, RD_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD, CS_Pin,GPIO_PIN_RESET);
      microDelay(0);
       //At least something... to get Ports updated
      analogIN[i] = GPIOE->IDR;
  }

  //HAL_GPIO_WritePin(GPIOD, CS_Pin,GPIO_PIN_SET);
  //HAL_GPIO_WritePin(GPIOD, RD_Pin,GPIO_PIN_SET);
  //************************************************************//
  //HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, analogIN[0]); //Update ADC1
  //HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, analogIN[1]); //Update ADC2

  HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R,UART_reciveCorrected[7]+150); //Update ADC1
  HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R,UART_reciveCorrected[9]+171); //Update ADC2
  //HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R,150); //Update ADC1
  //HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R,155); //Update ADC2



  //µsec in total
  RingIn1[indexer] = analogIN[0];
  voltRingIn1[indexer] = RingIn1[indexer]*(10.0/32767);
  if (voltRingIn1[indexer]<0){volt = voltRingIn1[indexer]*(-1.0);}
  else {volt = voltRingIn1[indexer];}

  if (voltageIn1MAX < volt){voltageIn1MAX=volt;}
    dbuRingIn1[indexer]  = 20*log(volt/1.735); //1.5 µsec!!!

  if (dbuMAX[0]<dbuRingIn1[indexer]){
	  dbuMAX[0]=dbuRingIn1[indexer];
  }


  RingIn2[indexer] = analogIN[1];
  voltRingIn2[indexer] = RingIn2[indexer]*10.0/32767;
  if (voltRingIn2[indexer]<0){volt = voltRingIn2[indexer]*(-1.0);}
  else {volt = voltRingIn2[indexer];}

  if (voltageIn2MAX < volt){voltageIn2MAX=volt;}
  dbuRingIn2[indexer]  = 20*log(volt/1.735);

  if (dbuMAX[1]<dbuRingIn2[indexer]){
	  dbuMAX[1]=dbuRingIn2[indexer];
  }
/*
  RingIn3[indexer] = analogIN[2];
  voltRingIn3[indexer] = RingIn3[indexer]*10.0/32767;
  if (voltRingIn3[indexer]<0){volt = voltRingIn3[indexer]*(-1.0);}
  else {volt = voltRingIn3[indexer];}
  if (voltageIn3MAX < volt){voltageIn3MAX=volt;}
  dbuRingIn3[indexer]  = 20*log(volt/0.775);

  RingIn4[indexer] = analogIN[3];
  voltRingIn4[indexer] = RingIn4[indexer]*10.0/32767;
  if (voltRingIn4[indexer]<0){volt = voltRingIn4[indexer]*(-1.0);}
  else {volt = voltRingIn4[indexer];}
  if (voltageIn4MAX < volt){voltageIn4MAX=volt;}
  dbuRingIn4[indexer]  = 20*log(volt/0.775);
*/
  RingIn5[indexer] = analogIN[4];
  voltRingIn5[indexer] = RingIn5[indexer]*10.0/32767;
  if (voltRingIn5[indexer]<0){
	  volt = voltRingIn5[indexer]*(-1.0);}
  else {volt = voltRingIn5[indexer];}
  if (voltageIn5MAX < volt){voltageIn5MAX=volt;}
  dbuRingIn5[indexer]  = 20*log(volt/1.735);//+4dBu

  RingIn6[indexer] = analogIN[5];
  voltRingIn6[indexer] = RingIn6[indexer]*10.0/32767;
  if (voltRingIn6[indexer]<0){volt = voltRingIn6[indexer]*(-1.0);}
  else {volt = voltRingIn6[indexer];}
  if (voltageIn6MAX < volt){voltageIn6MAX=volt;}
  dbuRingIn6[indexer]  = 20*log(volt/1.735);//+4dBu




  voltageRMStemp[0] = voltageRMStemp[0] + (voltRingIn1[indexer]*voltRingIn1[indexer]);
  voltageRMStemp[1] = voltageRMStemp[1] + (voltRingIn2[indexer]*voltRingIn2[indexer]);
  voltageRMStemp[2] = voltageRMStemp[2] + (voltRingIn3[indexer]*voltRingIn3[indexer]);
  voltageRMStemp[3] = voltageRMStemp[3] + (voltRingIn4[indexer]*voltRingIn4[indexer]);
  voltageRMStemp[4] = voltageRMStemp[4] + (voltRingIn5[indexer]*voltRingIn5[indexer]);
  voltageRMStemp[5] = voltageRMStemp[5] + (voltRingIn6[indexer]*voltRingIn6[indexer]);
  indexer++;



  if (indexer == SAMPLES){

	  indexer = 0;



	  voltageRMS[0]=voltageRMStemp[0];
	  voltageRMS[1]=voltageRMStemp[1];
	  voltageRMS[2]=voltageRMStemp[2];
	  voltageRMS[3]=voltageRMStemp[3];
	  voltageRMS[4]=voltageRMStemp[4];
	  voltageRMS[5]=voltageRMStemp[5];
	  for(int i=0;i<6;i++){
		  voltageRMS[i] = voltageRMS[i]/samples;
		  voltageRMS[i] = sqrt(voltageRMS[i]);
		  dbuRMS[i]= 20*log(voltageRMS[i]/1.227); //+4dBu
	  }

	  voltageRMStemp[0]=0;
	  voltageRMStemp[1]=0;
	  voltageRMStemp[2]=0;
	  voltageRMStemp[3]=0;
	  voltageRMStemp[4]=0;
	  voltageRMStemp[5]=0;



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

  	HAL_GPIO_TogglePin(GPIOF, DEBUG1_Pin);


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
