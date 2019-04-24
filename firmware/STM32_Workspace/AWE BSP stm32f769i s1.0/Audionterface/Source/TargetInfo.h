/*******************************************************************************
*
*               Audio Framework
*               ---------------
*
********************************************************************************
*     TargetInfo.h
********************************************************************************
*
*     Description:  All target specific information
*
*     Copyright:    DSP Concepts, LLC, 2007 - 2016
*                   1800 Wyatt Drive, Suite 14
*                   Sunnyvale, CA 95054
*
*******************************************************************************/
#ifndef _TARGETINFO_H
#define _TARGETINFO_H

#include "stm32f769i_discovery_qspi.h"

// Version Information
#define VER_DAY 30
#define VER_MONTH 10
#define VER_YEAR 17

#define CORE_ID 0
#define CORE_SPEED 216e6f
#define SAMPLE_SPEED 216e6f
#define HAS_FLOAT_SUPPORT 1
#define HAS_FLASH_FILESYSTEM 1
#define NO_INPUT_PINS 1
#define NO_OUTPUT_PINS 1
#define IS_SMP 0
#define NO_THREADS_SUPPORTED 2
#define FIXED_SAMPLE_RATE 48000.0f
#define IS_COMPLEX 0
#define SAMPLE_SIZE_IN_BYTES 4

/* ----------------------------------------------------------------------
** Specify the size of each of the heaps on this target
** ------------------------------------------------------------------- */
#define MASTER_HEAP_SIZE		(1024*13)
#define FASTB_HEAP_SIZE			(1024*38)
#define SLOW_HEAP_SIZE			(1024*2048) 

/* ----------------------------------------------------------------------
** Specify communication buffer size
** ------------------------------------------------------------------- */
#define MAX_COMMAND_BUFFER_LEN  272

/* ----------------------------------------------------------------------
** Specify flash memory available for flash file system
** ------------------------------------------------------------------- */
#define FLASH_MEMORY_SIZE_IN_BYTES MX25L512_FLASH_SIZE
#define FLASH_MEMORY_SIZE_IN_WORDS (MX25L512_FLASH_SIZE >> 2)
#define ERASEABLE_BLOCKSIZE MX25L512_SUBSECTOR_SIZE
#define FILE_SYSTEM_START_OFFSET 0x00000000	
#define FLASH_START_OFFSET 0x00000000

/* ----------------------------------------------------------------------
** Specify which modules to include on this target
** ------------------------------------------------------------------- */
#include "ModuleList.h"

#endif	// _TARGETINFO_H
