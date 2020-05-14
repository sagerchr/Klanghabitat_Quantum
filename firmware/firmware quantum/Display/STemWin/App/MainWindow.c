
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




static void _cbDialog(WM_MESSAGE * pMsg) {
	  GUI_DCACHE_Clear(1);
	  GUI_Clear();
	  GUI_SetColor( GUI_LIGHTGRAY );
  switch (pMsg->MsgId) {
  case WM_PAINT:

	  break;
  default:
    WM_DefaultProc(pMsg);

  }
  GUI_SetColor(GUI_BLACK);
  GUI_DrawRect   (200, 52, 600, 450);
  //////////////////////////DRAWING WAVEFORM////////////////////////
   	 for(int i=200; i<400;i++){

   		 	 GUI_SetColor( GUI_GRAY );
  			 GUI_DrawHLine(y+(i*2),x1, x1+inputRightStream[599-i]);
   		 	 GUI_DrawHLine(y+(i*2),x2-inputLeftStream[599-i], x2);
/*
  			 GUI_SetColor( GUI_GRAY_AA);
  			 GUI_DrawHLine(y+(i*2),x1, x1+outputRightStream[599-i]);
  			 GUI_DrawHLine(y+(i*2),x2-outputLeftStream[599-i], x2);
*/
  	}
  //////////////////////////////////////////////////////////////////
	    GUI_SetColor(GUI_LIGHTGRAY);
	    GUI_SetFont(&GUI_Font24B_1);
		GUI_GotoXY(10,10);
		GUI_DispFloatMin(TIM4->CNT, 1);
	    GUI_DispStringAt("X:", 80, 10);
	    GUI_GotoXY(100,10);
	    GUI_DispFloatMin(TouchXCoordinate, 1);
	    GUI_GotoXY(200,10);
	    GUI_DispStringAt("Y:", 180, 10);
	    GUI_DispFloatMin(TouchYCoordinate, 1);
  /////////////////////////////////////////////////////////////////

/*
	    GUI_SetFont(&GUI_Font24B_1);
		GUI_GotoXY(360,25);
		if(f_outputLeft_DB_MAXbufferd>0){
			GUI_SetColor(GUI_LIGHTRED);
		}else{
			GUI_SetColor(GUI_GRAY);
		}
		GUI_DispFloatMin(f_outputLeft_DB_MAXbufferd, 1);
		GUI_GotoXY(410,25);
		if(f_outputRight_DB_MAXbufferd>0){
			GUI_SetColor(GUI_LIGHTRED);
		}else{
			GUI_SetColor(GUI_GRAY);
		}
		GUI_DispFloatMin(f_outputRight_DB_MAXbufferd, 1);
*/












	    GUI_SetColor(GUI_GRAY);
	    GUI_SetFont(&GUI_Font32B_1);

	    GUI_DispStringAt("inputLeft(peak):", 50, 20);
	    GUI_GotoXY(50,50);
	    GUI_DispFloatMin(f_inputLeft_DB_MAXbufferd, 2);
	    GUI_DispStringAt("inputRight(peak):", 50, 80);
	    GUI_GotoXY(50,110);
	    GUI_DispFloatMin(f_inputRight_DB_MAXbufferd, 2);

	    GUI_DispStringAt("VCALeft(peak):", 50, 140);
	    GUI_GotoXY(50,170);
	    GUI_DispFloatMin(f_VCALeft_DB_MAXbufferd, 2);
	    GUI_DispStringAt("VCARight(peak):", 50, 200);
	    GUI_GotoXY(50,230);
	    GUI_DispFloatMin(f_VCARight_DB_MAXbufferd, 2);

	    GUI_DispStringAt("outputLeft(peak):", 50, 260);
	    GUI_GotoXY(50,290);
	    GUI_DispFloatMin(f_outputLeft_DB_MAXbufferd, 2);
	    GUI_DispStringAt("outputRight(peak):", 50, 320);
	    GUI_GotoXY(50,350);
	    GUI_DispFloatMin(f_outputRight_DB_MAXbufferd, 2);




	    GUI_SetColor(GUI_GRAY);
	    GUI_SetFont(&GUI_Font32B_1);

	    GUI_DispStringAt("inputLeft(RMS):", 550, 20);
	    GUI_GotoXY(620,50);
	    GUI_DispFloatMin(f_inputLeft_DB_RMS, 2);
	    GUI_DispStringAt("inputRight(RMS):", 550, 80);
	    GUI_GotoXY(620,110);
	    GUI_DispFloatMin(f_inputRight_DB_RMS, 2);

	    GUI_DispStringAt("VCALeft(RMS):", 550, 140);
	    GUI_GotoXY(620,170);
	    GUI_DispFloatMin(f_VCALeft_DB_RMS, 2);
	    GUI_DispStringAt("VCARight(RMS):", 550, 200);
	    GUI_GotoXY(620,230);
	    GUI_DispFloatMin(f_VCARight_DB_RMS, 2);

	    GUI_DispStringAt("outputLeft(RMS):", 550, 260);
	    GUI_GotoXY(620,290);
	    GUI_DispFloatMin(f_outputLeft_DB_RMS, 2);
	    GUI_DispStringAt("outputRight(RMS):", 550, 320);
	    GUI_GotoXY(620,350);
	    GUI_DispFloatMin(f_outputRight_DB_RMS, 2);





		GUI_SetColor(GUI_GRAY);
		GUI_SetFont(&GUI_Font24B_1);
		GUI_GotoXY(100,40);
		GUI_DispFloatMin(pots[1], 1);
		GUI_GotoXY(100,60);
		GUI_DispFloatMin(pots[2], 1);
		GUI_GotoXY(100,80);
		GUI_DispFloatMin(pots[3], 1);
		GUI_GotoXY(100,100);
		GUI_DispFloatMin(pots[4], 1);


 drawBarDottedVertical (368, 440,(f_inputLeft_DB_MAXbufferd+40)*10,(f_inputLeft_DB_bufferd+40)*10,GUI_GRAY_AA,30);
 drawBarDottedVertical (402, 440,(f_inputRight_DB_MAXbufferd+40)*10,(f_inputRight_DB_bufferd+40)*10,GUI_GRAY_AA,30);

 drawBarDottedVertical (349, 440,i_outputLeft_Indicator_MAXbufferd,i_outputLeft_Indicator_bufferd,GUI_GRAY_AA,15);
 drawBarDottedVertical (436, 440,i_outputRight_Indicator_MAXbufferd,i_outputRight_Indicator_bufferd,GUI_GRAY_AA,15);
/*
 ArcControl(80,100,pots[1],"Attack");
 ArcControl(80,260,pots[2],"Ratio");

 ArcControl(720,100,pots[4],"Volume");
 ArcControl(720,260,pots[3],"Thresh");


 GUI_SetPenSize(30);
 GUI_SetColor(GUI_GRAY);

 static int radius = 500;

 GUI_SetPenSize(20);
 GUI_SetColor(GUI_GRAY);
 GUI_DrawArc(1080, 240, radius, radius, 156, 204);

 GUI_SetColor(GUI_ORANGE);
 GUI_DrawArc(1080, 240, radius, radius, 156+(250-pots[4]), 204);

 GUI_SetColor(GUI_GRAY);
 GUI_DrawArc(-280, 240, radius, radius, -24, 24);
 GUI_SetColor(GUI_ORANGE);
 GUI_DrawArc(-280, 240, radius, radius, -24+(250-pots[2]), 24);
*/
 BSP_LED_Toggle(LED3); //Toggle LED to check Performance

}



WM_HWIN CreateMainWindow(void) {

  WM_HWIN Window;

  Window = WM_CreateWindow(0, 0, 1, 1,WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
