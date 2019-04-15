/*******************************************************************************
*
*               Audio Framework
*               ---------------
*
********************************************************************************
*     AudioDriver.c
********************************************************************************
*
*     Description:  AudioWeaver Audio Driver for STM Discovery board
*
*     Copyright:    DSP Concepts, Inc. (c) 2007 - 2016
*                   1800 Wyatt Drive, Suite 14
*                   Sunnyvale, CA 95054
*
*******************************************************************************/
#include "Platform.h"

// Buffer for USB Playback
#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4  
  INT16 USBBufferIn[USB_AUDIO_BUFFER_SIZE_IN_SAMPLES] @ ".DTCMRAM_Section";  
#else
	#if defined( __GNUC__ )
		__attribute__((__section__(".dtcmram")))
  	  	__ALIGN_BEGIN INT16 USBBufferIn[USB_AUDIO_BUFFER_SIZE_IN_SAMPLES] __ALIGN_END;
	#else
		#if defined ( __CC_ARM ) /*!< Keil Compiler */
			__attribute__((__section__(".data_DTCM")))
			__ALIGN_BEGIN INT16 USBBufferIn[USB_AUDIO_BUFFER_SIZE_IN_SAMPLES];
		#endif
	#endif
#endif

// Buffer for USB REcord
#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN INT16 USBBufferOut[USB_REC_EP_BUFFER_SIZE] __ALIGN_END;

volatile UINT32 nUSBReadBufferNdx = 0;
volatile UINT32 nUSBWriteBufferNdx = 0;

volatile UINT32 nScratchBufferNdx = 0;

volatile UINT32 nMicReadBufferNdx = 0;
volatile UINT32 nMicWriteBufferNdx = 0;

// Buffer to CODEC Audio in
#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4  
  INT16 AudioBufferIn[INPUT_AUDIO_BUFFER_SIZE] @ ".DTCMRAM_Section";  
#else
	#if defined( __GNUC__ )
		__attribute__((__section__(".dtcmram")))
  	  	__ALIGN_BEGIN INT16 AudioBufferIn[INPUT_AUDIO_BUFFER_SIZE] __ALIGN_END;
	#else
		#if defined ( __CC_ARM ) /*!< Keil Compiler */
			__attribute__((__section__(".data_DTCM")))
			__ALIGN_BEGIN INT16 AudioBufferIn[INPUT_AUDIO_BUFFER_SIZE];
		#endif
	#endif
#endif

// Buffer for CODEC Audio out
#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4  
  INT16 AudioBufferOut[OUTPUT_AUDIO_BUFFER_SIZE] @ ".DTCMRAM_Section";  
#else
	#if defined( __GNUC__ )
		__attribute__((__section__(".dtcmram")))
			__ALIGN_BEGIN INT16 AudioBufferOut[OUTPUT_AUDIO_BUFFER_SIZE] __ALIGN_END;
	#else
		#if defined ( __CC_ARM ) /*!< Keil Compiler */
			__attribute__((__section__(".data_DTCM")))
			__ALIGN_BEGIN INT16 AudioBufferOut[OUTPUT_AUDIO_BUFFER_SIZE];
		#endif
	#endif
#endif

#if defined ( __ICCARM__ ) // IAR Compiler
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN fract16 USB_ASRCBuffer[ASRC_BUFFER_SIZE_IN_SAMPLES] __ALIGN_END;

#if defined ( __ICCARM__ ) // IAR Compiler
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN fract16 USB_Record_ASRCBuffer[ASRC_RECORD_BUFFER_SIZE_IN_SAMPLES] __ALIGN_END;

fract16 USB_ASRCSamples[OUTPUT_BLOCKSIZE * USB_PLAYBACK_CHANNEL_COUNT]; 
fract16 USB_Record_ASRCSamples[OUTPUT_BLOCKSIZE * USB_RECORD_CHANNEL_COUNT];

fract16 ZeroedSamples[INPUT_BLOCKSIZE * USB_PLAYBACK_CHANNEL_COUNT]; 

volatile INT32 nInReadNdx = 0;
volatile INT32 nInWriteNdx = 0;
volatile INT32 nOutReadNdx = 0;
volatile INT32 nOutWriteNdx = 0;

INT16 MicBufferIn[MIC_BUFF_SIZE];

volatile BOOL g_bAudioPump1Active = FALSE;  
volatile BOOL g_bAudioPump2Active = FALSE; 
volatile BOOL g_bAudioPumpActive = FALSE;

volatile UINT32 g_nPumpCount = 0; 

static __IO uint32_t uwVolume = 50; 

static volatile fract32 nVolCurrentGain = 0;

volatile fract32 g_nNewVolGain = 0;

extern INT32 * pScratchBuff[SCRATCH_BUFFER_SIZE];

DSPC_ASRC USB_ASRC;
DSPC_ASRC USB_Record_ASRC;

volatile BOOL g_bRecording = FALSE;

// Saturate the Mic record PCM sample
#define SaturaLH(N, L, H) (((N)<(L))?(L):(((N)>(H))?(H):(N)))


//-----------------------------------------------------------------------------
// METHOD:  SetupAudio
// PURPOSE: Initialize Audio subsystem
//-----------------------------------------------------------------------------
void SetupAudio(void)
{    
    memset(AudioBufferIn, 0, sizeof(AudioBufferIn));
    memset(AudioBufferOut, 0, sizeof(AudioBufferOut));
    memset(USBBufferOut, 0, sizeof(USBBufferOut));    
        
    // When no USB audio playing pass this buffer of silence to the CODEC
    memset(ZeroedSamples, 0, sizeof(ZeroedSamples)); 

    BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE | INPUT_DEVICE_INPUT_LINE_1, uwVolume, BSP_AUDIO_FREQUENCY_48K); 
    BSP_AUDIO_IN_Init(BSP_AUDIO_FREQUENCY_48K, DEFAULT_AUDIO_IN_BIT_RESOLUTION, 4);  
  
}   // End SetupAudio


//-----------------------------------------------------------------------------
// METHOD:  AudioInit
// PURPOSE: Initialize AWE
//-----------------------------------------------------------------------------
AWE_OPTIMIZE_FOR_SPACE
AWE_FW_SLOW_CODE
void AudioInit(void)
{   
    // Initialize the ASRC for USB Playback
	dspc_asrc_init_Q15(&DSPC_ASRC_48000_TO_48000_32M_080DB_PROPS, 
                       USB_ASRCBuffer, 
                       DSPC_ASRC_STATE_LEN(INPUT_BLOCKSIZE, OUTPUT_BLOCKSIZE, ASRC_FS_IN_48000, ASRC_PHASELEN_28), 
                       DSPC_ASRC_GUARD_LEN(ASRC_FS_IN_48000, ASRC_FS_OUT_48000, ASRC_PHASELEN_28, OUTPUT_BLOCKSIZE), 
                       USB_PLAYBACK_CHANNEL_COUNT, 
                       &USB_ASRC);
    
    #if defined(MONO_RECORD)
    
        // Initialize the ASRC for USB Record
        dspc_asrc_init_Q15(&DSPC_ASRC_48000_TO_16000_32M_080DB_PROPS, 
                           USB_Record_ASRCBuffer, 
                           DSPC_ASRC_STATE_LEN(USB_RECORD_INPUT_BLOCKSIZE, USB_RECORD_OUTPUT_BLOCKSIZE, ASRC_FS_IN_48000, ASRC_PHASELEN_76), 
                           DSPC_ASRC_GUARD_LEN(ASRC_FS_IN_48000, ASRC_FS_OUT_16000, ASRC_PHASELEN_76, OUTPUT_BLOCKSIZE), 
                           USB_RECORD_CHANNEL_COUNT, 
                           &USB_Record_ASRC);
    
    #else
    
        // Initialize the ASRC for USB Record
        dspc_asrc_init_Q15(&DSPC_ASRC_48000_TO_48000_32M_080DB_PROPS, 
                           USB_Record_ASRCBuffer, 
                           DSPC_ASRC_STATE_LEN(USB_RECORD_INPUT_BLOCKSIZE, USB_RECORD_OUTPUT_BLOCKSIZE, ASRC_FS_IN_48000, ASRC_PHASELEN_28), 
                           DSPC_ASRC_GUARD_LEN(ASRC_FS_IN_48000, ASRC_FS_OUT_48000, ASRC_PHASELEN_28, OUTPUT_BLOCKSIZE), 
                           USB_RECORD_CHANNEL_COUNT, 
                           &USB_Record_ASRC);
   #endif

    dspc_asrc_write_zeros_Q15(&USB_Record_ASRC, ASRC_RECORD_BUFFER_SIZE_IN_SAMPLES / 2); 
    
    // USB audio interrupt
    HAL_NVIC_SetPriority(OTG_HS_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(OTG_HS_IRQn);
    
    // Ready to send next USB reply packet
    HAL_NVIC_SetPriority(ProcessUSBMsg_IRQ, 2, 0);
    HAL_NVIC_EnableIRQ(ProcessUSBMsg_IRQ);     
    
    HAL_NVIC_SetPriority(AUDIO_IN_SAIx_DMAx_IRQ, 3, 0);
    HAL_NVIC_EnableIRQ(AUDIO_IN_SAIx_DMAx_IRQ);    
    
    HAL_NVIC_SetPriority(AUDIO_DFSDMx_DMAx_TOP_LEFT_IRQ, 3, 0);
    HAL_NVIC_EnableIRQ(AUDIO_DFSDMx_DMAx_TOP_LEFT_IRQ);
    
    HAL_NVIC_SetPriority(AUDIO_DFSDMx_DMAx_TOP_RIGHT_IRQ, 3, 0);
    HAL_NVIC_EnableIRQ(AUDIO_DFSDMx_DMAx_TOP_RIGHT_IRQ);
    
    HAL_NVIC_SetPriority(AUDIO_DFSDMx_DMAx_Bottom_LEFT_IRQ, 3, 0);
    HAL_NVIC_EnableIRQ(AUDIO_DFSDMx_DMAx_Bottom_LEFT_IRQ);
    
    HAL_NVIC_SetPriority(AUDIO_DFSDMx_DMAx_Bottom_RIGHT_IRQ, 3, 0);
    HAL_NVIC_EnableIRQ(AUDIO_DFSDMx_DMAx_Bottom_RIGHT_IRQ);

    // DPC to process writing to USB ASRC
    HAL_NVIC_SetPriority(ProcessWriteASRC_IRQ, 4, 0);
    HAL_NVIC_EnableIRQ(ProcessWriteASRC_IRQ); 
    
    // DPC to process writing to Mic Buffers
    HAL_NVIC_SetPriority(MicProcessWrite_IRQ, 4, 0);
    HAL_NVIC_EnableIRQ(MicProcessWrite_IRQ);      
    
    HAL_NVIC_SetPriority(AudioWeaverPump_IRQ1, 5, 0);
    HAL_NVIC_EnableIRQ(AudioWeaverPump_IRQ1);    

    HAL_NVIC_SetPriority(AudioWeaverPump_IRQ2, 6, 0);
    HAL_NVIC_EnableIRQ(AudioWeaverPump_IRQ2); 
    
    BSP_AUDIO_IN_Record( (UINT16 *)AudioBufferIn, INPUT_AUDIO_BUFFER_SIZE);   
    BSP_AUDIO_OUT_Play( (UINT16 *)AudioBufferOut, OUTPUT_AUDIO_BUFFER_SIZE);    
    
}	// End awe_pltInit


//-----------------------------------------------------------------------------
// METHOD:  AWEProcessing
// PURPOSE: Pass new samples to Audio Weaver and return processed samples
//
// NOTES:
// Channels are ordered from the CODEC in TDM format.
//
// TDM format:
// +------------------|--------------------|
// | CODEC_SLOT0 Left | CODEC_SLOT0 Right  |
// | ADC Left         | ADC Right          |
// +----------------------------------------
//
//                                          +---------------+-------+-------+-------+
//                                          |  ADC  |  Mic  |  Mic  |  Mic  |  Mic  |
// AudioWeaver wants the sample order to be +---------------+-------+-------+-------+
//                                          | L | R | Top L | Top R | Bot L | Bot R | 
//                                          +---------------+-------+-------+-------+
//-----------------------------------------------------------------------------
void AWEProcessing(INT16 * pUSBSamples, INT16 * pAnalogInSamples, INT16 * pMicSamples, INT16 * pProcessedSamplesForCODEC, INT16 * pProcessedSamplesForUSB) 
{
	UINT32  fwInCount, fwOutCount;
    INT32  used_chans, chan;   
    INT32  pinStride, destStride;
    INT16  n16BitSample; 
    INT32  n32BitSample;
    UINT32 layoutMask;  
    INT32  nSample; 
    INT32 * dest32BitPtr;
    INT32 * src32BitPtr;
    INT16 * dest16BitPtr;    
    INT16 * src16BitPtr;    

    const UINT32 nPinNdx = 0;
   
    // If no AWE layout wired up then output silence
    if (!s_AudioRunning)
    {    
        memset(pProcessedSamplesForCODEC, 0, STEREO_BLOCK_SIZE_IN_SAMPLES * sizeof(INT16) );
        memset(pProcessedSamplesForUSB, 0, STEREO_BLOCK_SIZE_IN_SAMPLES * sizeof(INT16) );                
    }
    else
    {   
        // Get Current audio layout number of channels
        awe_fwGetChannelCount(&g_AWEInstance, &fwInCount, &fwOutCount);
        
        if (fwInCount > 0)
        {						           
            // Get the input pin channels actually used
            used_chans = (fwInCount < INPUT_CHANNEL_COUNT) ? fwInCount : INPUT_CHANNEL_COUNT;

            for (chan = 0; chan < used_chans; chan++)
            {     
                // When first 2 channels are USB audio              
                if (chan < 2)  
                {                    
                    src16BitPtr = pUSBSamples + chan; 
                }
                else if (chan < 4)
                {
                    src16BitPtr = pAnalogInSamples + (chan - 2); 
                }
                else
                {
                    src16BitPtr = pMicSamples + ( (chan - 4) * OUTPUT_BLOCKSIZE); 
                }
                
                // Determine where the Framework wants the input data written
                dest32BitPtr = awe_fwGetInputChannelPtr(&g_AWEInstance, nPinNdx, chan, &pinStride);
                               
                for (nSample = 0; nSample < CHANNEL_BLOCK_SIZE_IN_SAMPLES; nSample++)
                {
                    n16BitSample = *src16BitPtr;
                     
                    // Audio Weaver wants the sample in the high order bytes of the 32-bit word
                    *dest32BitPtr = n16BitSample << 16;
                    
                    dest32BitPtr += pinStride;
                    
                    if (chan < 4)         
                    {                    
                        src16BitPtr += 2;				
                    }
                    else
                    {	
                        // Mic buffer is not interleaved                        
                        src16BitPtr++;                      
                    }
                }                       
            }

            // Zero any unused layout inputs
            for ( ; chan < fwInCount; chan++)
            {
                // Determine where the Framework wants the input data written
                dest32BitPtr = awe_fwGetInputChannelPtr(&g_AWEInstance, nPinNdx, chan, &pinStride);   
                
                for (nSample = 0; nSample < CHANNEL_BLOCK_SIZE_IN_SAMPLES; nSample++)
                {                                 
                    *dest32BitPtr = 0;
                    dest32BitPtr += pinStride;				
                }
            }									
        }
               
        for (chan = 0; chan < OUTPUT_CHANNEL_COUNT; chan++)
        {
            if (chan < fwOutCount)
            {
                // Determine where the Framework wants the output data written
                src32BitPtr = awe_fwGetOutputChannelPtr(&g_AWEInstance, nPinNdx, chan, &pinStride);
                
                if (chan < 2)
                {
                    dest16BitPtr = pProcessedSamplesForCODEC + chan;
                    destStride = 2;
                }
                else
                {
                    dest16BitPtr = pProcessedSamplesForUSB + (chan - 2);
                    
                    #if defined(MONO_RECORD)
                        destStride = 1;
                    #else
                        destStride = 2;
                    #endif
                }
                
                for (nSample = 0; nSample < CHANNEL_BLOCK_SIZE_IN_SAMPLES; nSample++)
                {
                    n32BitSample = *src32BitPtr;
                    n16BitSample = n32BitSample >> 16;
                    
                    // Audio Weaver wants sample in high order bytes of 32-bit word
                    *dest16BitPtr = n16BitSample;

                    src32BitPtr += pinStride;		
                    dest16BitPtr += destStride;					 		
                }               
            } 
            else 
            {
				// The layout doesn't have enough channels; fill the remaining one with zeros
                if (chan < 2)
                {
                    dest16BitPtr = pProcessedSamplesForCODEC + chan;
                }
                else
                {
                    dest16BitPtr = pProcessedSamplesForUSB + (chan - 2);
                }
                
                for (nSample = 0; nSample < CHANNEL_BLOCK_SIZE_IN_SAMPLES; nSample++)
                {
                    *dest16BitPtr = 0;
                    dest16BitPtr += destStride;					 		
                }
            }
        } 

        layoutMask = awe_fwAudioDMAComplete(&g_AWEInstance, nPinNdx, CHANNEL_BLOCK_SIZE_IN_SAMPLES);

        if (layoutMask & 1)
        {
            if (s_AudioRunning && !g_bAudioPump1Active)
            { 
                NVIC_SetPendingIRQ(AudioWeaverPump_IRQ1); 
            }            
        }
        
        if (layoutMask & 2)
        {
            if (s_AudioRunning && !g_bAudioPump2Active)
            { 
                NVIC_SetPendingIRQ(AudioWeaverPump_IRQ2); 
            }            
        }        
    }
	
}	// End AWEProcessing


//-----------------------------------------------------------------------------
// METHOD:  ProcessWriteASRC_IRQHandler
// PURPOSE: DPC for writing to ASRC buffer
//-----------------------------------------------------------------------------
void ProcessWriteASRC_IRQHandler(void)
{
    // Insert 48 stereo samples that just arrived over USB into the ASRC jitter buffer
    dspc_asrc_write_input_Q15(&USB_ASRC, &USBBufferIn[nUSBReadBufferNdx], INPUT_BLOCKSIZE);
    
    // USB Audio double buffer
    nUSBReadBufferNdx = (nUSBReadBufferNdx + NEW_USB_SAMPLES) % USB_AUDIO_BUFFER_SIZE_IN_SAMPLES; 
    
    // Manually clear software interrupt
    NVIC_ClearPendingIRQ(ProcessWriteASRC_IRQ); 
    
}   // End ProcessWriteASRC_IRQHandler


//-----------------------------------------------------------------------------
// METHOD:  MicProcessWrite_IRQHandler
// PURPOSE: DPC for writing to Mic buffers
//-----------------------------------------------------------------------------
void MicProcessWrite_IRQHandler(void)
{
    INT32 n; 
  
    INT16 * pMicBuffer1 = &MicBufferIn[nMicWriteBufferNdx];
    INT16 * pMicBuffer2 = &MicBufferIn[nMicWriteBufferNdx+32];
    INT16 * pMicBuffer3 = &MicBufferIn[nMicWriteBufferNdx+64];
    INT16 * pMicBuffer4 = &MicBufferIn[nMicWriteBufferNdx+96];     

    nMicWriteBufferNdx  = (nMicWriteBufferNdx + NEW_MIC_BUFFER_SAMPLES) % MIC_BUFF_SIZE;
    
    for (n = 0; n < MIC_SINGLE_CHANNEL_BLOCK_SIZE; n++)
    {
        pMicBuffer1[n] = (INT16)(SaturaLH((Scratch2[nScratchBufferNdx + n] >> 8), -32760, 32760)); 
        pMicBuffer2[n] = (INT16)(SaturaLH((Scratch1[nScratchBufferNdx + n] >> 8), -32760, 32760));   
        pMicBuffer3[n] = (INT16)(SaturaLH((Scratch4[nScratchBufferNdx + n] >> 8), -32760, 32760)); 
        pMicBuffer4[n] = (INT16)(SaturaLH((Scratch3[nScratchBufferNdx + n] >> 8), -32760, 32760));              
    }
     
    nScratchBufferNdx = (nScratchBufferNdx + NEW_MIC_SAMPLES) % MIC_DOUBLE_BUFFER_SAMPLES;
    
    // Manually clear software interrupt
    NVIC_ClearPendingIRQ(MicProcessWrite_IRQ); 
    
}   // End MicProcessWrite_IRQHandler


//-----------------------------------------------------------------------------
// METHOD:  BSP_AUDIO_IN_DMA_Handler
// PURPOSE: Interrupt handler - called each time a frame of audio received
//-----------------------------------------------------------------------------
void BSP_AUDIO_IN_DMA_Handler(void)
{    
    int nSamplesAvail;  
    INT16 * pUSBSamples; 
    
    // Get the number of available USB samples in the ASRC jitter buffer
    nSamplesAvail = dspc_asrc_output_avail(&USB_ASRC);
    
    if (nSamplesAvail >= OUTPUT_BLOCKSIZE)
    {     
        // Read a block of samples from the ASRC jitter buffer
        dspc_asrc_read_output_linear_Q15(&USB_ASRC, USB_ASRCSamples, OUTPUT_BLOCKSIZE);     
        
        pUSBSamples = USB_ASRCSamples;       
    }
    else
    {
        // Insert zeros if no audio samples available (CODEC continually runs)
        pUSBSamples = ZeroedSamples;               
    } 
    
    AWEProcessing(pUSBSamples, &AudioBufferIn[nInReadNdx], &MicBufferIn[nMicReadBufferNdx], &AudioBufferOut[nOutWriteNdx], USB_Record_ASRCSamples);
    
    if (g_bRecording)
    {
        // Insert 32 mono or stereo samples processed from mics into the USB Record ASRC jitter buffer
        dspc_asrc_write_input_Q15(&USB_Record_ASRC, USB_Record_ASRCSamples, NEW_USB_RECORD_SAMPLES);
    }
    
    nInReadNdx = (nInReadNdx + STEREO_BLOCK_SIZE_IN_SAMPLES) % INPUT_AUDIO_BUFFER_SIZE; 
    
    nMicReadBufferNdx  = (nMicReadBufferNdx + NEW_MIC_BUFFER_SAMPLES) % MIC_BUFF_SIZE;
      
    nOutWriteNdx = (nOutWriteNdx + STEREO_BLOCK_SIZE_IN_SAMPLES) % OUTPUT_AUDIO_BUFFER_SIZE;   
    
}   // End BSP_AUDIO_IN_DMA_Handler


//-----------------------------------------------------------------------------
// METHOD:  AudioWeaver Pump Interrupt Handler
// PURPOSE: Perform AudioWeaver Processing
//-----------------------------------------------------------------------------
void AudioWeaverPump_IRQHandler1(void)
{
    g_bAudioPump1Active = TRUE;
    
    NVIC_ClearPendingIRQ(AudioWeaverPump_IRQ1); 
    
    if (s_AudioRunning)
    {
        // If IDLE loop did not get some CPU time then skip the pump
        // g_nPumpCount gets reset in the idle loop method awe_pltTick
        if (g_nPumpCount < MAX_PUMP_COUNT)
        {
            awe_fwPump(&g_AWEInstance, 0);
            g_nPumpCount++;
        }
    }
    
    g_bAudioPump1Active = FALSE; 

}   // End AudioWeaverPump_IRQHandler


//-----------------------------------------------------------------------------
// METHOD:  AudioWeaver Pump Interrupt Handler
// PURPOSE: Perform AudioWeaver Processing
//-----------------------------------------------------------------------------
void AudioWeaverPump_IRQHandler2(void)
{
    g_bAudioPump2Active = TRUE;
    
    NVIC_ClearPendingIRQ(AudioWeaverPump_IRQ2); 

    awe_fwPump(&g_AWEInstance, 1);

    g_bAudioPump2Active = FALSE; 

}   // End AudioWeaverPump_IRQHandler

