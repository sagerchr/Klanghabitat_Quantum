/*
 * SerialHandleTask.c
 *
 *  Created on: 29 Apr 2020
 *      Author: christiansager
 */
#include "main.h"
#include "SerialHandleTask.h"
#include "UART_IO.h"

UART_HandleTypeDef huart6;
void SerialHandleTask(void const * argument)
{
  for(;;)
  {

      UART_TRANSFER[0]='#';
      UART_TRANSFER[1]='s';
      UART_TRANSFER[2]='t';
      UART_TRANSFER[3]='a';
      UART_TRANSFER[4]=0xFF;//0
      UART_TRANSFER[5]=0x00;
      UART_TRANSFER[6]=pots[1];//2
      UART_TRANSFER[7]=pots[2];//3
      UART_TRANSFER[8]=pots[3];//4
      UART_TRANSFER[9]=pots[4];//5
      UART_TRANSFER[10]=0x00;
      UART_TRANSFER[11]=0x00;
      UART_TRANSFER[12]=0x02;//8
	  UART_TRANSFER[13]=0x03;//9
  }

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart6){

	UARTRECIVER();
}


