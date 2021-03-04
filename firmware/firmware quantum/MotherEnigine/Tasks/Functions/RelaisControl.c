/*
 * RelaisControl.c
 *
 *  Created on: 13.11.2019
 *      Author: christiansager
 */
#include "stm32f7xx_hal.h"
#include "RelaisControl.h"
#include "main.h"

/*
Relais1_GPIO_Port GPIOG
Relais2_GPIO_Port GPIOE
Relais3_GPIO_Port GPIOG
Relais4_GPIO_Port GPIOG
Relais5_GPIO_Port GPIOG
Relais6_GPIO_Port GPIOG
*/

void BypassLeft(Byp State){
	switch(State)
	{
		case activate:
			{
				HAL_GPIO_WritePin(GPIOG, Relais1_Pin,GPIO_PIN_SET);
			}
			break;
		case bypass:
			{
				HAL_GPIO_WritePin(GPIOG, Relais1_Pin,GPIO_PIN_RESET);
			}
			break;
	}
}

void BypassRight(Byp State){
	switch(State)
	{
		case activate:
			{
				HAL_GPIO_WritePin(GPIOG, Relais2_Pin,GPIO_PIN_SET);
			}
			break;
		case bypass:
			{
				HAL_GPIO_WritePin(GPIOG, Relais2_Pin,GPIO_PIN_RESET);
			}
			break;
	}
}








void VCASource(Source State){
	switch(State)
	{
		case MS:
			{
				HAL_GPIO_WritePin(GPIOG, Relais3_Pin,GPIO_PIN_SET);
			}
			break;
		case RL:
			{
				HAL_GPIO_WritePin(GPIOG, Relais3_Pin,GPIO_PIN_RESET);
			}
			break;
	}
}

void VCAOutput(Output Out, Convert Conv ){
	switch(Out)
	{
		case NormalOutput:
			{
				HAL_GPIO_WritePin(GPIOG, Relais5_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOG, Relais6_Pin,GPIO_PIN_RESET);
			}
			break;
		case MonoS:
			{
				HAL_GPIO_WritePin(GPIOG, Relais5_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOG, Relais6_Pin,GPIO_PIN_RESET);
			}
			break;
		case MonoM:
			{
				HAL_GPIO_WritePin(GPIOG, Relais5_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOG, Relais6_Pin,GPIO_PIN_SET);
			}
			break;
	}
	switch(Conv){
		case MS_Deconvert_Active:
			{
				HAL_GPIO_WritePin(GPIOG, Relais4_Pin,GPIO_PIN_SET);
			}
			break;
		case MS_Deconvert_Inactive:
			{
				HAL_GPIO_WritePin(GPIOG, Relais4_Pin,GPIO_PIN_RESET);
			}
			break;
	}
}
