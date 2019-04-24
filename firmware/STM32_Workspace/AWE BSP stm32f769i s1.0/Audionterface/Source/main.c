/*******************************************************************************
*
*               Audio Framework
*               ---------------
*
********************************************************************************
*     main.c
********************************************************************************
*
*     Description:  AudioWeaver target main program
*
*     Copyright:    DSP Concepts, Inc. (c) 2007 - 2016
*                   1800 Wyatt Drive, Suite 14
*                   Sunnyvale, CA 95054
*
*******************************************************************************/
#include "Platform.h"

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{      
	// Initialize AWE platform
 	awe_pltInit();
      
    // Initialize the AWE framework
	awe_fwInit(&g_AWEInstance);
   
    // Idle loop processing
	while (TRUE)
	{            
		// Process any platform tasks
		awe_pltTick();
                
		// Perform any framework tasks
		awe_fwTick(&g_AWEInstance); 
        
	}   // End while
    
}   // End main
