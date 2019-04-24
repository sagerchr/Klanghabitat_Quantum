/*******************************************************************************
*
*               Audio Framework
*               ---------------
*
********************************************************************************
*     GPIO.c
********************************************************************************
*
*     Description:  General Purpose I/O module
*
*     Copyright:    (c) 2017 DSP Concepts, Inc. All rights reserved.
*                   1800 Wyatt Drive, Suite 14
*                   Sunnyvale, CA 95054
*
*******************************************************************************/
#include "Platform.h"

//-----------------------------------------------------------------------------
// METHOD:  awe_pltGPIOSetPinDir
// PURPOSE: Set GPIO pin direction
//-----------------------------------------------------------------------------
void awe_pltGPIOSetPinDir(UINT32 nPinNo, UINT32 nPinDir)
{       
    // For this board there is only 1 input and 1 output
    
    //if (nPinDir == GPIO_DIR_OUTPUT)
    //{
    //    g_bBlinkLED2ForBoardAlive = FALSE;
    //}
    
}   // End awe_pltGPIOSetPinDir


//-----------------------------------------------------------------------------
// METHOD:  awe_pltGPIOSetPin
// PURPOSE: Set GBPIO pin value
//-----------------------------------------------------------------------------
void awe_pltGPIOSetPin(UINT32 nPinNo, UINT32 nValue)
{
    if (nPinNo < 1 || nPinNo > MAX_PINS)
    {
        return;
    }  
    
    if (nValue > 0)
    {
        BSP_LED_On(LED1);    
    }
    else
    {      
        BSP_LED_Off(LED1); 
    }

}   // End awe_pltGPIOSetPin


//-----------------------------------------------------------------------------
// METHOD:  awe_pltGPIOGetPin
// PURPOSE: Get GPIO pin value
//-----------------------------------------------------------------------------
void awe_pltGPIOGetPin(UINT32 nPinNo, UINT32 * nValue)
{ 
    if (nPinNo < 1 || nPinNo > MAX_PINS)
    {
        return;
    }
    
    *nValue = BSP_PB_GetState(BUTTON_USER);
    
}   // End awe_pltGPIOGetPin
