/*
 * UART_IO.c
 *
 *  Created on: 16.11.2019
 *      Author: christiansager
 */
#include "main.h"
#include "UART_IO.h"
UART_HandleTypeDef huart6;
UARTRECIVER(){

	HAL_UART_DMAPause(&huart6);
	 for(int i = 0; i<RX_IN_SIZE;i++){
		 UARTDATA[i]	= 0x00;
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
	   	    	    		UARTDATA[i] = UART_RECIVE_temp[i+start];
	   	    	    	 }

}


UARTSENDER(){
	HAL_UART_DMAPause(&huart6);



	uint8_t checksum = 0;
	for(int i = 0; i < 99; i++) {
			checksum += UART_TRANSFER[i];
		  }

	UART_TRANSFER[99]=checksum;


	HAL_UART_DMAResume(&huart6);

}



