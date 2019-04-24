// ----------------------------------------------------------------------
// DSP Concepts Asynchronous sample rate converter coefficient file.
//
// FSin: 48000
// FSout: 48000
// Interpolation factor M: 8
// Passband frequency edge: 18000 Hz
// Stopband frequency edge: 24000 Hz
// Stopband attenuation: 60.0 dB
// Maximum measured THD and frequency
// Linear interpolation:  -50.8 dB at frequency  11882.81 Hz 
// Cubic interpolation:   -71.3 dB at frequency  10324.22 Hz 
// Length of interpolation filter: 264
// Filter iterations per sample (filter phase): 24
// Fractional fStep = 1.000000
// ----------------------------------------------------------------------
#ifndef _DSPC_ASRC_48000_TO_48000_8M_060DB_H_
#define _DSPC_ASRC_48000_TO_48000_8M_060DB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "dspc_asrc.h"

#define ASRC_PHASELEN_24 24
#define ASRC_FS_IN_48000 48000
#define ASRC_FS_OUT_48000 48000

extern DSPC_ASRC_PROPS DSPC_ASRC_48000_TO_48000_8M_060DB_PROPS;

#ifdef __cplusplus
}
#endif

#endif /* !defined DSPC_ASRC_H_ */
