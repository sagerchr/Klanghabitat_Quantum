/*******************************************************************************
*
*               Audio Framework
*               ---------------
*
********************************************************************************
*     Platform.c
********************************************************************************
*
*     Description:  AudioWeaver Main Platform processing
*
*     Copyright:    (c) 2017 DSP Concepts, Inc. All rights reserved.
*                   1800 Wyatt Drive, Suite 14
*                   Sunnyvale, CA 95054
*
*******************************************************************************/
#include "aweOptionalFeatures.h"
#include "stm32f769i_discovery_qspi.h"

AWEInstance g_AWEInstance;

/* ----------------------------------------------------------------------
** Memory heaps
** ------------------------------------------------------------------- */
AWE_FW_SLOW_ANY_CONST UINT32 g_master_heap_size = MASTER_HEAP_SIZE;
AWE_FW_SLOW_ANY_CONST UINT32 g_slow_heap_size = SLOW_HEAP_SIZE;
AWE_FW_SLOW_ANY_CONST UINT32 g_fastb_heap_size = FASTB_HEAP_SIZE;

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
  UINT32 g_master_heap[MASTER_HEAP_SIZE] @ ".DTCMRAM_Section";   
#else
	#if defined( __GNUC__ )
		__attribute__((__section__(".dtcmram")))
  	  	__ALIGN_BEGIN UINT32 g_master_heap[MASTER_HEAP_SIZE] __ALIGN_END;        
	#else
		#if defined ( __CC_ARM ) /*!< Keil Compiler */
			__attribute__((__section__(".data_DTCM")))
			__ALIGN_BEGIN UINT32 g_master_heap[MASTER_HEAP_SIZE];            
		#endif
	#endif
#endif
            
#if defined ( __ICCARM__ ) /*!< IAR Compiler */
    #pragma data_alignment=4 
    UINT32 g_fastb_heap[FASTB_HEAP_SIZE];
#else
    __ALIGN_BEGIN UINT32 g_fastb_heap[FASTB_HEAP_SIZE] __ALIGN_END;
#endif

#if defined( __ICCARM__ ) /*!< IAR Compiler */
    #pragma data_alignment=4 
	__no_init UINT32 g_slow_heap[SLOW_HEAP_SIZE] @ ".SDRAM_Section";
#else
	#if defined( __GNUC__ )
		__attribute__((__section__(".sdram")))
		__ALIGN_BEGIN UINT32 g_slow_heap[SLOW_HEAP_SIZE] __ALIGN_END;
	#else
		#if defined ( __CC_ARM ) /*!< Keil Compiler */
			__attribute__((__section__(".data_SDRAM"), zero_init))
			__ALIGN_BEGIN UINT32 g_slow_heap[SLOW_HEAP_SIZE];
		#endif
	#endif
#endif

/* ----------------------------------------------------------------------
** Module table
** ------------------------------------------------------------------- */

/* Array of pointers to module descriptors. This is initialized at compile time.
Each item is the address of a module descriptor that we need linked in. The
linker magic is such that only those modules referenced here will be in the
final program. */
const ModClassModule * g_module_descriptor_table[] =
{
//------------- The suitably cast pointers to the module descriptors go here.
		LISTOFCLASSOBJECTS
};

UINT32 g_module_descriptor_table_size = sizeof(g_module_descriptor_table) / sizeof(g_module_descriptor_table[0]); 

// Audio Running Flag
volatile INT32 s_AudioRunning = 0;

volatile BOOL g_bReboot = FALSE;

/** The only input pin for this core. */
static IOPinDescriptor s_InputPin[1];

/** The only output pin for this core. */
static IOPinDescriptor s_OutputPin[1];


//-----------------------------------------------------------------------------
// METHOD:  awe_pltGetCore
// PURPOSE: Return core descriptor
//-----------------------------------------------------------------------------
CoreDescriptor * awe_pltGetCore(void *pOwner, UINT32 coreID)
{
    return NULL;
    
}   // End awe_pltGetCore


//-----------------------------------------------------------------------------
// METHOD:  awe_pltGetCores
// PURPOSE: Report number of cores in use on this target
//-----------------------------------------------------------------------------
int awe_pltGetCores()
{
     return 1;
    
}   // End awe_pltGetCores


//-----------------------------------------------------------------------------
// METHOD:  awe_pltDestroyAll
// PURPOSE: Destroy all core instances
//-----------------------------------------------------------------------------
void awe_pltDestroyAll()
{
    awe_fwDestroy(&g_AWEInstance);
    
}   // End awe_pltDestroyAll


//-----------------------------------------------------------------------------
// METHOD:  AWEInstanceInit
// PURPOSE: Initialize AWE Instance with target details
//-----------------------------------------------------------------------------
void AWEInstanceInit()
{
    UINT32 nInputWireInfo = INFO1_PROPS(INPUT_CHANNEL_COUNT, 
                                          CHANNEL_BLOCK_SIZE_IN_SAMPLES, 
                                          IS_COMPLEX, 
                                          SAMPLE_SIZE_IN_BYTES);
    
    UINT32 nOutputWireInfo = INFO1_PROPS(OUTPUT_CHANNEL_COUNT, 
                                         CHANNEL_BLOCK_SIZE_IN_SAMPLES, 
                                         IS_COMPLEX, 
                                         SAMPLE_SIZE_IN_BYTES);  
    
	memset(&g_AWEInstance, 0, sizeof(AWEInstance) );

	// Point to the start and stop functions.
	g_AWEInstance.m_pAwe_pltAudioStart = awe_pltAudioStart;
	g_AWEInstance.m_pAwe_pltAudioStop = awe_pltAudioStop;

	// Point to our private pins.
	g_AWEInstance.m_pInterleavedInputPin = s_InputPin;
	g_AWEInstance.m_pInterleavedOutputPin = s_OutputPin;

	// Point to the global module table.
	g_AWEInstance.m_module_descriptor_table_size = sizeof(g_module_descriptor_table) >> 2;
	g_AWEInstance.m_pModule_descriptor_table = g_module_descriptor_table;

	// This will be core ID 100.
	g_AWEInstance.m_coreID = CORE_ID;
    
	awe_fwInitTargetInfo(&g_AWEInstance, 
                         CORE_ID, 
                         CORE_SPEED, 
                         SAMPLE_SPEED,
                         "ST32F769", 
                         PROCESSOR_TYPE_CORTEXM7,
                         HAS_FLOAT_SUPPORT,
                         HAS_FLASH_FILESYSTEM,
                         NO_INPUT_PINS,
                         NO_OUTPUT_PINS,
                         IS_SMP,
                         NO_THREADS_SUPPORTED,
                         FIXED_SAMPLE_RATE,
                         INPUT_CHANNEL_COUNT,
                         OUTPUT_CHANNEL_COUNT,
                         VER_DAY, VER_MONTH, VER_YEAR
                         );
   
	awe_fwInit_io_pins(&g_AWEInstance, 1);
    
	s_InputPin[0].sampleRate = FIXED_SAMPLE_RATE;
	s_InputPin[0].wireInfo1 = nInputWireInfo;   
	s_InputPin[0].wireInfo3 |= CLOCK_MASTER_BIT;
	awe_SetPackedName(s_InputPin[0].m_pinName, "Input");

	s_OutputPin[0].sampleRate = FIXED_SAMPLE_RATE;
	s_OutputPin[0].wireInfo1 = nOutputWireInfo;     
	awe_SetPackedName(s_OutputPin[0].m_pinName, "Output");   

	// Allocate the heaps.
    g_AWEInstance.m_master_heap_size = MASTER_HEAP_SIZE;
    g_AWEInstance.m_slow_heap_size = SLOW_HEAP_SIZE;
    g_AWEInstance.m_fastb_heap_size = FASTB_HEAP_SIZE;

	g_AWEInstance.m_master_heap = g_master_heap;
	g_AWEInstance.m_slow_heap = g_slow_heap;
	g_AWEInstance.m_fastb_heap = g_fastb_heap;  
    
}   // End AWEInstanceInit


//-----------------------------------------------------------------------------
// METHOD:  awe_pltInit
// PURPOSE: Initialize AWE
//-----------------------------------------------------------------------------
AWE_OPTIMIZE_FOR_SPACE
AWE_FW_SLOW_CODE
void awe_pltInit(void)
{ 
    // Initialize the target info    
    AWEInstanceInit();
    
    // Setup processor clocks, signal routing, timers, etc.
    CoreInit();
    
    // Setup board peripherals (CODECs, external memory, etc.)
    BoardInit();  
    
    // Setup audio DMA, interrupt priorities, etc.
    AudioInit();
    
    // Setup communication channel for monitoring and control
    USBMsgInit();	
            
  	// Initialize the Flash File System
  	awe_pltInitFlashFileSystem();  
	
}	// End awe_pltInit


//-----------------------------------------------------------------------------
// METHOD:  awe_pltTick
// PURPOSE: 
//-----------------------------------------------------------------------------
AWE_OPTIMIZE_FOR_SPEED
AWE_FW_SLOW_CODE
void awe_pltTick(void)
{  
    BOOL bReplyReady;
    
    // Indicate that this idle loop call is getting CPU attention
    g_nPumpCount = 0; 
    
    CheckForUSBPacketReady();
    
    bReplyReady = awe_fwTuningTick(&g_AWEInstance);
    
    if (bReplyReady == REPLY_READY)
    {
        USBSendReply();
        
        if (g_bReboot)
        {
            g_bReboot = FALSE;
            HAL_Delay(500);
            HAL_NVIC_SystemReset();
        }
    }
    
    // Process any local controls 
    ProcessControlIO();    
    
}	// End awe_pltTick


//-----------------------------------------------------------------------------
// METHOD:  awe_pltGetCycleCount
// PURPOSE: Returns the current value in the counter
//-----------------------------------------------------------------------------
UINT32 awe_pltGetCycleCount(void)
{   
	UINT32 nCycles, nElapsedMilliSecs;
    
    // This value is 216,000
    UINT32 nReloadValue = SysTick->LOAD + 1;
    
    nElapsedMilliSecs = HAL_GetTick();
    
    // Current COUNTDOWN value ( 0 - 215,999 )
	nCycles = SysTick->VAL;	
    
    nElapsedMilliSecs = (nElapsedMilliSecs * nReloadValue) + nReloadValue - nCycles;	
          	
	return nElapsedMilliSecs;
    
}   // End awe_pltGetCycleCount


//-----------------------------------------------------------------------------
// METHOD:  awe_pltElapsedCycles
// PURPOSE: Returns the cycle count between start time and end time
//-----------------------------------------------------------------------------
UINT32 awe_pltElapsedCycles(UINT32 nStartTime, UINT32 nEndTime)
{
    UINT32 nElapsedTime;
    
	if (nEndTime > nStartTime)
	{
		nElapsedTime = nEndTime - nStartTime;
	}
	else
	{
		// Wrap around occurred 
		nElapsedTime = ((((UINT32)0xFFFFFFFF) - nStartTime) + nEndTime + 1);

        // Correct for race condition reading ms tick and elapsed cycle count
        if ( (nElapsedTime > 216000) && (nElapsedTime < 432000) )
        {
          nElapsedTime -= 216000;
        }
        else if (nElapsedTime > ( (UINT32)0xFFFFFFFF - 216000) )
        {
          nElapsedTime += 216000;
        }
    }
 
	return nElapsedTime;   
    
}   // End awe_pltElapsedCycles


//----------------------------------------------------------------------------
// METHOD:  awe_pltAudioStart
// PURPOSE: Start processing audio with AWE
//----------------------------------------------------------------------------
AWE_OPTIMIZE_FOR_SPACE 
AWE_FW_SLOW_CODE
INT32 awe_pltAudioStart(void)
{
    
    // At this point the model is fully instantiated and the control I/O can be setup
    ControlInit();
    
	// Mark the audio as started
	s_AudioRunning = 1;

	return 0;
    
}   // End awe_pltAudioStart


//----------------------------------------------------------------------------
// METHOD:  awe_pltAudioStop
// PURPOSE: Stop processing audio with AWE
//----------------------------------------------------------------------------
AWE_OPTIMIZE_FOR_SPACE 
AWE_FW_SLOW_CODE
INT32 awe_pltAudioStop(void)
{	   
    // Mark the audio as stopped
	s_AudioRunning = 0;

	return 0;
    
}   // End awe_pltAudioStop


#if (HAS_FLASH_FILESYSTEM == 1)


//-----------------------------------------------------------------------------
// METHOD:  awe_pltGetFlashEraseTime(void)
// PURPOSE: Return the number of seconds to erase flash file system
//-----------------------------------------------------------------------------
INT32 awe_pltGetFlashEraseTime(void)
{
    // This number must be measured for each target
    return ( (MX25L512_BULK_ERASE_MAX_TIME / 10000) * 2) + 20;

}   // End awe_pltGetFlashEraseTime


//-----------------------------------------------------------------------------
// METHOD:  awe_pltInitFlashFileSystem
// PURPOSE: This method is here
//-----------------------------------------------------------------------------
AWE_OPTIMIZE_FOR_SPACE
AWE_FW_SLOW_CODE
BOOL awe_pltInitFlashFileSystem(void)
{ 
    UINT32 Buffer[4];   
    
	g_filesystem_info.m_FlashDeviceDWords = FLASH_MEMORY_SIZE_IN_WORDS;
    
    // Prime the flash file system by issuing a read
    // The system returns invalid data on the first read
    awe_pltReadFlashMemory(0, (UINT32 *)Buffer, 4);
    
    return InitFlashFileSystem(FLASH_MEMORY_SIZE_IN_BYTES,
                               ERASEABLE_BLOCKSIZE,
                               FILE_SYSTEM_START_OFFSET);
    
}   // End awe_pltInitFlashFileSystem


//-----------------------------------------------------------------------------
// METHOD:  awe_pltReadFlashMemory
// PURPOSE: Read from flash memory device
//-----------------------------------------------------------------------------
AWE_OPTIMIZE_FOR_SPACE
AWE_FW_SLOW_CODE
BOOL awe_pltReadFlashMemory(UINT32 nFlashAddress, UINT32 * pBuffer, UINT32 nDWordsToRead)
{
    UINT8 nStatus;
    UINT32 nBytesToRead = nDWordsToRead * 4;
    UINT32 nEndingAddress = nFlashAddress + nBytesToRead;
    
 	// Flash address must be on a 4 byte boundary since writing DWords
	if ( (nFlashAddress & 0x00000003) != 0)
	{
		return FAILURE;
	}
    
    if (nEndingAddress >= FILE_SYSTEM_START_OFFSET + FLASH_MEMORY_SIZE_IN_BYTES)
    {
        return FAILURE;
    }
    
    if (BSP_QSPI_Read((uint8_t *)pBuffer, nFlashAddress, nBytesToRead) != QSPI_OK)
    {
        //printf("awe_pltReadFlashMemory failed\n");
        return FAILURE;
    }   

    do
    {
        nStatus = BSP_QSPI_GetStatus();
    }
    while (nStatus == QSPI_BUSY);   

    if (nStatus != QSPI_OK)
    {
        //printf("Error: awe_pltReadFlashMemory failed - nStatus = %d\n", nStatus);
    }
    
	return SUCCESS;	

}	// End awe_pltReadFlashMemory


//-----------------------------------------------------------------------------
// METHOD:  awe_pltWriteFlashMemory
// PURPOSE: Write to flash memory device
//-----------------------------------------------------------------------------
AWE_OPTIMIZE_FOR_SPACE
AWE_FW_SLOW_CODE
BOOL awe_pltWriteFlashMemory(UINT32 nFlashAddress, UINT32 * pBuffer, UINT32 nDWordsToWrite)
{ 
	UINT32 n;
    UINT32 nValueRead, nValueWritten;
    UINT32 nAddr;
    UINT32 nBytesToWrite = nDWordsToWrite * 4;
    
    UINT32 nEndingAddress = nFlashAddress + nBytesToWrite;  
		
	// Flash address must be on a 4 byte boundary since writing DWords
	if ( (nFlashAddress & 0x00000003) != 0)
	{
        //printf("awe_pltWriteFlashMemory failed\n");
		return FAILURE;
	}
    
    if (nEndingAddress >= FILE_SYSTEM_START_OFFSET + FLASH_MEMORY_SIZE_IN_BYTES)
    {
        //printf("awe_pltWriteFlashMemory failed\n");
        return FAILURE;
    }  
    
    if (BSP_QSPI_Write((uint8_t *)pBuffer, nFlashAddress, nBytesToWrite) != QSPI_OK)
    {
        //printf("awe_pltWriteFlashMemory BSP_QSPI_Write failed\n");
        return FAILURE;
    }    
    
    n = 0;
    
    for (nAddr = nFlashAddress; nAddr < nEndingAddress; nAddr += 4)
    {
        BSP_QSPI_Read((uint8_t *)&nValueRead, nAddr, 4);
        
        nValueWritten = pBuffer[n++];

        if (nValueWritten != nValueRead)
        {
            //printf("ERROR: awe_pltWriteFlashMemory read bytes did not match bytes written\n");
            //printf("Address: 0x%.8X Wrote 0x%X and read 0x%X\n", nAddr, nValueWritten, nValueRead);
            return FAILURE;
        }
    }     

	return SUCCESS;

}	// End awe_pltWriteFlashMemory


//-----------------------------------------------------------------------------
// METHOD:  awe_pltEraseFlashMemorySector
// PURPOSE: Erase Flash Memory used for Flash File System
//-----------------------------------------------------------------------------
AWE_OPTIMIZE_FOR_SPACE
AWE_FW_SLOW_CODE
BOOL awe_pltEraseFlashMemorySector(UINT32 nStartingAddress, UINT32 nNumberOfSectors)
{ 
    UINT8 nStatus;
    UINT32 n;
    UINT32 nSectorAddress;
    
    if (nStartingAddress == 0 && nNumberOfSectors == 16384)
    {        
        //printf("Start full erase\n");
        
        // This operation takes almost a full minute
        nStatus = BSP_QSPI_Erase_Chip();
        
        //printf("*** Full erase complete ***\n");

        if (nStatus != QSPI_OK)
        {
            return FAILURE;
        }    

        return SUCCESS;        
       
    }
  
    nSectorAddress = nStartingAddress & 0x1000;
    
    for (n = 0; n < nNumberOfSectors; n++)
    {            
        BSP_QSPI_Erase_Block(nSectorAddress);
        
        do
        {
            nStatus = BSP_QSPI_GetStatus();
        }
        while (nStatus == QSPI_BUSY);
        
        if (nStatus != QSPI_OK)
        {
            //printf("Error: BSP_QSPI_Erase_Block failed for block %d, nStatus = %d\n", n+1, nStatus);
        }
        
        nSectorAddress += 0x1000;
        
        HAL_Delay(100);
    }

	return SUCCESS;
      
}	// End awe_pltEraseFlashMemorySector

#endif
