/*
 * UART_IO.c
 *
 *  Created on: 16.11.2019
 *      Author: christiansager
 */
#include "main.h"
#include "UART_correction.h"
UART_HandleTypeDef huart6;

void UART_correction(){
	HAL_UART_DMAPause(&huart6);

	 for(int i = 0; i<RX_IN_SIZE;i++){
		 UART_reciveCorrected[i]	= 0x00;
		 UART_RECIVE_temp[i] = UART_RECIVE[i];
		 UART_RECIVE[i]=0;
	 }

	HAL_UART_DMAResume(&huart6);

	 int start = 0;
	 int offset = 0;

	     for(int i = 0; i<RX_IN_SIZE;i++){
	    	 if (UART_RECIVE_temp[i] == '#' && UART_RECIVE_temp[i+1] == 's'&& UART_RECIVE_temp[i+2] == 't' &&UART_RECIVE_temp[i+3] == 'a'){
	    		   start = i; //found start index @start
	    		   break;
	    	 }
	    	 if (UART_RECIVE_temp[i] == '#' && UART_RECIVE_temp[i+1] == 's'&& UART_RECIVE_temp[i+2] == 't' &&UART_RECIVE_temp[i-RX_IN_SIZE+3] == 'a'){
	    		   start = i; //found start index @start
	    		   break;
	    	 }
	    	 if (UART_RECIVE_temp[i] == '#' && UART_RECIVE_temp[i+1] == 's'&& UART_RECIVE_temp[i-RX_IN_SIZE+2] == 't' &&UART_RECIVE_temp[i-RX_IN_SIZE+3] == 'a'){
	    		   start = i; //found start index @start
	    		   break;
	    	 }
	    	 if (UART_RECIVE_temp[i] == '#' && UART_RECIVE_temp[i-RX_IN_SIZE+1] == 's'&& UART_RECIVE_temp[i-RX_IN_SIZE+2] == 't' &&UART_RECIVE_temp[i-RX_IN_SIZE+3] == 'a'){
	    		   start = i; //found start index @start
	    		   break;
	    	 }

	     }

	   	for (int i = 0; i< 100;i++){
	   		UART_reciveCorrected[i] = UART_RECIVE_temp[i+start];
	   	}

	   	uint8_t checksum = 0;
	   	for(int i = 0; i < 99; i++) {
	   	 	 checksum += UART_reciveCorrected[i];
	   	 }
	   if (checksum == UART_reciveCorrected[99]){
		   	  for (int i = 0; i< 100;i++){
		   	 	UART_IN[i] = UART_reciveCorrected[i];
		   	 }
	   	}

}
