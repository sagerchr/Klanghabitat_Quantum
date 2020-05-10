/*
 * SerialServer.c
 *
 *  Created on: 10 May 2020
 *      Author: christiansager
 */

#include "../tasks/SerialHandleTask/UART_IO.h"

float createFloat(int startadress){
	   /************Input Data to float**************/
	static int INT;
	static float test;
	   INT = UARTDATA[startadress+3] 			|
	   		(UARTDATA[startadress+2] << 8) 		|
	   		(UARTDATA[startadress+1] << 16) 	|
	   		(UARTDATA[startadress] << 24);

	   memcpy(&test, &INT, sizeof(test));
	   return test;
	   /*********************************************/
}



