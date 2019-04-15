/*******************************************************************************
*
*               Audio Framework
*               ---------------
*
********************************************************************************
*     AWE_Wrapper.h
********************************************************************************
*
*     Description:  AudioWeaver Wrapper Header File
*
*     Copyright:    (c) 2017 DSP Concepts, Inc. All Rights Reserved
*                   1800 Wyatt Drive, Suite 14
*                   Sunnyvale, CA 95054
*
*******************************************************************************/
 #ifndef __AWE_WRAPPER_H__
 #define __AWE_WRAPPER_H__
 
#include "stm32f769i_discovery.h"
#include "stm32f769i_discovery_audio.h"
#include "usbd_audio.h"
#include "PlatformAPI.h"
#include "Errors.h"
#include "TargetInfo.h"
#include "TuningHandler.h"
#include "ControlDriver.h"

#include "dspc_asrc_48000_to_16000_32m_080db.h"
#include "dspc_asrc_48000_to_48000_32m_080db.h"
 
#define INPUT_CHANNEL_COUNT 8

#if defined(MONO_RECORD)
    #define OUTPUT_CHANNEL_COUNT 3
#else
    #define OUTPUT_CHANNEL_COUNT 4
#endif

#define TOTAL_BUFFERS 2
#define CHANNEL_BLOCK_SIZE_IN_SAMPLES 32
#define STEREO_BLOCK_SIZE_IN_SAMPLES 64
#define MIC_BLOCK_SIZE_IN_SAMPLES 128
#define MIC_SINGLE_CHANNEL_BLOCK_SIZE 32
#define SCRATCH_BUFFER_SIZE 256

// EP size in bytes (48 samples * 2 channels * 2 bytes)
#define AUDIO_EP_BUFFER_SIZE 192

// Double buffer size in samples
#define USB_AUDIO_BUFFER_SIZE_IN_SAMPLES 192
#define NEW_USB_SAMPLES 96

#define MIC_DOUBLE_BUFFER_SAMPLES 64
#define NEW_MIC_SAMPLES 32
#define NEW_USB_RECORD_SAMPLES 32

#define INPUT_BLOCKSIZE 48
#define OUTPUT_BLOCKSIZE 32

#define USB_RECORD_INPUT_BLOCKSIZE 32

#define STEREO_CHANNEL_COUNT 2
#define MONO_CHANNEL_COUNT 1
#define USB_PLAYBACK_CHANNEL_COUNT 2

#define INPUT_AUDIO_BUFFER_SIZE (TOTAL_BUFFERS * STEREO_BLOCK_SIZE_IN_SAMPLES)
#define OUTPUT_AUDIO_BUFFER_SIZE (TOTAL_BUFFERS * STEREO_BLOCK_SIZE_IN_SAMPLES)

#define NUMBER_MICS 4
#define SCRATCH_BUFF_SIZE (TOTAL_BUFFERS * CHANNEL_BLOCK_SIZE_IN_SAMPLES * NUMBER_MICS)

#define MIC_BUFF_SIZE (TOTAL_BUFFERS * CHANNEL_BLOCK_SIZE_IN_SAMPLES * NUMBER_MICS)
#define NEW_MIC_BUFFER_SAMPLES 128

#define HID_EP_BUFFER_SIZE 64
#define HID_REPORT_PACKET_SIZE 56
#define HID_REPORT_DATA_SIZE 52
#define DATA_SIZE_IN_DWORDS 13
#define MAX_COMMAND_BUFFER_LEN 272
#define AUDIO_OUT_PACKET_SIZE_BYTES 192

#define MAX_PINS 1
#define GPIO_DIR_OUTPUT 1
#define MAX_AWE_BUFFERSIZE 264

#if defined(MONO_RECORD)
    // EP size in bytes (16 samples * 1 channel * 2 bytes)
    #define USB_REC_EP_BUFFER_SIZE 32
    #define USB_RECORD_CHANNEL_COUNT 1
    #define USB_RECORD_OUTPUT_BLOCKSIZE 16
    #define ASRC_RECORD_BUFFER_SIZE_IN_SAMPLES DSPC_ASRC_BUFFER_LEN(ASRC_FS_IN_48000, ASRC_FS_OUT_16000, ASRC_PHASELEN_76, USB_RECORD_INPUT_BLOCKSIZE, USB_RECORD_OUTPUT_BLOCKSIZE, USB_RECORD_CHANNEL_COUNT)
#else
    // EP size in bytes (48 samples * 2 channels * 2 bytes)
    #define USB_REC_EP_BUFFER_SIZE 192
    #define USB_RECORD_CHANNEL_COUNT 2
    #define USB_RECORD_OUTPUT_BLOCKSIZE 48
    #define ASRC_RECORD_BUFFER_SIZE_IN_SAMPLES DSPC_ASRC_BUFFER_LEN(ASRC_FS_IN_48000, ASRC_FS_OUT_48000, ASRC_PHASELEN_28, USB_RECORD_INPUT_BLOCKSIZE, USB_RECORD_OUTPUT_BLOCKSIZE, USB_RECORD_CHANNEL_COUNT)
#endif

#define ASRC_BUFFER_SIZE_IN_SAMPLES DSPC_ASRC_BUFFER_LEN(ASRC_FS_IN_48000, ASRC_FS_OUT_48000, ASRC_PHASELEN_28, INPUT_BLOCKSIZE, OUTPUT_BLOCKSIZE, USB_PLAYBACK_CHANNEL_COUNT)

#define MAX_PUMP_COUNT 100

#define ProcessWriteASRC_IRQHandler CAN1_TX_IRQHandler
#define ProcessWriteASRC_IRQ CAN1_TX_IRQn

#define AudioWeaverPump_IRQHandler1 CAN1_RX0_IRQHandler
#define AudioWeaverPump_IRQ1 CAN1_RX0_IRQn

#define ProcessUSBMsg_IRQHandler CAN1_RX1_IRQHandler
#define ProcessUSBMsg_IRQ CAN1_RX1_IRQn

#define AudioWeaverPump_IRQHandler2 CAN1_SCE_IRQHandler
#define AudioWeaverPump_IRQ2 CAN1_SCE_IRQn

#define MicProcessWrite_IRQHandler CAN2_TX_IRQHandler
#define MicProcessWrite_IRQ CAN2_TX_IRQn

extern volatile BOOL g_bReadyToSend;

extern UINT32 s_PacketBuffer[MAX_COMMAND_BUFFER_LEN];
extern UINT8 HIDInBuff[HID_EP_BUFFER_SIZE];
extern UINT8 HIDOutBuff[HID_EP_BUFFER_SIZE];

extern INT16 USBBufferIn[USB_AUDIO_BUFFER_SIZE_IN_SAMPLES];
extern INT16 USBBufferOut[USB_REC_EP_BUFFER_SIZE];
extern volatile UINT32 nUSBReadBufferNdx;
extern volatile UINT32 nUSBWriteBufferNdx;

extern USBD_HandleTypeDef USBD_Device;

extern INT32 Scratch1[MIC_DOUBLE_BUFFER_SAMPLES];
extern INT32 Scratch2[MIC_DOUBLE_BUFFER_SAMPLES];
extern INT32 Scratch3[MIC_DOUBLE_BUFFER_SAMPLES];
extern INT32 Scratch4[MIC_DOUBLE_BUFFER_SAMPLES];

extern INT16 MicBufferIn[MIC_BUFF_SIZE];
extern volatile UINT32 nMicReadBufferNdx;
extern volatile UINT32 nMicWriteBufferNdx;

extern volatile BOOL g_bBlinkLED2ForBoardAlive;
extern volatile INT32 s_AudioRunning;
extern volatile UINT32 g_nPumpCount;
extern volatile BOOL g_bUSBPacketReceived;

extern DWORD g_target_control_flags;

extern AWEInstance g_AWEInstance;

extern DSPC_ASRC USB_Record_ASRC;
extern fract16 ZeroedSamples[INPUT_BLOCKSIZE * USB_PLAYBACK_CHANNEL_COUNT];

void SetupAudio(void);

void awe_pltInit(void);

void awe_pltTick(void);

void CoreInit(void);
void BoardInit(void);
void AudioInit(void);
void USBMsgInit(void);
void CheckForUSBPacketReady(void);
void USBSendReply(void);

void awe_pltGPIOSetPinDir(UINT32 nPinNo, UINT32 nPinDir);
void awe_pltGPIOSetPin(UINT32 nPinNo, UINT32 nValue);
void awe_pltGPIOGetPin(UINT32 nPinNo, UINT32 * nValue);

INT32 awe_pltAudioStart(void);

INT32 awe_pltAudioStop(void);

void BSP_AUDIO_IN_DMA_Handler(void);

void AWEProcessing(INT16 * pUSBSamples, INT16 * pAnalogInSamples, INT16 * pMicSamples, INT16 * pProcessedSamplesForCODEC, INT16 * pProcessedSamplesForUSB);

extern BOOL InitFlashFileSystem(UINT32 nFlashMemorySizeBytes,
								UINT32 nEraseableBlockSize,
								UINT32 nFileSystemStartOffset);

BOOL awe_pltInitFlashFileSystem(void);
BOOL awe_pltReadFlashMemory(UINT32 nAddress, UINT32 * pBuffer, UINT32 nDWordsToRead);
BOOL awe_pltWriteFlashMemory(UINT32 nAddress, UINT32 * pBuffer, UINT32 nDWordsToWrite);
BOOL awe_pltEraseFlashMemorySector(UINT32 nStartingAddress, UINT32 nNumberOfSectors);
BOOL awe_pltAllocateBlock(UINT32 nAddress);

#endif
