
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "stm32f4xx_hal.h"

static int i = 0;

static void _cbDialog(WM_MESSAGE * pMsg) {

  switch (pMsg->MsgId) {
  case WM_PAINT:
    break;
  default:
    WM_DefaultProc(pMsg);
  }


	  GUI_SetBkColor(GUI_GREEN);
	  GUI_Clear();
	  GUI_SetColor(GUI_BLUE);
	  GUI_SetFont(&GUI_Font32_1);
	  GUI_DispStringAt("Window3", i, 0);
	  if(i == 500) i=0;
	  i++;
}


WM_HWIN CreateWindow3(WM_HWIN *hWinParent) {

  WM_HWIN Window;

  Window = WM_CreateWindowAsChild(100, 0, 400, 50, *hWinParent, WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
