/*******************************************************************************
*
*               Audio Framework
*               ---------------
*
********************************************************************************
*     AWEFlash.c
********************************************************************************
*
*     Description:  AudioWeaver Flash Memory Interface
*
*     Copyright:    DSP Concepts, Inc. (c) 2007 - 2016
*                   1800 Wyatt Drive, Suite 14
*                   Sunnyvale, CA 95054
*
*******************************************************************************/
//#include <stdio.h>
#include "stm32f769i_discovery_qspi.h"
#include "AWEFlash.h"

/* ----------------------------------------------------------------------
** Initialize the flash file system
** ------------------------------------------------------------------- */

UINT32 const FLASH_MEMORY_SIZE_IN_BYTES = MX25L512_FLASH_SIZE;
UINT32 const FLASH_MEMORY_SIZE_IN_WORDS = MX25L512_FLASH_SIZE >> 2;
UINT32 const ERASEABLE_BLOCKSIZE = MX25L512_SUBSECTOR_SIZE;
UINT32 const FILE_SYSTEM_START_OFFSET = 0x00000000;	
UINT32 const FLASH_START_OFFSET = 0x000000;


///-----------------------------------------------------------------------------
/// @name  INT32 awe_pltGetFlashEraseTime(void)
/// @brief Number of seconds to erase flash file system
///
/// @retval  	Number of seconds to erase the flash file system
///-----------------------------------------------------------------------------
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
