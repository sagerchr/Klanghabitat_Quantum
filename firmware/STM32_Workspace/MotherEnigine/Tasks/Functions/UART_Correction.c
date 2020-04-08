/*
 * UART_IO.c
 *
 *  Created on: 16.11.2019
 *      Author: christiansager
 */
#include "main.h"
#include "UART_correction.h"

void UART_correction(){

	 int start = 0;
	 int offset = 0;
	     for(int i = 0; i<150;i++){

	    	 if (UART_recive[i] == '#' && UART_recive[i+1] == 's'&& UART_recive[i+2] == 't' && UART_recive[i+3] == 'a'){
	    		   start = i; //found start index @start
	    		   break;
	    	 }
	    	 if (UART_recive[i] == '#' && UART_recive[i+1] == 's'&& UART_recive[i+2] == 't' && UART_recive[i-147] == 'a'){
	    		   start = i; //found start index @start
	    		   break;
	    	 }
	    	 if (UART_recive[i] == '#' && UART_recive[i+1] == 's'&& UART_recive[i-148] == 't' && UART_recive[i-147] == 'a'){
	    		   start = i; //found start index @start
	    		   break;
	    	 }
	    	 if (UART_recive[i] == '#' && UART_recive[i-149] == 's'&& UART_recive[i-148] == 't' && UART_recive[i-147] == 'a'){
	    		   start = i; //found start index @start
	    		   break;
	    	 }

	     }
	   	    	     if (start == 0){
	   	    	    	 for (int i = 0; i< 150;i++){
	   	    	    		UART_reciveCorrected[i] = UART_recive[i];
	   	    	    	 }
	   	    	     }
	   	    	     else if (start != 0){
	   	        	     for (int i = 0; i< 150;i++){
	   	        	    	UART_reciveCorrected[i] = UART_recive[i+start];
	   	        	    	 offset = i+1;
	   	        	    	 if (i+start == 149){
	   	        	    		 break;
	   	        	    	 }
	   	        	     }
	   	        	     for (int i = 0; i< 150;i++){
	   	        	    	UART_reciveCorrected[i+offset] = UART_recive[i];
	   	        	    	 if (i+offset == 149){
	   	        	    		 break;
	   	        	    	 }
	   	        	     }
	   	    	     }

}
