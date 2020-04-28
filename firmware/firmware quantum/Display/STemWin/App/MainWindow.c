
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "stm32f4xx_hal.h"




static void _cbDialog(WM_MESSAGE * pMsg) {

  switch (pMsg->MsgId) {
  case WM_PAINT:
    break;
  default:
    WM_DefaultProc(pMsg);
  }


	  GUI_SetBkColor(GUI_TRANSPARENT);
	  GUI_Clear();
	  GUI_SetColor(GUI_BLUE);
	  GUI_SetFont(&GUI_Font32_1);
	  GUI_DispStringAt("MainWindow", 0, 0);
}


WM_HWIN CreateMainWindow(void) {

  WM_HWIN Window;

  Window = WM_CreateWindow(0, 0, 800, 480,WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
