/**
  ******************************************************************************
  * @file    usbd_audio.c
  * @author  MCD Application Team
  * @version V2.4.2
  * @date    11-December-2015
  * @brief   This file provides the Audio core functions.
  *
  * @verbatim
  *      
  *          ===================================================================      
  *                                AUDIO Class  Description
  *          ===================================================================
 *           This driver manages the Audio Class 1.0 following the "USB Device Class Definition for
  *           Audio Devices V1.0 Mar 18, 98".
  *           This driver implements the following aspects of the specification:
  *             - Device descriptor management
  *             - Configuration descriptor management
  *             - Standard AC Interface Descriptor management
  *             - 1 Audio Streaming Interface (with single channel, PCM, Stereo mode)
  *             - 1 Audio Streaming Endpoint
  *             - 1 Audio Terminal Input (1 channel)
  *             - Audio Class-Specific AC Interfaces
  *             - Audio Class-Specific AS Interfaces
  *             - AudioControl Requests: only SET_CUR and GET_CUR requests are supported (for Mute)
  *             - Audio Feature Unit (limited to Mute control)
  *             - Audio Synchronization type: Asynchronous
  *             - Single fixed audio sampling rate (configurable in usbd_conf.h file)
  *          The current audio class version supports the following audio features:
  *             - Pulse Coded Modulation (PCM) format
  *             - sampling rate: 48KHz. 
  *             - Bit resolution: 16
  *             - Number of channels: 2
  *             - Volume control
  *             - Mute/Unmute capability
  *             - Asynchronous Endpoints 
  *          
  * @note     In HS mode and when the DMA is used, all variables and data structures
  *           dealing with the DMA during the transaction process should be 32-bit aligned.
  *           
  *      
  *  @endverbatim
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "usbd_audio.h"
#include "usbd_desc.h"
#include "usbd_ctlreq.h"
#include "Platform.h"

#define DEV_SPK_MAX_VOL		0x0000 
#define DEV_SPK_MIN_VOL		0xDB10
#define DEV_SPK_RES_VOL		0x0030
#define DEV_SPK_CUR_VOL		0xFFF0  
                                        
#define TRUE 1
#define FALSE 0  

extern volatile fract32 g_nNewVolGain;
extern volatile BOOL g_bRecording;

static VEC_INLINE fract32 float_to_fract32(float x)
{
      // Clip to the allowable range
      float temp;
      if (x < -1.0f)
      {
          return((fract32)0x80000000);
      }

      if (x >= 1.0f)
      {
          return(0x7FFFFFFF);
      }

      temp = x * 2147483648.0f;
      temp+= temp> 0.0f? 0.5f : -0.5f;

      // Multiply by 2^31
      return (fract32)(temp);

}   // End float_to_fract32    

                                         
/**
  * @}
  */ 

/** @defgroup AudioWeaver_Private_Variables
  * @{
  */ 
static uint32_t s_nPacketBufferNdx = 0;
static uint32_t s_nPacketLenInDWords = 0;

USBD_AUDIO_HandleTypeDef AudioParameters;

uint32_t nEndNdx = 0;
uint32_t nWordsReceived = 0;

extern const uint8_t USBD_AUDIO_CfgDesc[USB_AUDIO_CONFIG_DESC_SIZE];
extern const uint8_t HID_ReportDescriptor[REPORT_DESC_SIZE];
extern const uint8_t USBD_HID_Desc[USB_HID_DESC_SIZE];
extern const uint8_t USBD_AUDIO_DeviceQualifierDesc[USB_LEN_DEV_QUALIFIER_DESC];


/** @defgroup USBD_AUDIO_Private_FunctionPrototypes
  * @{
  */
static uint8_t  USBD_AUDIO_Init(USBD_HandleTypeDef *pdev, 
                                uint8_t cfgidx);

static uint8_t  USBD_AUDIO_DeInit(USBD_HandleTypeDef *pdev, 
                                  uint8_t cfgidx);

static uint8_t  USBD_AUDIO_Setup(USBD_HandleTypeDef *pdev, 
                                 USBD_SetupReqTypedef *req);

static uint8_t  *USBD_AUDIO_GetCfgDesc(uint16_t *length);

static uint8_t  *USBD_AUDIO_GetDeviceQualifierDesc (uint16_t *length);

static uint8_t  USBD_AUDIO_DataIn(USBD_HandleTypeDef *pdev, uint8_t epnum);

static uint8_t  USBD_AUDIO_DataOut(USBD_HandleTypeDef *pdev, uint8_t epnum);

static uint8_t  USBD_AUDIO_EP0_RxReady(USBD_HandleTypeDef *pdev);

static uint8_t  USBD_AUDIO_EP0_TxReady(USBD_HandleTypeDef *pdev);

static uint8_t  USBD_AUDIO_SOF(USBD_HandleTypeDef *pdev);

static uint8_t  USBD_AUDIO_IsoINIncomplete(USBD_HandleTypeDef *pdev, uint8_t epnum);

static uint8_t  USBD_AUDIO_IsoOutIncomplete(USBD_HandleTypeDef *pdev, uint8_t epnum);

static void AUDIO_REQ_GetCurrent(USBD_HandleTypeDef *pdev, USBD_SetupReqTypedef *req);

static void AUDIO_REQ_SetCurrent(USBD_HandleTypeDef *pdev, USBD_SetupReqTypedef *req);
 

/** @defgroup USBD_AUDIO_Private_Variables
  * @{
  */ 
USBD_ClassTypeDef USBD_AUDIO = 
{
  USBD_AUDIO_Init,
  USBD_AUDIO_DeInit,
  USBD_AUDIO_Setup,
  USBD_AUDIO_EP0_TxReady,  
  USBD_AUDIO_EP0_RxReady,
  USBD_AUDIO_DataIn,
  USBD_AUDIO_DataOut,
  USBD_AUDIO_SOF,
  USBD_AUDIO_IsoINIncomplete,
  USBD_AUDIO_IsoOutIncomplete,      
  USBD_AUDIO_GetCfgDesc,
  USBD_AUDIO_GetCfgDesc, 
  USBD_AUDIO_GetCfgDesc,
  USBD_AUDIO_GetDeviceQualifierDesc
};

// -90.5 dB
int16_t nMinVol = DEV_SPK_MIN_VOL;

// 0 dB 
int16_t nMaxVol = DEV_SPK_MAX_VOL;

// 1/256 dB step
int16_t nResVol = DEV_SPK_RES_VOL; 

// -22.5 dB
volatile int16_t g_nCurrentVolume = DEV_SPK_CUR_VOL;

/**
  * @}
  */ 

/** @defgroup USBD_AUDIO_Private_Functions
  * @{
  */ 

/**
  * @brief  USBD_AUDIO_Init
  *         Initialize the AUDIO interface
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
static uint8_t USBD_AUDIO_Init(USBD_HandleTypeDef *pdev, 
                               uint8_t cfgidx)
{
  USBD_AUDIO_HandleTypeDef * haudio;
    
  USBD_LL_OpenEP(pdev,
                 AUDIO_OUT_EP,
                 USBD_EP_TYPE_ISOC,
                 AUDIO_EP_BUFFER_SIZE);   
    
  USBD_LL_OpenEP(pdev,
                 AUDIO_IN_EP,
                 USBD_EP_TYPE_ISOC,
                 USB_REC_EP_BUFFER_SIZE);     
      
  USBD_LL_OpenEP(pdev,
                 HID_IN_EP,
                 USBD_EP_TYPE_INTR,
                 HID_EP_BUFFER_SIZE);
    
  USBD_LL_OpenEP(pdev,
                 HID_OUT_EP,
                 USBD_EP_TYPE_INTR,
                 HID_EP_BUFFER_SIZE);
     
  pdev->pClassData = &AudioParameters;
  memset(pdev->pClassData, 0, sizeof(USBD_AUDIO_HandleTypeDef) );
  
  if (pdev->pClassData == NULL)
  {
    return USBD_FAIL; 
  }
  else
  {
    haudio = (USBD_AUDIO_HandleTypeDef *)pdev->pClassData;
    haudio->alt_setting = 0;
    haudio->offset = AUDIO_OFFSET_UNKNOWN;
    haudio->wr_ptr = 0; 
    haudio->rd_ptr = 0;  
    haudio->rd_enable = 0;
    haudio->buffer = USBBufferIn;
    
    /* Initialize the Audio output Hardware layer */
    if (((USBD_AUDIO_ItfTypeDef *)pdev->pUserData)->Init(USBD_AUDIO_FREQ, AUDIO_DEFAULT_VOLUME, 0) != USBD_OK)
    {
      return USBD_FAIL;
    }
    
    /* Prepare Out endpoint to receive 1st packet */ 
    USBD_LL_PrepareReceive(pdev,
                           AUDIO_OUT_EP,
                           (PBYTE)haudio->buffer,                        
                           AUDIO_EP_BUFFER_SIZE);   

    // Prepare Out endpoint to receive HID Report packets    
    USBD_LL_PrepareReceive(pdev, 
                           HID_OUT_EP, 
                           HIDOutBuff, 
                           HID_EP_BUFFER_SIZE); 

    USBD_LL_FlushEP(pdev, AUDIO_IN_EP);
 
    USBD_LL_Transmit(pdev, AUDIO_IN_EP,
                     (PBYTE)USBBufferOut,                        
                     USB_REC_EP_BUFFER_SIZE);    
  }
  
  return USBD_OK;
  
}   // End USBD_AUDIO_Init


/**
  * @brief  USBD_AUDIO_Init
  *         DeInitialize the AUDIO layer
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
static uint8_t USBD_AUDIO_DeInit(USBD_HandleTypeDef *pdev, 
                                  uint8_t cfgidx)
{
  
  USBD_LL_CloseEP(pdev, AUDIO_OUT_EP);
    
  USBD_LL_CloseEP(pdev, AUDIO_IN_EP);    
     
  USBD_LL_CloseEP(pdev, HID_IN_EP);
    
  USBD_LL_CloseEP(pdev, HID_OUT_EP); 
  
  return USBD_OK;
}

/**
  * @brief  USBD_AUDIO_Setup
  *         Handle the AUDIO specific requests
  * @param  pdev: instance
  * @param  req: usb requests
  * @retval status
  */
static uint8_t USBD_AUDIO_Setup(USBD_HandleTypeDef * pdev, 
                                USBD_SetupReqTypedef * req)
{
    USBD_AUDIO_HandleTypeDef * haudio;
    uint16_t len;
    uint8_t *pbuf;
    static uint8_t nHIDProtocol = 0;
    static uint8_t nHIDIdleState = 0;
    uint8_t ret = USBD_OK;
       
    haudio = (USBD_AUDIO_HandleTypeDef *)pdev->pClassData;

    switch (req->bmRequest & USB_REQ_TYPE_MASK)
    {
        
    case USB_REQ_TYPE_CLASS: 
        
        switch (req->bRequest)
        {
        case AUDIO_REQ_GET_CUR:
            AUDIO_REQ_GetCurrent(pdev, req);
            break;
          
        case AUDIO_REQ_SET_CUR:
            AUDIO_REQ_SetCurrent(pdev, req);   
            break;
        
        case HID_REQ_SET_PROTOCOL:
            nHIDProtocol = (uint8_t)(req->wValue);
            break;

        case HID_REQ_GET_PROTOCOL:
            USBD_CtlSendData(pdev, &nHIDProtocol, 1);    
            break;

        case HID_REQ_SET_IDLE:
            nHIDIdleState = (uint8_t)(req->wValue >> 8);
            break;

        case HID_REQ_GET_IDLE:
            USBD_CtlSendData(pdev, &nHIDIdleState, 1); 
            break;
                           
        case AUDIO_REQ_GET_MIN:
            
            USBD_CtlSendData(pdev, (uint8_t *)&nMinVol, sizeof(nMinVol) );
            break;

        case AUDIO_REQ_GET_MAX:
           
            USBD_CtlSendData(pdev, (uint8_t *)&nMaxVol, sizeof(nMaxVol) );
            break;

        case AUDIO_REQ_GET_RES:
                 
            USBD_CtlSendData(pdev, (uint8_t *)&nResVol, sizeof(nResVol) );
            break;
        
          
        default:
            USBD_CtlError(pdev, req);
            ret = USBD_FAIL; 
        }
        
        break;

    case USB_REQ_TYPE_STANDARD:

        switch (req->bRequest)
        {
        case USB_REQ_GET_DESCRIPTOR:      
           
            if ( (req->wValue >> 8) == AUDIO_DESCRIPTOR_TYPE)
            {
                pbuf = (uint8_t *)USBD_AUDIO_CfgDesc + 18;
                len = MIN(USB_AUDIO_DESC_SIZ , req->wLength);
                        
                USBD_CtlSendData(pdev, pbuf, len);
            }
            else if ( (req->wIndex & 0x00FF) == HID_INTERFACE_NUMBER)
            {           
                if (req->wValue >> 8 == HID_REPORT_DESCRIPTOR_TYPE)
                {
                    pbuf = (uint8_t *)HID_ReportDescriptor;
                    len = MIN(REPORT_DESC_SIZE, req->wLength);
                                   
                    USBD_CtlSendData(pdev, pbuf, len);
                }
                else if (req->wValue >> 8 == HID_DESCRIPTOR_TYPE)
                {
                    pbuf = (uint8_t *)USBD_HID_Desc;
                    len = MIN(USB_HID_DESC_SIZE, req->wLength);
                                    
                    USBD_CtlSendData(pdev, pbuf, len);
                }
            }

            break;
          
        case USB_REQ_GET_INTERFACE:
            
            USBD_CtlSendData(pdev, (uint8_t *)haudio->alt_setting, 1);
        
            break;
          
        case USB_REQ_SET_INTERFACE:
            
            if ((uint8_t)(req->wValue) <= USBD_MAX_NUM_INTERFACES)
            {
                haudio->alt_setting = (uint8_t)(req->wValue);
                
                // wIndex 1 - Play, 2 - Record
                if (req->wIndex == 2)
                {
                    if (req->wValue == 1)
                    {
                        g_bRecording = TRUE;
                        //printf("R\n");
                    }
                    else
                    {
                        g_bRecording = FALSE;
                        //printf("NR\n");                        
                    }
                }                   
            }
            else
            {
                /* Call the error management function (command will be nacked */
                USBD_CtlError(pdev, req);
            }
            
            break; 
          
        default:
            
          USBD_CtlError(pdev, req);
          ret = USBD_FAIL; 
             
        }
    }
    
    return ret;
    
}   // End USBD_AUDIO_Setup


/**
  * @brief  USBD_AUDIO_GetCfgDesc 
  *         return configuration descriptor
  * @param  speed : current device speed
  * @param  length : pointer data length
  * @retval pointer to descriptor buffer
  */
static uint8_t * USBD_AUDIO_GetCfgDesc (uint16_t *length)
{
  *length = sizeof (USBD_AUDIO_CfgDesc);
  return (uint8_t *)USBD_AUDIO_CfgDesc;
}


/**
  * @brief  USBD_AUDIO_EP0_RxReady
  *         handle EP0 Rx Ready event
  * @param  pdev: device instance
  * @retval status
  */
static uint8_t USBD_AUDIO_EP0_RxReady(USBD_HandleTypeDef *pdev)
{
    USBD_AUDIO_HandleTypeDef *haudio;

    haudio = (USBD_AUDIO_HandleTypeDef *)pdev->pClassData;

    if (haudio->control.cmd == AUDIO_REQ_SET_CUR)
    {   
        if (haudio->control.unit == AUDIO_OUT_STREAMING_CTRL)
        {
            uint8_t nControlSelector = HIBYTE(pdev->request.wValue); 
            
            if (nControlSelector == AUDIO_CONTROL_MUTE)
            {            
                ((USBD_AUDIO_ItfTypeDef *)pdev->pUserData)->MuteCtl(haudio->control.data[0]);
            }
            else if (nControlSelector == AUDIO_CONTROL_VOLUME)
            {
                int16_t  nValue;
                float fValue;
                
                nValue = haudio->control.data[1]; 
                nValue = (nValue << 8) | haudio->control.data[0]; 
                
                nValue = -nValue; 
                
                nValue = nValue ? nValue : 1;

                fValue = 100.0f / nValue;
                
                g_nNewVolGain = float_to_fract32(fValue);                            
            }
            
            haudio->control.cmd = 0;
            haudio->control.len = 0;            
        }
    }

    return USBD_OK;       
    
}   // End USBD_AUDIO_EP0_RxReady


/**
  * @brief  USBD_AUDIO_EP0_TxReady
  *         handle EP0 TRx Ready event
  * @param  pdev: device instance
  * @retval status
  */
static uint8_t USBD_AUDIO_EP0_TxReady(USBD_HandleTypeDef *pdev)
{
  // Only OUT control data are processed
  return USBD_OK;
}


/**
  * @brief  USBD_AUDIO_SOF
  *         handle SOF event
  * @param  pdev: device instance
  * @retval status
  */   
static uint8_t USBD_AUDIO_SOF(USBD_HandleTypeDef *pdev)
{
  return USBD_OK;
}


/**
  * @brief  USBD_AUDIO_SOF
  *         handle SOF event
  * @param  pdev: device instance
  * @retval status
  */
void USBD_AUDIO_Sync(USBD_HandleTypeDef *pdev, AUDIO_OffsetTypeDef offset)
{

}


/**
  * @brief  USBD_AUDIO_IsoINIncomplete
  *         handle data ISO IN Incomplete event
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */

static uint8_t USBD_AUDIO_IsoINIncomplete(USBD_HandleTypeDef *pdev, uint8_t epnum)
{
  return USBD_OK;
}


/**
  * @brief  USBD_AUDIO_IsoOutIncomplete
  *         handle data ISO OUT Incomplete event
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
static uint8_t USBD_AUDIO_IsoOutIncomplete(USBD_HandleTypeDef *pdev, uint8_t epnum)
{
  return USBD_OK;
}


/**
  * @brief  USBD_AUDIO_DataIn
  *         handle data IN Stage
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
static uint8_t USBD_AUDIO_DataIn(USBD_HandleTypeDef *pdev, 
                                 uint8_t epnum)
{
    if (epnum == (AUDIO_IN_EP & 0x7F) )
    {
        INT16 * pUSBSamples;
              
        // Get the number of available USB samples in the ASRC jitter buffer
        INT32 nSamplesAvail = dspc_asrc_output_avail(&USB_Record_ASRC);
        
        if (nSamplesAvail >= USB_RECORD_OUTPUT_BLOCKSIZE)
        {     
            // Read a block of samples from the ASRC jitter buffer
            dspc_asrc_read_output_linear_Q15(&USB_Record_ASRC, USBBufferOut, USB_RECORD_OUTPUT_BLOCKSIZE);  
            pUSBSamples =  USBBufferOut;                           
        }
        else
        {
            // Insert zeros if no audio samples available (CODEC continually runs)
            pUSBSamples = ZeroedSamples;            
        }
               
        USBD_LL_Transmit(pdev, AUDIO_IN_EP,
                         (PBYTE)pUSBSamples,                        
                          USB_REC_EP_BUFFER_SIZE); 
    }
    else
    {
        // (epnum == HID_IN_EP)
        if (g_bReadyToSend)
        {
            NVIC_SetPendingIRQ(ProcessUSBMsg_IRQ);  
        }  
    }        
    
    return USBD_OK;
}


/**
  * @brief  USBD_AUDIO_DataOut
  *         handle data OUT Stage
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
static uint8_t USBD_AUDIO_DataOut(USBD_HandleTypeDef *pdev, uint8_t epnum)
{      
    if (epnum == AUDIO_OUT_EP)
    {  
        USBD_AUDIO_HandleTypeDef * haudio = (USBD_AUDIO_HandleTypeDef*)pdev->pClassData; 
        
        // Prepare Out endpoint to receive next audio packet
        USBD_LL_PrepareReceive(pdev,
                               AUDIO_OUT_EP,
                               (PBYTE)&(haudio->buffer[nUSBWriteBufferNdx]), 
                               AUDIO_EP_BUFFER_SIZE);       
        
        nUSBWriteBufferNdx = (nUSBWriteBufferNdx + NEW_USB_SAMPLES) % USB_AUDIO_BUFFER_SIZE_IN_SAMPLES;        

        // Issue software interrupt to place received data into ASRC buffer
        NVIC_SetPendingIRQ(ProcessWriteASRC_IRQ);  
    }
  
    if (epnum == HID_OUT_EP)
    {  
        uint8_t nPayloadByteCount;

        nPayloadByteCount = HIDOutBuff[3];  
        nWordsReceived = nPayloadByteCount >> 2;
        nEndNdx = s_nPacketBufferNdx + nWordsReceived;

        if ( nEndNdx < MAX_COMMAND_BUFFER_LEN)   
        {
            // Copy the data into the AWE packet buffer
            memcpy(&s_PacketBuffer[s_nPacketBufferNdx], &HIDOutBuff[4], nPayloadByteCount);

            // Prepare Out endpoint to receive next HID packet
            USBD_LL_PrepareReceive(pdev, HID_OUT_EP, HIDOutBuff, HID_EP_BUFFER_SIZE);

            if (s_nPacketBufferNdx == 0)
            {
                uint32_t * pPacketLen = (uint32_t *)&HIDOutBuff[4];
                s_nPacketLenInDWords = *pPacketLen >> 16;
            }  

            // Turn byte count into DWORD count and add to index
            s_nPacketBufferNdx += nWordsReceived;					

            if (s_nPacketBufferNdx >= s_nPacketLenInDWords)
            {               
                g_bUSBPacketReceived = TRUE;
                
                s_nPacketBufferNdx = 0;  

                s_nPacketLenInDWords = 0;            
            }  
        }
        else
        {
            // Buffer overrun - reset message handling
            
            s_nPacketBufferNdx = 0;  

            s_nPacketLenInDWords = 0;            
        }    
        
    }   // End if
   
    return USBD_OK;
}

/**
  * @brief  AUDIO_Req_GetCurrent
  *         Handles the GET_CUR Audio control request.
  * @param  pdev: instance
  * @param  req: setup class request
  * @retval status
  */
static void AUDIO_REQ_GetCurrent(USBD_HandleTypeDef *pdev, USBD_SetupReqTypedef *req)
{  
    USBD_AUDIO_HandleTypeDef *haudio;

    haudio = (USBD_AUDIO_HandleTypeDef*)pdev->pClassData;
    
    if ( (req->wValue >> 8) == AUDIO_CONTROL_MUTE)
    {
        memset(haudio->control.data, 0, 64);
        
        // Send the current mute state
        USBD_CtlSendData(pdev, 
                        haudio->control.data,
                        req->wLength);        
    }
    else
    {
        // Send the current volume
        USBD_CtlSendData(pdev, 
                        (uint8_t *)&g_nCurrentVolume,
                        sizeof(g_nCurrentVolume) );
    }
    
}   // End AUDIO_REQ_GetCurrent

/**
  * @brief  AUDIO_Req_SetCurrent
  *         Handles the SET_CUR Audio control request.
  * @param  pdev: instance
  * @param  req: setup class request
  * @retval status
  */
static void AUDIO_REQ_SetCurrent(USBD_HandleTypeDef *pdev, USBD_SetupReqTypedef *req)
{ 
    USBD_AUDIO_HandleTypeDef *haudio;

    haudio = (USBD_AUDIO_HandleTypeDef*)pdev->pClassData;

    if (req->wLength)
    {
        /* Prepare the reception of the buffer over EP0 */
        USBD_CtlPrepareRx(pdev,
                          haudio->control.data,                                  
                          req->wLength);    

        haudio->control.cmd = AUDIO_REQ_SET_CUR;     /* Set the request value */
        haudio->control.len = req->wLength;          /* Set the request data length */
        haudio->control.unit = HIBYTE(req->wIndex);  /* Set the request target unit */
    }

}   // End AUDIO_REQ_SetCurrent


/**
* @brief  DeviceQualifierDescriptor 
*         return Device Qualifier descriptor
* @param  length : pointer data length
* @retval pointer to descriptor buffer
*/
static uint8_t * USBD_AUDIO_GetDeviceQualifierDesc(uint16_t *length)
{
  *length = sizeof (USBD_AUDIO_DeviceQualifierDesc);
    
  return (uint8_t *)USBD_AUDIO_DeviceQualifierDesc;
}

/**
* @brief  USBD_AUDIO_RegisterInterface
* @param  fops: Audio interface callback
* @retval status
*/
uint8_t USBD_AUDIO_RegisterInterface(USBD_HandleTypeDef   *pdev, 
                                     USBD_AUDIO_ItfTypeDef *fops)
{
  if (fops != NULL)
  {
    pdev->pUserData= fops;
  }
  
  return 0;
  
}   // End USBD_AUDIO_RegisterInterface
