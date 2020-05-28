
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "stm32f4xx_hal.h"
#include "recources/startscreen_quantum.h"
#include "GuiElements/AudioMeter.h"
#include "GuiElements/Controlls.h"

static int i = 0;

static void _cbDialog(WM_MESSAGE * pMsg) {

  switch (pMsg->MsgId) {
  case WM_PAINT:
	  GUI_DrawBitmap(&bmstartscreen_quantum, 0, 0);
	  	GUI_SetColor( GUI_WHITE );
	  	GUI_SetFont(&GUI_Font32B_1);
	  	GUI_DispStringAt("Version: 1.2",250,350);
	  	GUI_DispStringAt("IP Adress: 192.168.1.205",250,380);
    break;
  default:
    WM_DefaultProc(pMsg);
  }



}


WM_HWIN CreateInfoWindow(void) {

  WM_HWIN Window;

  Window = WM_CreateWindow(0, 0, 800, 480,WM_CF_SHOW , _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
