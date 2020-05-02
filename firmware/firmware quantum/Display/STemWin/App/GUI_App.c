  /**
  ******************************************************************************
  * @file    GUI_App.c
  * @author  MCD Application Team
  * @brief   Simple demo drawing "Hello world"  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright © 2018 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
#include "GUI_App.h"
#include "GUI.h"
#include "main.h"
#include "DIALOG.h"
#include "main.h"
#include "../tasks/SerialHandleTask/UART_IO.h"


extern  WM_HWIN CreateMainWindow(void);
extern  WM_HWIN CreateSettingsWindow(void);
extern  WM_HWIN CreateWindow2(void);
extern  WM_HWIN CreateWindow3(WM_HWIN *hWinParent);
UART_HandleTypeDef huart6;


I2C_HandleTypeDef hi2c1;
TS_StateTypeDef TS_State;

uint8_t level = 0;
uint8_t aTxBuffer[] = "          ";
uint8_t aRxBuffer[10];

uint8_t buttonstateLeft;
uint8_t buttonstateRight;


int maxValueLeft = 0;
int newValueLeft = 0;
int maxValueRight = 0;
int newValueRight = 0;

int maxValueLeftOUT = 0;
int newValueLeftOUT = 0;
int maxValueRightOUT = 0;
int newValueRightOUT = 0;

float rightDB = -130.0;
float leftDB = -130.0;

float max_leftIN = 0.0;
float max_rightIN = 0.0;

float test = 0.0;


float adc1_ist = 0.0;
float adc1_volt = 0.0;
float adc1_db = 0.0;
float smooth1= 0.0;
float peaksmooth1= 0.0;
float diff1 = 0.0;


int adc2 = 0.0;
float adc2_ist = 0.0;
float adc2_volt = 0.0;
float adc2_db = 0.0;
float smooth2= 0.0;
float peaksmooth2= 0.0;
float diff2 = 0.0;

int adc3 = 0.0;
float adc3_ist = 0.0;
float adc3_volt = 0.0;
float adc3_db = 0.0;
float smooth3= 0.0;
float peaksmooth3= 0.0;
float diff3 = 0.0;

int adc4 = 0.0;
float adc4_ist = 0.0;
float adc4_volt = 0.0;
float adc4_db = 0.0;
float smooth4= 0.0;
float peaksmooth4= 0.0;
float diff4 = 0.0;

float leftIN = 0.0;
float rightIN = 0.0;

float spectrum_max[100];
void GRAPHICS_MainTask(void) {


  /* 2- Create a Window using GUIBuilder */



	GUI_Clear();
	  GUI_SetBkColor(GUI_DARKGRAY);


	  WM_HWIN MainWindow;
	  WM_HWIN SettingsWindow;

	MainWindow = CreateMainWindow();
	SettingsWindow = CreateSettingsWindow();
	GUI_Clear();
/* USER CODE BEGIN GRAPHICS_MainTask */
 /* User can implement his graphic application here */
  /* Hello Word example */

/* USER CODE END GRAPHICS_MainTask */
	int moved = 0;
	uint8_t wait=0;
	int slide=480;
	int raiser=50;
	int count=1;
  while(1)
{

      GUI_Delay(1);

      UART_TRANSFER[0]='#';
      UART_TRANSFER[1]='s';
      UART_TRANSFER[2]='t';
      UART_TRANSFER[3]='a';
      UART_TRANSFER[4]=0xFF;//0
      UART_TRANSFER[5]=0x00;
      UART_TRANSFER[6]=pots[1];//2
      UART_TRANSFER[7]=pots[2];//3
      UART_TRANSFER[8]=pots[3];//4
      UART_TRANSFER[9]=pots[4];//5
      UART_TRANSFER[10]=0x00;
      UART_TRANSFER[11]=0x00;
      UART_TRANSFER[12]=0x02;//8
	  UART_TRANSFER[13]=0x03;//9

    aTxBuffer[0]= 'T';
  	aTxBuffer[1]= 'E';
  	aTxBuffer[2]= 'S';
  	aTxBuffer[3]= 'T';

  	aTxBuffer[9]=10;

    switch (count) {
    case 1:
     	 HAL_I2C_Master_Transmit(&hi2c1, 30, aTxBuffer,10,1);
     	 HAL_I2C_Master_Receive(&hi2c1, 30, aRxBuffer,10,1);
     	 if(aRxBuffer[8]!=255) {pots[2]=aRxBuffer[7];}
     	 if(aRxBuffer[9]!=255) {pots[1]=aRxBuffer[9];}
     	 if(aRxBuffer[6]!=255) {buttonstateLeft=aRxBuffer[6];}
     	 count=2;
     	 break;
    case 2:
    	HAL_I2C_Master_Transmit(&hi2c1, 40, aTxBuffer,10,1);
     	 HAL_I2C_Master_Receive(&hi2c1, 40, aRxBuffer,10,1);
     	 if(aRxBuffer[8]!=255) {pots[4]=aRxBuffer[7];}
     	 if(aRxBuffer[9]!=255) {pots[3]=aRxBuffer[9];}
     	 if(aRxBuffer[6]!=255) {buttonstateRight=aRxBuffer[6];}
         count=3;
     	 break;
    case 3:
    	BSP_TS_GetState(&TS_State);
    	TouchXCoordinate = TS_State.touchX[0];
        TouchYCoordinate = TS_State.touchY[0];
        count=1;
     	 break;
    }


	BSP_TS_GetState(&TS_State);
	TouchXCoordinate = TS_State.touchX[0];
    TouchYCoordinate = TS_State.touchY[0];



	    if(TouchYCoordinate<350&&moved==1){
	    	WM_MoveTo(SettingsWindow,100 , 480);
	    	slide =480;
	    	moved = 0;
	    }



	    if(TouchYCoordinate>300&&TouchXCoordinate>250&&TouchXCoordinate<350 && moved == 0){
	    	if(slide >= 100){
	    		slide-=raiser;
	    		raiser-=3;
	    	}
	    	WM_MoveWindow(SettingsWindow,0,-400);
	    	moved = 1;
	    }

	    if (moved == 1){
	    	WM_Invalidate(SettingsWindow);
		    WM_SendMessageNoPara(SettingsWindow, WM_Paint);
		    wait = 0;
		    WM_SetFocus(SettingsWindow);
	    }



	    wait++;
	    WM_Invalidate(MainWindow);
	    WM_SendMessageNoPara(MainWindow, WM_Paint);



	    BSP_LED_Toggle(LED1);
}
}

/*************************** End of file ****************************/

/*
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart6){

	UARTRECIVER();

	LeftStream[699] = UARTDATA[6];

	for(int i=0; i<699;i++)
	{
		LeftStream[i] = LeftStream[i+1];
	}

	RightStream[699] = UARTDATA[7];

	for(int i=0; i<699;i++)
	{
		RightStream[i] = RightStream[i+1];
	}


}
*/


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart6){

	BSP_LED_Toggle(LED1);
   	UARTRECIVER(); //Recive Data from UART --> UARTDATA



	LeftStream[199] = adc2;

	for(int i=0; i<199;i++)
	{
		LeftStream[i] = LeftStream[i+1];
	}

	RightStream[199] = adc1;

	for(int i=0; i<199;i++)
	{
		RightStream[i] = RightStream[i+1];
	}



	newValueLeft = UARTDATA[6];
	newValueRight = UARTDATA[7];
	newValueLeftOUT = UARTDATA[10];
	newValueRightOUT = UARTDATA[11];

	if(maxValueLeft < newValueLeft){
		maxValueLeft = newValueLeft;
	}

	if(maxValueRight < newValueRight){
		maxValueRight = newValueRight;
	}

	if(maxValueLeftOUT < newValueLeftOUT){
		maxValueLeftOUT = newValueLeftOUT;
	}

	if(maxValueRightOUT < newValueRightOUT){
		maxValueRightOUT = newValueRightOUT;
	}


	int32_t INT;

		   /************Input Data to float**************/
		   INT = UARTDATA[15] 	|
		   		(UARTDATA[14] << 8) 	|
		   		(UARTDATA[13] << 16) 	|
		   		(UARTDATA[12] << 24);

		   memcpy(&test, &INT, sizeof(test));
		   leftIN = test;
		   /*********************************************/

		   /************Input Data to float**************/
		   INT = UARTDATA[19] 	|
		   		(UARTDATA[18] << 8) 	|
		   		(UARTDATA[17] << 16) 	|
		   		(UARTDATA[16] << 24);
		   memcpy(&test, &INT, sizeof(test));
		   rightIN = test;
		   /*********************************************/
			if(max_leftIN < leftIN){
				max_leftIN = leftIN;
			}
			if(max_rightIN < rightIN){
				max_rightIN = rightIN;
			}

			for(int i=0; i<100; i++){
				if (spectrum_max[i]<UARTDATA[i+50]){
					spectrum_max[i] = UARTDATA[i+50];
				}
			}



	if(reset == 1){

		rightDB = max_rightIN;
		leftDB =  max_leftIN;

		if(maxValueLeft==0){
		adc1 = 1;
		}
		else{
		adc1 = maxValueLeft;
		}
		if(maxValueRight==0){
		adc2 = 1;
		}
		else{
		adc2 = maxValueRight;
		}
		if(maxValueLeftOUT==0){
		adc3 = 1;
		}
		else{
		adc3 = maxValueLeftOUT;
		}
		if(maxValueRightOUT==0){
		adc4 = 1;
		}
		else{
		adc4 = maxValueRightOUT;
		}
		maxValueLeft = 0;
		maxValueRight = 0;
		maxValueLeftOUT = 0;
		maxValueRightOUT = 0;
		max_leftIN = -130.0;
		max_rightIN = -130.0;




		reset = 0;

	}




}


