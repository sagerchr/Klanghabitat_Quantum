/*
 * MessageHandler.h
 *
 *  Created on: 22.03.2021
 *      Author: christiansager
 */

#ifndef FUNCTIONS_MESSAGEHANDLER_H_
#define FUNCTIONS_MESSAGEHANDLER_H_


uint8_t SendProcess;

char *OldestMessage;
uint32_t MessageID, MessageID_RECEIVE, ID_COUNT, ReceivedMessageID;
int SendMessageStackPointer,PopStackPointer, ReceiveMessageStackPointer, UnsentMessages;


void WriteMessage (char *string);
int compare (char *str1 , char *str2);
void InitMeassageHandler();




#endif /* FUNCTIONS_MESSAGEHANDLER_H_ */
