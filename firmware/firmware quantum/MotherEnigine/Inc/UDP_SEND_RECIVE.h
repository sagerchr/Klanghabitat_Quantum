/*
 * UDP_SEND_RECIVE.h
 *
 *  Created on: 23.11.2019
 *      Author: christiansager
 */

void UDP_init(int IP1,int IP2,int IP3,int IP4); //INIT the UDP Session
void OSCmessageINTSend(char *OSCAdress,int size, int value);
void OSCmessageFLOATSend(char *OSCAdress,int size, int a, int b, int c, int d);
char UDP_RECIVE[50];
char OSC_FORMAT;
char OSC_PATH[50];
uint32_t OSC_UNSIGNETINTEGER;
int32_t OSC_SIGNEDINTEGER;
float OSC_FLOAT;
