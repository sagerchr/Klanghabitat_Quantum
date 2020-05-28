#include "main.h"
TS_StateTypeDef ts;
  uint8_t level = 0;
  uint8_t aTxBuffer[] = "          ";
  uint8_t aRxBuffer[10];

  uint8_t buttonstateLeft;
  uint8_t buttonstateRight;
  I2C_HandleTypeDef hi2c1;


void BSP_Pointer_Update(void) {
  GUI_PID_STATE TS_State;               /* Structure that reports the touch state to STemWin */
  static TS_StateTypeDef prev_state;    /* Previous touch state from the touch sensor used from BSP package */
  //                   /* Actual touch state from the touch sensor used from BSP package */
  uint16_t xDiff, yDiff;                /* Difference in postitions between touch states*/
  BSP_TS_GetState(&ts);                 /* Read the touch state from touch sensor (BSP API)*/
  TS_State.Pressed = ts.touchDetected;  /* Store pressed state to STemWin structure*/


  TouchXCoordinate = ts.touchX[0];
  TouchYCoordinate = ts.touchY[0];
  TouchDetected = ts.touchDetected;


  /* Compute x variation */
  xDiff = (prev_state.touchX[0] > ts.touchX[0]) ? (prev_state.touchX[0] - ts.touchX[0]) : (ts.touchX[0] - prev_state.touchX[0]);

  /* Compute y variation */
  yDiff = (prev_state.touchY[0] > ts.touchY[0]) ? (prev_state.touchY[0] - ts.touchY[0]) : (ts.touchY[0] - prev_state.touchY[0]);

  /* Check if the touch is pressed */
  if ((prev_state.touchDetected != ts.touchDetected) || (xDiff > 3)|| (yDiff > 3))
  {
    prev_state.touchDetected = ts.touchDetected;
    /* Check touch variations */
    if ((ts.touchX[0] != 0) && (ts.touchY[0] != 0))
    {
      prev_state.touchX[0] = ts.touchX[0];
      prev_state.touchY[0] = ts.touchY[0];
    }
    TS_State.Layer = 0;
    TS_State.x = prev_state.touchX[0];
    TS_State.y = prev_state.touchY[0];

    /* Send touch state to STemWin */
    GUI_TOUCH_StoreStateEx(&TS_State);
  }
}

int count = 1;

//HelperVariables for DoubleClick Sense//
//+++++++++++++++++++++++++++++++++++++//
int DoubleClick1Event = 0;
int DoubleClick1 = 0;
int intervall1 = 0;
int high1 = 0;
//++++++++++++++++++++++++++++++++++++//
int DoubleClick2Event = 0;
int DoubleClick2 = 0;
int intervall2 = 0;
int high2 = 0;
//++++++++++++++++++++++++++++++++++++//
int DoubleClick3Event = 0;
int DoubleClick3 = 0;
int intervall3 = 0;
int high3 = 0;
//++++++++++++++++++++++++++++++++++++//
int DoubleClick4Event = 0;
int DoubleClick4 = 0;
int intervall4 = 0;
int high4 = 0;
//++++++++++++++++++++++++++++++++++++//

void TOUCHUPDATE(){
	if(TIM4->CNT>100){
		BSP_LED_Toggle(LED1);
		    switch (count) {

		    case 1:

		    	if 		(Encoder3.Color == GUI_LIGHTGRAY)	{aTxBuffer[1] = 0;}
		    	else if (Encoder3.Color == GUI_MAGENTA)		{aTxBuffer[1] = 1;}
		    	else if (Encoder3.Color == GUI_ORANGE)		{aTxBuffer[1] = 2;}
		    	else if (Encoder3.Color == GUI_CYAN)		{aTxBuffer[1] = 3;}
		    	else if (Encoder3.Color == GUI_LIGHTYELLOW)	{aTxBuffer[1] = 4;}
		    	else if (Encoder3.Color == GUI_LIGHTGREEN)	{aTxBuffer[1] = 5;}
		    	else if (Encoder3.Color == GUI_LIGHTBLUE)	{aTxBuffer[1] = 6;}
		    	else								    	{aTxBuffer[1] = 10;}

		    	if 		(Encoder4.Color == GUI_LIGHTGRAY)	{aTxBuffer[2] = 0;}
		    	else if (Encoder4.Color == GUI_MAGENTA)		{aTxBuffer[2] = 1;}
		    	else if (Encoder4.Color == GUI_ORANGE)		{aTxBuffer[2] = 2;}
		    	else if (Encoder4.Color == GUI_CYAN)		{aTxBuffer[2] = 3;}
		    	else if (Encoder4.Color == GUI_LIGHTYELLOW)	{aTxBuffer[2] = 4;}
		    	else if (Encoder4.Color == GUI_LIGHTGREEN)	{aTxBuffer[2] = 5;}
		    	else if (Encoder4.Color == GUI_LIGHTBLUE)	{aTxBuffer[2] = 6;}
		    	else								    	{aTxBuffer[2] = 10;}



		    	 HAL_I2C_Master_Transmit(&hi2c1, 40, aTxBuffer,10,10);
				 HAL_I2C_Master_Receive(&hi2c1, 40, aRxBuffer,10,10);

				 if(aRxBuffer[6]!=255) {buttonstateRight=aRxBuffer[6];}

				 if(aRxBuffer[7]!=255) {
					 Encoder3.value=aRxBuffer[7];
				 }
				 if(aRxBuffer[9]!=255){
					 Encoder4.value=aRxBuffer[9];
				 }

				 Encoder3.buttonState =	!(aRxBuffer[6] & 0x01);
				 Encoder4.buttonState = !((aRxBuffer[6]>>2) & 0x01);

				 //+++++++++++++++ENCODER 3 DOUBLECLICK SENSE++++++++++++++//
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
				 if(Encoder3.buttonState&&DoubleClick3<2&&!high3){
					 DoubleClick3 = DoubleClick3+1;
					 high3 = 1;
					 intervall3 = 0;
				 }

				 if(!Encoder3.buttonState){
					 high3 = 0;
				 }

				 if (DoubleClick3 == 2 && intervall3 < 20){
					 DoubleClick3 = 0;
					 Encoder3.doubleclickEvent = 1;
					 intervall3=0;
				 }
				 if (Encoder3.doubleclickEvent && intervall3 == 20){
					 Encoder3.doubleclickEvent = 0;
				 }

				 intervall3++;
				 if(intervall3 >= 20){intervall3 = 20;DoubleClick3 = 0;}
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

				 //+++++++++++++++ENCODER 4 DOUBLECLICK SENSE++++++++++++++//
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
				 if(Encoder4.buttonState&&DoubleClick4<2&&!high4){
					 DoubleClick4 = DoubleClick4+1;
					 high4 = 1;
					 intervall4 = 0;
				 }

				 if(!Encoder4.buttonState){
					 high4 = 0;
				 }

				 if (DoubleClick4 == 2 && intervall4 < 20){
					 DoubleClick4 = 0;
					 Encoder4.doubleclickEvent = 1;
					 intervall4=0;
				 }
				 if (Encoder4.doubleclickEvent && intervall4 == 20){
					 Encoder4.doubleclickEvent = 0;
				 }

				 intervall4++;
				 if(intervall4 >= 20){intervall4 = 20;DoubleClick4 = 0;}
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//



		    	 count =2;
		     	 break;
		    case 2:


		    	if 		(Encoder1.Color == GUI_LIGHTGRAY)	{aTxBuffer[2] = 0;}
		    	else if (Encoder1.Color == GUI_MAGENTA)		{aTxBuffer[2] = 1;}
		    	else if (Encoder1.Color == GUI_ORANGE)		{aTxBuffer[2] = 2;}
		    	else if (Encoder1.Color == GUI_CYAN)		{aTxBuffer[2] = 3;}
		    	else if (Encoder1.Color == GUI_LIGHTYELLOW)	{aTxBuffer[2] = 4;}
		    	else if (Encoder1.Color == GUI_LIGHTGREEN)	{aTxBuffer[2] = 5;}
		    	else if (Encoder1.Color == GUI_LIGHTBLUE)	{aTxBuffer[2] = 6;}
		    	else								    	{aTxBuffer[2] = 10;}

		    	if 		(Encoder2.Color == GUI_LIGHTGRAY)	{aTxBuffer[1] = 0;}
		    	else if (Encoder2.Color == GUI_MAGENTA)		{aTxBuffer[1] = 1;}
		    	else if (Encoder2.Color == GUI_ORANGE)		{aTxBuffer[1] = 2;}
		    	else if (Encoder2.Color == GUI_CYAN)		{aTxBuffer[1] = 3;}
		    	else if (Encoder2.Color == GUI_LIGHTYELLOW)	{aTxBuffer[1] = 4;}
		    	else if (Encoder2.Color == GUI_LIGHTGREEN)	{aTxBuffer[1] = 5;}
		    	else if (Encoder2.Color == GUI_LIGHTBLUE)	{aTxBuffer[1] = 6;}
		    	else								    	{aTxBuffer[1] = 10;}



				 HAL_I2C_Master_Transmit(&hi2c1, 30, aTxBuffer,10,10);
				 HAL_I2C_Master_Receive(&hi2c1, 30, aRxBuffer,10,10);

				 if(aRxBuffer[6]!=255) {buttonstateLeft=aRxBuffer[6];}

				 if(aRxBuffer[7]!=255){
					 Encoder1.value=aRxBuffer[7];
				 }
				 if(aRxBuffer[9]!=255){
					 Encoder2.value=aRxBuffer[9];
				 }

				 Encoder1.buttonState= !((aRxBuffer[6]>>2) & 0x01);
				 Encoder2.buttonState= !(aRxBuffer[6] & 0x01);

				 //+++++++++++++++ENCODER 1 DOUBLECLICK SENSE++++++++++++++//
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
				 if(Encoder1.buttonState&&DoubleClick1<2&&!high1){
					 DoubleClick1 = DoubleClick1+1;
					 high1 = 1;
					 intervall1 = 0;
				 }

				 if(!Encoder1.buttonState){
					 high1 = 0;
				 }

				 if (DoubleClick1 == 2 && intervall1 < 20){
					 DoubleClick1 = 0;
					 Encoder1.doubleclickEvent = 1;
					 intervall1=0;
				 }
				 if (Encoder1.doubleclickEvent && intervall1 == 20){
					 Encoder1.doubleclickEvent = 0;
				 }

				 intervall1++;
				 if(intervall1 >= 20){intervall1 = 20;DoubleClick1 = 0;}
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

				 //+++++++++++++++ENCODER 2 DOUBLECLICK SENSE++++++++++++++//
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
				 if(Encoder2.buttonState&&DoubleClick2<2&&!high2){
					 DoubleClick2 = DoubleClick2+1;
					 high2 = 1;
					 intervall2 = 0;
				 }

				 if(!Encoder2.buttonState){
					 high2 = 0;
				 }

				 if (DoubleClick2 == 2 && intervall2 < 20){
					 DoubleClick2 = 0;
					 Encoder2.doubleclickEvent = 1;
					 intervall2=0;
				 }
				 if (Encoder2.doubleclickEvent && intervall2 == 20){
					 Encoder2.doubleclickEvent = 0;
				 }

				 intervall2++;
				 if(intervall2 >= 20){intervall2 = 20;DoubleClick2 = 0;}
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
				 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++//




		    	 count=3;
		     	 break;
		    case 3:
		    	BSP_Pointer_Update();

		     	count=1;
		        break;
		    }
		    TIM4->CNT = 0;
	  	}
}
