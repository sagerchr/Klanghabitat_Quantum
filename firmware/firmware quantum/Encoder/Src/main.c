/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
DMA_HandleTypeDef hdma_i2c1_rx;
DMA_HandleTypeDef hdma_i2c1_tx;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim16;

UART_HandleTypeDef huart1;

osThreadId LEDHandle;
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM16_Init(void);
static void MX_DMA_Init(void);
void ENCODER_TASK(void const * argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint32_t ENC1;
uint32_t ENC2;
uint32_t ENC3;

uint8_t R_ENC1 = 100;
uint8_t G_ENC1 = 50;
uint8_t B_ENC1 = 0;

uint8_t R_ENC2 = 100;
uint8_t G_ENC2 = 50;
uint8_t B_ENC2 = 0;

uint8_t R_ENC3 = 100;
uint8_t G_ENC3 = 50;
uint8_t B_ENC3 = 0;

uint8_t I2C_data = 0;

uint8_t aTxBuffer[] = "ENCODER123";

/* Buffer used for reception */
uint8_t aRxBuffer[10];

//uint32_t Encoder_CODE;
uint8_t buttonstate;


int adress=0;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  adress = HAL_GPIO_ReadPin(GPIOF,ADDRESS_Pin);

  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  MX_TIM16_Init();
  MX_DMA_Init();
  /* USER CODE BEGIN 2 */



  HAL_TIM_Encoder_Start(&htim1,TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);


  //HAL_I2C_Slave_Transmit_DMA(&hi2c1,aTxBuffer,1);

  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of LED */
  osThreadDef(LED, ENCODER_TASK, osPriorityNormal, 0, 96);
  LEDHandle = osThreadCreate(osThread(LED), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */
	int ownAddress1 = 0;
	if (adress == 0){
		ownAddress1 = 40;
	}
	if (adress == 1){
		ownAddress1 = 30;
	}


  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00101D2D;
  hi2c1.Init.OwnAddress1 = ownAddress1;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_ENABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_ENABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter 
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter 
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 1024;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  //htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_FALLING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_FALLING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1024;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_FALLING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_FALLING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 1024;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_FALLING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_FALLING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM16 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM16_Init(void)
{

  /* USER CODE BEGIN TIM16_Init 0 */

  /* USER CODE END TIM16_Init 0 */

  /* USER CODE BEGIN TIM16_Init 1 */

  /* USER CODE END TIM16_Init 1 */
  htim16.Instance = TIM16;
  htim16.Init.Prescaler = 48;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = 10000;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim16) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM16_Init 2 */

  /* USER CODE END TIM16_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 38400;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel2_3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel2_3_IRQn, 3, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, R_ENC1_Pin|G_ENC1_Pin|B_ENC1_Pin|R_ENC2_Pin 
                          |G_ENC2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, B_ENC2_Pin|R_ENC3_Pin|G_ENC3_Pin|B_ENC3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : Button_ENC3_Pin ADDRESS_Pin */
  GPIO_InitStruct.Pin = Button_ENC3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = ADDRESS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);



  /*Configure GPIO pins : R_ENC1_Pin G_ENC1_Pin B_ENC1_Pin R_ENC2_Pin 
                           G_ENC2_Pin */
  GPIO_InitStruct.Pin = R_ENC1_Pin|G_ENC1_Pin|B_ENC1_Pin|R_ENC2_Pin 
                          |G_ENC2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : B_ENC2_Pin R_ENC3_Pin G_ENC3_Pin B_ENC3_Pin */
  GPIO_InitStruct.Pin = B_ENC2_Pin|R_ENC3_Pin|G_ENC3_Pin|B_ENC3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : Button_ENC1_Pin Button_ENC2_Pin */
  GPIO_InitStruct.Pin = Button_ENC1_Pin|Button_ENC2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c)
{

	HAL_I2C_Slave_Transmit(&hi2c1,aTxBuffer,10,100); //Transmit after completed the READ


	if (aRxBuffer[1]==0){R_ENC1 = 50;	G_ENC1 = 100;	B_ENC1 = 100;}   //LIGHTGRAY
	if (aRxBuffer[1]==1){R_ENC1 = 100;	G_ENC1 = 0;		B_ENC1 = 50;}    //MAGENTA
	if (aRxBuffer[1]==2){R_ENC1 = 100;	G_ENC1 = 50;	B_ENC1 = 00;}    //ORANGE
	if (aRxBuffer[1]==3){R_ENC1 = 0;	G_ENC1 = 50;	B_ENC1 = 100;}	 //CYAN
	if (aRxBuffer[1]==4){R_ENC1 = 50;	G_ENC1 = 100;	B_ENC1 = 0;} 	 //LGHTYELLOW
	if (aRxBuffer[1]==5){R_ENC1 = 10;	G_ENC1 = 100;	B_ENC1 = 10;} 	 //LIGHTGREEN
	if (aRxBuffer[1]==6){R_ENC1 = 0;	G_ENC1 = 10;	B_ENC1 = 100;}   //LIGHTBLUE
	if (aRxBuffer[1]==10){R_ENC1 = 0;	G_ENC1 = 0;		B_ENC1 = 0;}     //OFF

	if (aRxBuffer[2]==0){R_ENC3 = 50;	G_ENC3 = 100;	B_ENC3 = 100;}   //White
	if (aRxBuffer[2]==1){R_ENC3 = 100;	G_ENC3 = 0;		B_ENC3 = 50;}    //MAGENTA
	if (aRxBuffer[2]==2){R_ENC3 = 100;	G_ENC3 = 50;	B_ENC3 = 00;}    //Orange
	if (aRxBuffer[2]==3){R_ENC3 = 0;	G_ENC3 = 50;	B_ENC3 = 100;}	 //CYAN
	if (aRxBuffer[2]==4){R_ENC3 = 50;	G_ENC3 = 100;	B_ENC3 = 0;} 	 //Yellow
	if (aRxBuffer[2]==5){R_ENC3 = 10;	G_ENC3 = 100;	B_ENC3 = 10;} 	 //Green
	if (aRxBuffer[2]==6){R_ENC3 = 0;	G_ENC3 = 10;	B_ENC3 = 100;}   //BLUE
	if (aRxBuffer[2]==10){R_ENC3 = 0;	G_ENC3 = 0;		B_ENC3 = 0;}     //OFF





}
/* USER CODE END 4 */

/* USER CODE BEGIN Header_ENCODER_TASK */
/**
  * @brief  Function implementing the LED thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_ENCODER_TASK */
void ENCODER_TASK(void const * argument)
{
  /* USER CODE BEGIN 5 */


	int count=0;

  /* Infinite loop */
  for(;;)
  {



	ENC1 = (TIM1->CNT)/4;
	ENC2 = (TIM2->CNT)/4;
    ENC3 = (TIM3->CNT)/4;

    if(!HAL_GPIO_ReadPin(GPIOF,Button_ENC3_Pin)){
    	buttonstate |= 1<<2;
    }
    else{
    	buttonstate &= ~(1)<<2;
    }
    if(!HAL_GPIO_ReadPin(GPIOB,Button_ENC2_Pin)){
    	buttonstate |= 1<<1;
    }
    else{
    	buttonstate &= ~(1)<<1;
    }
    if(!HAL_GPIO_ReadPin(GPIOB,Button_ENC1_Pin)){
    	buttonstate |= 1<<0;
    }
    else{
    	buttonstate &= ~(1)<<0;
    }









    //A Ratio of about (R)38-(G)25-(B)0 gives nice yellow RATIO 1:2
	if (count>=100){count=0;}

	if (count < R_ENC1){HAL_GPIO_WritePin(GPIOA, R_ENC1_Pin,GPIO_PIN_RESET);}
	else{HAL_GPIO_WritePin(GPIOA, R_ENC1_Pin,GPIO_PIN_SET);}
	if (count < G_ENC1){HAL_GPIO_WritePin(GPIOA, G_ENC1_Pin,GPIO_PIN_RESET);}
	else{HAL_GPIO_WritePin(GPIOA, G_ENC1_Pin,GPIO_PIN_SET);}
	if (count < B_ENC1){HAL_GPIO_WritePin(GPIOA, B_ENC1_Pin,GPIO_PIN_RESET);}
	else{HAL_GPIO_WritePin(GPIOA, B_ENC1_Pin,GPIO_PIN_SET);}


	if (count < R_ENC3){HAL_GPIO_WritePin(GPIOB, R_ENC3_Pin,GPIO_PIN_RESET);}
	else{HAL_GPIO_WritePin(GPIOB, R_ENC3_Pin,GPIO_PIN_SET);}
	if (count < G_ENC3){HAL_GPIO_WritePin(GPIOB, G_ENC3_Pin,GPIO_PIN_RESET);}
	else{HAL_GPIO_WritePin(GPIOB, G_ENC3_Pin,GPIO_PIN_SET);}
	if (count < B_ENC3){HAL_GPIO_WritePin(GPIOB, B_ENC3_Pin,GPIO_PIN_RESET);}
	else{HAL_GPIO_WritePin(GPIOB, B_ENC3_Pin,GPIO_PIN_SET);}
	HAL_I2C_Slave_Receive_IT(&hi2c1,aRxBuffer,10);

    if(adress == 1){
    	aTxBuffer[5] = buttonstate;
        aTxBuffer[6]=ENC3;
        aTxBuffer[7]=ENC2;
        aTxBuffer[8]=ENC1;
    }
    else{
    	aTxBuffer[5] = buttonstate;
        aTxBuffer[6]=ENC1;
        aTxBuffer[7]=ENC2;
        aTxBuffer[8]=ENC3;
    }


	count++;

  }
  /* USER CODE END 5 */ 
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM14 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM14) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
