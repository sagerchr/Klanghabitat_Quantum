  /**
  ******************************************************************************
  * @file    GUI_App.c
  * @author  MCD Application Team
  * @brief   Simple demo drawing "Hello world"  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright © 2018 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
#include "GUI_App.h"
#include "GUI.h"
#include "usb_device.h"
#include "DIALOG.h"
//extern  WM_HWIN CreateWindow(void);
  

//void GRAPHICS_MainTask(void) {
  /* 2- Create a Window using GUIBuilder */
  //CreateWindow();
/* USER CODE BEGIN GRAPHICS_MainTask */
 /* User can implement his graphic application here */
  /* Hello Word example */
    //GUI_Clear();
    //GUI_SetColor(GUI_BLUE);
    //GUI_SetFont(&GUI_Font32_1);
    //GUI_DispStringAt("Hello world!", (LCD_GetXSize()-150)/2, (LCD_GetYSize()-20)/2);
/*
void MainTask(void) {

   GUI_Clear();
   GUI_SetColor(GUI_BLUE);
   GUI_SetFont(&GUI_Font32_1);
   GUI_DispStringAt("Hello world!", (LCD_GetXSize()-150)/2, (LCD_GetYSize()-20)/2);

   while (1) {
    GUI_Delay(250);
    GUI_Clear();
    GUI_SetColor(GUI_BLUE);
    GUI_SetFont(&GUI_Font32_1);
    GUI_DispStringAt("Hello world!", (LCD_GetXSize()-150)/2, (LCD_GetYSize()-20)/2);
  }

}

*/

uint8_t Value;



static void _cbWin(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  case WM_PAINT:
    GUI_SetBkColor(GUI_WHITE);
    GUI_Clear();
    GUI_AA_SetFactor(10);
    GUI_SetColor(GUI_BLACK);
    GUI_AA_SetFactor(10);
    GUI_SetFont(&GUI_Font32_1);
    GUI_AA_SetFactor(10);
    GUI_DispDecAt(Value, 400, 240, 3);
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

void CDC_ReceiveCallBack(uint8_t *buf, uint32_t len){
Value = (int) &buf;
}


void MainTask(void) {



  WM_HWIN hWin;
  GUI_Init();
  hWin = WM_CreateWindow(0, 0, 800, 480, WM_CF_SHOW, _cbWin, 0);

  while (1) {
	  GUI_Delay(50);
	  WM_Invalidate(hWin);
    //Value = (Value > 100) ? 0 : Value + 1;
  }

}

/*************************** End of file ****************************/


/* USER CODE END GRAPHICS_MainTask */



/*************************** End of file ****************************/
