/*
 * UART_IO.c
 *
 *  Created on: 16.11.2019
 *      Author: christiansager
 */
#include "main.h"
#include "UART_IO.h"

void UARTRECIVER(){

	 for(int i = 0; i<50;i++){
		 UARTDATA[i]	= 0x00;

	 }

	 int start = 0;
	 int offset = 0;
	   	    	     for(int i = 0; i<50;i++){
	   	    	    	 if (UART_RECIVE[i] == '#' && UART_RECIVE[i+1] == 's'&& UART_RECIVE[i+2] == 't' &&UART_RECIVE[i+3] == 'a'){
	   	    	    		   start = i; //found start index @start
	   	    	    		   break;
	   	    	    	 }
	   	    	    	 if (UART_RECIVE[i] == '#' && UART_RECIVE[i+1] == 's'&& UART_RECIVE[i+2] == 't' &&UART_RECIVE[i-47] == 'a'){
	   	    	    		   start = i; //found start index @start
	   	    	    		   break;
	   	    	    	 }
	   	    	    	 if (UART_RECIVE[i] == '#' && UART_RECIVE[i+1] == 's'&& UART_RECIVE[i-48] == 't' &&UART_RECIVE[i-47] == 'a'){
	   	    	    		   start = i; //found start index @start
	   	    	    		   break;
	   	    	    	 }
	   	    	    	 if (UART_RECIVE[i] == '#' && UART_RECIVE[i-49] == 's'&& UART_RECIVE[i-48] == 't' &&UART_RECIVE[i-47] == 'a'){
	   	    	    		   start = i; //found start index @start
	   	    	    		   break;
	   	    	    	 }

	   	    	     }

	   	    	  UARTDATA[50] = start;
	   	    	     if (start == 0){
	   	    	    	 for (int i = 0; i< 50;i++){
	   	    	    		UARTDATA[i] = UART_RECIVE[i];
	   	    	    	 }
	   	    	     }
	   	    	     else if (start != 0){
	   	        	     for (int i = 0; i< 50;i++){
	   	        	    	UARTDATA[i] = UART_RECIVE[i+start];
	   	        	    	 offset = i+1;
	   	        	    	 if (i+start == 49){
	   	        	    		 break;
	   	        	    	 }
	   	        	     }
	   	        	     for (int i = 0; i< 50;i++){
	   	        	    	UARTDATA[i+offset] = UART_RECIVE[i];
	   	        	    	 if (i+offset == 49){
	   	        	    		 break;
	   	        	    	 }
	   	        	     }
	   	    	     }
	   	    	  UARTDATA[50] = start;


}
