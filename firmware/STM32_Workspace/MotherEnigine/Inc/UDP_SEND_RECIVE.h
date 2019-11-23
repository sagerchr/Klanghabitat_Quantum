/*
 * UDP_SEND_RECIVE.h
 *
 *  Created on: 23.11.2019
 *      Author: christiansager
 */

void UDP_init(int IP1,int IP2,int IP3,int IP4); //INIT the UDP Session
void OSCmessageINTSend(char *OSCAdress,int size, int value);
char UDP_RECIVE[20];
