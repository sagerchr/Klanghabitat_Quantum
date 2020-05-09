
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "stm32f4xx_hal.h"
#include "recources/buttons/spectrum.h"
#include "recources/buttons/network.h"
#include "recources/buttons/home.h"
#include "recources/buttons/back.h"
#include "recources/buttons/next.h"
#include "recources/buttons/add.h"
#include "recources/buttons/ok.h"
#include "main.h"
/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.40                          *
*        Compiled Jun 22 2017, 10:13:26                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_SpectrumButton  (GUI_ID_USER + 0x04)
#define ID_NetworkButton  (GUI_ID_USER + 0x05)
#define ID_addButton  (GUI_ID_USER + 0x06)
#define ID_okButton  (GUI_ID_USER + 0x07)
#define ID_TEXT_0  (GUI_ID_USER + 0x08)
#define ID_TEXT_1  (GUI_ID_USER + 0x09)
#define ID_TEXT_2  (GUI_ID_USER + 0x0A)
#define ID_TEXT_3  (GUI_ID_USER + 0x0C)
#define ID_TEXT_4  (GUI_ID_USER + 0x0B)


#define BackColour     0x33404040
// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/


/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 100, 120, 600,240, 0, 0x0, 0 },

  { BUTTON_CreateIndirect, "SpectrumButton", ID_SpectrumButton, 35, 80, 80, 80, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "NetworkButton", ID_NetworkButton, 185, 80, 80, 80, 0, 0x0, 0 },

  { BUTTON_CreateIndirect, "addButton", ID_addButton, 335, 80, 80, 80, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "okButton", ID_okButton, 485, 80, 80, 80, 0, 0x0, 0 },

  {TEXT_CreateIndirect, "Text", ID_TEXT_0, 0,20,600, 50, 0, 0x64, 0},

  {TEXT_CreateIndirect, "Text", ID_TEXT_1, 0,  180,150, 20, 0, 0x64, 0},
  {TEXT_CreateIndirect, "Text", ID_TEXT_2, 150,180,150, 20, 0, 0x64, 0},
  {TEXT_CreateIndirect, "Text", ID_TEXT_3, 300,180,150, 20, 0, 0x64, 0},
  {TEXT_CreateIndirect, "Text", ID_TEXT_4, 450,180,150, 20, 0, 0x64, 0},

  //PROGBAR_Handle PROGBAR_CreateIndirect(const GUI_WIDGET_CREATE_INFO * pCreateInfo, WM_HWIN hWinParent, int x0, int y0, WM_CALLBACK * cb);

  //BUTTON_Handle BUTTON_CreateIndirect(const GUI_WIDGET_CREATE_INFO * pCreateInfo, WM_HWIN hWinParent, int x0, int y0, WM_CALLBACK * cb);

  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _GetImageById
*/


int Button_spectrumState=0;
static void _cbButton_spectrum(WM_MESSAGE * pMsg)
{
  switch (pMsg->MsgId)
  {
    /* Component repaint message */
    case WM_PAINT:
    	if(!Button_spectrumState){
    		GUI_SetColor( GUI_LIGHTGRAY );
    	}
    	else{
    		GUI_SetColor( GUI_ORANGE );
    	}
      GUI_DrawBitmap(&bmspectrum, 0, 0);
      break;
    /* Default callback message */
    default:
      BUTTON_Callback(pMsg);
  }
}

int Button_NetworkState=0;
static void _cbButtonNetwork(WM_MESSAGE * pMsg)
{
  switch (pMsg->MsgId)
  {
    /* Component repaint message */
    case WM_PAINT:
    	if(!Button_NetworkState){
    		GUI_SetColor( GUI_LIGHTGRAY );
    	}
    	else{
    		GUI_SetColor( GUI_ORANGE );
    	}
      GUI_DrawBitmap(&bmnetwork, 0, 0);
      break;
    /* Default callback message */
    default:
      BUTTON_Callback(pMsg);
  }
}

int Button_addState=0;
static void _cbButton_add(WM_MESSAGE * pMsg)
{
  switch (pMsg->MsgId)
  {
    /* Component repaint message */
    case WM_PAINT:
    	if(!Button_addState){
    		GUI_SetColor( GUI_LIGHTGRAY );
    	}
    	else{
    		GUI_SetColor( GUI_ORANGE );
    	}
      GUI_DrawBitmap(&bmadd, 0, 0);
      break;
    /* Default callback message */
    default:
      BUTTON_Callback(pMsg);
  }
}


static void _cbButton_ok(WM_MESSAGE * pMsg)
{
  switch (pMsg->MsgId)
  {
    /* Component repaint message */
    case WM_PAINT:
    	if(!Button_okState){
    		GUI_SetColor( GUI_LIGHTGRAY );
    	}
    	else{
    		GUI_SetColor( GUI_ORANGE );
    	}
      GUI_DrawBitmap(&bmOK, 0, 0);
      break;
    /* Default callback message */
    default:
      BUTTON_Callback(pMsg);
  }
}
// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/

WM_HWIN parent;
static void _cbDialog(WM_MESSAGE * pMsg) {

  WM_HWIN      hItem;
  int          NCode;
  int          Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:

	hItem = WM_GetDialogItem(pMsg->hWin, ID_SpectrumButton);
	WM_SetCallback(hItem, _cbButton_spectrum);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_NetworkButton);
	WM_SetCallback(hItem, _cbButtonNetwork);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_addButton);
	WM_SetCallback(hItem, _cbButton_add);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_okButton);
	WM_SetCallback(hItem, _cbButton_ok);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(hItem, "MODE");
    TEXT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetFont(hItem, GUI_FONT_32B_1);
    TEXT_SetTextColor(hItem, GUI_LIGHTGRAY);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetText(hItem, "M/S");
    TEXT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetFont(hItem, GUI_FONT_32B_1);
    TEXT_SetTextColor(hItem, GUI_LIGHTGRAY);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetText(hItem, "Stereo");
    TEXT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetFont(hItem, GUI_FONT_32B_1);
    TEXT_SetTextColor(hItem, GUI_LIGHTGRAY);;

    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
    TEXT_SetText(hItem, "DualMono");
    TEXT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetFont(hItem, GUI_FONT_32B_1);
    TEXT_SetTextColor(hItem, GUI_LIGHTGRAY);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
    TEXT_SetText(hItem, "Bypass");
    TEXT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetFont(hItem, GUI_FONT_32B_1);
    TEXT_SetTextColor(hItem, GUI_LIGHTGRAY);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_PAINT:
		GUI_SetBkColor(GUI_DARKGRAY);
		GUI_Clear();
	break;

  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_SpectrumButton: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
    	  Button_spectrumState = !Button_spectrumState;
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)

    	  //buttonState= 0;
    	// USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)

    	  //buttonState= 0;
    	// USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_NetworkButton: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  Button_NetworkState = !Button_NetworkState;
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
    	  HAL_Delay(10);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_addButton: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)

    	  Button_addState = !Button_addState;
    	  /*
    	  hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    	  TEXT_SetFont(hItem, GUI_FONT_32B_1);
    	  TEXT_SetTextColor(hItem,GUI_WHITE);
    	  TEXT_SetText(hItem, "New string");
    	  */
    	  // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
    	  HAL_Delay(10);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_okButton: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  Button_okState =!Button_okState;
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)

        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
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
*       CreateWindow
*/

WM_HWIN CreateDialog(WM_HWIN parentRef) {
	parent = parentRef;
	WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);

  //DIALOG_SetBkColor(GUI_INVALID_COLOR);


  WM_Paint(hWin);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
