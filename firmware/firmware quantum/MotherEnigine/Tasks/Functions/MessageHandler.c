/*
 * MessageHandler.c
 *
 *  Created on: 22.03.2021
 *      Author: christiansager
 */
#include "Main.h"
#include "MessageHandler.h"



void InitMeassageHandler(){
	WriteStack = 0;   // Initialize Stack
	ReadStack = 0;
}

void pushToMessageQueue(char *String)
{
			if (WriteStack >= MAXSTACK){
				WriteStack = 0;
			}
            strcpy(MessageStack[WriteStack], String);
            WriteStack = WriteStack + 1;
}

void popFromMessageQueue(char *String)
{
			if (ReadStack >= MAXSTACK){
				ReadStack = 0;
			}
            strcpy(String, MessageStack[ReadStack]);
            ReadStack = ReadStack+1;
}



void WriteMessage (char *string){

		for(int i = 100; i < 198; i++){
			UART_transmit[i]=0x00;
		}

		int i = 0;

		  while ((*(string+i) != '\r' && *(string+i+1) != '\n') || i == 98){

			  UART_transmit[i+100]=*(string+i);

			  i++;
		  }

}


int compare (char *str1 , char *str2){

	int i = 0;
	int OK=0;
	  while ((*(str1+i) != '\n' )|| i == 98){

		  if ((str1+i) == (str2+i)){
				OK = 1;
			}
			else{
				OK = 0;
				break;
			}

		  i++;
	  }

		if (OK == 1) return 1;
			else if (OK == 0) return 0;
}
