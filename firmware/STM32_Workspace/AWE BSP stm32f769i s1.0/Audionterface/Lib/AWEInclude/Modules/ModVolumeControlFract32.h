/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModVolumeControlFract32.h
****************************************************************************
*
*     Description:  Volume control with Fletcher-Munson loudness compensation
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
 * @brief Volume control with Fletcher-Munson loudness compensation
 */

#ifndef _MOD_VOLUMECONTROLFRACT32_H
#define _MOD_VOLUMECONTROLFRACT32_H

#include "ModCommon.h"
#include "MathHelper.h"
#include "ModBiquadSmoothedFract32.h"

#define MASK_VolumeControlFract32_gain 0x00000100
#define MASK_VolumeControlFract32_centerFreq 0x00000200
#define MASK_VolumeControlFract32_c2 0x00000400
#define MASK_VolumeControlFract32_c1 0x00000800
#define MASK_VolumeControlFract32_c0 0x00001000
#define MASK_VolumeControlFract32_b0_LPF 0x00002000
#define MASK_VolumeControlFract32_b1_LPF 0x00004000
#define MASK_VolumeControlFract32_b2_LPF 0x00008000
#define OFFSET_VolumeControlFract32_gain 0x00000008
#define OFFSET_VolumeControlFract32_centerFreq 0x00000009
#define OFFSET_VolumeControlFract32_c2 0x0000000A
#define OFFSET_VolumeControlFract32_c1 0x0000000B
#define OFFSET_VolumeControlFract32_c0 0x0000000C
#define OFFSET_VolumeControlFract32_b0_LPF 0x0000000D
#define OFFSET_VolumeControlFract32_b1_LPF 0x0000000E
#define OFFSET_VolumeControlFract32_b2_LPF 0x0000000F

#define CLASSID_VOLUMECONTROLFRACT32 (CLASS_ID_MODBASE + 214)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modVolumeControlFract32Instance
{
    ModuleInstanceDescriptor instance;
    FLOAT32            gain;                // Gain through the volume control
    FLOAT32            centerFreq;          // Center frequency of the low frequency resonance
    FLOAT32            c2;                  // X^2 coefficient
    FLOAT32            c1;                  // X^1 coefficient
    FLOAT32            c0;                  // X^0 coefficient
    FLOAT32            b0_LPF;              // First numerator coefficient
    FLOAT32            b1_LPF;              // Second numerator coefficient
    FLOAT32            b2_LPF;              // Third numerator coefficient
        awe_modBiquadSmoothedFract32Instance    *mixerFilt;          // 2nd order smoothly updating IIR filter
} awe_modVolumeControlFract32Instance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modVolumeControlFract32Class;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
ModInstanceDescriptor * awe_modVolumeControlFract32Constructor(INT32 * FW_RESTRICT retVal, UINT32 nIO, WireInstance ** FW_RESTRICT pWires, size_t argCount, const Sample * FW_RESTRICT args);
#endif // #ifndef AWE_STATIC_CODE


void awe_modVolumeControlFract32Process(void *pInstance);

UINT32 awe_modVolumeControlFract32Set(void *pInstance, UINT32 mask);
 



#ifdef __cplusplus
}
#endif


#endif // _MOD_VOLUMECONTROLFRACT32_H

/**
 * @}
 *
 * End of file.
 */