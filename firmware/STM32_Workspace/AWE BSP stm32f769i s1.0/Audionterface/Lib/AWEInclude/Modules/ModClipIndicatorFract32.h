/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModClipIndicatorFract32.h
****************************************************************************
*
*     Description:  Detects clipping by measuring when a signal level exceeds a specified threshold
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
 * @brief Detects clipping by measuring when a signal level exceeds a specified threshold
 */

#ifndef _MOD_CLIPINDICATORFRACT32_H
#define _MOD_CLIPINDICATORFRACT32_H

#include "ModCommon.h"
#include "MathHelper.h"

#define MASK_ClipIndicatorFract32_threshold 0x00000100
#define MASK_ClipIndicatorFract32_attackTime 0x00000200
#define MASK_ClipIndicatorFract32_releaseTime 0x00000400
#define MASK_ClipIndicatorFract32_thresholdCoeff 0x00000800
#define MASK_ClipIndicatorFract32_attackCoeff 0x00001000
#define MASK_ClipIndicatorFract32_releaseCoeff 0x00002000
#define MASK_ClipIndicatorFract32_value 0x00004000
#define MASK_ClipIndicatorFract32_isClipping 0x00008000
#define OFFSET_ClipIndicatorFract32_threshold 0x00000008
#define OFFSET_ClipIndicatorFract32_attackTime 0x00000009
#define OFFSET_ClipIndicatorFract32_releaseTime 0x0000000A
#define OFFSET_ClipIndicatorFract32_thresholdCoeff 0x0000000B
#define OFFSET_ClipIndicatorFract32_attackCoeff 0x0000000C
#define OFFSET_ClipIndicatorFract32_releaseCoeff 0x0000000D
#define OFFSET_ClipIndicatorFract32_value 0x0000000E
#define OFFSET_ClipIndicatorFract32_isClipping 0x0000000F

#define CLASSID_CLIPINDICATORFRACT32 (CLASS_ID_MODBASE + 138)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modClipIndicatorFract32Instance
{
    ModuleInstanceDescriptor instance;
    FLOAT32            threshold;           // Threshold in dB above which clipping occurs
    FLOAT32            attackTime;          // Attack time of the clipping detector.  Specifies how quickly the value is allowed to rise
    FLOAT32            releaseTime;         // Release time of the clipping detector.  Specifies how quickly the value is allowed to decay
    fract32            thresholdCoeff;      // Internal derived parameter which equals undb20(threshold)
    fract32            attackCoeff;         // Internal coefficient that realizes the attack time
    fract32            releaseCoeff;        // Internal coefficient that realizes the release time
    fract32*           value;               // Internal array of envelope follower state variables, one per channel
    INT32*             isClipping;          // Boolean array of clipping values, one per channel
} awe_modClipIndicatorFract32Instance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modClipIndicatorFract32Class;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
ModInstanceDescriptor * awe_modClipIndicatorFract32Constructor(INT32 * FW_RESTRICT retVal, UINT32 nIO, WireInstance ** FW_RESTRICT pWires, size_t argCount, const Sample * FW_RESTRICT args);
#endif // #ifndef AWE_STATIC_CODE


void awe_modClipIndicatorFract32Process(void *pInstance);

UINT32 awe_modClipIndicatorFract32Set(void *pInstance, UINT32 mask);
 



#ifdef __cplusplus
}
#endif


#endif // _MOD_CLIPINDICATORFRACT32_H

/**
 * @}
 *
 * End of file.
 */