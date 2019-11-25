  /**
  ******************************************************************************
x  * @file    GUI_App.c
  * @file    GUI_App.c
  * @author  MCD Application Team
  * @brief   Simple demo drawing "Hello world"  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright © 2018 STMicroelectronics International N.V.
  * All rights reserved.xx</center></h2>
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
#include "usb_device.h"
#include "UART_IO.h"


extern  WM_HWIN CreateWindow(void);



TS_StateTypeDef TS_State;
I2C_HandleTypeDef hi2c1;
UART_HandleTypeDef huart6;

uint8_t level = 0;
uint8_t i2cBuffer[2];
uint16_t Adr[6] = {0,8,16,32,64,128};
uint8_t word;
char array[20];

int start = 0;
int offset = 0;
int intervall = 0;
int counter = 0;

char transmitCDC[4];
uint8_t ReciveCDC;
uint8_t count;
uint8_t buffer[10];
char transmit[10];
//GUI_RECT pRect = {250,100,600,400};
GUI_RECT pRect = {200,0,600,480};
int toggle=0;

void CDC_ReceiveCallBack(uint8_t *buf, uint32_t len){
     ReciveCDC = &buf;
}

int wait = 0;
int activeKnob = 0;


void GRAPHICS_MainTask(void) {


    WM_HWIN hWin;
    hWin = CreateWindow();


    while(1)
  {

        GUI_Delay(1);

        WM_Invalidate(hWin);

        WM_SendMessageNoPara(hWin, WM_PaintWindowAndDescs);


   /******************** READ ENCODER ***********************/


             for (int i=0; i<6; i++){
                 i2cBuffer[0]= 0x0B;
                 HAL_I2C_Master_Transmit(&hi2c1, Adr[i],i2cBuffer,1,1);
                 HAL_I2C_Master_Receive(&hi2c1, Adr[i], &i2cBuffer[1],1,1);
                 pots[i]=i2cBuffer[1];
             }
             level=pots[0];
             left=pots[0];
             right=pots[5];

   /**********************************************************/

   /************** Panning Action TouchScreen ****************/
             /*left = (X/2) - 200;
             if (left <=1){left = 0;}
             if (left >= 254){left = 254;}

             right = 200 - (X/2);
             if (right <=1){right = 0;}
             if (right >= 254){right = 254;}
  /**********************************************************/


  /************ Transmit data to AnalogEngine****************/
             transmit[0]=0xFF;
             transmit[1]=left;
             transmit[2]=pots[1];
             transmit[3]=pots[2];
             transmit[4]=pots[3];
             transmit[5]=pots[4];
             transmit[6]=right;
             transmit[7]=0x01;
             transmit[8]=0x02;
             transmit[9]=0x03;

              HAL_UART_Transmit(&huart6, transmit , 10, 1);

  /**********************************************************/


  }

    /* USER CODE END GRAPHICS_MainTask */
      while(1)
    {
          GUI_Delay(100);
    }
    }

    /*************************** End of file ****************************/

