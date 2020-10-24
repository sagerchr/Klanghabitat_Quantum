/*
 * DAC_Control.c
 *
 *  Created on: 19.01.2020
 *      Author: christiansager
 */
#include "main.h"

SPI_HandleTypeDef hspi2;



void DAC_Control(uint8_t DACselect, uint8_t DeviceAdr, uint8_t value){
	HAL_GPIO_WritePin(GPIOB, CS_DAC1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, CS_POTI_Pin, GPIO_PIN_SET);

	uint16_t payload;
	uint8_t payloadUpper;
	uint8_t payloadLower;

	payload = value << 4;
	if (DACselect == 1){
		  payload |= 0u << 14;
		  payload |= 0u << 15;
	}
	if (DACselect == 2){
		  payload |= 1u << 14;
		  payload |= 0u << 15;
	}
	if (DACselect == 3){
		  payload |= 0u << 14;
		  payload |= 1u << 15;
	}
	if (DACselect == 4){
		  payload |= 1u << 14;
		  payload |= 1u << 15;
	}
	payload |= 1u << 12;
	payload |= 0u << 13;

	payloadUpper = payload >>8;
	payloadLower = payload;

	uint8_t message[2] = {payloadUpper,payloadLower};
	if(DeviceAdr == 1){
	HAL_GPIO_WritePin(GPIOB, CS_DAC1_Pin, GPIO_PIN_RESET);
	}
	if(DeviceAdr == 2){
	HAL_GPIO_WritePin(GPIOB, CS_POTI_Pin, GPIO_PIN_RESET);
	}

	HAL_SPI_Transmit(&hspi2, (uint8_t *)message, strlen(message), 10000);
	HAL_Delay(1);

	if(DeviceAdr == 1){
	HAL_GPIO_WritePin(GPIOB, CS_DAC1_Pin, GPIO_PIN_SET);
	}
	if(DeviceAdr == 2){
	HAL_GPIO_WritePin(GPIOB, CS_POTI_Pin, GPIO_PIN_SET);
	}
}


