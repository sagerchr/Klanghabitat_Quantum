//
//  timeutil.c
//  MACOpenBLT
//
//  Created by Christian Sager on 30.07.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#include <stdint.h>                         /* for standard integer types              */
#include <stddef.h>                         /* for NULL declaration                    */
#include <stdbool.h>                        /* for boolean type                        */
#include <unistd.h>                         /* UNIX standard functions                 */
#include <sys/time.h>                       /* time definitions                        */
#include "util.h"                           /* Utility module                          */


/************************************************************************************//**
** \brief     Get the system time in milliseconds.
** \return    Time in milliseconds.
**
****************************************************************************************/
uint32_t UtilTimeGetSystemTimeMs(void)
{
  uint32_t result = 0;
  struct timeval tv;

  if (gettimeofday(&tv, NULL) == 0)
  {
    result = (((uint32_t)tv.tv_sec * 1000ul) + ((uint32_t)tv.tv_usec / 1000ul));
  }
  /* Give the result back to the caller. */
  return result;
} /*** end of UtilTimeGetSystemTimeMs ***/


/************************************************************************************//**
** \brief     Performs a delay of the specified amount of milliseconds.
** \param     delay Delay time in milliseconds.
**
****************************************************************************************/
void UtilTimeDelayMs(uint16_t delay)
{
  (void)usleep(1000u * delay);
} /*** end of UtilTimeDelayMs **/


/*********************************** end of timeutil.c *********************************/

