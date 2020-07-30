//
//  netaccess.h
//  MACOpenBLT
//
//  Created by Christian Sager on 30.07.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#ifndef NETACCESS_H
#define NETACCESS_H

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************************
* Function prototypes
****************************************************************************************/
void NetAccessInit(void);
void NetAccessTerminate(void);
bool NetAccessConnect(char const * address, uint16_t port);
void NetAccessDisconnect(void);
bool NetAccessSend(uint8_t const * data, uint32_t length);
bool NetAccessReceive(uint8_t * data, uint32_t * length, uint32_t timeout);

#ifdef __cplusplus
}
#endif

#endif /* NETACCESS_H */
/********************************* end of netaccess.h **********************************/

