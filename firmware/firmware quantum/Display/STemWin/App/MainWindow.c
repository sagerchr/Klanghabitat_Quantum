
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "GuiElements/AudioMeter.h"
#include "GuiElements/Controlls.h"
#include "../tasks/SerialHandleTask/UART_IO.h"



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

//////////////////////////DRAWING WAVEFORM////////////////////////
  int x1=345;
  int x=465;
  int y=-348;

  	  for(int i=200; i<400;i++){

		   GUI_SetColor( GUI_GRAY );
		   GUI_DrawHLine(y+(i*2),x1-RightStream[599-i], x1);

		   GUI_SetColor( GUI_GRAY );
		   GUI_DrawHLine(y+(i*2),x, x+LeftStream[599-i]);

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

 BSP_LED_Toggle(LED3); //Toggle LED to check Performance

}



WM_HWIN CreateMainWindow(void) {

  WM_HWIN Window;

  Window = WM_CreateWindow(0, 0, 1, 1,WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
