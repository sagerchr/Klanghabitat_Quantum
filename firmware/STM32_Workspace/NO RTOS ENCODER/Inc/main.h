/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Button_ENC3_Pin GPIO_PIN_0
#define Button_ENC3_GPIO_Port GPIOF
#define ADDRESS_Pin GPIO_PIN_1
#define ADDRESS_GPIO_Port GPIOF
#define ENCODER2_A_Pin GPIO_PIN_0
#define ENCODER2_A_GPIO_Port GPIOA
#define ENCODER2_B_Pin GPIO_PIN_1
#define ENCODER2_B_GPIO_Port GPIOA
#define VCP_TX_Pin GPIO_PIN_2
#define VCP_TX_GPIO_Port GPIOA
#define R_ENC1_Pin GPIO_PIN_3
#define R_ENC1_GPIO_Port GPIOA
#define G_ENC1_Pin GPIO_PIN_4
#define G_ENC1_GPIO_Port GPIOA
#define B_ENC1_Pin GPIO_PIN_5
#define B_ENC1_GPIO_Port GPIOA
#define ENCODER3_A_Pin GPIO_PIN_6
#define ENCODER3_A_GPIO_Port GPIOA
#define ENCODER3_B_Pin GPIO_PIN_7
#define ENCODER3_B_GPIO_Port GPIOA
#define B_ENC2_Pin GPIO_PIN_0
#define B_ENC2_GPIO_Port GPIOB
#define R_ENC3_Pin GPIO_PIN_1
#define R_ENC3_GPIO_Port GPIOB
#define ENCODER1_A_Pin GPIO_PIN_8
#define ENCODER1_A_GPIO_Port GPIOA
#define ENCODER1_B_Pin GPIO_PIN_9
#define ENCODER1_B_GPIO_Port GPIOA
#define R_ENC2_Pin GPIO_PIN_11
#define R_ENC2_GPIO_Port GPIOA
#define G_ENC2_Pin GPIO_PIN_12
#define G_ENC2_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define VCP_RX_Pin GPIO_PIN_15
#define VCP_RX_GPIO_Port GPIOA
#define G_ENC3_Pin GPIO_PIN_3
#define G_ENC3_GPIO_Port GPIOB
#define B_ENC3_Pin GPIO_PIN_4
#define B_ENC3_GPIO_Port GPIOB
#define Button_ENC1_Pin GPIO_PIN_5
#define Button_ENC1_GPIO_Port GPIOB
#define Button_ENC2_Pin GPIO_PIN_7
#define Button_ENC2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
