/*******************************************************************************
*
*               Audio Framework
*               ---------------
*
********************************************************************************
*     BoardSetup.c
********************************************************************************
*
*     Description:  STM Discovery board configuration
*
*     Copyright:    DSP Concepts, Inc. (c) 2007 - 2016
*                   1800 Wyatt Drive, Suite 14
*                   Sunnyvale, CA 95054
*
*******************************************************************************/
#include "usbd_desc.h"
#include "usbd_audio_if.h"
#include "stm32f769i_discovery_qspi.h"
#include "stm32f769i_discovery_lcd.h"
#include "BoardSetup.h"

USBD_HandleTypeDef USBD_Device;

extern volatile int32_t g_bSuspendWhileRunning;

static void SystemClock_Config(void);
static void CPU_CACHE_Enable(void);
void Toggle_Leds(void);


/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;

  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Activate the OverDrive to reach the 216 MHz Frequency */
  HAL_PWREx_EnableOverDrive();
   
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | 
                                 RCC_CLOCKTYPE_HCLK   | 
                                 RCC_CLOCKTYPE_PCLK1  | 
                                 RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7);
      
  /* Select PLLSAI output as USB clock source */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_CLK48;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48SOURCE_PLLSAIP;
  //PeriphClkInitStruct.PLLSAI.PLLSAIN = 384;
  //PeriphClkInitStruct.PLLSAI.PLLSAIQ = 7; 
  //PeriphClkInitStruct.PLLSAI.PLLSAIP = RCC_PLLSAIP_DIV8;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 192;
  PeriphClkInitStruct.PLLSAI.PLLSAIQ = 4; 
  PeriphClkInitStruct.PLLSAI.PLLSAIP = RCC_PLLSAIP_DIV4;
  
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);   
  
  SystemCoreClockUpdate();

}   // End SystemClock_Config


/**
  * @brief  Clock Config.
  * @param  hsai: might be required to set audio peripheral predivider if any.
  * @param  AudioFreq: Audio frequency used to play the audio stream.
  * @note   This API is called by BSP_AUDIO_OUT_Init() and BSP_AUDIO_OUT_SetFrequency()
  *         Being __weak it can be overwritten by the application     
  * @retval None
  */
void BSP_AUDIO_OUT_ClockConfig(SAI_HandleTypeDef *hsai, uint32_t AudioFreq, void *Params)
{
    RCC_PeriphCLKInitTypeDef RCC_PeriphCLKInitStruct;   

    HAL_RCCEx_GetPeriphCLKConfig(&RCC_PeriphCLKInitStruct);
    
    RCC_PeriphCLKInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SAI1;
    RCC_PeriphCLKInitStruct.Sai1ClockSelection = RCC_SAI1CLKSOURCE_PLLSAI;

    // Set the PLL configuration according to the audio frequency 
    if ((AudioFreq == AUDIO_FREQUENCY_11K) || (AudioFreq == AUDIO_FREQUENCY_22K) || (AudioFreq == AUDIO_FREQUENCY_44K))
    {
        // Configure PLLSAI prescalers 
        // PLLI2S_VCO: VCO_429M
            
        // SAI_CLK(first level) = PLLSAI_VCO/PLLSAIQ = 429/2 = 214.5 Mhz
        // SAI_CLK_x = SAI_CLK(first level)/PLLSAIDIVQ = 214.5/19 = 11.289 Mhz        
        RCC_PeriphCLKInitStruct.PLLSAI.PLLSAIN = 429; 
        RCC_PeriphCLKInitStruct.PLLSAI.PLLSAIQ = 2; 
        RCC_PeriphCLKInitStruct.PLLSAIDivQ = 19;
          
        HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphCLKInitStruct);
    }
    else // AUDIO_FREQUENCY_8K, AUDIO_FREQUENCY_16K, AUDIO_FREQUENCY_48K), AUDIO_FREQUENCY_96K 
    {
        // SAI clock config
        // PLLI2S_VCO: VCO_344M      
        
        // SAI_CLK(first level) = PLLI2S_VCO/PLLSAIQ = 344/7 = 49.142 Mhz
        // SAI_CLK_x = SAI_CLK(first level)/PLLI2SDivQ = 49.142/1 = 49.142 Mhz     
        RCC_PeriphCLKInitStruct.PLLSAI.PLLSAIN = 344;
        RCC_PeriphCLKInitStruct.PLLSAI.PLLSAIQ = 7;
        RCC_PeriphCLKInitStruct.PLLSAIDivQ = 1;
          
        HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphCLKInitStruct);
    }

}    // End BSP_AUDIO_OUT_ClockConfig



/**
  * @brief  Toggle LEDs to show user input state.   
  * @param  None
  * @retval None
  */
void Toggle_Leds(void)
{
    static uint32_t ticks;

    if (ticks++ == 0xFFFFF)
    {
        BSP_LED_Toggle(LED1);
        ticks = 0;
    }
}


/**
  * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
  * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
  *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;
  
  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU attributes as WT for SRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x20020000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_512KB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}


/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
    /*
    __DSB();
    
    // Disable the MPU 
    MPU->CTRL = 0;

    // Configure Region 0 for internal SRAM as Normal memory type with WBWA and shareable (for coherency with DMA) 
    MPU->RBAR = 0x20000000 |                    // Region address 
                MPU_RBAR_VALID_Msk |            // Region configured 
                (0 << MPU_RBAR_REGION_Pos);     // Region 0 
    MPU->RASR = (0x0 << MPU_RASR_XN_Pos) |      // Allow instruction fetches (may contain code) 
                (0x3 << MPU_RASR_AP_Pos) |      // R/W 
                (0x1 << MPU_RASR_TEX_Pos) |     // WBWA 
                (0x1 << MPU_RASR_S_Pos) |       // Shareable 
                (0x1 << MPU_RASR_C_Pos) |       // Cacheable 
                (0x1 << MPU_RASR_B_Pos) |       // Bufferable 
                (0x00 << MPU_RASR_SRD_Pos ) |   // All sub-regions configured 
                (0x12 << MPU_RASR_SIZE_Pos) |   // 512KB 
                MPU_RASR_ENABLE_Msk;            // Enable 

    // Configure Region 1 for SDRAM as Normal memory type with WBWA and shareable (for coherency with DMA) 
    MPU->RBAR = 0xC0000000 |                    // Region address 
                MPU_RBAR_VALID_Msk |            // Region configured 
                (1 << MPU_RBAR_REGION_Pos);     // Region 1 
    MPU->RASR = (0x0 << MPU_RASR_XN_Pos) |      // Allow instruction fetches (may contain code) 
                (0x3 << MPU_RASR_AP_Pos) |      // R/W 
                (0x1 << MPU_RASR_TEX_Pos) |     // WBWA 
                (0x1 << MPU_RASR_S_Pos) |       // Shareable 
                (0x1 << MPU_RASR_C_Pos) |       // Cacheable 
                (0x1 << MPU_RASR_B_Pos) |       // Bufferable 
                (0x00 << MPU_RASR_SRD_Pos ) |   // All sub-regions configured 
                (0x18 << MPU_RASR_SIZE_Pos) |   // 32MB 
                MPU_RASR_ENABLE_Msk;            // Enable 

    // Configure Region 2 for External Flash as Strongly ordered memory type 
    MPU->RBAR = 0x60000000 |                    // Region address 
                MPU_RBAR_VALID_Msk |            // Region configured 
                (2 << MPU_RBAR_REGION_Pos);     // Region 2 
    MPU->RASR = (0x1 << MPU_RASR_XN_Pos) |      // No instruction fetches (it's a file system) 
                (0x3 << MPU_RASR_AP_Pos) |      // R/W 
                (0x0 << MPU_RASR_TEX_Pos) |     // Strongly ordered 
                (0x0 << MPU_RASR_S_Pos) |       // Don't care, Implicitly shareable 
                (0x0 << MPU_RASR_C_Pos) |       // Not cacheable 
                (0x0 << MPU_RASR_B_Pos) |       // Not bufferable 
                (0x00 << MPU_RASR_SRD_Pos ) |   // All sub-regions configured 
                (0x17 << MPU_RASR_SIZE_Pos) |   // 16MB 
                MPU_RASR_ENABLE_Msk;            // Enable 

    // Enable the MPU, and use the default map for any unspecified region 
    MPU->CTRL = MPU_CTRL_PRIVDEFENA_Msk | MPU_CTRL_ENABLE_Msk;
    __DSB();
    __ISB();

    // Invalidate I&D Cache 
    SCB_InvalidateICache();
    SCB_InvalidateDCache();
    
    // Enable branch prediction 
    SCB->CCR |= (1 << 18); 
    __DSB();
    
    */

    // Enable I&D Cache 
    SCB_EnableICache();
    SCB_EnableDCache();
    
}   // End CPU_CACHE_Enable


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


void USB_ReInit()   
{
    USBD_DeInit(&USBD_Device);
    
    // Init Device Library
    USBD_Init(&USBD_Device, &AUDIO_Desc, 0);

    // Add Supported Class
    USBD_RegisterClass(&USBD_Device, USBD_AUDIO_CLASS);

    // Add Interface callbacks for AUDIO Class
    USBD_AUDIO_RegisterInterface(&USBD_Device, &USBD_AUDIO_fops);

    // Start Device Process
    USBD_Start(&USBD_Device); 
    
    HAL_Delay(500);

    g_bSuspendWhileRunning = 0;
    
}   // End USB_ReInit


/**
  * @brief  CoreInit
  * @param  None
  * @retval None
  */
void CoreInit(void)
{       
    // Initialize the low part of the stack - so we can see how much stack is used
    //memset((void *)(0x20050000 - 0x900), 0xCD, 0x900 - 16);
    
    MPU_Config();
    
    /* Enable the CPU Cache */
    CPU_CACHE_Enable();

    /* STM32F7xx HAL library initialization:
       - Configure the Flash ART accelerator on ITCM interface
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Low Level Initialization
    */
    HAL_Init();

    // Configure the System clock to have a frequency of 216 MHz
    SystemClock_Config();
    
	// Core_Cm7.h has a bug in the way they set the timer tick interrupt priority
    // Want timer tick to be the highest priority
    HAL_NVIC_SetPriority(SysTick_IRQn, 1, 0); 
    
}   // End CoreInit


/**
  * @brief  BoardInit
  * @param  None
  * @retval None
  */
void BoardInit(void)
{   
    // Setup SDRAM access  
    BSP_SDRAM_Init();  
    
    // Setup QSPI to access flash memory
    BSP_QSPI_Init();
      
    // Setup the LCD
    //BSP_LCD_Init();
    
    // Setup the audio subsystem
    SetupAudio();
    
    BSP_LED_Init(LED1);
    BSP_LED_Init(LED2);
    
    BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);

    // Init Device Library
    USBD_Init(&USBD_Device, &AUDIO_Desc, 0);

    // Add Supported Class
    USBD_RegisterClass(&USBD_Device, USBD_AUDIO_CLASS);

    // Add Interface callbacks for AUDIO Class
    USBD_AUDIO_RegisterInterface(&USBD_Device, &USBD_AUDIO_fops); 
	
}   // End BoardInit

