#include "main.h"
#include "DIALOG.h"
#include <stdio.h>


#define ID_ENC_Button  1


static GUI_COLOR COLOR;
static GUI_COLOR TEXTCOLOR;
BUTTON_Handle hButton;
static int value;
static uint8_t radius;
Enc_MakeUpGainSelected=0;

static void _cbENC_Button(WM_MESSAGE * pMsg)
{

  switch (pMsg->MsgId)
  {
    /* Component repaint message */
    case WM_PAINT:
    	if(Enc_MakeUpGainSelected == 1){
    			COLOR = GUI_GRAY;
    	    	}
    	    	else{
    	    	COLOR = GUI_DARKGRAY;
    	    	}


      break;
    /* Default callback message */
    default:
      BUTTON_Callback(pMsg);
  }
}




static void _cbDialog(WM_MESSAGE * pMsg) {
  int           Id, NotificationCode;


  switch(pMsg->MsgId) {
//////////////////////////////////////////////////////////////////
  case WM_CREATE:
   hButton = BUTTON_CreateEx(0, 0, 180, 100, pMsg->hWin, WM_CF_SHOW, 0, ID_ENC_Button);
   WM_SetCallback(hButton, _cbENC_Button);



    break;
//////////////////////////////////////////////////////////////////
  case WM_PAINT:

  	GUI_SetBkColor(COLOR);
  	GUI_Clear();



    GUI_SetColor(TEXTCOLOR);
    GUI_SetFont(&GUI_Font32B_1);
    GUI_DispStringAt("make up gain", 0, 0);
    GUI_SetFont(&GUI_FontD36x48);
    GUI_GotoXY(0,30);
    GUI_DispFloatMin(value, 1);



    break;
//////////////////////////////////////////////////////////////////
  case WM_NOTIFY_PARENT:
    //The Button will notify parent when it was clicked
    Id    = WM_GetId(pMsg->hWinSrc);
    NotificationCode = pMsg->Data.v;
    // Check if notification was sent from the button.
    switch(Id) {
    case ID_ENC_Button:
      // Check for the correct notification code.
      switch(NotificationCode) {
      case WM_NOTIFICATION_CLICKED:

	  	  //###########################KILL OTHER WINDOW SELCETION FIRST IF ONE IS SELCTED######################################//
		  if 	  (Enc_AttackSelected)		{pMsg->Data.v = 1; pMsg->MsgId = WM_USER;  WM_SendMessage (Enc_AttackWindow, pMsg);}
		  else if (Enc_DistortionSelected)	{pMsg->Data.v = 1; pMsg->MsgId = WM_USER;  WM_SendMessage (Enc_DistortionWindow, pMsg);}
		  //else if (Enc_MakeUpGainSelected)	{pMsg->Data.v = 1; pMsg->MsgId = WM_USER;  WM_SendMessage (Enc_MakeUpGainWindow, pMsg);}
		  else if (Enc_OutputSelected)		{pMsg->Data.v = 1; pMsg->MsgId = WM_USER;  WM_SendMessage (Enc_OutputWindow, pMsg);}
		  else if (Enc_RatioSelected)		{pMsg->Data.v = 1; pMsg->MsgId = WM_USER;  WM_SendMessage (Enc_RatioWindow, pMsg);}
		  else if (Enc_ReleaseSelected)		{pMsg->Data.v = 1; pMsg->MsgId = WM_USER;  WM_SendMessage (Enc_ReleaseWindow, pMsg);}
		  else if (Enc_InputSelected)		{pMsg->Data.v = 1; pMsg->MsgId = WM_USER;  WM_SendMessage (Enc_InputWindow, pMsg);}
		  //####################################################################################################################//



    	  Enc_MakeUpGainSelected = !Enc_MakeUpGainSelected;

    	  if(Enc_MakeUpGainSelected){

    	      BUTTON_SetState(hButton, 1);
    	    }
    	  else{

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
    	//#########UPDATE Color & value#############//
		if(pMsg->Data.v==0){
			TEXTCOLOR = makeUpGain.Color;
		    value = makeUpGain.value;
		}
		//#########################################//

		//#########Remote unselect#################//
		else if(pMsg->Data.v==1){
			Enc_MakeUpGainSelected = !Enc_MakeUpGainSelected;
			BUTTON_SetState(hButton, Enc_MakeUpGainSelected);
		}
		//#########################################//

    break;
/////////////////////////////////////////////////////////////////
   default:
    WM_DefaultProc(pMsg);
  }
}


WM_HWIN CreateEnc_MakeUpGainWindow(void) {

	Enc_MakeUpGainWindow = WM_CreateWindow(600, 130, 180, 100, WM_CF_HIDE, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Enc_MakeUpGainWindow;
}

