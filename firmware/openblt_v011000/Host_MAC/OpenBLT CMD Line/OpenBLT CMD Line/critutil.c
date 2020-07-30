//
//  critutil.c
//  MACOpenBLT
//
//  Created by Christian Sager on 30.07.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#include <assert.h>                         /* for assertions                          */
#include <stdint.h>                         /* for standard integer types              */
#include <stdbool.h>                        /* for boolean type                        */
#include <pthread.h>                        /* for posix threads                       */
#include "util.h"                           /* Utility module                          */


/****************************************************************************************
* Local data declarations
****************************************************************************************/
/** \brief Flag to determine if the critical section object was already initialized. */
static volatile bool criticalSectionInitialized = false;

/** \brief Critical section object. */
static volatile pthread_mutex_t mtxCritSect;


/************************************************************************************//**
** \brief     Initializes the critical section module. Should be called before the
**            Enter/Exit functions are used. It is okay to call this initialization
**            multiple times from different modules.
**
****************************************************************************************/
void UtilCriticalSectionInit(void)
{
  /* Only initialize if not yet done so previously. */
  if (!criticalSectionInitialized)
  {
    /* Initialize the critical section object. */
    (void)pthread_mutex_init((pthread_mutex_t *)&mtxCritSect, NULL);
    /* Set initialized flag. */
    criticalSectionInitialized = true;
  }
} /*** end of UtilCriticalSectionInit ***/


/************************************************************************************//**
** \brief     Terminates the critical section module. Should be called once critical
**            sections are no longer needed. Typically called from another module's
**            termination function that also initialized it. It is okay to call this
**            termination multiple times from different modules.
**
****************************************************************************************/
void UtilCriticalSectionTerminate(void)
{
  /* Only terminate if it was initialized. */
  if (criticalSectionInitialized)
  {
    /* Reset the initialized flag. */
    criticalSectionInitialized = false;
    /* Delete the critical section object. */
    (void)pthread_mutex_destroy((pthread_mutex_t *)&mtxCritSect);
  }
} /*** end of UtilCriticalSectionTerminate ***/



/************************************************************************************//**
** \brief     Enters a critical section. The functions UtilCriticalSectionEnter and
**            UtilCriticalSectionExit should always be used in a pair.
**
****************************************************************************************/
void UtilCriticalSectionEnter(void)
{
  /* Check initialization. */
  assert(criticalSectionInitialized);

  /* Only continue if actually initialized. */
  if (criticalSectionInitialized)
  {
    (void)pthread_mutex_lock((pthread_mutex_t *)&mtxCritSect);
  }
} /*** end of UtilCriticalSectionEnter ***/ /*lint !e456 !e454 */


/************************************************************************************//**
** \brief     Leaves a critical section. The functions UtilCriticalSectionEnter and
**            UtilCriticalSectionExit should always be used in a pair.
**
****************************************************************************************/
void UtilCriticalSectionExit(void)
{
  /* Check initialization. */
  assert(criticalSectionInitialized);

  /* Only continue if actually initialized. */
  if (criticalSectionInitialized)
  {
    (void)pthread_mutex_unlock((pthread_mutex_t *)&mtxCritSect); /*lint !e455 */
  }
} /*** end of UtilCriticalSectionExit ***/


/*********************************** end of critutil.c *********************************/

