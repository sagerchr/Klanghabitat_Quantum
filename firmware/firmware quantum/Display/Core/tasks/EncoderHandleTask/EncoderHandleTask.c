/*
 * SerialHandleTask.c
 *
 *  Created on: 29 Apr 2020
 *      Author: christiansager
 */
#include "EncoderHandleTask.h"

#include "main.h"


I2C_HandleTypeDef hi2c1;
TS_StateTypeDef TS_State;

uint8_t level = 0;
uint8_t aTxBuffer[] = "          ";
uint8_t aRxBuffer[10];

uint8_t buttonstateLeft;
uint8_t buttonstateRight;



void EncoderHandleTask(void const * argument)
{


	HAL_Delay(250);
  for(;;)
  {
	  	HAL_Delay(25);

      	aTxBuffer[0]= 'T';
      	aTxBuffer[1]= 'E';
      	aTxBuffer[2]= 'S';
      	aTxBuffer[3]= 'T';

      	aTxBuffer[9]=10;

      	 HAL_I2C_Master_Transmit(&hi2c1, 30, aTxBuffer,10,1000);
      	 HAL_I2C_Master_Receive(&hi2c1, 30, aRxBuffer,10,1000);
      	 if(aRxBuffer[8]!=255) {pots[2]=aRxBuffer[7];}
      	 if(aRxBuffer[9]!=255) {pots[1]=aRxBuffer[9];}
      	 if(aRxBuffer[6]!=255) {buttonstateLeft=aRxBuffer[6];}

      	 HAL_I2C_Master_Transmit(&hi2c1, 40, aTxBuffer,10,1000);
      	 HAL_I2C_Master_Receive(&hi2c1, 40, aRxBuffer,10,1000);
      	 if(aRxBuffer[8]!=255) {pots[4]=aRxBuffer[7];}
      	 if(aRxBuffer[9]!=255) {pots[3]=aRxBuffer[9];}
      	 if(aRxBuffer[6]!=255) {buttonstateRight=aRxBuffer[6];}

        BSP_TS_GetState(&TS_State);

        TouchX = TS_State.touchX[0];
        TouchY = TS_State.touchY[0];

  }

}



