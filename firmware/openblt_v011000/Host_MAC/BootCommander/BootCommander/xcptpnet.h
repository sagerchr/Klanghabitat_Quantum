//
//  xcptpnet.h
//  MACOpenBLT
//
//  Created by Christian Sager on 30.07.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#ifndef XCPTPNET_H
#define XCPTPNET_H

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************************
* Type definitions
****************************************************************************************/
/** \brief Layout of structure with settings specific to the XCP transport layer module
 *         for TCP/IP.
 */
typedef struct t_xcp_tp_net_settings
{
  char const * address;          /**< Target IP-address or hostname on the network.    */
  uint16_t port;                 /**< TCP port to use.                                 */
} tXcpTpNetSettings;


/***************************************************************************************
* Function prototypes
****************************************************************************************/
tXcpTransport const * XcpTpNetGetTransport(void);

#ifdef __cplusplus
}
#endif

#endif /* XCPTPNET_H */
/*********************************** end of xcptpnet.h *********************************/
