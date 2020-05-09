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

void TOUCHUPDATE(){
	if(TIM4->CNT>100){
		BSP_LED_Toggle(LED1);
		    switch (count) {

		    case 1:
				 HAL_I2C_Master_Transmit(&hi2c1, 40, aTxBuffer,10,10);
				 HAL_I2C_Master_Receive(&hi2c1, 40, aRxBuffer,10,10);
				 if(aRxBuffer[8]!=255) {pots[4]=aRxBuffer[7];}
				 if(aRxBuffer[9]!=255) {pots[3]=aRxBuffer[9];}
				 if(aRxBuffer[6]!=255) {buttonstateRight=aRxBuffer[6];}
		    	 count =2;
		     	 break;
		    case 2:
				 HAL_I2C_Master_Transmit(&hi2c1, 30, aTxBuffer,10,10);
				 HAL_I2C_Master_Receive(&hi2c1, 30, aRxBuffer,10,10);
				 if(aRxBuffer[8]!=255) {pots[2]=aRxBuffer[7];}
				 if(aRxBuffer[9]!=255) {pots[1]=aRxBuffer[9];}
				 if(aRxBuffer[6]!=255) {buttonstateLeft=aRxBuffer[6];}
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
