//
//  util.h
//  MACOpenBLT
//
//  Created by Christian Sager on 30.07.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#ifndef UTIL_H
#define UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************************
* Function prototypes
****************************************************************************************/
uint16_t UtilChecksumCrc16Calculate(uint8_t const * data, uint32_t len);
uint32_t UtilChecksumCrc32Calculate(uint8_t const * data, uint32_t len);
bool UtilFileExtractFilename(char const * fullFilename, char * filenameBuffer);
uint32_t UtilTimeGetSystemTimeMs(void);
void UtilTimeDelayMs(uint16_t delay);
void UtilCriticalSectionInit(void);
void UtilCriticalSectionTerminate(void);
void UtilCriticalSectionEnter(void);
void UtilCriticalSectionExit(void);
bool UtilCryptoAes256Encrypt(uint8_t * data, uint32_t len, uint8_t const * key);
bool UtilCryptoAes256Decrypt(uint8_t * data, uint32_t len, uint8_t const * key);


#ifdef __cplusplus
}
#endif

#endif /* UTIL_H */
/********************************* end of util.h ***************************************/

