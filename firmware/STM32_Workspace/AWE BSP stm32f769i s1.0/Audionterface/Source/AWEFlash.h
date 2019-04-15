#/* ----------------------------------------------------------------------------
 *   Extern functions
 * ------------------------------------------------------------------------- */
#include "TargetProcessor.h"
#include "framework.h"

#ifndef SUCCESS
#define SUCCESS 1
#endif

#ifndef FAILURE
#define FAILURE 0
#endif


#define FILESYSTEM_TYPE_FLASH 2

extern const UINT32 FLASH_MEMORY_SIZE_IN_BYTES;
extern const UINT32 FLASH_MEMORY_SIZE_IN_WORDS;
extern const UINT32 ERASEABLE_BLOCKSIZE;
extern const UINT32 FILE_SYSTEM_START_OFFSET;    
extern const UINT32 FLASH_START_OFFSET;

extern FileSystemInfo g_filesystem_info;

extern BOOL InitFlashFileSystem(UINT32 nFlashMemorySizeBytes,
								UINT32 nEraseableBlockSize,
								UINT32 nFileSystemStartOffset);


BOOL awe_pltInitFlashFileSystem(void);
BOOL awe_pltReadFlashMemory(UINT32 nAddress, UINT32 * pBuffer, UINT32 nDWordsToRead);
BOOL awe_pltWriteFlashMemory(UINT32 nAddress, UINT32 * pBuffer, UINT32 nDWordsToWrite);
BOOL awe_pltEraseFlashMemorySector(UINT32 nStartingAddress, UINT32 nNumberOfSectors);
BOOL awe_pltAllocateBlock(UINT32 nAddress);

extern FileSystemInfo g_filesystem_info;
