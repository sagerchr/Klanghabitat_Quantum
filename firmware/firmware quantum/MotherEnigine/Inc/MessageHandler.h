/*
 * MessageHandler.h
 *
 *  Created on: 22.03.2021
 *      Author: christiansager
 */

#ifndef FUNCTIONS_MESSAGEHANDLER_H_
#define FUNCTIONS_MESSAGEHANDLER_H_


typedef struct Message {
   char MESSAGE[80];
   uint32_t Message_ID;
   int status;
}  Message;

Message SendMessageStack[MAXSTACK];
Message ReceiveMessageStack[MAXSTACK];


uint8_t SendProcess;

char *OldestMessage;
uint32_t MessageID, ID_COUNT, ReceivedMessageID;
int SendMessageStackPointer,PopStackPointer, ReceiveMessageStackPointer, UnsentMessages;


void WriteMessage (char *string);
int compare (char *str1 , char *str2);





#endif /* FUNCTIONS_MESSAGEHANDLER_H_ */
