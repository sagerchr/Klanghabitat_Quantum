/*
 * MessageHandler.c
 *
 *  Created on: 14.04.2021
 *      Author: christiansager
 */
#include "main.h"
#include "MessageHandler.h"
#include "../tasks/SerialHandleTask/UART_IO.h"

void getMessageToReciveStack()
{
			WriteReceiveStackPointer++;

			if (WriteReceiveStackPointer >= MAXSTACK-1){
				WriteReceiveStackPointer = 0;			//Reset WriteStackPointer if end of Queue is reached
			}

			for(int i = 100; i < 180; i++){
				MessageReceiveStack[WriteReceiveStackPointer].MESSAGE[i-100] = UARTDATA_checked[i];
			}

			MessageReceiveStack[WriteReceiveStackPointer].Message_ID = MessageID;

			MessageControl = 20; //Set Read to OK.

}
