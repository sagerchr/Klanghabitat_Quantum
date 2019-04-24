/*******************************************************************************
*
*               Audio Framework
*               ---------------
*
********************************************************************************
*     TuningDriver.c
********************************************************************************
*
*     Description:  AudioWeaver Tuning Driver for STM Discovery board
*
*     Copyright:    DSP Concepts, Inc. (c) 2007 - 2016
*                   1800 Wyatt Drive, Suite 14
*                   Sunnyvale, CA 95054
*
*******************************************************************************/
#include <string.h>
#include "Platform.h"


static volatile UINT32 g_nPacketBufferNdx = 0;
static volatile UINT32 g_nTotalBytesToSend = 0;

volatile BOOL g_bUSBPacketReceived = FALSE;
volatile BOOL g_bReadyToSend = TRUE;

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN UINT32 s_PacketBuffer[MAX_COMMAND_BUFFER_LEN] __ALIGN_END = {0};

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN UINT8 HIDInBuff[HID_EP_BUFFER_SIZE] __ALIGN_END = {0};

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN UINT8 HIDOutBuff[HID_EP_BUFFER_SIZE] __ALIGN_END = {0};

volatile BOOL g_bBlinkLED2ForBoardAlive = TRUE;

//-----------------------------------------------------------------------------
// METHOD:  TuningInit
// PURPOSE: 
//-----------------------------------------------------------------------------
AWE_OPTIMIZE_FOR_SPEED
AWE_FW_SLOW_CODE
void USBMsgInit(void)
{   
	// Initialize the communication handler
  	awe_fwTuningInit(s_PacketBuffer, MAX_COMMAND_BUFFER_LEN); 
           
    // Ready to send next USB reply packet
    HAL_NVIC_SetPriority(ProcessUSBMsg_IRQ, 4, 0);
    HAL_NVIC_EnableIRQ(ProcessUSBMsg_IRQ); 
   
    // Start Device Process
    USBD_Start(&USBD_Device);    
    
}   // End USBMsgInit


//-----------------------------------------------------------------------------
// METHOD:  ProcessUSBMsg_IRQHandler
// PURPOSE: Handler to send back multi-packet USB HID reply
//-----------------------------------------------------------------------------
void ProcessUSBMsg_IRQHandler(void)
{ 
    if (g_bBlinkLED2ForBoardAlive)
    {
        // Indicate board running by toggling LED2
        BSP_LED_Toggle(LED2);
    }        
    
    if (g_nTotalBytesToSend > 0)
    {
		uint32_t nBytesToSend;
		
        nBytesToSend = g_nTotalBytesToSend  > HID_REPORT_DATA_SIZE ? HID_REPORT_DATA_SIZE: g_nTotalBytesToSend;
        
        HIDInBuff[3] = (uint8_t)nBytesToSend;
        
        memcpy(&HIDInBuff[4], &s_PacketBuffer[g_nPacketBufferNdx], nBytesToSend);          
        
		g_nPacketBufferNdx += nBytesToSend >> 2;
		g_nTotalBytesToSend -= nBytesToSend;
        
        // g_bReadyToSend is used in interrupt IN callback to call this handler again
        // if more data needs to be sent back to the host
        if (g_nTotalBytesToSend > 0)
        {
            g_bReadyToSend = TRUE;
        }
        else
        {
            g_bReadyToSend = FALSE;
        } 
              
        USBD_LL_Transmit(&USBD_Device, HID_IN_EP, HIDInBuff, HID_REPORT_PACKET_SIZE);          
    }  
    
    NVIC_ClearPendingIRQ(ProcessUSBMsg_IRQ);     
    
}   // End ProcessUSBMsg_IRQHandler


//-----------------------------------------------------------------------------
// METHOD:  CheckForUSBPacketReady
// PURPOSE: Checks if USB packet has been received and calls into framework
//-----------------------------------------------------------------------------
AWE_OPTIMIZE_FOR_SPEED
AWE_FW_SLOW_CODE
void CheckForUSBPacketReady(void)
{
    static INT32 nLoopCount = 0;
    
    // g_bUSBPacketReceived is set in USB interrupt callback when a HID packet is received
	if (g_bUSBPacketReceived)	
	{
        // Reset flag so we'll know when the next USB packet is received
        g_bUSBPacketReceived = FALSE;                                     
          
        // Indicate packet is ready.
        awe_fwTuningRxPacket();   
 
        nLoopCount = 0;        
    } 
    else 
    {           
        if (g_bBlinkLED2ForBoardAlive)
        {    
            // Blink LED1 to show board is alive
            nLoopCount++;
            
            if (nLoopCount == 500000)
            {              
                // Indicate board running by toggling LED2
                BSP_LED_Toggle(LED2);
                                           
                nLoopCount = 0;
            }   
        }
    }          
		
}	// End awe_pltTick


//-----------------------------------------------------------------------------
// METHOD:  USBSendReply
// PURPOSE: Sends the first packet of a possibly multi-packet reply
//-----------------------------------------------------------------------------
void USBSendReply(void)
{
    UINT32 nPacketLenInDWords;
    
    nPacketLenInDWords = s_PacketBuffer[0] >> 16;

    if (nPacketLenInDWords > (UINT32)MAX_COMMAND_BUFFER_LEN)
    {
        nPacketLenInDWords = MAX_COMMAND_BUFFER_LEN;
    }
    
    g_nPacketBufferNdx = 0;
    
    // HID Report ID
    HIDInBuff[0] = 1;
    
    HIDInBuff[1] = 0;
    HIDInBuff[2] = 0;
    
    g_nTotalBytesToSend = nPacketLenInDWords << 2;
    
    // Start process of sending back possibly multi-packet USB reply
    NVIC_SetPendingIRQ(ProcessUSBMsg_IRQ);   
    
}   // End USBSendReply
