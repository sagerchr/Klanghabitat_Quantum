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
#include "main.h"
#include "DIALOG.h"
extern  WM_HWIN CreateWindow(void);  



TS_StateTypeDef TS_State;
I2C_HandleTypeDef hi2c2;
UART_HandleTypeDef huart6;

uint8_t level = 0;
uint8_t i2cBuffer[2];
uint16_t Adr[6] = {0,8,16,32,64,128};
uint8_t word;
char array[20];

int start = 0;
char newArray[10];

GUI_RECT pRect = {325,80,475,400};
//GUI_RECT pRect = {0,0,800,480};




void GRAPHICS_MainTask(void) {









	WM_HWIN hWin;
	hWin = CreateWindow();


    while(1)
  {

         WM_Invalidate(hWin);


        //WM_InvalidateArea(&pRect);

         GUI_Delay(1);





    	  BSP_TS_GetState(&TS_State);
    	     if(TS_State.touchDetected == TOUCH_EVENT_PRESS_DOWN)
    		{
    	      X = TS_State.touchX[0];
    		  Y = TS_State.touchY[0];
    		  HAL_GPIO_TogglePin(GPIOG, LAMP4_Pin);
    		}


    	     for (int i=0; i<6; i++){
            	 i2cBuffer[0]= 0x0B;
            	 HAL_I2C_Master_Transmit(&hi2c2, Adr[i],i2cBuffer,1,100);
            	 HAL_I2C_Master_Receive(&hi2c2, Adr[i], &i2cBuffer[1],1,100);
            	 pots[i]=i2cBuffer[1];
    	     }
    	     level=pots[0];
    	     HAL_GPIO_TogglePin(GPIOA, LAMP1_Pin);
    	     HAL_UART_Transmit(&huart6, (uint8_t*)(&level) , 1, 100);

    	     //Das hier funktioniert
    	     //HAL_UART_Receive(&huart6, &word, 1,10);

    	     UART_TRANSFER;
	 //HAL_UART_Receive(&huart6, &array, 10,5);

    	     for(int i = 0; i<20;i++){
    	    	 if (array[i] == 0x00 && i>0){
    	    		   start = i;
    	    		   break;
    	    	 }
    	     }

    	     for (int i = 0; i< 10;i++){
    	    	 newArray [i] = array[i+start];
    	     }

    	     adc1 = newArray[3];
    	     adc2 = newArray[4];


    	     for(int i = 0; i<20;i++){
    	    	 array[i] = 0;
    	     }

    	     for (int i = 0; i< 10;i++){
    	    	 newArray [i] = 0;
    	     }
    	     start = 0;

  }
/* USER CODE END GRAPHICS_MainTask */
  while(1)
{
      GUI_Delay(100);
}
}

/*************************** End of file ****************************/
