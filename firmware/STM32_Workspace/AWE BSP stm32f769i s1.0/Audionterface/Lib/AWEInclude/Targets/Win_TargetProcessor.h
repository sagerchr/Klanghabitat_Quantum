/* ----------------------------------------------------------------------------
 *	 Preprocessor Definitions
 * ------------------------------------------------------------------------- */

#ifndef WIN_TARGET_PROCESSOR_H_
#define WIN_TARGET_PROCESSOR_H_

#define VEC_RESTRICT	__restrict
#define VEC_INLINE		__inline

#define DISABLE_INTERRUPTS()
#define ENABLE_INTERRUPTS()

#include "Windows.h"

/*
 * @def FW_RESTRICT
 * @brief Compiler-specific C99 restrict keyword.
 */

#define FW_RESTRICT

#include "StandardDefs.h"

/* ----------------------------------------------------------------------
** Cycle counting macros
** ------------------------------------------------------------------- */

UINT32 awe_pltGetCycleCount(void);
UINT32 awe_pltElapsedCycles(UINT32 start_time, UINT32 end_time);

static VEC_INLINE void awe_fwCycleInit(void)
{
}

static VEC_INLINE UINT32 awe_fwGetCycles(void)
{
  LARGE_INTEGER ltime;
  LARGE_INTEGER freq;
  UINT32 cycles;
  double ftime;
  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&ltime);
  ftime = ((double)ltime.QuadPart / (double)freq.QuadPart) * 1e7;
  cycles = (UINT32)ftime;
  return (cycles);
}


static VEC_INLINE UINT32 awe_fwElapsedCycles(UINT32 start_time, UINT32 end_time)
{
  return end_time - start_time;
}

#endif	  /* !defined  WIN_TARGET_PROCESSOR_H_ */
