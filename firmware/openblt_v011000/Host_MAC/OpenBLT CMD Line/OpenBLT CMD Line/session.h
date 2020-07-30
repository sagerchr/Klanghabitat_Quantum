//
//  session.h
//  MACOpenBLT
//
//  Created by Christian Sager on 30.07.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#ifndef SESSION_H
#define SESSION_H

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Session communication protocol interface. */
typedef struct t_session_protocol
{
  /** \brief Initializes the protocol module. */
  void (* Init) (void const * settings);
  /** \brief Terminates the protocol module. */
  void (* Terminate) (void);
  /** \brief Starts the firmware update session. This is where the connection with the
   *         target is made and the bootloader on the target is activated.
   */
  bool (* Start) (void);
  /** \brief Stops the firmware update. This is where the bootloader starts the user
   *         program on the target if a valid one is present. After this the connection
   *         with the target is severed.
   */
  void (* Stop) (void);
  /** \brief Requests the bootloader to erase the specified range of memory on the
   *         target. The bootloader aligns this range to hardware specified erase blocks.
   */
  bool (* ClearMemory) (uint32_t address, uint32_t len);
  /** \brief Requests the bootloader to program the specified data to memory. In case of
   *         non-volatile memory, the application needs to make sure the memory range
   *         was erased beforehand.
   */
  bool (* WriteData) (uint32_t address, uint32_t len, uint8_t const * data);
  /** \brief Request the bootloader to upload the specified range of memory. The data is
   *         stored in the data byte array to which the pointer was specified.
   */
  bool (* ReadData) (uint32_t address, uint32_t len, uint8_t * data);
} tSessionProtocol;


/****************************************************************************************
* Function prototypes
****************************************************************************************/
void SessionInit(tSessionProtocol const * protocol, void const * protocolSettings);
void SessionTerminate(void);
bool SessionStart(void);
void SessionStop(void);
bool SessionClearMemory(uint32_t address, uint32_t len);
bool SessionWriteData(uint32_t address, uint32_t len, uint8_t const * data);
bool SessionReadData(uint32_t address, uint32_t len, uint8_t * data);


#ifdef __cplusplus
}
#endif

#endif /* SESSION_H */
/********************************* end of session.h ************************************/

 
 
