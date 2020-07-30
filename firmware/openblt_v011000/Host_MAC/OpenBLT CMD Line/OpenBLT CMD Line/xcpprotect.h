//
//  xcpprotect.h
//  MACOpenBLT
//
//  Created by Christian Sager on 30.07.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#ifndef XCPPROTECT_H
#define XCPPROTECT_H

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************************
* Macro definitions
****************************************************************************************/
/* XCP supported resources. */
#define XCPPROTECT_RESOURCE_PGM        (0x10u)   /**< ProGraMing resource.             */
#define XCPPROTECT_RESOURCE_STIM       (0x08u)   /**< data STIMulation resource.       */
#define XCPPROTECT_RESOURCE_DAQ        (0x04u)   /**< Data AcQuisition resource.       */
#define XCPPROTECT_RESOURCE_CALPAG     (0x01u)   /**< CALibration and PAGing resource. */


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void XcpProtectInit(char const * seedKeyFile);
void XcpProtectTerminate(void);
bool XCPProtectComputeKeyFromSeed(uint8_t resource, uint8_t seedLen,
                                  uint8_t const * seedPtr, uint8_t * keyLenPtr,
                                  uint8_t * keyPtr);
bool XcpProtectGetPrivileges(uint8_t * resourcePtr);


#ifdef __cplusplus
}
#endif

#endif /* XCPPROTECT_H */
/*********************************** end of xcpprotect.h *******************************/
