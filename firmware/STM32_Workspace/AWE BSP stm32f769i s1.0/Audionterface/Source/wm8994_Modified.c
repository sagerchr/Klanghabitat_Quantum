
/*******************************************************************************
*
*               Audio Framework
*               ---------------
*
********************************************************************************
*     wm8994_Modified.c
********************************************************************************
*
*     Description:  AudioWeaver Codec Driver for STM32F746NG DISCO board
*
*     Copyright:    DSP Concepts, Inc. (c) 2007 - 2016
*                   1800 Wyatt Drive, Suite 14
*                   Sunnyvale, CA 95054
*
*******************************************************************************/

/** This file is based on the following file from ST
  ******************************************************************************
  * @file    wm8994.c
  * @author  MCD Application Team
  * @version V2.0.0
  * @date    24-June-2015
  * @brief   This file provides the WM8994 Audio Codec driver.   
  ******************************************************************************
  
  CODEC Configuration:
  
      Board blue jack connected to IN1LN and IN1RN
      Board green jack connected to HPOUT1R and HPOUT1L
      Mic connected to IN2RN
      All other inputs and outputs disabled
  */

#include "wm8994_Modified.h"

/* Uncomment this line to enable verifying data sent to codec after each write 
   operation (for debug purpose) */
#if !defined (VERIFY_WRITTENDATA)  
#define VERIFY_WRITTENDATA
#endif /* VERIFY_WRITTENDATA */


// Audio codec driver structure initialization  
AUDIO_DrvTypeDef wm8994_drv = 
{
  wm8994_Init,
  wm8994_DeInit,
  wm8994_ReadID,

  wm8994_Play,
  wm8994_Pause,
  wm8994_Resume,
  wm8994_Stop,  

  wm8994_SetFrequency,
  wm8994_SetVolume,
  wm8994_SetMute,  
  wm8994_SetOutputMode,

  wm8994_Reset
};

static uint32_t outputEnabled = 0;

static uint8_t CODEC_IO_Write(uint8_t Addr, uint16_t Reg, uint16_t Value);
 

/**
  * @brief Initializes the audio codec and the control interface.
  * @param DeviceAddr: Device address on communication Bus.   
  * @param OutputInputDevice: can be OUTPUT_DEVICE_SPEAKER, OUTPUT_DEVICE_HEADPHONE,
  *  OUTPUT_DEVICE_BOTH, OUTPUT_DEVICE_AUTO, INPUT_DEVICE_DIGITAL_MICROPHONE_1,
  *  INPUT_DEVICE_DIGITAL_MICROPHONE_2, INPUT_DEVICE_INPUT_LINE_1 or INPUT_DEVICE_INPUT_LINE_2.
  * @param Volume: Initial volume level (from 0 (Mute) to 100 (Max))
  * @param AudioFreq: Audio Frequency 
  * @retval 0 if correct communication, else wrong communication
  */
uint32_t wm8994_Init(uint16_t DeviceAddr, uint16_t OutputInputDevice, uint8_t Volume, uint32_t AudioFreq)
{
    uint32_t counter = 0;

    // Initialize the Control interface of the Audio Codec
    //AUDIO_IO_Init(); 

    // Reset the Codec Registers
    wm8994_drv.Reset(DeviceAddr); 

    // wm8994 Errata Work-Arounds
    counter += CODEC_IO_Write(DeviceAddr, 0x102, 0x0003);
    counter += CODEC_IO_Write(DeviceAddr, 0x817, 0x0000);
    counter += CODEC_IO_Write(DeviceAddr, 0x102, 0x0000);  

    // Enable VMID soft start (fast), Start-up Bias Current Enabled
    counter += CODEC_IO_Write(DeviceAddr, 0x39, 0x006C);

    // Enable bias generator, Enable VMID
    counter += CODEC_IO_Write(DeviceAddr, 0x01, 0x0003);

    // Add Delay
    AUDIO_IO_Delay(50);

    // (AIF1D) AC1L_EN AC1R_ENA DAC1L_ENA DAC1R_ENA
    counter += CODEC_IO_Write(DeviceAddr, 0x05, 0x0303);

    // Enable the AIF1 Timeslot 0 (Left) to DAC 1 (Left) mixer path (AIF1D) AC1L_TO_D
    counter += CODEC_IO_Write(DeviceAddr, 0x601, 0x0001);

    // Enable the AIF1 Timeslot 0 (Right) to DAC 1 (Right) mixer path (AIF1D) AC1R_TO_D
    counter += CODEC_IO_Write(DeviceAddr, 0x602, 0x0001);
 
    // AIF1ADC1L_ENA (timeslot 0), AIF1ADC1R_ENA (timeslot 0), ADCL_ENA, ADCR_ENA
    counter += CODEC_IO_Write(DeviceAddr, 0x04, 0x0303);

    /* Enable AIF1 DRC1 Signal Detect & DRC in AIF1ADC1 Left/Right Timeslot 0 */
    counter += CODEC_IO_Write(DeviceAddr, 0x440, 0x00DB);       

    // Enable IN1L_ENA IN1R_ENA MIXIN_L_ENA MIXINR_ENA, Enable Thermal sensor & shutdown
    counter += CODEC_IO_Write(DeviceAddr, 0x02, 0x6350);
    
    /* Enable the ADCL(Left) to AIF1 Timeslot 0 (Left) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x606, 0x0002);

    /* Enable the ADCR(Right) to AIF1 Timeslot 0 (Right) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x607, 0x0002);    

    // GPIO1 pin configuration GP1_DIR = output, GP1_FN = AIF1 DRC2 signal detect
    counter += CODEC_IO_Write(DeviceAddr, 0x700, 0x000E);

    /*  Clock Configurations */
    switch (AudioFreq)
    {
        case  AUDIO_FREQUENCY_8K:
        /* AIF1 Sample Rate = 8 (KHz), ratio=256 */ 
        counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0003);
        break;

        case  AUDIO_FREQUENCY_16K:
        /* AIF1 Sample Rate = 16 (KHz), ratio=256 */ 
        counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0033);
        break;

        case  AUDIO_FREQUENCY_48K:
        /* AIF1 Sample Rate = 48 (KHz), ratio=256 */ 
        counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0083);
        break;

        case  AUDIO_FREQUENCY_96K:
        /* AIF1 Sample Rate = 96 (KHz), ratio=256 */ 
        counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x00A3);
        break;

        case  AUDIO_FREQUENCY_11K:
        /* AIF1 Sample Rate = 11.025 (KHz), ratio=256 */ 
        counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0013);
        break;

        case  AUDIO_FREQUENCY_22K:
        /* AIF1 Sample Rate = 22.050 (KHz), ratio=256 */ 
        counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0043);
        break;

        case  AUDIO_FREQUENCY_44K:
        /* AIF1 Sample Rate = 44.1 (KHz), ratio=256 */ 
        counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0073);
        break; 

        default:
        /* AIF1 Sample Rate = 48 (KHz), ratio=256 */ 
        counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0083);
        break; 
    }

    /* AIF1 Word Length = 16-bits, AIF1 Format = I2S (Default Register Value) */
    counter += CODEC_IO_Write(DeviceAddr, 0x300, 0x4010);

    /* slave mode */
    counter += CODEC_IO_Write(DeviceAddr, 0x302, 0x0000);

    /* Enable the DSP processing clock for AIF1, Enable the core clock */
    counter += CODEC_IO_Write(DeviceAddr, 0x208, 0x000A);
    
    counter += CODEC_IO_Write(DeviceAddr, 0x200, 0x0001);

    /* Enable HPOUT1L, HPOUT1R, VMID_SEL, and BIAS_ENA */
    counter += CODEC_IO_Write(DeviceAddr, 0x01, 0x0303); 
    
    /* Add Delay */
    AUDIO_IO_Delay(20);

    /* Enable HPOUT1 (Left) and HPOUT1 (Right) intermediate stages */
    counter += CODEC_IO_Write(DeviceAddr, 0x60, 0x0022);

    /* Enable Charge Pump */
    counter += CODEC_IO_Write(DeviceAddr, 0x4C, 0x9F25);
    
    /* Add Delay */
    AUDIO_IO_Delay(25);      
    
    /* Select DAC1 (Left) to Left Headphone Output PGA (HPOUT1LVOL) path */
    /* DAC1L_TO_HPOUT1L BIT 8 */
    counter += CODEC_IO_Write(DeviceAddr, 0x2D, 0x0100);

    /* Select DAC1 (Right) to Right Headphone Output PGA (HPOUT1RVOL) path */
    /* DAC1R_TO_HPOUT1R BIT 8 */
    counter += CODEC_IO_Write(DeviceAddr, 0x2E, 0x0100);   

    /* Enable DC Servo and trigger start-up mode on HPOUT1L and HPOUT1R */
    counter += CODEC_IO_Write(DeviceAddr, 0x54, 0x0033);  

    /* Add Delay */
    AUDIO_IO_Delay(250);

    /* Enable HPOUT1 (Left) and HPOUT1 (Right) intermediate and output stages. Remove clamps */
    counter += CODEC_IO_Write(DeviceAddr, 0x60, 0x00EE);
    
    /* Unmute the AIF1 Timeslot 0 DAC path */
    counter += CODEC_IO_Write(DeviceAddr, 0x420, 0x0000);    

    /* Unmute DAC 1 (Left) */
    counter += CODEC_IO_Write(DeviceAddr, 0x610, 0x00C0);

    /* Unmute DAC 1 (Right) */
    counter += CODEC_IO_Write(DeviceAddr, 0x611, 0x00C0);

    /* Enable HPOUT1L, HPOUT1R, VMID_SEL, and BIAS_ENA  */
    counter += CODEC_IO_Write(DeviceAddr, 0x01, 0x0303);

    /* ADC oversample enable */
    counter += CODEC_IO_Write(DeviceAddr, 0x620, 0x0002);

    /* Disable mute on IN1L, IN1L Volume = +4.5dB */
    counter += CODEC_IO_Write(DeviceAddr, 0x18, 0x010E);
    
    /* Disable mute on IN1R, IN1R Volume = +4.5dB */
    counter += CODEC_IO_Write(DeviceAddr, 0x1A, 0x010E);

    /* IN1LN_TO_IN1L, IN1LP_TO_VMID, IN1RN_TO_IN1R, IN1RP_TO_VMID */
    counter += CODEC_IO_Write(DeviceAddr, 0x28, 0x0011);
    
    // Unmute IN1L_TO_MIXINL, Gain = 0x0020 for +0dB 0x0030 for +30dB
    counter += CODEC_IO_Write(DeviceAddr, 0x29, 0x0020);            

    // Unmute IN1R_TO_MIXINR, Gain = 0x0020 for +0dB 0x0030 for +30dB
    counter += CODEC_IO_Write(DeviceAddr, 0x2A, 0x0020);     

    /* AIF ADC1 HPF enable, HPF cut = hifi mode fc=4Hz at fs=48kHz */
    counter += CODEC_IO_Write(DeviceAddr, 0x410, 0x1800);
    
    // Set all gains to 0 dB
    counter += CODEC_IO_Write(DeviceAddr, 0x400, 0x1C0);
    counter += CODEC_IO_Write(DeviceAddr, 0x401, 0x1C0);
    counter += CODEC_IO_Write(DeviceAddr, 0x402, 0x1C0);
    counter += CODEC_IO_Write(DeviceAddr, 0x403, 0x1C0);    
    counter += CODEC_IO_Write(DeviceAddr, 0x404, 0x1C0);
    counter += CODEC_IO_Write(DeviceAddr, 0x405, 0x1C0);    
    counter += CODEC_IO_Write(DeviceAddr, 0x610, 0x1C0);   
    counter += CODEC_IO_Write(DeviceAddr, 0x611, 0x1C0);    

    /* HPOUT1_VU, HPOUT1L_ZC, HPOUT1L_MUTE_N and HPOUT1L_VOL = -5 dB */
    counter += CODEC_IO_Write(DeviceAddr, 0x1C, 0x0174);

    /* HPOUT1_VU, HPOUT1R_ZC, HPOUT1R_MUTE_N and HPOUT1R_VOL = -5 dB */
    counter += CODEC_IO_Write(DeviceAddr, 0x1D, 0x0174);

    /* Return communication control value */
    return counter;  
}

/**
  * @brief  Deinitializes the audio codec.
  * @param  None
  * @retval  None
  */
void wm8994_DeInit(void)
{
  /* Deinitialize Audio Codec interface */
  AUDIO_IO_DeInit();
}

/**
  * @brief  Get the WM8994 ID.
  * @param DeviceAddr: Device address on communication Bus.
  * @retval The WM8994 ID 
  */
uint32_t wm8994_ReadID(uint16_t DeviceAddr)
{
  /* Initialize the Control interface of the Audio Codec */
  //AUDIO_IO_Init();

  return ((uint32_t)AUDIO_IO_Read(DeviceAddr, WM8994_CHIPID_ADDR));
}

/**
  * @brief Start the audio Codec play feature.
  * @note For this codec no Play options are required.
  * @param DeviceAddr: Device address on communication Bus.   
  * @retval 0 if correct communication, else wrong communication
  */
uint32_t wm8994_Play(uint16_t DeviceAddr, uint16_t* pBuffer, uint16_t Size)
{
  uint32_t counter = 0;
 
  /* Resumes the audio file playing */  
  /* Unmute the output first */
  counter += wm8994_SetMute(DeviceAddr, AUDIO_MUTE_OFF);
  
  return counter;
}

/**
  * @brief Pauses playing on the audio codec.
  * @param DeviceAddr: Device address on communication Bus. 
  * @retval 0 if correct communication, else wrong communication
  */
uint32_t wm8994_Pause(uint16_t DeviceAddr)
{  
  uint32_t counter = 0;
 
  /* Pause the audio file playing */
  /* Mute the output first */
  counter += wm8994_SetMute(DeviceAddr, AUDIO_MUTE_ON);
  
  /* Put the Codec in Power save mode */
  counter += CODEC_IO_Write(DeviceAddr, 0x02, 0x01);
 
  return counter;
}

/**
  * @brief Resumes playing on the audio codec.
  * @param DeviceAddr: Device address on communication Bus. 
  * @retval 0 if correct communication, else wrong communication
  */
uint32_t wm8994_Resume(uint16_t DeviceAddr)
{
  uint32_t counter = 0;
 
  /* Resumes the audio file playing */  
  /* Unmute the output first */
  counter += wm8994_SetMute(DeviceAddr, AUDIO_MUTE_OFF);
  
  return counter;
}

/**
  * @brief Stops audio Codec playing. It powers down the codec.
  * @param DeviceAddr: Device address on communication Bus. 
  * @param CodecPdwnMode: selects the  power down mode.
  *          - CODEC_PDWN_SW: only mutes the audio codec. When resuming from this 
  *                           mode the codec keeps the previous initialization
  *                           (no need to re-Initialize the codec registers).
  *          - CODEC_PDWN_HW: Physically power down the codec. When resuming from this
  *                           mode, the codec is set to default configuration 
  *                           (user should re-Initialize the codec in order to 
  *                            play again the audio stream).
  * @retval 0 if correct communication, else wrong communication
  */
uint32_t wm8994_Stop(uint16_t DeviceAddr, uint32_t CodecPdwnMode)
{
  uint32_t counter = 0;

  if (outputEnabled != 0)
  {
    /* Mute the output first */
    counter += wm8994_SetMute(DeviceAddr, AUDIO_MUTE_ON);

    if (CodecPdwnMode == CODEC_PDWN_SW)
    {
       /* Only output mute required*/
    }
    else /* CODEC_PDWN_HW */
    {
      /* Mute the AIF1 Timeslot 0 DAC1 path */
      counter += CODEC_IO_Write(DeviceAddr, 0x420, 0x0200);

      /* Mute the AIF1 Timeslot 1 DAC2 path */
      counter += CODEC_IO_Write(DeviceAddr, 0x422, 0x0200);

      /* Disable DAC1L_TO_HPOUT1L */
      counter += CODEC_IO_Write(DeviceAddr, 0x2D, 0x0000);

      /* Disable DAC1R_TO_HPOUT1R */
      counter += CODEC_IO_Write(DeviceAddr, 0x2E, 0x0000);

      /* Disable DAC1 and DAC2 */
      counter += CODEC_IO_Write(DeviceAddr, 0x05, 0x0000);

      /* Reset Codec by writing in 0x0000 address register */
      counter += CODEC_IO_Write(DeviceAddr, 0x0000, 0x0000);

      outputEnabled = 0;
    }
  }
  return counter;
}

/**
  * @brief Sets higher or lower the codec volume level.
  * @param DeviceAddr: Device address on communication Bus.
  * @param Volume: a byte value from 0 to 255 (refer to codec registers 
  *         description for more details).
  * @retval 0 if correct communication, else wrong communication
  */
uint32_t wm8994_SetVolume(uint16_t DeviceAddr, uint8_t Volume)
{
    return 0;
}

/**
  * @brief Enables or disables the mute feature on the audio codec.
  * @param DeviceAddr: Device address on communication Bus.   
  * @param Cmd: AUDIO_MUTE_ON to enable the mute or AUDIO_MUTE_OFF to disable the
  *             mute mode.
  * @retval 0 if correct communication, else wrong communication
  */
uint32_t wm8994_SetMute(uint16_t DeviceAddr, uint32_t Cmd)
{
  uint32_t counter = 0;
  
  if (outputEnabled != 0)
  {
    /* Set the Mute mode */
    if (Cmd == AUDIO_MUTE_ON)
    {
      /* Soft Mute the AIF1 Timeslot 0 DAC1 path L&R */
      counter += CODEC_IO_Write(DeviceAddr, 0x420, 0x0200);

      /* Soft Mute the AIF1 Timeslot 1 DAC2 path L&R */
      counter += CODEC_IO_Write(DeviceAddr, 0x422, 0x0200);
    }
    else /* AUDIO_MUTE_OFF Disable the Mute */
    {
      /* Unmute the AIF1 Timeslot 0 DAC1 path L&R */
      counter += CODEC_IO_Write(DeviceAddr, 0x420, 0x0000);

      /* Unmute the AIF1 Timeslot 1 DAC2 path L&R */
      counter += CODEC_IO_Write(DeviceAddr, 0x422, 0x0000);
    }
  }
  return counter;
}

/**
  * @brief Switch dynamically (while audio file is played) the output target 
  *         (speaker or headphone).
  * @param DeviceAddr: Device address on communication Bus.
  * @param Output: specifies the audio output target: OUTPUT_DEVICE_SPEAKER,
  *         OUTPUT_DEVICE_HEADPHONE, OUTPUT_DEVICE_BOTH or OUTPUT_DEVICE_AUTO 
  * @retval 0 if correct communication, else wrong communication
  */
uint32_t wm8994_SetOutputMode(uint16_t DeviceAddr, uint8_t Output)
{
  uint32_t counter = 0; 
  
  switch (Output) 
  {
  case OUTPUT_DEVICE_SPEAKER:
    /* Enable DAC1 (Left), Enable DAC1 (Right), 
    Disable DAC2 (Left), Disable DAC2 (Right)*/
    counter += CODEC_IO_Write(DeviceAddr, 0x05, 0x0C0C);
    
    /* Enable the AIF1 Timeslot 0 (Left) to DAC 1 (Left) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x601, 0x0000);
    
    /* Enable the AIF1 Timeslot 0 (Right) to DAC 1 (Right) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x602, 0x0000);
    
    /* Disable the AIF1 Timeslot 1 (Left) to DAC 2 (Left) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x604, 0x0002);
    
    /* Disable the AIF1 Timeslot 1 (Right) to DAC 2 (Right) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x605, 0x0002);
    break;
    
  case OUTPUT_DEVICE_HEADPHONE:
    /* Disable DAC1 (Left), Disable DAC1 (Right), 
    Enable DAC2 (Left), Enable DAC2 (Right)*/
    counter += CODEC_IO_Write(DeviceAddr, 0x05, 0x0303);
    
    /* Enable the AIF1 Timeslot 0 (Left) to DAC 1 (Left) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x601, 0x0001);
    
    /* Enable the AIF1 Timeslot 0 (Right) to DAC 1 (Right) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x602, 0x0001);
    
    /* Disable the AIF1 Timeslot 1 (Left) to DAC 2 (Left) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x604, 0x0000);
    
    /* Disable the AIF1 Timeslot 1 (Right) to DAC 2 (Right) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x605, 0x0000);
    break;
    
  case OUTPUT_DEVICE_BOTH:
    /* Enable DAC1 (Left), Enable DAC1 (Right), 
    also Enable DAC2 (Left), Enable DAC2 (Right)*/
    counter += CODEC_IO_Write(DeviceAddr, 0x05, 0x0303 | 0x0C0C);
    
    /* Enable the AIF1 Timeslot 0 (Left) to DAC 1 (Left) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x601, 0x0001);
    
    /* Enable the AIF1 Timeslot 0 (Right) to DAC 1 (Right) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x602, 0x0001);
    
    /* Enable the AIF1 Timeslot 1 (Left) to DAC 2 (Left) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x604, 0x0002);
    
    /* Enable the AIF1 Timeslot 1 (Right) to DAC 2 (Right) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x605, 0x0002);
    break;
    
  default:
    /* Disable DAC1 (Left), Disable DAC1 (Right), 
    Enable DAC2 (Left), Enable DAC2 (Right)*/
    counter += CODEC_IO_Write(DeviceAddr, 0x05, 0x0303);
    
    /* Enable the AIF1 Timeslot 0 (Left) to DAC 1 (Left) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x601, 0x0001);
    
    /* Enable the AIF1 Timeslot 0 (Right) to DAC 1 (Right) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x602, 0x0001);
    
    /* Disable the AIF1 Timeslot 1 (Left) to DAC 2 (Left) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x604, 0x0000);
    
    /* Disable the AIF1 Timeslot 1 (Right) to DAC 2 (Right) mixer path */
    counter += CODEC_IO_Write(DeviceAddr, 0x605, 0x0000);
    break;    
  }  
  return counter;
}

/**
  * @brief Sets new frequency.
  * @param DeviceAddr: Device address on communication Bus.
  * @param AudioFreq: Audio frequency used to play the audio stream.
  * @retval 0 if correct communication, else wrong communication
  */
uint32_t wm8994_SetFrequency(uint16_t DeviceAddr, uint32_t AudioFreq)
{
  uint32_t counter = 0;
 
  /*  Clock Configurations */
  switch (AudioFreq)
  {
  case  AUDIO_FREQUENCY_8K:
    /* AIF1 Sample Rate = 8 (KHz), ratio=256 */ 
    counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0003);
    break;
    
  case  AUDIO_FREQUENCY_16K:
    /* AIF1 Sample Rate = 16 (KHz), ratio=256 */ 
    counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0033);
    break;
    
  case  AUDIO_FREQUENCY_48K:
    /* AIF1 Sample Rate = 48 (KHz), ratio=256 */ 
    counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0083);
    break;
    
  case  AUDIO_FREQUENCY_96K:
    /* AIF1 Sample Rate = 96 (KHz), ratio=256 */ 
    counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x00A3);
    break;
    
  case  AUDIO_FREQUENCY_11K:
    /* AIF1 Sample Rate = 11.025 (KHz), ratio=256 */ 
    counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0013);
    break;
    
  case  AUDIO_FREQUENCY_22K:
    /* AIF1 Sample Rate = 22.050 (KHz), ratio=256 */ 
    counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0043);
    break;
    
  case  AUDIO_FREQUENCY_44K:
    /* AIF1 Sample Rate = 44.1 (KHz), ratio=256 */ 
    counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0073);
    break; 
    
  default:
    /* AIF1 Sample Rate = 48 (KHz), ratio=256 */ 
    counter += CODEC_IO_Write(DeviceAddr, 0x210, 0x0083);
    break; 
  }
  return counter;
}

/**
  * @brief Resets wm8994 registers.
  * @param DeviceAddr: Device address on communication Bus. 
  * @retval 0 if correct communication, else wrong communication
  */
uint32_t wm8994_Reset(uint16_t DeviceAddr)
{
  uint32_t counter = 0;
  
  /* Reset Codec by writing in 0x0000 address register */
  counter = CODEC_IO_Write(DeviceAddr, 0x0000, 0x0000);
    
  outputEnabled = 0;

  return counter;
}

/**
  * @brief  Writes/Read a single data.
  * @param  Addr: I2C address
  * @param  Reg: Reg address 
  * @param  Value: Data to be written
  * @retval None
  */
static uint8_t CODEC_IO_Write(uint8_t Addr, uint16_t Reg, uint16_t nWriteValue)
{
    uint16_t nReadValue;
    
    uint8_t result = 0;
  
    AUDIO_IO_Write(Addr, Reg, nWriteValue);
  
#ifdef VERIFY_WRITTENDATA
    
    nReadValue = AUDIO_IO_Read(Addr, Reg);
    
    /* Verify that the data has been correctly written */
    result = nReadValue == nWriteValue ? 0 : 1;
    
#endif /* VERIFY_WRITTENDATA */
  
    return result;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
