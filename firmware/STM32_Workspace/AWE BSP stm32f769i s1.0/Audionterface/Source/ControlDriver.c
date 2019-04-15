/*******************************************************************************
*
*               STM BSP Driver
*               ---------------
*
********************************************************************************
*     ControlDriver.c
********************************************************************************
*
*     Description:  AudioWeaver Control Driver for STM Discovery board
*
*     DSP Concepts, Inc.
*     1800 Wyatt Drive, Suite 14
*     Sunnyvale, CA 95054
*
*     Copyright (c) 2007 - 2017 DSP Concepts, Inc. All rights reserved.
*
*******************************************************************************/
#include "Platform.h"

#include "ModSink.h"
#include "ModDCSourceV2.h"

#define OBJECT_FOUND 0

// Structure with information needed to interact with the control
typedef struct {
    ModClassModule * pModule;
    UINT32 nPinNo;
}   CONTROL_TYPE;

// This target board control inputs
const UINT16 InputCtrlID[CTRL_NUM_INPUTS] = {CTRL_BUTTON1};

// Need to keep track of which I/O pin is assigned to each control
const UINT32 InputCtrlPinNo[CTRL_NUM_INPUTS] = {1};

// Table of pointers to instantiated source control modules
CONTROL_TYPE g_InputControl[CTRL_NUM_INPUTS] = {NULL};

// Need to keep track of how many source controls have been instantiated in the Model
UINT16 g_nInputControlCount = 0;

// This target board control outputs
const UINT16 OutputCtrlID[CTRL_NUM_OUTPUTS] = {CTRL_LED1};

// Need to keep track of which I/O pin is assigned to each control
const UINT32 OutputCtrlPinNo[CTRL_NUM_INPUTS] = {1};

// Table of pointers to instantiated sink control modules
CONTROL_TYPE g_OutputControl[CTRL_NUM_INPUTS] = {NULL};

// Need to keep track of how many sink controls have been instantiated in the Model
UINT16 g_nOutputControlCount = 0;

/**
 * @brief Look for and initialize any control module instances in the current AWE model
 */
void ControlInit(void)
{
    InstanceDescriptor * pInstance;
	UINT32 classID;
    UINT16 n;

	g_nInputControlCount = 0;
    
    // Find any source control modules instantiated in the model
    for (n = 0; n < CTRL_NUM_INPUTS; n++)
    {
        // Does the current AWE model have a source module with this control object ID?
        if (awe_fwGetObjectByID(&g_AWEInstance, InputCtrlID[n], &pInstance, &classID) != OBJECT_FOUND)
        {
            // No such object.
            continue;
        }
        
        // Check that module assigned this object ID is of module class DC Source
        if (classID != CLASSID_DCSOURCEV2)
        {
            continue;
        }
        
        // Save the module instance in the control info structure
        g_InputControl[g_nInputControlCount].pModule = (ModClassModule *)pInstance;
        
        // Save the I/O pin number in the control info structure
        g_InputControl[g_nInputControlCount].nPinNo = InputCtrlPinNo[n];
        
        g_nInputControlCount++;
        
        InitializeControlPeripheral(InputCtrlID[n]);
    }

    g_nOutputControlCount = 0;

    // Find any sink control modules instantiated in the model
    for (n = 0; n < CTRL_NUM_OUTPUTS; n++)
    {
       // Does the current AWE model have a sink module with this control object ID?
        if (awe_fwGetObjectByID(&g_AWEInstance, OutputCtrlID[n], &pInstance, &classID) != OBJECT_FOUND)
        {
            // No such object.
            continue;
        }
        
        // Check that module assigned this object ID is of module class Sink
        if (classID != CLASSID_SINK)
        {
            continue;
        }      
        
        // Save the module instance in the control info structure
        g_OutputControl[g_nOutputControlCount].pModule = (ModClassModule *)pInstance;
        
        // Save the I/O pin number in the control info structure
        g_OutputControl[g_nOutputControlCount].nPinNo = OutputCtrlPinNo[n];
        
        g_nOutputControlCount++;
        
        InitializeControlPeripheral(OutputCtrlID[n]);        
    }    

}   // End ControlInit


/**
 * @brief  Initialize any hardware resources needed for each control
 */
void InitializeControlPeripheral(UINT32 nControlID)
{
    switch (nControlID)
    {       
        case CTRL_BUTTON1:
            awe_pltGPIOSetPinDir(1, GPIO_DIR_INPUT);
            break;
        
        case CTRL_LED1:
            awe_pltGPIOSetPinDir(1, GPIO_DIR_OUTPUT);            
            break;
        
        default:           
            ;
    }   // End switch
    
}   // End InitializeControlPeripheral


/**
 * @brief  Perform control I/O
 */
void ProcessControlIO(void)
{
    UINT32 nPinValue;
    UINT16 n;
    
    // Process any source control modules   
    for (n = 0; n < g_nInputControlCount; n++)
    {
        // Get the AWE module instance for this source control
        awe_modDCSourceV2Instance * pModule = (awe_modDCSourceV2Instance *)g_InputControl[n].pModule;
        
        // Which GPIO pin is this control attached to
        UINT32 nPinNo = g_InputControl[n].nPinNo;
        
        // Get the current state of the control
        awe_pltGPIOGetPin(nPinNo, &nPinValue);
        
        // Update the AWE module state
        pModule->value = (FLOAT32)nPinValue;
    }
       
    // Process any sink control modules   
    for (n = 0; n < g_nOutputControlCount; n++)
    {
        // Get the AWE module instance for this sink control
        awe_modSinkInstance * pModule = (awe_modSinkInstance *)g_OutputControl[n].pModule;
        
        // Which GPIO pin is this control attached to
        UINT32 nPinNo = g_OutputControl[n].nPinNo;
        
        // Set to 1 if greater than 0 otherwise set to 0
        nPinValue = (UINT32)(*(pModule->value) ) > 0 ? 1 : 0;
        
        // Change the ouput state of this control
        awe_pltGPIOSetPin(nPinNo, nPinValue);
    }    
      
} // End ProcessControlIO
