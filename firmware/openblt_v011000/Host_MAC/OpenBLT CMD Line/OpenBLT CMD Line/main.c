//
//  main.c
//  OpenBLT CMD Line
//
//  Created by Christian Sager on 30.07.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#include <stdio.h>
#include "openblt.h"
#include <unistd.h>
#include <assert.h>


int main(int argc, const char * argv[]) {
    
    printf(BltVersionGetString());
    
    BltFirmwareInit(BLT_FIRMWARE_PARSER_SRECORD);
    tBltSessionSettingsXcpV10 Sessionsettings;
    tBltTransportSettingsXcpV10Rs232 TransportSettings;

    
    Sessionsettings.timeoutT1 = 1000;
    Sessionsettings.timeoutT3 = 2000;
    Sessionsettings.timeoutT4 = 10000;
    Sessionsettings.timeoutT5 = 1000;
    Sessionsettings.timeoutT6 = 50;
    Sessionsettings.timeoutT7 = 2000;
    Sessionsettings.connectMode = 0;
    
    TransportSettings.portName = "/dev/cu.usbmodem142503";
    TransportSettings.baudrate = 57600;


    BltSessionInit(BLT_SESSION_XCP_V10, &Sessionsettings, BLT_TRANSPORT_XCP_V10_RS232,&TransportSettings);
    BltUtilTimeGetSystemTime();
    
    
    
    
    BltSessionStart();

    while(BltSessionStart() != BLT_RESULT_OK){
    }
    
    printf("\r\nwe are connected!\r\n");

    printf("Waiting 1 seconds!\r\n");
    
    int i=0;
    while(i<1){
        sleep(1);
        printf("counting %d seconds\r\n",i);
        i++;
    }
    
    
    
    #define RESULT_OK                           (0)
    #define RESULT_ERROR_FIRMWARE_LOAD          (2)
    int result = RESULT_OK;
    
    char const * appFirmwareFile = "/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Prog/Debug/demoprog_stm32f767.srec";
    
    
    
    
    
   printf("Loading firmware data from file..."); (void)fflush(stdout);
    /* Initialize the firmware data module using the S-record parser. */
    BltFirmwareInit(BLT_FIRMWARE_PARSER_SRECORD);
    /* Load firmware data from the firmware file without memory address offset. */
    if (BltFirmwareLoadFromFile(appFirmwareFile, 0) != BLT_RESULT_OK)
    {
      /* Set error code. */
      result = RESULT_ERROR_FIRMWARE_LOAD;
    }
    /* Check to make sure that data was actually present, in which case at least one
     * firmware data segment should be there.
     */
    if (result == RESULT_OK)
    {
      if (BltFirmwareGetSegmentCount() == 0)
      {
        /* Set error code. */
        result = RESULT_ERROR_FIRMWARE_LOAD;
      }
    }
    //printf("%s\n", GetLineTrailerByResult((bool)(result != RESULT_OK)));
    /* Determine and output firmware data statistics. */
    if (result == RESULT_OK)
    {
      uint32_t firmwareDataTotalSize;
      uint32_t firmwareDataTotalSegments;
      uint32_t firmwareDataBaseAddress = 0;
      uint32_t segmentIdx;
      uint32_t segmentLen;
      uint32_t segmentBase;
      uint8_t const * segmentData;
      
      /* Store the number of segments. */
      firmwareDataTotalSegments = BltFirmwareGetSegmentCount();
      /* Loop through all segments. */
      firmwareDataTotalSize = 0;
      for (segmentIdx = 0; segmentIdx < firmwareDataTotalSegments; segmentIdx++)
      {
        /* Extract segment info. */
        segmentData = BltFirmwareGetSegment(segmentIdx, &segmentBase, &segmentLen);
        /* Sanity check. */
        assert( (segmentData != NULL) && (segmentLen > 0) );
        /* Update total size. */
        firmwareDataTotalSize += segmentLen;
        /* If it is the first segment, then store the base address. */
        if (segmentIdx == 0)
        {
          firmwareDataBaseAddress = segmentBase;
        }
      }
    }
    

    BltSessionStop();
    printf("\r\nStop Session and go ahead with user programm\r\n");
    BltSessionTerminate();
    BltFirmwareTerminate();
   
    printf("Programm finished\r\n\r\n\r\n");
}
