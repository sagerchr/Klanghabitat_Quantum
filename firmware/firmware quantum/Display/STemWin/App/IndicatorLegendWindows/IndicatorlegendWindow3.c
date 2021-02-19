
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "stm32f4xx_hal.h"


static void _cbDialog(WM_MESSAGE * pMsg) {

  switch (pMsg->MsgId) {
  case WM_CREATE:

    break;
  case WM_PAINT:
	  GUI_SetBkColor(GUI_BLACK);

	  GUI_Clear();
	  		for(int i=0; i<400;i++){
	  			GUI_SetColor(GUI_LIGHTGRAY);
	  			if(i % 25 == 0){
	  				GUI_DrawHLine(400-i-20,2,+12);
	  			}
	  			if(i % 50 == 0){
	  				GUI_DrawHLine(400-i-20+1,2,+12);
	  				GUI_DrawHLine(400-i-20,2,+12);
	  				GUI_DrawHLine(400-i-20-1,2,+12);

	  				GUI_GotoXY(20,400-i-20-5);
	  				GUI_DispFloatMin(((i-400-20+100)/10)+2, 1);


	  			}
	  		}

    break;
  default:
    WM_DefaultProc(pMsg);

	}

}


WM_HWIN CreateIndicatorWindow3(void) {



  IndicatorWindow3 = WM_CreateWindow(545, 60, 50, 390,WM_CF_HIDE , _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return IndicatorWindow3;
}
