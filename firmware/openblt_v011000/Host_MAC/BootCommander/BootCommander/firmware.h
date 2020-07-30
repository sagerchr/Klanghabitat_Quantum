//
//  firmware.h
//  MACOpenBLT
//
//  Created by Christian Sager on 30.07.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#ifndef FIRMWARE_H
#define FIRMWARE_H

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Groups information together of a firmware segment, such that it can be used
 *         as a node in a linked list.
 */
typedef struct t_firmware_segment
{
  /** \brief Start memory address of the segment. */
  uint32_t base;
  /** \brief Number of data bytes in the segment. */
  uint32_t length;
  /** \brief Pointer to array with the segment's data bytes. */
  uint8_t *data;
  /** \brief Pointer to the previous node, or NULL if it is the first one. */
  struct t_firmware_segment * prev;
  /** \brief Pointer to the next node, or NULL if it is the last one. */
  struct t_firmware_segment * next;
} tFirmwareSegment;

/** \brief Firmware file parser. */
typedef struct t_firmware_parser
{
  /** \brief Extract the firmware segments from the firmware file and add them as nodes
   *         to the linked list.
   */
  bool (* LoadFromFile) (char const * firmwareFile, uint32_t addressOffset);
  /** \brief Write all the firmware segments from the linked list to the specified
   *         firmware file.
   */
  bool (* SaveToFile) (char const * firmwareFile);
} tFirmwareParser;


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void FirmwareInit(tFirmwareParser const * parser);
void FirmwareTerminate(void);
bool FirmwareLoadFromFile(char const * firmwareFile, uint32_t addressOffset);
bool FirmwareSaveToFile(char const * firmwareFile);
uint32_t FirmwareGetSegmentCount(void);
tFirmwareSegment * FirmwareGetSegment(uint32_t segmentIdx);
bool FirmwareAddData(uint32_t address, uint32_t len, uint8_t const * data);
bool FirmwareRemoveData(uint32_t address, uint32_t len);
void FirmwareClearData(void);


#ifdef __cplusplus
}
#endif

#endif /* FIRMWARE_H */
/********************************* end of firmware.h ***********************************/

 
 
