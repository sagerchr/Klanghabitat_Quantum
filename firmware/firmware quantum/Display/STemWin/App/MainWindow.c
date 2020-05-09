
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "GuiElements/AudioMeter.h"
#include "GuiElements/Controlls.h"
#include "../tasks/SerialHandleTask/UART_IO.h"





int start=0;
uint32_t lineStart,lineEnd;
uint32_t lineStart2,lineEnd2;
int x=700, y;

TS_StateTypeDef TS_State;

uint8_t runner = 0;



static void _cbDialog(WM_MESSAGE * pMsg) {

  switch (pMsg->MsgId) {
  case WM_PAINT:
	  break;
  default:
    WM_DefaultProc(pMsg);

  }
  	  GUI_DCACHE_Clear(0);


	  GUI_Clear();


GUI_SetColor( GUI_LIGHTGRAY );


/*
GUI_DrawGradientH (30,370,130,380,GUI_DARKGRAY, GUI_GRAY);
GUI_DrawGradientH (30,400,130,410,GUI_DARKGRAY, GUI_GRAY);
GUI_DrawGradientH (30,430,130,440,GUI_DARKGRAY, GUI_GRAY);
*/


  int x1=345;
  x=465;

 if(Waveform){

		y=-348;
		for(int i=200; i<400;i++){

		   GUI_SetColor( GUI_GRAY );
		   GUI_DrawHLine(y+(i*2),x1-RightStream[599-i], x1);

		   GUI_SetColor( GUI_GRAY );
		   GUI_DrawHLine(y+(i*2),x, x+LeftStream[599-i]);

		}


 }

 drawBarDottedVertical (350, 30,val1MAXbuffered/1,val1buffered/1);
 drawBarDottedVertical (410, 30,val2MAXbuffered/1,val2buffered/1);

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

 BSP_LED_Toggle(LED3);

}



WM_HWIN CreateMainWindow(void) {

  WM_HWIN Window;

  Window = WM_CreateWindow(0, 0, 1, 1,WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
