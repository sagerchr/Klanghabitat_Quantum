/*
 * MessageHandler.h
 *
 *  Created on: 14.04.2021
 *      Author: christiansager
 */

#ifndef APP_MESSAGEHANDLER_H_
#define APP_MESSAGEHANDLER_H_

typedef struct Message {
   char MESSAGE[80];
   int Message_ID;
   int status;
}  Message;

Message MessageStack[MAXSTACK];
Message MessageReceiveStack[MAXSTACK];


int WriteReceiveStackPointer,ReadReceiveStackPointer, MessageID;

char MessageControl;

#endif /* APP_MESSAGEHANDLER_H_ */
