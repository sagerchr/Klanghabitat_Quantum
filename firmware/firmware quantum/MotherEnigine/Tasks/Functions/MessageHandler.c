/*
 * MessageHandler.c
 *
 *  Created on: 22.03.2021
 *      Author: christiansager
 */
#include "Main.h"
#include "MessageHandler.h"

//###################################################//
//############### Initialize Stack ##################//
//###################################################//
void InitMeassageHandler(){
	WriteStackPointer = 0;
	ReadStackPointer = 0;
	ID_COUNT = 0;
}
//###################################################//


//###################################################//
//######## Push a new Message to the Stack ##########//
//###################################################//
void pushToMessageQueue(char *String)
{
			if (WriteStackPointer >= MAXSTACK){
				WriteStackPointer = 0;			//Reset WriteStackPointer if end of Queue is reached
			}

            strcpy(MessageStack[WriteStackPointer].MESSAGE, String); //Fill Message to the Stack
            MessageStack[WriteStackPointer].Message_ID = ID_COUNT++; //Set Message_ID
            MessageStack[WriteStackPointer].status = 10; //Set Status to 10 "unread by slave"

            WriteStackPointer = WriteStackPointer + 1; //Increment Write StackPointer

            if(WriteStackPointer - ReadStackPointer >= 0){
            	UnsentMessages =  WriteStackPointer - ReadStackPointer;
            }
            else{
            	UnsentMessages =  WriteStackPointer + (MAXSTACK - ReadStackPointer);
            }
}
//###################################################//


//#####################################################################//
//####### Pop oldest Message from the Stack and write to UART #########//
//#####################################################################//
void popFromMessageQueue(char *String, uint8_t *LB, uint8_t *HB)
{
			if (ReadStackPointer >= MAXSTACK-1){
				ReadStackPointer = 0;
			}
            strcpy(String, MessageStack[ReadStackPointer].MESSAGE);

          ReadStackPointer = ReadStackPointer+1;


  		WriteMessage (String);  //Write Message to the UART_transmit

  		UART_transmit[181] = MessageStack[ReadStackPointer].Message_ID  & 0x00FF; //low byte
  		UART_transmit[182] = MessageStack[ReadStackPointer].Message_ID >> 8; //high byte

  		UART_transmit[183] = MessageStack[ReadStackPointer].status; //Put the Status on the UART_transmit

  		SendProcess = 1;
}
//#######################################################################//

void WriteMessageID (uint32_t MessageID){
	UART_transmit[190] = MessageID  & 0x00FF; //low byte
	UART_transmit[191] = MessageID >> 8; //high byte
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
