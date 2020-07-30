//
//  xcpprotect.c
//  MACOpenBLT
//
//  Created by Christian Sager on 30.07.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#include <assert.h>                         /* for assertions                          */
#include <stdint.h>                         /* for standard integer types              */
#include <stddef.h>                         /* for NULL declaration                    */
#include <stdbool.h>                        /* for boolean type                        */
#include <dlfcn.h>                          /* for dynamic loading                     */
#include "xcpprotect.h"                     /* XCP protection module                   */


/****************************************************************************************
* Type definitions
****************************************************************************************/
/* Seed and key shared library function types. */
typedef uint32_t ( * tXcpProtectLibComputeKey)(uint8_t resource, uint8_t seedLen,
                                               uint8_t const * seedPtr,
                                               uint8_t * keyLenPtr, uint8_t * keyPtr);
typedef uint32_t ( * tXcpProtectLibGetPrivileges)(uint8_t * resourcePtr);


/****************************************************************************************
* Local data declarations
****************************************************************************************/
/** \brief Handle to the dynamically loaded seed and key shared library. It can also be
 *         used as a flag to determine if the shared library was specified and success-
 *         fully loaded.
 */
static void * seedNKeyLibraryHandle;

/** \brief Function pointer to the XCP_ComputeKeyFromSeed shared library function. */
static tXcpProtectLibComputeKey xcpProtectLibComputeKey;

/** \brief Function pointer to the XCP_GetAvailablePrivileges shared library function. */
static tXcpProtectLibGetPrivileges xcpProtectLibGetPrivileges;


/************************************************************************************//**
** \brief     Initializes the XCP protection module.
** \param     seedKeyFile Filename of the seed and key shared library that contains the
**            following functions:
**            - XCP_ComputeKeyFromSeed()
**            - XCP_GetAvailablePrivileges()
**
****************************************************************************************/
void XcpProtectInit(char const * seedKeyFile)
{
  /* Init locals. */
  seedNKeyLibraryHandle = NULL;
  /* Reset library function pointers. */
  xcpProtectLibComputeKey = NULL;
  xcpProtectLibGetPrivileges = NULL;

  /* Only load the shared library is a valid file was specified. */
  if (seedKeyFile != NULL)
  {
    /* Attempt to load the shared library. */
    seedNKeyLibraryHandle = dlopen(seedKeyFile, RTLD_LAZY);
    /* Load the function pointers from the shared library. */
    if (seedNKeyLibraryHandle != NULL)
    {
      xcpProtectLibComputeKey = dlsym(seedNKeyLibraryHandle,
                                      "XCP_ComputeKeyFromSeed");
      xcpProtectLibGetPrivileges = dlsym(seedNKeyLibraryHandle,
                                         "XCP_GetAvailablePrivileges");
    }
  }
} /*** end of XcpProtectInit ***/


/************************************************************************************//**
** \brief     Terminates the XCP protection module.
**
****************************************************************************************/
void XcpProtectTerminate(void)
{
  /* Reset library function pointers. */
  xcpProtectLibComputeKey = NULL;
  xcpProtectLibGetPrivileges = NULL;
  /* Only unload the shared library if one was loaded. */
  if (seedNKeyLibraryHandle != NULL)
  {
    /* Unload the shared library. */
    (void)dlclose(seedNKeyLibraryHandle);
    /* Reset the handle. */
    seedNKeyLibraryHandle = NULL;
  }
} /*** end of XcpProtectTerminate ***/


/************************************************************************************//**
** \brief     Computes the key for the requested resource.
** \param     resource resource for which the unlock key is requested
** \param     seedLen  length of the seed
** \param     seedPtr  pointer to the seed data
** \param     keyLenPtr pointer where to store the key length
** \param     keyPtr pointer where to store the key data
** \return    True if successful, false otherwise.
**
****************************************************************************************/
bool XCPProtectComputeKeyFromSeed(uint8_t resource, uint8_t seedLen,
                                  uint8_t const * seedPtr, uint8_t * keyLenPtr,
                                  uint8_t * keyPtr)
{
  bool result = false;

  /* Check parameters. */
  assert(seedLen > 0);
  assert(seedPtr != NULL);
  assert(keyLenPtr != NULL);
  assert(keyPtr != NULL);

  /* Only continue if the parameters are valid. */
  if ( (seedLen > 0) && (seedPtr != NULL) && (keyLenPtr != NULL) &&
       (keyPtr != NULL) ) /*lint !e774 */
  {
    /* Only continue with a valid function pointer into the shared library. */
    if (xcpProtectLibComputeKey != NULL)
    {
      /* Call the library function. */
      if (xcpProtectLibComputeKey(resource, seedLen, seedPtr, keyLenPtr, keyPtr) == 0)
      {
        /* All good so update the result value accordingly. */
        result = true;
      }
    }
  }
  /* Give the result back to the caller. */
  return result;
} /*** end of XCPProtectComputeKeyFromSeed ***/


/************************************************************************************//**
** \brief     Obtains a bitmask of the resources for which an key algorithm is available.
** \param     resourcePtr pointer where to store the supported resources for the key
**                        computation.
** \return    XCP_RESULT_OK on success, otherwise XCP_RESULT_ERROR.
**
****************************************************************************************/
bool XcpProtectGetPrivileges(uint8_t * resourcePtr)
{
  bool result = false;

  /* Check parameters. */
  assert(resourcePtr != NULL);

  /* Only continue if the parameter is valid. */
  if (resourcePtr != NULL) /*lint !e774 */
  {
    /* Only continue with a valid function pointer into the shared library. */
    if (xcpProtectLibGetPrivileges != NULL)
    {
      /* Call the library function. */
      if (xcpProtectLibGetPrivileges(resourcePtr) == 0)
      {
        /* All good so update the result value accordingly. */
        result = true;
      }
    }
  }
  /* Give the result back to the caller. */
  return result;
} /*** end of XcpProtectGetPrivileges ***/


/*********************************** end of xcpprotect.c *******************************/
