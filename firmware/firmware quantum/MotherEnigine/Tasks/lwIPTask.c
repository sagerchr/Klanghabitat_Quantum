/*
 * lwIPTask.c
 *
 *  Created on: 08.11.2019
 *      Author: christiansager
 */

#include "main.h"
#include "lwip/apps/httpd.h"
#include "lwip.h"
#include <string.h>
#include "UDP_SEND_RECIVE.h"
#include "webserver.h"
#include "MY_FLASH.h"
#include "RelaisControl.h"
#include "OSC_Lib.h"
#include "UART_correction.h"


DAC_HandleTypeDef hdac;
UART_HandleTypeDef huart6;
static struct udp_pcb *Broadcaster;
uint8_t errors= 0;
char Serial_READ[4] = {5,9,7,'S'};
uint8_t l = 0;
int stringlength;

osc_message osc;

uint8_t IP_Client[4];
char IP1_client[3];
char IP2_client[3];
char IP3_client[3];
char IP4_client[3];

uint8_t IP_client_number[4];


void lwIPTask(void const * argument){
/*
	MY_FLASH_SetSectorAddrs(11, 0x081C0000);
	MY_FLASH_ReadN(0,IP_READ,4,DATA_TYPE_8);
*/
	//==========CREATE & START all lwIP Services========//
	 MX_LWIP_Init(IP_READ_FLASH[0], IP_READ_FLASH[1], IP_READ_FLASH[2], IP_READ_FLASH[3]); //SetUp with IP ADRESS read from Flash
	//UDP_init(192,168,1,43); //INIT the UDP Session (Partner IP ADRESS)
	 httpd_init();//start the web Server
	 myCGIinit();//initialize the CGI handlers
	 mySSIinit();//initialize the SSI handlers
	//============================================================================================================//







	//============================================================================================================//
	// In this section the management of client is done.
	//
	// #1: The device is currently broadcasting its IP and Serial Number on Port 9010
	// #2: If a client wants to connect he has to send its IP Address + some more info
	// #3: A new socket will be created via UDP_init
	// #4: running the server application normally
	//
	// #5:
	// #6:
	//

	//============================================================================================================//


	 void ConnectionWhish(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)

	{
		char IP_Adress_Client[16];
		for (int i=0; i<50; i++){OSC_PATH[i] = 0x00;} //clear the OSC_PATH
		HAL_GPIO_TogglePin(GPIOB, LD2_Pin); //Blaue LED an
		memcpy(UDP_RECIVE, p -> payload, p -> len); //put the incoming udp data to UDP_RECIVE
		pbuf_free(p);//clear the udp buffer in the lwIP
		tosc_parseMessage(&osc, p -> payload, p -> len);//Find .adressEND & .format
		OSC_FORMAT = *osc.format; //Find out the format of data
		uint8_t AdressEND = osc.adressEND;//safe the AdressEND to vraiable
		memcpy(OSC_PATH, p -> payload, AdressEND); //Put the Payload until AdressEND as the OSC_PATH
		uint8_t numberSTART = osc.numberSTART; //Find out where the starting of 4 byte number is


		if(OSC_FORMAT=='s'){
			for (int i=0;i<16;i++){
				IP_Adress_Client[i] = UDP_RECIVE[numberSTART+i];
			}

			int i = 0;
			int index = 0;

			while (IP_Adress_Client[i]!= '.'){
				IP1_client[i-index] = IP_Adress_Client[i];
				i++;
			}
			i++;
			index = i;

			while (IP_Adress_Client[i]!= '.'){
				IP2_client[i-index] = IP_Adress_Client[i];
				i++;
			}
			i++;
			index = i;

//============================================================================//
			while (IP_Adress_Client[i]!= '.'){
				IP3_client[i-index] = IP_Adress_Client[i];
				i++;
			}
			if (i-index == 2){
				for (int i=2; i>0;i--){
					IP3_client[i] = IP3_client [i-1];
				}
				IP3_client[0] = '0';
			}
			if (i-index == 1){
				for (int i=2; i>0;i--){
					IP3_client[i] = IP3_client [i-2];
				}
				IP3_client[0] = '0';
				IP3_client[1] = '0';
			}
			i++;
			index = i;
//============================================================================//
			while (IP_Adress_Client[i]!= 0x00){
				IP4_client[i-index] = IP_Adress_Client[i];
				i++;
			}
			if (i-index == 2){
				for (int i=2; i>0;i--){
					IP4_client[i] = IP4_client [i-1];
				}
				IP4_client[0] = '0';
			}
			if (i-index == 1){
				for (int i=2; i>0;i--){
					IP4_client[i] = IP4_client [i-2];
				}
				IP4_client[0] = '0';
				IP4_client[1] = '0';
			}

//============================================================================//



		}

		IP_client_number[0] =  atoi(IP1_client);
		IP_client_number[1] =  atoi(IP2_client);
		IP_client_number[2] =  atoi(IP3_client);
		IP_client_number[3] =  atoi(IP4_client);



		UDP_init(IP_client_number[0],IP_client_number[1],IP_client_number[2],IP_client_number[3]);


	}

	 err_t         udpErr;
	 ip_addr_t     ownIPaddr;
	 Broadcaster = udp_new();

	 if(Broadcaster != NULL)
	      {
	        IP4_ADDR(&ownIPaddr,  IP_READ_FLASH[0], IP_READ_FLASH[1], IP_READ_FLASH[2], IP_READ_FLASH[3]); //The IP Adress of the STM32
	        udpErr = udp_bind(Broadcaster, &ownIPaddr, 9010); //Definition of
	        udp_recv(Broadcaster, ConnectionWhish, NULL);//Create udp_recive callback
	        if (udpErr ==ERR_OK){
	        }
	      }


	//============================================================================================================//
	void BroadcastDeviceInfo(uint8_t status)

	{

	ip_addr_t       client1IpAddr; //The Clients IP Address
	struct pbuf     *ethTxBuffer_p;


	stringlength = OSCmessageDeviceInfo("/klanghabitat/DeviceInfo", 24, "Device: Quantum; Version: 1.0; status: ready",44, (char)IP_READ_FLASH[0],(char)IP_READ_FLASH[1],(char)IP_READ_FLASH[2],(char)IP_READ_FLASH[3]); //Will be found as "DeviceInfo"


	char DeviceInfoToSend[stringlength];
	for(int i=0; i<stringlength; i++){
		DeviceInfoToSend[i]=DeviceInfo[i];
	}

	IP4_ADDR(&client1IpAddr,  IP_READ_FLASH[0], IP_READ_FLASH[1], IP_READ_FLASH[2], 255); //make Broadcast xxx.xxx.xxx.255

	ethTxBuffer_p = pbuf_alloc(PBUF_TRANSPORT, sizeof(DeviceInfoToSend), PBUF_RAM); //TX BUFFER TO SOMETHING WE CAN SEND
	if (ethTxBuffer_p == NULL){}
	memcpy(ethTxBuffer_p->payload, DeviceInfoToSend, sizeof(DeviceInfoToSend));
	//memcpy(ethTxBuffer_p->payload, UDP, sizeof(UDP));
	udp_sendto(Broadcaster, ethTxBuffer_p, &client1IpAddr,9010);  //SEND UDP TO PORT 9002
	pbuf_free(ethTxBuffer_p);  //Free the TX Buffer

	}

	//============================================================================================================//







char UART_IN[10];
//char FFT_String[12] = {'/','F','F','T','/','L','E','F','T','/','0','0'};
	  /* Infinite loop */
	  for(;;)
	  {

		  l++;
		  if (l == 0){BroadcastDeviceInfo(l);}

		  //OSCmessageStringSend("/klanghabitat", 13, "Device: Test; IP: 127.1.1.2",27);

		 //=========================================================================//
		 //=================CONTROL RELAIS VIA OSC MEASSAGE=========================//
		 if (match("/MotherEngine/Relais/bypassLeft") && OSC_SIGNEDINTEGER ==  1){
			 BypassLeft(bypass);}
		 if (match("/MotherEngine/Relais/bypassLeft") && OSC_SIGNEDINTEGER == 0){
			 BypassLeft(activate);}

		 if (match("/MotherEngine/Relais/bypassRight") && OSC_SIGNEDINTEGER ==  1){
			 BypassRight(bypass);}
		 if (match("/MotherEngine/Relais/bypassRight") && OSC_SIGNEDINTEGER == 0){
			 BypassRight(activate);}

		 if (match("/MotherEngine/Relais/K5") && OSC_SIGNEDINTEGER == 1){
			 HAL_GPIO_WritePin(GPIOG, Relais3_Pin,GPIO_PIN_SET);}
		 if (match("/MotherEngine/Relais/K5") && OSC_SIGNEDINTEGER == 0){
			 HAL_GPIO_WritePin(GPIOG, Relais3_Pin,GPIO_PIN_RESET);}

		 if (match("/MotherEngine/Relais/K6") && OSC_SIGNEDINTEGER == 1){
			 HAL_GPIO_WritePin(GPIOG, Relais4_Pin,GPIO_PIN_SET);}
		 if (match("/MotherEngine/Relais/K6") && OSC_SIGNEDINTEGER == 0){
			 HAL_GPIO_WritePin(GPIOG, Relais4_Pin,GPIO_PIN_RESET);}

		 if (match("/MotherEngine/Relais/K7") && OSC_SIGNEDINTEGER == 1){
			 HAL_GPIO_WritePin(GPIOG, Relais5_Pin,GPIO_PIN_SET);}
		 if (match("/MotherEngine/Relais/K7") && OSC_SIGNEDINTEGER == 0){
			 HAL_GPIO_WritePin(GPIOG, Relais5_Pin,GPIO_PIN_RESET);}

		 if (match("/MotherEngine/Relais/K8") && OSC_SIGNEDINTEGER == 1){
			 HAL_GPIO_WritePin(GPIOG, Relais6_Pin,GPIO_PIN_SET);}
		 if (match("/MotherEngine/Relais/K8") && OSC_SIGNEDINTEGER == 0){
			 HAL_GPIO_WritePin(GPIOG, Relais6_Pin,GPIO_PIN_RESET);}
		 //=========================================================================//




		 DAC_Control(3,2,UART_reciveCorrected[6]);
		 DAC_Control(4,2,UART_reciveCorrected[8]);




		OSCmessageINTSend("/VALUE/Level/CH1/RMS",  20, voltageRMS[0]*30);
		OSCmessageINTSend("/VALUE/Level/CH2/RMS",  20, voltageRMS[1]*30);



		OSCmessageINTSend("/help/Level/devider",  19, 146);


		  char data[sizeof(float)];
		  float f = -1.236;
		  char a = data[0];char b = data[1];char c = data[2];char d = data[3];



		  memcpy(data, &dbuRMS[1], sizeof &dbuRMS[0]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  OSCmessageFLOATSend("/VALUE/Level/CH2/FLOAT",  22, a,b,c,d);

		  memcpy(data, &dbuRMS[2], sizeof &dbuRMS[0]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  OSCmessageFLOATSend("/VALUE/Level/CH3/FLOAT",  22, a,b,c,d);

		  memcpy(data, &dbuRMS[3], sizeof &dbuRMS[0]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  OSCmessageFLOATSend("/VALUE/Level/CH4/FLOAT",  22, a,b,c,d);

		  memcpy(data, &dbuRMS[4], sizeof &dbuRMS[0]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  OSCmessageFLOATSend("/VALUE/Level/CH5/FLOAT",  22, a,b,c,d);

		  memcpy(data, &dbuRMS[5], sizeof &dbuRMS[0]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  OSCmessageFLOATSend("/VALUE/Level/CH6/FLOAT",  22, a,b,c,d);

		float offset = -124.0;

		  memcpy(data, &offset, sizeof &dbuRMS[0]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  OSCmessageFLOATSend("/help/Level/offset",  18, a,b,c,d);

		  memcpy(data, &dbuRMS[0], sizeof &dbuRMS[0]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  OSCmessageFLOATSend("/VALUE/Level/CH1/FLOAT",  22, a,b,c,d);

/*****************************************************************************/
		  char p = 48;
		  char k = 48;

		  char FFT_String[12] = {'/','F','F','T','/','L','E','F','T','/','0','0'};

		  for (int i=0; i<50; i++){
			  memcpy(data, &FFT_result[i], sizeof &FFT_result[i]);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  FFT_String[11] = p;
			  OSCmessageFLOATSend(FFT_String, 12, a,b,c,d);
			  p = (char)p+1;
			  if(p == 58){
				  p=48;
				  k = (char)k+1;
				  FFT_String[10] = k;
			  }

		  }



/*****************************************************************************/


		OSCmessageINTSend("/VALUE/ERROR/ER1____",  20, errors);



//*************************SEND DATA TO FRONTPANEL************************//

//#################!!!!!!!!!!!!ATTENTION!!!!!!!!!!!!#################//

//				DMA Pause -> Write Data -> DMA Resume
// This is done because we want to write data without transferring data
// 	This is just possible because in stm32f7xx_hal_uart.c the UART_RX was disabled
// otherwise DMA for RX would also be stopping.

//

//#############PAUSE the DMA to be able to write data#######//
		HAL_UART_DMAPause(&huart6);
//##########################################################//
		for (int i= 0; i<150;i++){
			UART_transmit[i] = 0x00;
		}



		  UART_transmit[0]='#';
		  UART_transmit[1]='s';
		  UART_transmit[2]='t';
		  UART_transmit[3]='a';
		  UART_transmit[4]=0x01;//1
		  UART_transmit[5]=0x02;//2
		  UART_transmit[6]=voltageIn1MAX*30;//3
		  UART_transmit[7]=voltageIn2MAX*30;//4
		  UART_transmit[8]=0x10;//5
		  UART_transmit[9]=0x10;//6
		  UART_transmit[10]=voltageIn5MAX*30;//7
		  UART_transmit[11]=voltageIn6MAX*30;//8
		  memcpy(data, &dbuMAX[0], sizeof &dbuMAX[0]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[12]=d;
		  UART_transmit[13]=c;
		  UART_transmit[14]=b;
		  UART_transmit[15]=a;
		  memcpy(data, &dbuMAX[1], sizeof &dbuMAX[1]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[16]=d;
		  UART_transmit[17]=c;
		  UART_transmit[18]=b;
		  UART_transmit[19]=a;

		  for(int i=100; i<150; i++){

			  UART_transmit[i-50]= FFT_result[i-100]/2;
			  UART_transmit[i]= FFT_result2[i-100]/2;
		  }

		  resetMax=1;
//############# RESMUE the DMA to output the data#########//
		  HAL_UART_DMAResume(&huart6);
//#######################################################//

		   HAL_Delay(5);
//***********************************************************************//
	  }


}

int match(char *matchString){
	int i=0;
	int OK=0;
	while(OSC_PATH[i]!='\0'){
		i++;
			if(OSC_PATH[i] == matchString[i]){
				OK = 1;
			}
			else{
				OK = 0;
				break;
			}
	}
	if (OK == 1) return 1;
	else if (OK == 0) return 0;
}




void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	errors = errors+1;

  /* Prevent unused argument(s) compilation warning */
	  HAL_UART_Receive_DMA(&huart6, UART_recive,150);
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_ErrorCallback can be implemented in the user file.
   */
}
