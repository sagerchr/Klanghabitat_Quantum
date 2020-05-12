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
#include "valueTable.h"
#include "SerialServer.h"

extern  WM_HWIN CreateMainWindow(void);
extern  WM_HWIN CreateInfoWindow(void);
extern  WM_HWIN CreateSettingsButtonWindow(void);
extern void TOUCHUPDATE();

UART_HandleTypeDef huart6;
TIM_HandleTypeDef htim4;
TS_StateTypeDef ts;





int pass = 0;

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

int trans;
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim4;

GUI_RECT pRect = {200,0,600,480};
int done = 0;


GUI_HMEM hSpline;



void GRAPHICS_MainTask(void) {


	GUI_Clear();
	GUI_SetBkColor(GUI_DARKGRAY);

/////////////////////////////////////////////////////////////////////////
////////CREATION OF ALL WINDOWS//////////////////////////////////////////
	InfoWindow = CreateInfoWindow();
	SettingsButtonWindow = CreateSettingsButtonWindow();
	MainWindow = CreateMainWindow();


////////////////////////////////////////////////////////////////////////
///////////Show InfoWindow on Startup///////////////////////////////////
	WM_ShowWindow (InfoWindow);
////////////////////////////////////////////////////////////////////////

	int timer = 0;

	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_Base_Start(&htim4);

  while(1)
  	  {


	  reset = 1; //Reset Input Buffer collection

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
      UART_TRANSFER[10]=Button_okState;
      UART_TRANSFER[11]=0x00;
      UART_TRANSFER[12]=0x02;//8
	  UART_TRANSFER[13]=0x03;//9

///////////////INFO-WINDOW SHOW HANDLER//////////////////////////////
	    if(TouchDetected){touch++;}
	    else{touch=0;}

	    if (touch>50){

	    	WM_HideWindow (SettingsButtonWindow);
	    	WM_ShowWindow (InfoWindow);
	    	touch = 0;
	    	timer = 0;
	    }

	    if (timer>20){
	    	WM_HideWindow (InfoWindow);
	    	WM_ShowWindow(SettingsButtonWindow);
	    }
	    timer++;
///////////////////////////////////////////////////////////////////


///////////////////ALWAYS Update Main Window///////////////////////
	   WM_Invalidate(MainWindow);
	   WM_SendMessageNoPara(MainWindow, WM_Paint);
	   GUI_Delay(1);
	   GUI_SetTimeSlice(1);
///////////////////////////////////////////////////////////////////
	   BSP_LED_Toggle(LED1);
	}
}




int val1;
int val2;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart6){

	TOUCHUPDATE(); //Recive Data from Touchpanel and Encoder
	UARTRECIVER(); //Recive Data from UART --> UARTDATA

    upcounter = UARTDATA[4]; //Watchdog coming from the MotherEngine is used to identify new Value

	if(reset||(upcounter != upcounterLast)){
	//************************NEW VALUES CAME IN**********************************//
	//***********Everything in this IF CASE should be done for new Values*********//


	//*******************!!!UPDATE  of all Float value!!!*************************//
	//****************************************************************************//

		f_inputLeft_DB = createFloat(12);
		f_inputRight_DB = createFloat(16);

		f_VCALeft_DB = createFloat(20); //Array Address needs to be defined/changed
		f_VCARight_DB = createFloat(24);

		f_outputLeft_DB = createFloat(28); //Array Address needs to be defined/changed
		f_outputRight_DB = createFloat(32);

	//****************************************************************************//
	//*******************!!!UPDATE Waveform!!!************************************//
	//****************************************************************************//
		i_inputLeft_Waveform = UARTDATA[6];
		i_inputRight_Waveform = UARTDATA[7];
		i_VCALeft_Waveform = UARTDATA[8];
		i_VCALeft_Waveform = UARTDATA[9];
		i_outputLeft_Waveform = UARTDATA[10];
		i_outputRight_Waveform = UARTDATA[11];

		inputLeftStream[399] = i_inputLeft_Waveform;
		for(int i=0; i<399;i++){inputLeftStream[i] = inputLeftStream[i+1];}

		inputRightStream[399] = i_inputRight_Waveform;
		for(int i=0; i<399;i++){inputRightStream[i] = inputRightStream[i+1];}

		VCALeftStream[399] = i_VCALeft_Waveform;
		for(int i=0; i<399;i++){VCALeftStream[i] = VCALeftStream[i+1];}

		VCARightStream[399] = i_VCALeft_Waveform;
		for(int i=0; i<399;i++){VCARightStream[i] = VCARightStream[i+1];}

		outputLeftStream[399] = i_outputLeft_Waveform;
		for(int i=0; i<399;i++){outputLeftStream[i] = outputLeftStream[i+1];}

		outputRightStream[399] = i_outputRight_Waveform;
		for(int i=0; i<399;i++){outputRightStream[i] = outputRightStream[i+1];}

	//****************************************************************************//
	//*******************!!!UPDATE INDICATOR!!!***********************************//
	//****************************************************************************//

		i_inputLeft_Indicator = UARTDATA[6];
		i_inputRight_Indicator = UARTDATA[7];
		i_VCALeft_Indicator = UARTDATA[8];
		i_VCARight_Indicator = UARTDATA[9];
		i_outputLeft_Indicator = UARTDATA[10];
		i_outputRight_Indicator = UARTDATA[11];

	reset = 0;
	upcounterLast = upcounter;

	}


	  if (i_inputLeft_Indicator > i_inputLeft_Indicator_bufferd){i_inputLeft_Indicator_bufferd = i_inputLeft_Indicator;}
	  else {i_inputLeft_Indicator_bufferd -=0.005*(i_inputLeft_Indicator_bufferd-i_inputLeft_Indicator);}

	  if (i_inputLeft_Waveform > i_inputLeft_Indicator_MAXbufferd){i_inputLeft_Indicator_MAXbufferd = i_inputLeft_Indicator;}
	  else {i_inputLeft_Indicator_MAXbufferd -=0.001*(i_inputLeft_Indicator_MAXbufferd-i_inputLeft_Indicator);}


	  if (i_inputRight_Indicator > i_inputRight_Indicator_bufferd){i_inputRight_Indicator_bufferd = i_inputRight_Indicator;}
	  else {i_inputRight_Indicator_bufferd -=0.005*(i_inputRight_Indicator_bufferd-i_inputRight_Indicator);}

	  if (i_inputRight_Indicator > i_inputRight_Indicator_MAXbufferd){i_inputRight_Indicator_MAXbufferd = i_inputRight_Indicator;}
	  else {i_inputRight_Indicator_MAXbufferd -=0.001*(i_inputRight_Indicator_MAXbufferd-i_inputRight_Indicator);}


	  if (i_outputLeft_Indicator > i_outputLeft_Indicator_bufferd){i_outputLeft_Indicator_bufferd = i_outputLeft_Indicator;}
	  else {i_outputLeft_Indicator_bufferd -=0.005*(i_outputLeft_Indicator_bufferd-i_outputLeft_Indicator);}

	  if (i_outputLeft_Indicator> i_outputLeft_Indicator_MAXbufferd){i_outputLeft_Indicator_MAXbufferd = i_outputLeft_Indicator;}
	  else {i_outputLeft_Indicator_MAXbufferd -=0.001*(i_outputLeft_Indicator_MAXbufferd-i_outputLeft_Indicator);}


	  if (i_outputRight_Indicator > i_outputRight_Indicator_bufferd){i_outputRight_Indicator_bufferd = i_outputRight_Indicator;}
	  else {i_outputRight_Indicator_bufferd -=0.005*(i_outputRight_Indicator_bufferd-i_outputRight_Indicator);}

	  if (i_outputRight_Indicator > i_outputRight_Indicator_MAXbufferd){i_outputRight_Indicator_MAXbufferd = i_outputRight_Indicator;}
	  else {i_outputRight_Indicator_MAXbufferd -=0.001*(i_outputRight_Indicator_MAXbufferd-i_outputRight_Indicator);}



/////////INPUT LEFT
	  if (f_inputLeft_DB > f_inputLeft_DB_bufferd){f_inputLeft_DB_bufferd = f_inputLeft_DB;}
	  else {f_inputLeft_DB_bufferd -=0.01*(f_inputLeft_DB_bufferd-f_inputLeft_DB);}

	  if (f_inputLeft_DB > f_outputLeft_DB_bufferd){f_inputLeft_DB_MAXbufferd = f_inputLeft_DB;}
	  else {f_inputLeft_DB_MAXbufferd -=0.005*(f_inputLeft_DB_MAXbufferd-f_inputLeft_DB);}
/////////INPUT RIGHT
	  if (f_inputRight_DB > f_inputRight_DB_bufferd){f_inputRight_DB_bufferd = f_inputRight_DB;}
	  else {f_inputRight_DB_bufferd -=0.01*(f_inputRight_DB_bufferd-f_inputRight_DB);}

	  if (f_inputRight_DB > f_inputRight_DB_bufferd){f_inputRight_DB_MAXbufferd = f_inputRight_DB;}
	  else {f_inputRight_DB_MAXbufferd -=0.005*(f_inputRight_DB_MAXbufferd-f_inputRight_DB);}

/////////VCA LEFT
	  if (f_VCALeft_DB > f_VCALeft_DB_bufferd){f_VCALeft_DB_bufferd = f_VCALeft_DB;}
	  else {f_VCALeft_DB_bufferd -=0.01*(f_VCALeft_DB_bufferd-f_VCALeft_DB);}

	  if (f_VCALeft_DB > f_VCALeft_DB_bufferd){f_VCALeft_DB_MAXbufferd = f_VCALeft_DB;}
	  else {f_VCALeft_DB_MAXbufferd -=0.005*(f_VCALeft_DB_MAXbufferd-f_VCALeft_DB);}
/////////VCA RIGHT
	  if (f_VCARight_DB > f_VCARight_DB_bufferd){f_VCARight_DB_bufferd = f_VCARight_DB;}
	  else {f_VCARight_DB_bufferd -=0.01*(f_VCARight_DB_bufferd-f_VCARight_DB);}

	  if (f_VCARight_DB > f_VCARight_DB_bufferd){f_VCARight_DB_MAXbufferd = f_VCARight_DB;}
	  else {f_VCARight_DB_MAXbufferd -=0.005*(f_VCARight_DB_MAXbufferd-f_VCARight_DB);}

/////////OUTPUT LEFT
	  if (f_outputLeft_DB > f_outputLeft_DB_bufferd){f_outputLeft_DB_bufferd = f_outputLeft_DB;}
	  else {f_inputLeft_DB_bufferd -=0.001*(f_inputLeft_DB_bufferd-f_inputLeft_DB);}

	  if (f_outputLeft_DB > f_outputLeft_DB_bufferd){f_outputLeft_DB_MAXbufferd = f_outputLeft_DB;}
	  else {f_outputLeft_DB_MAXbufferd -=0.005*(f_outputLeft_DB_MAXbufferd-f_outputLeft_DB);}
/////////OUTPUT RIGHT
	  if (f_outputRight_DB > f_outputRight_DB_bufferd){f_outputRight_DB_bufferd = f_outputRight_DB;}
	  else {f_outputRight_DB_bufferd -=0.01*(f_outputRight_DB_bufferd-f_outputRight_DB);}

	  if (f_outputRight_DB > f_outputRight_DB_bufferd){f_outputRight_DB_MAXbufferd = f_outputRight_DB;}
	  else {f_outputRight_DB_MAXbufferd -=0.005*(f_outputRight_DB_MAXbufferd-f_outputRight_DB);}





}


