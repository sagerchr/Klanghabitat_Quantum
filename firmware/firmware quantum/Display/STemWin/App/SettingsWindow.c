
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "GuiElements/AudioMeter.h"
#include "GuiElements/Controlls.h"
#include "../tasks/SerialHandleTask/UART_IO.h"
#include "recources/buttons/spectrum.h"
#include "recources/buttons/network.h"
#include "recources/buttons/home.h"
#include "recources/buttons/back.h"
#include "recources/buttons/next.h"


static void _cbDialog(WM_MESSAGE * pMsg) {
	GUI_SetColor(GUI_GRAY);
	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("Settings",300,0);

  switch (pMsg->MsgId) {
  case WM_PAINT:
	  GUI_SetBkColor(GUI_DARKGRAY);
	  GUI_Clear();

	  drawControllBar(150, 100, pots[1],pots[1], "1" );
	  drawControllBar(150, 150, pots[2],pots[2], "1" );
	  drawControllBar(150, 200, pots[3],pots[3], "1" );
	  drawControllBar(150, 250, pots[4],pots[4], "1" );

	  int val = UARTDATA[6];
	  GUI_SetColor(GUI_LIGHTGRAY);
	  GUI_SetFont(&GUI_FontD24x32);
	  drawFloatNumber(400,80,pots[1],"","");
	  GUI_SetFont(&GUI_FontD24x32);
	  drawFloatNumber(400,130,pots[2],"","");
	  GUI_SetFont(&GUI_FontD24x32);
	  drawFloatNumber(400,180,pots[3],"","");
	  GUI_SetFont(&GUI_FontD24x32);
	  drawFloatNumber(400,230,pots[4],"","");

	  GUI_DrawBitmap(&bmback, 0, 0);
	  GUI_DrawBitmap(&bmnext, 520, 0);



	  GUI_DrawBitmap(&bmspectrum, 80, 270);
	  GUI_DrawBitmap(&bmnetwork, 320, 270);
	  GUI_DrawBitmap(&bmhome, 440, 270);


    break;
  default:
    WM_DefaultProc(pMsg);
  }


  BSP_LED_Toggle(LED2);

}


WM_HWIN CreateSettingsWindow(void) {

  WM_HWIN SettingsWindow;

  SettingsWindow = WM_CreateWindow(100, 480, 600, 350, WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return SettingsWindow;
}
