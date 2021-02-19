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
#include "BUFFERVALUE.h"


extern  WM_HWIN CreateMainWindow(void);
extern  WM_HWIN CreateInfoWindow(void);
extern  WM_HWIN CreateSettingsButtonWindow(void);
extern  WM_HWIN CreateIndicatorWindow1(void);
extern  WM_HWIN CreateIndicatorWindow2(void);
extern  WM_HWIN CreateIndicatorWindow3(void);

extern  WM_HWIN CreateEnc_InputWindow(void);
extern  WM_HWIN CreateEnc_AttackWindow(void);
extern  WM_HWIN CreateEnc_OutputWindow(void);
extern  WM_HWIN CreateEnc_ThresholdWindow(void);
extern  WM_HWIN CreateEnc_RatioWindow(void);
extern  WM_HWIN CreateEnc_MakeUpGainWindow(void);
extern  WM_HWIN CreateEnc_ReleaseWindow(void);

extern void TOUCHUPDATE();


UART_HandleTypeDef huart6;
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim4;


char checksum;
uint16_t checksum16;
int CheckSumOK = 0;


void GRAPHICS_MainTask(void) {


	//GUI_Clear();
	//GUI_SetBkColor(GUI_DARKGRAY);

/////////////////////////////////////////////////////////////////////////
////////CREATION OF ALL WINDOWS//////////////////////////////////////////
	InfoWindow = CreateInfoWindow();
	SettingsButtonWindow = CreateSettingsButtonWindow();
	IndicatorWindow1 = CreateIndicatorWindow1();
	IndicatorWindow2 = CreateIndicatorWindow2();
	IndicatorWindow3 = CreateIndicatorWindow3();

	Enc_InputWindow = CreateEnc_InputWindow();
	Enc_AttackWindow = CreateEnc_AttackWindow();
	Enc_OutputWindow = CreateEnc_OutputWindow();
	Enc_ThresholdWindow = CreateEnc_ThresholdWindow();
	Enc_MakeUpGainWindow = CreateEnc_MakeUpGainWindow();
	Enc_RatioWindow = CreateEnc_RatioWindow();
	Enc_ReleaseWindow = CreateEnc_ReleaseWindow();

	MainWindow = CreateMainWindow();

////////////////////////////////////////////////////////////////////////
///////////Show InfoWindow on Startup///////////////////////////////////
	WM_ShowWindow (InfoWindow);
////////////////////////////////////////////////////////////////////////

	int timer = 0;

	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_Base_Start(&htim4);

	strcpy( gain.name, "input");
	input.value = 0;
	input.Color = GUI_LIGHTGRAY;
	input.assignedPot = 0;

	strcpy( attack.name, "attack");
	attack.value = 0;
	attack.Color = GUI_LIGHTGREEN;
	attack.assignedPot = 1;
	Encoder1.Color = GUI_LIGHTGREEN;

	strcpy( makeUpGain.name, "makeUpGain");
	makeUpGain.value = 0;
	makeUpGain.Color = GUI_LIGHTGRAY;
	makeUpGain.assignedPot = 0 ;

	strcpy( release.name, "release");
	release.value = 0;
	release.Color = GUI_CYAN;
	release.assignedPot = 2;
	Encoder2.Color = GUI_CYAN;

	strcpy( ratio.name, "ratio");
	ratio.value = 0;
	ratio.Color = GUI_ORANGE;
	ratio.assignedPot = 4;
	Encoder4.Color = GUI_ORANGE;

	strcpy( distortion.name, "distortion");
	distortion.value = 0;
	distortion.Color = GUI_LIGHTGRAY;
	distortion.assignedPot = 0;

	strcpy( threshold.name, "threshold");
	threshold.value = 0;
	threshold.Color = GUI_MAGENTA;
	threshold.assignedPot = 3;
	Encoder3.Color = GUI_MAGENTA;

	strcpy( outputgain.name, "outgain");
	outputgain.value = 0;
	outputgain.Color = GUI_LIGHTGRAY;
	outputgain.assignedPot = 0;




  while(1)
  	  {


	  reset = 1; //Reset Input Buffer collection

	  for (int i=0; i<100;i++){
		  UART_TRANSFER[i]=0x00;
	  }


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
	    	GUI_Clear();
	    	GUI_SetBkColor(GUI_WHITE);
	    	WM_HideWindow (IndicatorWindow1);
	    	WM_HideWindow (IndicatorWindow2);
	    	WM_HideWindow (IndicatorWindow3);
	    	WM_HideWindow (SettingsButtonWindow);

	    	WM_HideWindow(Enc_InputWindow);
	    	WM_HideWindow(Enc_AttackWindow);
	    	WM_HideWindow(Enc_ReleaseWindow);

	    	WM_HideWindow(Enc_OutputWindow);
	    	WM_HideWindow(Enc_ThresholdWindow);
	    	WM_HideWindow(Enc_MakeUpGainWindow);
	    	WM_HideWindow(Enc_RatioWindow);

	    	WM_ShowWindow(InfoWindow);
	    	touch = 0;
	    	timer = 0;
	    }

	    if (timer==50){
	    	GUI_Clear();
	    	//GUI_SetBkColor(GUI_DARKGRAY);
	    	GUI_SetBkColor(GUI_BLACK);

	    	WM_ShowWindow(SettingsButtonWindow);
	    	WM_ShowWindow(IndicatorWindow1);
	    	WM_ShowWindow(IndicatorWindow2);
	    	WM_ShowWindow(IndicatorWindow3);

	    	WM_ShowWindow(Enc_InputWindow);
	    	WM_ShowWindow(Enc_AttackWindow);
	    	WM_ShowWindow(Enc_OutputWindow);
	    	WM_ShowWindow(Enc_ThresholdWindow);
	    	WM_ShowWindow(Enc_MakeUpGainWindow);
	    	WM_ShowWindow(Enc_RatioWindow);
	    	WM_ShowWindow(Enc_ReleaseWindow);

	    	WM_HideWindow(InfoWindow);


	    }

	    timer++;



	    if (UARTDATA[70] == 1){

	    	NVIC_SystemReset();
	    	HAL_Delay(1);

	    }

///////////////////////////////////////////////////////////////////
	    p_Bufferd = 0.01;
	    p_MAXBufferd = 0.001;

///////////////////ALWAYS Update Main Window///////////////////////
	   WM_Invalidate(MainWindow);
	   WM_SendMessageNoPara(MainWindow, WM_Paint);

	   UARTSENDER();

	   GUI_Delay(1);
	   HAL_UART_DMAResume(&huart6);
	   GUI_SetTimeSlice(1);
///////////////////////////////////////////////////////////////////

	}
}



int cnt=0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart6){


	UARTRECIVER(); //Recive Data from UART --> UARTDATA

	BSP_LED_Toggle(LED1);
	TOUCHUPDATE(); //Recive Data from Touchpanel and Encoder
	BUFFERVALUEUPDATE(); //create Buffered Values


	//Temporary assign pot to variabale

	pots[1] = Encoder1.value;
	pots[2] = Encoder2.value;
	pots[3] = Encoder3.value;
	pots[4] = Encoder4.value;



	input.value = 0;
	attack.value = Encoder1.value;
	release.value = Encoder2.value;
	distortion.value = 0;
	makeUpGain.value = 0;
	ratio.value = Encoder4.value;
	outputgain.value = 0;
	gain.value = 0;
	threshold.value = Encoder3.value;








    upcounter = UARTDATA[4]; //Watchdog coming from the MotherEngine is used to identify new Value

    //CheckSum check
    checksum = 0;
    checksum16 = 0;
    CheckSumOK = 0;

    for(int i = 0; i < 98; i++) {
    	checksum += UARTDATA[i];
    	checksum16 += UARTDATA[i];
    }

    if(((checksum16 & 0x00FF) == UARTDATA[98]) && ((checksum16 >> 8) == UARTDATA[99])){
    	CheckSumOK = 1;
    }
    else{
    	CheckSumOK = 0;

    }


    //if((upcounter != upcounterLast)){
	if((upcounter != upcounterLast)&&CheckSumOK){
	//************************NEW VALUES CAME IN**********************************//
	//***********Everything in this IF CASE should be done for new Values*********//


	//*******************!!!UPDATE  of all Float value!!!*************************//
	//****************************************************************************//


       	 	f_inputLeft_DB = createFloat(12);
			f_inputRight_DB = createFloat(16);
			f_VCALeft_DB = createFloat(20);
			f_VCARight_DB = createFloat(24);
			f_outputLeft_DB = createFloat(28);
			f_outputRight_DB = createFloat(32);
			f_inputLeft_DB_RMS = createFloat(36);
			f_inputRight_DB_RMS = createFloat(40);
			f_VCALeft_DB_RMS = createFloat(44);
			f_VCARight_DB_RMS = createFloat(48);
			f_outputLeft_DB_RMS = createFloat(52);
			f_outputRight_DB_RMS = createFloat(56);

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
/*
		VCALeftStream[399] = i_VCALeft_Waveform;
		for(int i=0; i<399;i++){VCALeftStream[i] = VCALeftStream[i+1];}

		VCARightStream[399] = i_VCALeft_Waveform;
		for(int i=0; i<399;i++){VCARightStream[i] = VCARightStream[i+1];}

		outputLeftStream[399] = i_outputLeft_Waveform;
		for(int i=0; i<399;i++){outputLeftStream[i] = outputLeftStream[i+1];}

		outputRightStream[399] = i_outputRight_Waveform;
		for(int i=0; i<399;i++){outputRightStream[i] = outputRightStream[i+1];}
*/
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





}


