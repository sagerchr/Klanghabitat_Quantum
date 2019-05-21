/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModIntToFloat.h
****************************************************************************
*
*     Description:  Integer to floating-point conversion
*
*     Copyright:    DSP Concepts, Inc, 2007 - 2017
*                   1800 Wyatt Drive, Suite 14
*                   Santa Clara, CA 95054
*
***************************************************************************/

/**
 * @addtogroup Modules
 * @{
 */

/**
 * @file
 * @brief Integer to floating-point conversion
 */

#ifndef _MOD_INTTOFLOAT_H
#define _MOD_INTTOFLOAT_H

#include "ModCommon.h"
#include "MathHelper.h"


#define CLASSID_INTTOFLOAT (CLASS_ID_MODBASE + 2017)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modIntToFloatInstance
{
    ModuleInstanceDescriptor instance;
    
    
} awe_modIntToFloatInstance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modIntToFloatClass;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
// This points the constructor for this class to the base constructor
#define awe_modIntToFloatConstructor(ARG1, ARG2, ARG3, ARG4, ARG5) ClassModule_Constructor(CLASSID_INTTOFLOAT, ARG1, ARG2, ARG3, ARG4, ARG5)
#endif // #ifndef AWE_STATIC_CODE


void awe_modIntToFloatProcess(void *pInstance);

 

void awe_modIntToFloatBypass(void *pInstance);


#ifdef __cplusplus
}
#endif


#endif // _MOD_INTTOFLOAT_H

/**
 * @}
 *
 * End of file.
 */