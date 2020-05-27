
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "GuiElements/AudioMeter.h"
#include "GuiElements/Controlls.h"
#include "../tasks/SerialHandleTask/UART_IO.h"
#include "valueTable.h"
int counterArray[100];
int counter=0;
int sum = 0;


int toggle=1;

int x2=345;
int x1=455;
int y=-348;
//int y=-52;



static void _cbDialog(WM_MESSAGE * pMsg) {

if(Enc_AttackSelected+
	Enc_ReleaseSelected+
	Enc_InputSelected+
	Enc_DistortionSelected+
	Enc_MakeUpGainSelected+
	Enc_OutputSelected+
	Enc_RatioSelected == 0){
	nothingSelected = 1;
}else{
	nothingSelected = 0;
}


//############################################################//
	WM_Invalidate(Enc_InputWindow);
	WM_Invalidate(Enc_AttackWindow);
	WM_Invalidate(Enc_OutputWindow);
	WM_Invalidate(Enc_DistortionWindow);
	WM_Invalidate(Enc_MakeUpGainWindow);
	WM_Invalidate(Enc_RatioWindow);
	WM_Invalidate(Enc_ReleaseWindow);
	WM_Invalidate(SettingsButtonWindow);
//############################################################//
	pMsg->MsgId = WM_USER;
	pMsg->Data.v = 0; //MEANS update color & value
 	WM_SendMessage (Enc_InputWindow, pMsg);
//############################################################//
 	pMsg->MsgId = WM_USER;
 	pMsg->Data.v = 0; //MEANS update color & value
 	WM_SendMessage (Enc_AttackWindow, pMsg);
//############################################################//
 	pMsg->MsgId = WM_USER;
 	pMsg->Data.v = 0; //MEANS update color & value
 	WM_SendMessage (Enc_OutputWindow, pMsg);
//############################################################//
 	pMsg->MsgId = WM_USER;
 	pMsg->Data.v = 0; //MEANS update color & value
 	WM_SendMessage (Enc_DistortionWindow, pMsg);
//############################################################//
 	pMsg->MsgId = WM_USER;
 	pMsg->Data.v = 0; //MEANS update color & value
 	WM_SendMessage (Enc_MakeUpGainWindow, pMsg);
//############################################################//
 	pMsg->MsgId = WM_USER;
 	pMsg->Data.v = 0; //MEANS update color & value
 	WM_SendMessage (Enc_RatioWindow, pMsg);
//############################################################//
 	pMsg->MsgId = WM_USER;
 	pMsg->Data.v = 0; //MEANS update color & value
 	WM_SendMessage (Enc_ReleaseWindow, pMsg);
//############################################################//

	  GUI_DCACHE_Clear(1);
	  GUI_Clear();
	  GUI_SetColor( GUI_LIGHTGRAY );



	  switch (pMsg->MsgId) {
	  	  case WM_PAINT:

	  		  break;
	  	  default:

	  		  WM_DefaultProc(pMsg);

  }






  //////////////////////////DRAWING WAVEFORM////////////////////////
   	 for(int i=200; i<400;i++){

   		 	 //GUI_SetColor( GUI_LIGHTGRAY );
  			 //GUI_DrawHLine(y+(i*2),x1, x1+inputRightStream[599-i]);
   		 	 //GUI_DrawHLine(y+(i*2),x2-inputLeftStream[599-i], x2);
/*
  			 GUI_SetColor( GUI_GRAY_AA);
  			 GUI_DrawHLine(y+(i*2),x1, x1+outputRightStream[599-i]);
  			 GUI_DrawHLine(y+(i*2),x2-outputLeftStream[599-i], x2);
*/
  	}





//INPUT INDICATOR///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
GUI_SetColor(GUI_LIGHTGRAY);
GUI_SetFont(&GUI_Font32_1);
GUI_DispStringAt("input", 222, 440);

GUI_SetFont(&GUI_Font20_1);

GUI_SetColor(GUI_GRAY);
GUI_GotoXY(210,20);
GUI_DispFloatMin(f_inputLeft_DB_MAXbufferd, 1);
GUI_GotoXY(260,20);
GUI_DispFloatMin(f_inputRight_DB_MAXbufferd, 1);

GUI_SetColor(GUI_LIGHTGRAY);
GUI_GotoXY(210,40);
GUI_DispFloatMin(f_inputLeft_DB_RMS_MAXbufferd, 1);
GUI_GotoXY(260,40);
GUI_DispFloatMin(f_inputRight_DB_RMS_MAXbufferd, 1);


drawBarDottedVertical (222, 440,(f_inputLeft_DB_MAXbufferd+30)*10,(f_inputLeft_DB_bufferd+30)*10,GUI_GRAY_AA,30);
drawBarDottedVertical (256, 440,(f_inputRight_DB_MAXbufferd+30)*10,(f_inputRight_DB_bufferd+30)*10,GUI_GRAY_AA,30);

drawBarDottedVertical (222, 440,(f_inputLeft_DB_RMS_MAXbufferd+30)*10,(f_inputLeft_DB_RMS_bufferd+30)*10,GUI_LIGHTGRAY,30);
drawBarDottedVertical (256, 440,(f_inputRight_DB_RMS_MAXbufferd+30)*10,(f_inputRight_DB_RMS_bufferd+30)*10,GUI_LIGHTGRAY,30);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//AFTER VCA INDICATOR/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
GUI_SetColor(GUI_LIGHTGRAY);
GUI_SetFont(&GUI_Font32_1);
GUI_DispStringAt("VCA", 348, 440);

GUI_SetFont(&GUI_Font20_1);

GUI_SetColor(GUI_GRAY);
GUI_GotoXY(336,20);
GUI_DispFloatMin(f_VCALeft_DB_MAXbufferd, 1);
GUI_GotoXY(386,20);
GUI_DispFloatMin(f_VCARight_DB_MAXbufferd, 1);

GUI_SetColor(GUI_LIGHTGRAY);
GUI_GotoXY(336,40);
GUI_DispFloatMin(f_VCALeft_DB_RMS_MAXbufferd, 1);
GUI_GotoXY(386,40);
GUI_DispFloatMin(f_VCARight_DB_RMS_MAXbufferd, 1);

 drawBarDottedVertical (348, 440,(f_VCALeft_DB_MAXbufferd+30)*10,(f_VCALeft_DB_bufferd+30)*10,GUI_GRAY_AA,30);
 drawBarDottedVertical (382, 440,(f_VCARight_DB_MAXbufferd+30)*10,(f_VCARight_DB_bufferd+30)*10,GUI_GRAY_AA,30);

 drawBarDottedVertical (348, 440,(f_VCALeft_DB_RMS_MAXbufferd+30)*10,(f_VCALeft_DB_RMS_bufferd+30)*10,GUI_LIGHTGRAY,30);
 drawBarDottedVertical (382, 440,(f_VCARight_DB_RMS_MAXbufferd+30)*10,(f_VCARight_DB_RMS_bufferd+30)*10,GUI_LIGHTGRAY,30);
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//OUTPUT INDICATOR///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 GUI_SetColor(GUI_LIGHTGRAY);
 GUI_SetFont(&GUI_Font32_1);
 GUI_DispStringAt("output", 480, 440);

 GUI_SetFont(&GUI_Font20_1);

 GUI_SetColor(GUI_GRAY);
 GUI_GotoXY(468,20);
 GUI_DispFloatMin(f_outputLeft_DB_MAXbufferd, 1);
 GUI_GotoXY(518,20);
 GUI_DispFloatMin(f_outputRight_DB_MAXbufferd, 1);

 GUI_SetColor(GUI_LIGHTGRAY);
 GUI_GotoXY(468,40);
 GUI_DispFloatMin(f_outputLeft_DB_RMS_MAXbufferd, 1);
 GUI_GotoXY(518,40);
 GUI_DispFloatMin(f_outputRight_DB_RMS_MAXbufferd, 1);

 drawBarDottedVertical (480, 440,(f_outputLeft_DB_MAXbufferd+30)*10,(f_outputLeft_DB_bufferd+30)*10,GUI_GRAY_AA,30);
 drawBarDottedVertical (514, 440,(f_outputRight_DB_MAXbufferd+30)*10,(f_outputRight_DB_bufferd+30)*10,GUI_GRAY_AA,30);

 drawBarDottedVertical (480, 440,(f_outputLeft_DB_RMS_MAXbufferd+30)*10,(f_outputLeft_DB_RMS_bufferd+30)*10,GUI_LIGHTGRAY,30);
 drawBarDottedVertical (514, 440,(f_outputRight_DB_RMS_MAXbufferd+30)*10,(f_outputRight_DB_RMS_bufferd+30)*10,GUI_LIGHTGRAY,30);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


 BSP_LED_Toggle(LED3); //Toggle LED to check Performance

}



WM_HWIN CreateMainWindow(void) {

  WM_HWIN Window;

  Window = WM_CreateWindow(0, 0, 1, 1,WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
