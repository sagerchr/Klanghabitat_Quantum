/* ----------------------------------------------------------------------------
 *	 Preprocessor Definitions
 * ------------------------------------------------------------------------- */

#ifndef ADI_SHARC_TARGET_PROCESSOR_H_
#define ADI_SHARC_TARGET_PROCESSOR_H_

#define VEC_RESTRICT	restrict
#define VEC_INLINE		inline

#define USE_SIMD2

#ifdef __2136x__
#if defined(__ADSP21367__) || defined(__ADSP21368__) || defined(__ADSP21369__)
#include <def21369.h>
#ifdef __ECC__
asm("#include <def21369.h>");
#endif

#else
#include <def21365.h>
#ifdef __ECC__
asm("#include <def21364.h>");
#endif
#endif
#endif //__2136x__

#ifdef __2137x__
#include <def21375.h>
#ifdef __ECC__
asm("#include <def21375.h>");
#endif

/* Define the macro if anomaly exists */
#define WORKAROUND_FOR_ANOMALY_15000004
#define WORKAROUND_FOR_ANOMALY_09000018

#endif //__2137x__

#ifdef __ADSP21469__
#include <def21469.h>
#ifdef __ECC__
asm("#include <def21469.h>");
#endif

/* Define the macro if anomaly exists */
#define WORKAROUND_FOR_ANOMALY_15000004
#endif //__ADSP21469__

#ifdef __ADSP21479__
#include <def21479.h>
#ifdef __ECC__
asm("#include <def21479.h>");
#endif

/* Define the macro if anomaly exists */
#define WORKAROUND_FOR_ANOMALY_15000004
#endif //__ADSP21479__


#ifdef __ADSP21489__
#include <def21489.h>
#ifdef __ECC__
asm("#include <def21489.h>");
#endif

/* Define the macro if anomaly exists */
#define WORKAROUND_FOR_ANOMALY_15000004
#endif //__ADSP21489__

#define DISABLE_INTERRUPTS()	asm("bit clr MODE1 IRPTEN; nop; nop;")
#define ENABLE_INTERRUPTS()	asm("bit set MODE1 IRPTEN; nop; nop;")

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
** a limitation of the C language).	 Fortunately, VDSP offers
** a work around. */

#define AWE_OPTIMIZE_FOR_SPEED _Pragma("optimize_for_speed")
#define AWE_OPTIMIZE_FOR_SPACE _Pragma("optimize_for_space")
#define AWE_OPTIMIZE_OFF _Pragma("optimize_off")

#else

// SHARC and Blackfin ASM segment names
#define AWE_PRIO0_FAST_CODE .segment /pm awe_prio0_fastcode;

#endif

/* ----------------------------------------------------------------------
** Cycle counting macros (used in C code only)
** ------------------------------------------------------------------- */

#ifdef __ECC__

static VEC_INLINE UINT32 awe_fwGetCycles(void)
{
	UINT32 _tcount;
	__asm volatile ("%0=EMUCLK;" : "=d" (_tcount));
	return _tcount;
}

static VEC_INLINE UINT32 awe_fwElapsedCycles(UINT32 start_time, UINT32 end_time)
{
  return end_time - start_time;
}
#endif // __ECC__

#endif	  /* !defined  ADI_SHARC_TARGET_PROCESSOR_H_ */
