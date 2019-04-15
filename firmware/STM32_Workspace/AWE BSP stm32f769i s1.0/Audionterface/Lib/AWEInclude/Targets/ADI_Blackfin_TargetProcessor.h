/* ----------------------------------------------------------------------------
 *       Preprocessor Definitions
 * ------------------------------------------------------------------------- */

#ifndef ADI_BLACKFIN_TARGET_PROCESSOR_H_
#define ADI_BLACKFIN_TARGET_PROCESSOR_H_

#define VEC_RESTRICT    restrict
#define VEC_INLINE              inline

#if defined(__ADSPBF537__)
#include <cdefbf537.h>
#include <defbf537.h>
#elif defined(__ADSPBF561__)
#include <cdefbf561.h>
#include <defbf561.h>
#elif defined(__ADSPBF527__)
#include <cdefbf527.h>
#include <defbf527.h>
#elif defined(__ADSPBF548__)
#include <cdefBF548.h>
#include <defBF548.h>
#elif defined(__ADSPBF592A__)
#include <cdefBF592-A.h>
#include <defBF592-A.h>
#elif defined(__ADSPBF609__)
#include <cdefBF609.h>
#include <defBF609.h>
#elif defined(__ADSPBF707__)
#include <cdefBF707.h>
#include <defBF707.h>
#else
// For now, assume 532/533/531
#include <cdefbf532.h>
#include <defbf532.h>
#endif

#include <ccblkfn.h>

// These macros have to be used as a pair because of the local
// variable imask which is created.

#define DISABLE_INTERRUPTS() { \
  asm("SSYNC;"); \
  unsigned int imask = cli()

#define ENABLE_INTERRUPTS() \
  asm("SSYNC;"); \
  sti(imask); \
  }


/**
 * @def FW_RESTRICT
 * @brief Compiler-specific C99 restrict keyword.
 */

#define FW_RESTRICT		restrict

#ifdef __ECC__
#include "StandardDefs.h"
#endif

/* ----------------------------------------------------------------------
** Memory segments for various processors
** ------------------------------------------------------------------- */

#ifdef __ECC__
#define AWE_MOD_SLOW_CODE section("awe_mod_slowcode")
#define AWE_MOD_FAST_CODE section("awe_mod_fastcode")

#define AWE_FW_SLOW_CODE section("awe_fw_slowcode")
#define AWE_FW_FAST_CODE section("awe_fw_fastcode")

#define AWE_USB_INTERNAL_CODE section("awe_usb_internalcode")

#define AWE_PRIO0_FAST_CODE section("awe_prio0_fastcode")

#define AWE_MOD_SLOW_DM_DATA section("awe_mod_slowdmdata")
#define AWE_MOD_FAST_DM_DATA section("awe_mod_fastdmdata")
#define AWE_MOD_SLOW_PM_DATA section("awe_mod_slowpmdata")
#define AWE_MOD_FAST_PM_DATA section("awe_mod_fastpmdata")

#define AWE_FW_SLOW_DM_DATA section("awe_fw_slowdmdata")
#define AWE_FW_FAST_DM_DATA section("awe_fw_fastdmdata")
#define AWE_FW_SLOW_PM_DATA section("awe_fw_slowpmdata")
#define AWE_FW_FAST_PM_DATA section("awe_fw_fastpmdata")

// Used by statically generated code
#define AWE_FW_WIRE_DATA section("awe_fw_wiredata")

#define AWE_USB_INTERNAL_DATA section("awe_usb_internaldata")

#define AWE_FAST_DMA_DATA section("awe_fastdmadata")

#define AWE_MOD_SLOW_DM_CONST section("awe_mod_slowdmconst")
#define AWE_MOD_FAST_DM_CONST section("awe_mod_fastdmconst")
#define AWE_MOD_SLOW_PM_CONST section("awe_mod_slowpmconst")
#define AWE_MOD_FAST_PM_CONST section("awe_mod_fastpmconst")
#define AWE_MOD_SLOW_ANY_DATA section("awe_mod_slowanydata")
#define AWE_MOD_FAST_ANY_DATA section("awe_mod_fastanydata")

#define AWE_MOD_SLOW_ANY_CONST section("awe_mod_slowanyconst")
#define AWE_MOD_FAST_ANY_CONST section("awe_mod_fastanyconst")

#define AWE_FW_SLOW_DM_CONST section("awe_fw_slowdmconst")
#define AWE_FW_FAST_DM_CONST section("awe_fw_fastdmconst")
#define AWE_FW_SLOW_PM_CONST section("awe_fw_slowpmconst")
#define AWE_FW_FAST_PM_CONST section("awe_fw_fastpmconst")
#define AWE_FW_SLOW_ANY_DATA section("awe_fw_slowanydata")
#define AWE_FW_FAST_ANY_DATA section("awe_fw_fastanydata")

#define AWE_FW_SLOW_ANY_CONST section("awe_fw_slowanyconst")
#define AWE_FW_FAST_ANY_CONST section("awe_fw_fastanyconst")

/* Note that a #define statement cannot include a #pragma (this is
** a limitation of the C language).      Fortunately, VDSP offers
** a work around. */

#define AWE_OPTIMIZE_FOR_SPEED _Pragma("optimize_for_speed")
#define AWE_OPTIMIZE_FOR_SPACE _Pragma("optimize_for_space")
#define AWE_OPTIMIZE_OFF _Pragma("optimize_off")

#endif

/* ----------------------------------------------------------------------
** Cycle counting macros
** ------------------------------------------------------------------- */

static VEC_INLINE UINT32 awe_fwGetCycles(void)
{
  UINT32 _tcount;
  __asm volatile ("%0=CYCLES;" : "=d" (_tcount));
  return _tcount;
}

static VEC_INLINE UINT32 awe_fwElapsedCycles(UINT32 start_time, UINT32 end_time)
{
  return end_time - start_time;
}

#endif    /* !defined  ADI_BLACKFIN_TARGET_PROCESSOR_H_ */
