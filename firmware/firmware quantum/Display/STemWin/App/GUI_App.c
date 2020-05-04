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
extern  WM_HWIN CreateInfoWindow(void);
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
TIM_HandleTypeDef htim4;

int count=1;
void GRAPHICS_MainTask(void) {


  /* 2- Create a Window using GUIBuilder */



	GUI_Clear();
	  GUI_SetBkColor(GUI_DARKGRAY);


	  WM_HWIN MainWindow;
	  WM_HWIN SettingsWindow;
	  WM_HWIN InfoWindow;

	  InfoWindow = CreateInfoWindow();
	MainWindow = CreateMainWindow();
	SettingsWindow = CreateSettingsWindow();


/* USER CODE BEGIN GRAPHICS_MainTask */
 /* User can implement his graphic application here */
  /* Hello Word example */

/* USER CODE END GRAPHICS_MainTask */
	int SettingsVisable = 0;
	uint8_t wait=0;
	int slide=480;
	int raiser=50;

	int closestartscreen=0;
	int timer = 0;

	int valuechange=0;
	WM_ShowWindow (InfoWindow);



	  uint32_t lineStart,lineEnd;
	  uint32_t lineStart2,lineEnd2;
	  Waveform = 1;
	  HAL_TIM_Base_Start(&htim4);

  while(1)
{


	  BSP_LED_Toggle(LED1);
	  reset = 1;
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






	    if(TouchXCoordinate>450&&TouchXCoordinate<600&&TouchYCoordinate>300&&SettingsVisable==1){
	    	WM_MoveTo(SettingsWindow,100 , 480);
	    	slide =480;
	    	SettingsVisable = 0;
	    	valuechange = 0;
	    }
	    if(TouchXCoordinate>200&&TouchXCoordinate<250&&TouchYCoordinate>300&&SettingsVisable==1&&valuechange==0){
	    	if(Waveform==0){
	    		Waveform = 1;
	    		valuechange=1;
	    	}
	    	else{
	    		Waveform = 0;
	    		valuechange=1;
	    	}
	    }


	    if(TouchXCoordinate>0&&TouchXCoordinate<100&&TouchYCoordinate>150&&TouchYCoordinate<300 && SettingsVisable == 0){
	    	if(slide >= 100){
	    		slide-=raiser;
	    		raiser-=3;
	    	}
	    	WM_MoveWindow(SettingsWindow,0,-400);
	    	SettingsVisable = 1;
	    }

	    if (SettingsVisable == 1){
	    	WM_Invalidate(SettingsWindow);
		    WM_SendMessageNoPara(SettingsWindow, WM_Paint);
		    wait = 0;
		    WM_SetFocus(SettingsWindow);
	    }



	    WM_Invalidate(MainWindow);
	    WM_SendMessageNoPara(MainWindow, WM_Paint);

	    aTxBuffer[0]= 'T';
	  	aTxBuffer[1]= 'E';
	  	aTxBuffer[2]= 'S';
	  	aTxBuffer[3]= 'T';

	  	aTxBuffer[9]=10;

		  GUI_SetColor(GUI_LIGHTGRAY);
		  GUI_SetFont(&GUI_Font24B_1);
		  GUI_GotoXY(30,30);
		  GUI_DispFloatMin(TIM4->CNT, 1);







	    if(TouchDetected){
	    	touch++;
	    }
	    else{
	    	touch=0;
	    }

	    if (touch>20){
	    	timer = 0;
	    	WM_ShowWindow (InfoWindow);
	    	touch = 0;
	    }


	    wait++;
	    timer++;

	    if (timer>20){
	    	WM_HideWindow (InfoWindow);
	    }






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


  	if(TIM4->CNT>100){
	    switch (count) {
	    case 1:
			 HAL_I2C_Master_Transmit(&hi2c1, 40, aTxBuffer,10,10);
			 HAL_I2C_Master_Receive(&hi2c1, 40, aRxBuffer,10,10);
			 if(aRxBuffer[8]!=255) {pots[4]=aRxBuffer[7];}
			 if(aRxBuffer[9]!=255) {pots[3]=aRxBuffer[9];}
			 if(aRxBuffer[6]!=255) {buttonstateRight=aRxBuffer[6];}
	    	 count =2;
	     	 break;
	    case 2:
			 HAL_I2C_Master_Transmit(&hi2c1, 30, aTxBuffer,10,10);
			 HAL_I2C_Master_Receive(&hi2c1, 30, aRxBuffer,10,10);
			 if(aRxBuffer[8]!=255) {pots[2]=aRxBuffer[7];}
			 if(aRxBuffer[9]!=255) {pots[1]=aRxBuffer[9];}
			 if(aRxBuffer[6]!=255) {buttonstateLeft=aRxBuffer[6];}
	    	 count=3;
	     	 break;
	    case 3:
	    	BSP_TS_GetState(&TS_State);
	     	TouchXCoordinate = TS_State.touchX[0];
	     	TouchYCoordinate = TS_State.touchY[0];
	     	TouchDetected = TS_State.touchDetected;
	     	count=1;
	        break;
	    }
	    TIM4->CNT = 0;
  	}

   	UARTRECIVER(); //Recive Data from UART --> UARTDATA





    upcounter = UARTDATA[4];

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



	if(reset == 1 || (upcounter != upcounterLast)){

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



		BSP_LED_Toggle(LED1);
		reset = 0;

	}


	   int val 	= adc1;
	   int val2 =adc2;


	  if (val2 > val2buffered){
		  val2buffered = val2;
	  }
	  else {
		  val2buffered -=0.005*(val2buffered-val2);
	  }

	  if (val > val1buffered){
		  val1buffered = val;
	  }
	  else {
		  val1buffered -=0.005*(val1buffered-val);
	  }


	  if (val2 > val2MAXbuffered){
		  val2MAXbuffered = val2;
	  }
	  else {
		  val2MAXbuffered -=0.001*(val2MAXbuffered-val2);
	  }

	  if (val > val1MAXbuffered){
		  val1MAXbuffered = val;
	  }
	  else {
		  val1MAXbuffered -=0.001*(val1MAXbuffered-val);
	  }




if(upcounter != upcounterLast){
	LeftStream[399] = adc2;

	for(int i=0; i<399;i++)
	{
		LeftStream[i] = LeftStream[i+1];
	}

	RightStream[399] = adc1;

	for(int i=0; i<399;i++)
	{
		RightStream[i] = RightStream[i+1];
	}
	upcounterLast=upcounter;
}









}


