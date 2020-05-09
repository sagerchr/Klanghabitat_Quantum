/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2020  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V6.10 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only  be used  in accordance  with  a license  and should  not be  re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : BUTTON_Usage.c
Purpose     : Sample that demonstrates the usage of a BUTTON widget.
Requirements: WindowManager - (x)
              MemoryDevices - ( )
              AntiAliasing  - ( )
              VNC-Server    - ( )
              PNG-Library   - ( )
              TrueTypeFonts - ( )
---------------------------END-OF-HEADER------------------------------
*/

#include "DIALOG.h"
#include <stdio.h>
#include "recources/buttons/menu.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_BUTTON  1
/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/


WM_HWIN ButtonWindow;
extern	WM_HWIN CreateDialog(WM_HWIN parent);
WM_HWIN Dialog;
int buttStatus=0;




static void _cbButton_spectrum(WM_MESSAGE * pMsg)
{

  switch (pMsg->MsgId)
  {
    /* Component repaint message */
    case WM_PAINT:
    	if(buttStatus == 0){
    		GUI_SetColor( GUI_GRAY );
    	}
    	else{
    		GUI_SetColor( GUI_ORANGE );
    	}
      GUI_DrawBitmap(&bmmenu, 0, 0);
      break;
    /* Default callback message */
    default:
      BUTTON_Callback(pMsg);
  }
}



static void _cbDialog(WM_MESSAGE * pMsg) {
  int           Id, NCode;
  BUTTON_Handle hButton;

  switch(pMsg->MsgId) {
  case WM_CREATE:
    //
    // Create a button as child of this window.
    //
    hButton = BUTTON_CreateEx(0, 0, 80, 80, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON);
    BUTTON_SetText(hButton, "Click me");
    WM_SetCallback(hButton, _cbButton_spectrum);
    break;
  case WM_PAINT:
    GUI_SetBkColor(GUI_DARKGRAY);
    GUI_Clear();
    break;
  case WM_NOTIFY_PARENT:
    //
    // Since the button is a child of this window, reacts on the button
    // are sent to its parent window.
    //
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    //
    // Check if notification was sent from the button.
    //
    switch(Id) {
    case ID_BUTTON:
      //
      // Check for the correct notification code.
      //
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
    	buttStatus = !buttStatus;
    	if(buttStatus){
    		Dialog = CreateDialog(ButtonWindow);
    	}
    	else{
    		WM_DeleteWindow(Dialog);
    	}
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      }
      break;
    }
    break;

   default:
    WM_DefaultProc(pMsg);
  }

}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/


WM_HWIN CreateSettingsButtonWindow(void) {



  ButtonWindow = WM_CreateWindow(50, 350, 80, 80, WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return ButtonWindow;
}
