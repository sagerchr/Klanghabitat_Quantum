
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "GuiElements/AudioMeter.h"
#include "GuiElements/Controlls.h"
#include "../tasks/SerialHandleTask/UART_IO.h"


//#include "recources/buttons/spectrum.h"



 #define GRAY          0x00000000

static void _cbDialog(WM_MESSAGE * pMsg) {


  switch (pMsg->MsgId) {
  case WM_PAINT:


	  GUI_SetBkColor(GUI_DARKGRAY);
	  GUI_Clear();

	  GUI_SetColor(GUI_LIGHTGRAY);

	  GUI_DrawRect(2, 2, 597, 297);
	  GUI_DrawRect(0, 0, 599, 299);



/*
	  GUI_DrawBitmap(&bmadd, 5, 105);
	  GUI_DrawBitmap(&bmadd, 105, 105);
	  GUI_DrawBitmap(&bmadd, 205, 105);
	  GUI_DrawBitmap(&bmadd, 305, 105);
*/
	  GUI_SetBkColor(GUI_GRAY);
	  GUI_DrawGradientH (10,100,140,180,GUI_GRAY, GUI_GRAY);
	  GUI_SetFont(&GUI_Font32B_1);
	  GUI_SetTextAlign (GUI_TA_HCENTER | GUI_TA_VCENTER);
	  GUI_DispStringAt  ("M/S", 75 ,140);


	  GUI_DrawGradientH (160,100,290,180,GUI_GRAY, GUI_GRAY);
	  GUI_DrawGradientH (310,100,440,180,GUI_GRAY, GUI_GRAY);
	  GUI_DrawGradientH (460,100,590,180,GUI_GRAY, GUI_GRAY);

	  GUI_SetColor(GUI_ORANGE);


    break;
  default:
    WM_DefaultProc(pMsg);
  }


  BSP_LED_Toggle(LED2);

}


WM_HWIN CreateSettingsWindow(void) {

  WM_HWIN SettingsWindow;

  SettingsWindow = WM_CreateWindow(100, -300, 600, 300, WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return SettingsWindow;
}
