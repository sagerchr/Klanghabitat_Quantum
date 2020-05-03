
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "GuiElements/AudioMeter.h"
#include "GuiElements/Controlls.h"
#include "../tasks/SerialHandleTask/UART_IO.h"
#include "recources/buttons/menu.h"

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
	  GUI_SetBkColor(GUI_DARKGRAY);
	  reset = 1;


GUI_SetColor( GUI_LIGHTGRAY );






//GUI_DrawBitmap(&bmmaintenance, 665, 8);
GUI_DrawBitmap(&bmmenu, 50, 210);



  int x1=380;
  x=452;
  y=-350;

 if(Waveform){
  	for(int i=100; i<200;i++){

  	   	 GUI_SetColor( GUI_GRAY );
  	   	 /*
  	   	 lineStart = y - (RightStream[i]/2);
  	     lineEnd = lineStart + (RightStream[i]);
  	     GUI_DrawVLine(x+(i*4),lineStart, lineEnd);

  		 lineStart2 = (480-y) - (LeftStream[i]/2);
  	     lineEnd2 = lineStart2 + (LeftStream[i]);
  	     GUI_DrawVLine(x+(i*4),lineStart2, lineEnd2);
  	     */

  	   GUI_DrawHLine(y+(i*4),x1-RightStream[299-i], x1);
  	   GUI_DrawHLine(y+(i*4),x, x+LeftStream[299-i]);



  	   }
 }


	  drawBarDottedVertical (360, 30,val1MAXbuffered/1,val1buffered/1);
	  drawBarDottedVertical (420, 30,val2MAXbuffered/1,val2buffered/1);




  //drawFloatNumber (400, 200, TouchDetected, "", "");

  //drawFloatNumber (300, 200, touch, "", "");

  //drawFloatNumber (20, 220, TouchXCoordinate, "", "");
  //drawFloatNumber (20, 260, TouchYCoordinate, "", "");

 ArcControl(100,400,pots[1],"Attack");
 ArcControl(100,100,pots[2],"Ratio");
 ArcControl(700,100,pots[4],"Volume");
 ArcControl(700,400,pots[3],"Thresh");




  BSP_LED_Toggle(LED3);
}









WM_HWIN CreateMainWindow(void) {

  WM_HWIN Window;

  Window = WM_CreateWindow(0, 0, 1, 1,WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
