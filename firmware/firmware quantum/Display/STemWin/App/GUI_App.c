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

#include "DIALOG.h"
#include "main.h"

extern  WM_HWIN CreateMainWindow(void);
extern  WM_HWIN CreateWindow1(void);
extern  WM_HWIN CreateWindow2(void);
extern  WM_HWIN CreateWindow3(WM_HWIN *hWinParent);
TS_StateTypeDef TS_State;
int X=0;
int Y=0;

void GRAPHICS_MainTask(void) {


  /* 2- Create a Window using GUIBuilder */




	  GUI_SetBkColor(GUI_WHITE);
	  GUI_Clear();

	WM_HWIN MainWindow;
	WM_HWIN Window1;
	WM_HWIN Window2;
	WM_HWIN Window3;

	MainWindow = CreateMainWindow();
	Window2 = CreateWindow2();
	Window1 = CreateWindow1();
	Window3 = CreateWindow3(&Window1);
/* USER CODE BEGIN GRAPHICS_MainTask */
 /* User can implement his graphic application here */
  /* Hello Word example */

/* USER CODE END GRAPHICS_MainTask */
	int p=0;


  while(1)
{ 	  //WM_ClrHasTrans(SecondWindow);

	  p+=0;

      WM_Invalidate(Window1);
      WM_SendMessageNoPara(Window1, WM_Paint);

      WM_Invalidate(Window2);
      WM_SendMessageNoPara(Window2, WM_Paint);

      WM_Invalidate(Window3);
      WM_SendMessageNoPara(Window3, WM_Paint);


      BSP_TS_GetState(&TS_State);

      X = TS_State.touchX[0];
      Y = TS_State.touchY[0];


      WM_MoveTo(Window1,X-300,Y);


      GUI_Delay(1);


}
}

/*************************** End of file ****************************/
