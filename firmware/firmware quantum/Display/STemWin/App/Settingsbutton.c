
#include "main.h"
#include "DIALOG.h"
#include <stdio.h>
#include "recources/buttons/menu.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_SettingsButton  1




extern	WM_HWIN CreateSettingsDialog();

int SettingsButtonState=0;




static void _cbButton_spectrum(WM_MESSAGE * pMsg)
{

  switch (pMsg->MsgId)
  {
    /* Component repaint message */
    case WM_PAINT:
    	if(SettingsButtonState == 1){
    		GUI_SetColor( GUI_ORANGE );
    	}
    	else{
    		GUI_SetColor( GUI_GRAY );
    	}
      GUI_DrawBitmap(&bmmenu, 35, 35);
      break;
    /* Default callback message */
    default:
      BUTTON_Callback(pMsg);
  }
}


BUTTON_Handle hButton;
static void _cbSettingsButtonDialog(WM_MESSAGE * pMsg) {
  int           Id, NotificationCode;


  switch(pMsg->MsgId) {
//////////////////////////////////////////////////////////////////
  case WM_CREATE:
    hButton = BUTTON_CreateEx(0, 0, 150, 150, pMsg->hWin, WM_CF_SHOW, 0, ID_SettingsButton);
    WM_SetCallback(hButton, _cbButton_spectrum);
    break;
//////////////////////////////////////////////////////////////////
  case WM_PAINT:
    GUI_SetBkColor(GUI_DARKGRAY);
    GUI_Clear();
    break;
//////////////////////////////////////////////////////////////////
  case WM_NOTIFY_PARENT:
    //The Button will notify parent when it was clicked
    Id    = WM_GetId(pMsg->hWinSrc);
    NotificationCode = pMsg->Data.v;
    // Check if notification was sent from the button.
    switch(Id) {
    case ID_SettingsButton:
      // Check for the correct notification code.
      switch(NotificationCode) {
      case WM_NOTIFICATION_CLICKED:
    	  SettingsButtonState = !SettingsButtonState;

    	  if(SettingsButtonState){
    	      SettingsDialog = CreateSettingsDialog();
    	      BUTTON_SetState(hButton, 1);
    	    }
    	  else{
    	      WM_DeleteWindow(SettingsDialog);
    	      BUTTON_SetState(hButton, 0);
    	    }
        break;
      case WM_NOTIFICATION_RELEASED:

        break;
      }
      break;
    }
    break;
//////////////////////////////////////////////////////////////////
    case WM_USER:
    	//NotificationCode = pMsg->Data.v;
    	WM_DeleteWindow(SettingsDialog);
    	SettingsButtonState = !SettingsButtonState;
    	if(SettingsButtonState){SettingsDialog = CreateSettingsDialog();}
    	BUTTON_SetState(hButton, SettingsButtonState);

    break;
/////////////////////////////////////////////////////////////////
   default:
    WM_DefaultProc(pMsg);
  }

}


WM_HWIN CreateSettingsButtonWindow(void) {



  SettingsButtonWindow = WM_CreateWindow(15, 315, 150, 150, WM_CF_HIDE, _cbSettingsButtonDialog, 0);

  WM_MULTIBUF_Enable(1);

  return SettingsButtonWindow;
}
