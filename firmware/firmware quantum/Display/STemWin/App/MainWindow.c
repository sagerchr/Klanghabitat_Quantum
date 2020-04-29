
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

	  GUI_Clear();
	  GUI_SetBkColor(GUI_DARKGRAY);

  GUI_SetColor(GUI_WHITE);
  GUI_SetFont(&GUI_Font32_1);

  //GUI_DispStringAt("Window1", i, 50);

  drawBarHorizontal (200,200, (float)UARTDATA[6],(float)UARTDATA[6], "test", 1);
  drawControllBar(100,300, pots[2],pots[2], "ControllBar" );
  drawControllBar(500,300, pots[4],pots[4], "ControllBar" );


}


WM_HWIN CreateMainWindow(void) {

  WM_HWIN Window;

  Window = WM_CreateWindow(0, 0, 800, 480,WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
