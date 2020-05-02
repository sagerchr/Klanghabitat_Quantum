
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "GuiElements/AudioMeter.h"
#include "GuiElements/Controlls.h"
#include "../tasks/SerialHandleTask/UART_IO.h"
#include "recources/startscreen_quantum.h"
#include "recources/buttons/maintenance/maintenance_active.h"
#include "recources/buttons/maintenance/maintenance_inactive.h"
#include "recources/buttons/maintenance/maintenance.h"

int start=0;
uint32_t lineStart,lineEnd;
uint32_t lineStart2,lineEnd2;
int x=700, y;



float val2buffered=0;
float val1buffered=0;
float val2MAXbuffered=0;
float val1MAXbuffered=0;
uint8_t runner = 0;
static void _cbDialog(WM_MESSAGE * pMsg) {

  switch (pMsg->MsgId) {
  case WM_PAINT:
    break;
  default:
    WM_DefaultProc(pMsg);
    reset = 1;
  }
  	  GUI_DCACHE_Clear(0);
	  GUI_Clear();
	  GUI_SetBkColor(GUI_DARKGRAY);

if(TouchYCoordinate<150){
	GUI_DrawBitmap(&bmstartscreen_quantum, 0, 0);
	GUI_SetColor( GUI_WHITE );
	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("Version: 1.2",250,350);
	GUI_DispStringAt("IP Adress: 192.168.1.205",250,380);
}

else {




x=0;
y= 160;



GUI_SetColor( GUI_LIGHTGRAY );

for(int i=0; i<200;i++){

   	 GUI_SetColor( GUI_LIGHTGRAY );
	 lineStart = y - (RightStream[i]/2);
     lineEnd = lineStart + (RightStream[i]);
     GUI_DrawVLine(x+(i*4),lineStart, lineEnd);

	 lineStart2 = (480-y) - (LeftStream[i]/2);
     lineEnd2 = lineStart2 + (LeftStream[i]);
     GUI_DrawVLine(x+(i*4),lineStart2, lineEnd2);

   }

GUI_DrawBitmap(&bmmaintenance, 50, 350);

   int val 	= adc1;
   int val2 =adc2;


  drawControllBar(10, 400, pots[1],pots[1], "1" );
  drawControllBar(10, 450, pots[2],pots[2], "1" );
  drawControllBar(410, 400, pots[3],pots[3], "1" );
  drawControllBar(410, 450, pots[4],pots[4], "1" );



  if (val2 > val2buffered){
	  val2buffered = val2;
  }
  else {
	  val2buffered -=0.05*(val2buffered-val2);
  }

  if (val > val1buffered){
	  val1buffered = val;
  }
  else {
	  val1buffered -=0.05*(val1buffered-val);
  }


  if (val2 > val2MAXbuffered){
	  val2MAXbuffered = val2;
  }
  else {
	  val2MAXbuffered -=0.01*(val2MAXbuffered-val2);
  }

  if (val > val1MAXbuffered){
	  val1MAXbuffered = val;
  }
  else {
	  val1MAXbuffered -=0.01*(val1MAXbuffered-val);
  }

  drawBarDotted (20, 10,val1MAXbuffered/2,val1buffered/2);
  drawBarDotted (20, 75,val2MAXbuffered/2,val2buffered/2);




  BSP_LED_Toggle(LED3);
}


}






WM_HWIN CreateMainWindow(void) {

  WM_HWIN Window;

  Window = WM_CreateWindow(0, 0, 1, 1,WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
