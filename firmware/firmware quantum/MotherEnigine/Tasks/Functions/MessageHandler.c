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
	SendMessageStackPointer = -1;
	PopStackPointer = -1;
	ReceiveMessageStackPointer = -1;
	ID_COUNT = 0;

	for(int i=0; i<MAXSTACK; i++)
				{
					ReceiveMessageStack[i].Message_ID = -1;
				}
}
//###################################################//


//###################################################//
//######## Push a new Message to the Stack ##########//
//###################################################//
void pushToMessageQueue(char *String)
{
			if (SendMessageStackPointer == MAXSTACK-1){
				SendMessageStackPointer = -1;			//Reset WriteStackPointer if end of Queue is reached
			}
			SendMessageStackPointer = SendMessageStackPointer + 1; //Increment Write StackPointer

            strcpy(SendMessageStack[SendMessageStackPointer].MESSAGE, String); //Fill Message to the Stack
            SendMessageStack[SendMessageStackPointer].Message_ID = ID_COUNT++; //Set Message_ID
            SendMessageStack[SendMessageStackPointer].status = 5; //Set Status to 5 "not yet sent to slave"
}
//###################################################//


//#####################################################################//
//####### Pop oldest Message from the Stack and write to UART #########//
//#####################################################################//
uint16_t popFromMessageQueue()
{
	char *String;


	//################Check if the last Message was read successfully bz the slave####################//
	ReceivedMessageID = (UARTDATA_CHECKED [182] << 8) | (UARTDATA_CHECKED [181] & 0xFF);

	if(ReceivedMessageID == MessageID && SendProcess == 1){
		  SendMessageStack[PopStackPointer].status = 40; //Check Message as successfully read by slave
		  UART_TRANSFER[183] = 0; //Tell slave there is no Message to read
		  SendProcess = 0; //Send Process is done
	}
	//################################################################################################//


		if(SendProcess == 0){
			if (PopStackPointer == (MAXSTACK-1))
			{
				PopStackPointer = -1;
			}
			PopStackPointer = PopStackPointer+1;
		}



		if(SendMessageStack[PopStackPointer].status == 5 && SendProcess == 0){

			SendMessageStack[PopStackPointer].status = 10; //Set Status to 10 "sent to slave"

	        strcpy(String, SendMessageStack[PopStackPointer].MESSAGE);

	  		WriteMessage (String);  //Write Message to the UART_transmit

	  		MessageID = SendMessageStack[PopStackPointer].Message_ID;
	  		UART_TRANSFER[181] = SendMessageStack[PopStackPointer].Message_ID  & 0x00FF; //low byte
	  		UART_TRANSFER[182] = SendMessageStack[PopStackPointer].Message_ID >> 8; //high byte

	  		UART_TRANSFER[183] = SendMessageStack[PopStackPointer].status; //Put the Status on the UART_transmit

	  		SendProcess = 1;
		}



  		return SendMessageStack[PopStackPointer].Message_ID;
}
//#######################################################################//

void getMessageToReciveStack()
{

	MessageID = (UARTDATA_CHECKED[182]<<8) | (UARTDATA_CHECKED[181] & 0xFF);

	if (UARTDATA_CHECKED[183] == 10)
	{

		int new_ID = 0;
		for(int i=0; i<MAXSTACK; i++)
		{
			if(MessageID == ReceiveMessageStack[i].Message_ID){
			new_ID = 0;
			break;
			}
			else
			{
			new_ID = 1;
			}
		}

		if(new_ID)
		{

				if (ReceiveMessageStackPointer >= MAXSTACK)
				{
					ReceiveMessageStackPointer = 0;			//Reset WriteStackPointer if end of Queue is reached
				}

				for(int i = 100; i < 180; i++)
				{
					ReceiveMessageStack[ReceiveMessageStackPointer].MESSAGE[i-100] = UARTDATA_CHECKED[i];
				}

				ReceiveMessageStack[ReceiveMessageStackPointer].Message_ID = MessageID;

				ReceiveMessageStackPointer++;
				//Show Master that Message was read succesfully
				UART_TRANSFER[181] = MessageID & 0x00FF;
				UART_TRANSFER[182] = MessageID >> 8;

		}
	}
}


void WriteMessageID (uint32_t MessageID){
	UART_TRANSFER[190] = MessageID  & 0x00FF; //low byte
	UART_TRANSFER[191] = MessageID >> 8; //high byte
}

void WriteMessage (char *string){

		for(int i = 100; i < 198; i++){
			UART_TRANSFER[i]=0x00;
		}

		int i = 0;

		  while ((*(string+i) != '\r' && *(string+i+1) != '\n') || i == 98){

			  UART_TRANSFER[i+100]=*(string+i);

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
