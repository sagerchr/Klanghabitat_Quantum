
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "stm32f4xx_hal.h"
#include "GuiElements/AudioMeter.h"
#include "GuiElements/Controlls.h"

static int i = 0;

static void _cbDialog(WM_MESSAGE * pMsg) {

  switch (pMsg->MsgId) {
  case WM_PAINT:
    break;
  default:
    WM_DefaultProc(pMsg);
  }


	  GUI_SetBkColor(GUI_BLUE);
	  GUI_Clear();
	  GUI_SetColor(GUI_GREEN);
	  GUI_SetFont(&GUI_Font32_1);
	  GUI_DispStringAt("Window2", i, 0);

	  drawControllBar(100,100, pots[1],pots[1], "ControllBar" );


	  if(i == 500) i=0;
	  i++;
}


WM_HWIN CreateWindow2(void) {

  WM_HWIN Window;

  Window = WM_CreateWindow(0, 100, 600, 200,WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
