// ----------------------------------------------------------------------
// DSP Concepts Asynchronous sample rate converter coefficient file.
//
// FSin: 48000
// FSout: 16000
// Interpolation factor M: 32
// Passband frequency edge: 6000 Hz
// Stopband frequency edge: 8000 Hz
// Stopband attenuation: 80.0 dB
// Maximum measured THD and frequency
// Linear interpolation:  -69.8 dB at frequency    113.28 Hz 
// Cubic interpolation:   -79.3 dB at frequency    230.47 Hz 
// Length of interpolation filter: 2660
// Filter iterations per sample (filter phase): 76
// Fractional fStep = 3.000000
// ----------------------------------------------------------------------
#ifndef _DSPC_ASRC_48000_TO_16000_32M_080DB_H_
#define _DSPC_ASRC_48000_TO_16000_32M_080DB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "dspc_asrc.h"

#define ASRC_PHASELEN_76 76
#define ASRC_FS_IN_48000 48000
#define ASRC_FS_OUT_16000 16000

extern DSPC_ASRC_PROPS DSPC_ASRC_48000_TO_16000_32M_080DB_PROPS;

#ifdef __cplusplus
}
#endif

#endif /* !defined DSPC_ASRC_H_ */
