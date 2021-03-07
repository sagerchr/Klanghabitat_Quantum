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
#include "arm_math.h"
#include "arm_const_structs.h"
#include "stm32f7xx.h"
#include "ValueTableMotherEngine.h"
#include "lwip/tcp.h"

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
uint8_t upcounter;

uint8_t checksum;
uint16_t checksum16;
int OK = 0;

uint8_t IP_READ[4];

uint8_t pressed;

err_t err;

err_t
recv_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err){

	char recived[50];
	tcp_recved(tpcb, p->len);
	memcpy(recived, p -> payload, p -> len); //put the incoming udp data to UDP_RECIVE
	pbuf_free(p);
}

err_t
accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err){
	tcp_arg(newpcb,NULL);
	tcp_recv(newpcb, recv_callback);

	//Fire the Bootloader
	SharedParamsWriteByIndex(0, 1);
	BootActivate();
}





void lwIPTask(void const * argument){




for (int i=0; i<175;i++){
	DAC_Control(1,1,i); //SYM1 adjust
}
for (int i=0; i<176;i++){
	DAC_Control(2,1,i); //SYM2 adjust
}
for (int i=0; i<10;i++){
	DAC_Control(3,1,i); //SYM3 adjust
}
for (int i=0; i<10;i++){
	DAC_Control(4,1,i); //SYM4 adjust
}




		//==========CREATE & START all lwIP Services========//



	MY_FLASH_ReadN(0,IP_READ_FLASH,4,DATA_TYPE_8);
	 MX_LWIP_Init(IP_READ_FLASH[0], IP_READ_FLASH[1], IP_READ_FLASH[2], IP_READ_FLASH[3]); //SetUp with IP ADRESS read from Flash
	 httpd_init();//start the web Server
	 myCGIinit();//initialize the CGI handlers
	 mySSIinit();//initialize the SSI handlers

	  UartBridge_init();

	  //########create pcb for firmware  upgrade on port 1000#########//
	  static struct tcp_pcb *pcb;
	  err_t err;
	  pcb = tcp_new();
	  err = tcp_bind(pcb, IP_ADDR_ANY, 1000);
	  tcp_arg(pcb,NULL);
	  pcb = tcp_listen(pcb);
	  tcp_accept(pcb, accept_callback);
	  //###############################################################//


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
		IP_client_number[2] =  1;
		IP_client_number[3] =  atoi(IP4_client);

		if (match("/connection")){
			UDP_init(IP_client_number[0],IP_client_number[1],IP_client_number[2],IP_client_number[3]);

		}

		if (match("/Disconnection")){
			//UDP_deinit();

			UDP_init(192,168,1,1);

			 httpd_init();//start the web Server
			 myCGIinit();//initialize the CGI handlers
			 mySSIinit();//initialize the SSI handlers
		}

		//UDP_init(IP_client_number[0],IP_client_number[1],IP_client_number[2],IP_client_number[3]);


	}

	 err_t         udpErr;
	 ip_addr_t     ownIPaddr;
	 Broadcaster = udp_new();

	 if(Broadcaster != NULL)
	      {
	        IP4_ADDR(&ownIPaddr,  IP_READ_FLASH[0], IP_READ_FLASH[1], IP_READ_FLASH[2], IP_READ_FLASH[3]); //The IP Adress of the STM32
	        udpErr = udp_bind(Broadcaster, &ownIPaddr, 9011); //Definition of
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






//char FFT_String[12] = {'/','F','F','T','/','L','E','F','T','/','0','0'};
	  /* Infinite loop */
	  for(;;)
	  {



		  l++;
		  if (l == 0){
			  BroadcastDeviceInfo(l);

		  }
			  OSCmessageINTSend("/Watchdog",  9, l);
		  //OSCmessageStringSend("/klanghabitat", 13, "Device: Test; IP: 127.1.1.2",27);

		 //=========================================================================//
		 //=================CONTROL RELAIS VIA OSC MEASSAGE=========================//
		 /*
		 if (match("/MotherEngine/Relais/bypassLeft") && OSC_SIGNEDINTEGER ==  1){
			 BypassLeft(bypass);}
		 if (match("/MotherEngine/Relais/bypassLeft") && OSC_SIGNEDINTEGER == 0){
			 BypassLeft(activate);}

		 if (match("/MotherEngine/Relais/bypassRight") && OSC_SIGNEDINTEGER ==  1){
			 BypassRight(bypass);}
		 if (match("/MotherEngine/Relais/bypassRight") && OSC_SIGNEDINTEGER == 0){
			 BypassRight(activate);}
		 */

		if (UART_IN[10] && pressed <20){pressed++;}
		if (!UART_IN[10]){pressed = 0;}



		  if (pressed >=15){
			  BypassRight(bypass);BypassLeft(bypass);}
		  else{
			  BypassRight(activate);BypassLeft(activate);
		  }

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


		  //DAC_Control(1,2,UART_reciveCorrected[6]); //offset VCA1
		  //DAC_Control(2,2,UART_reciveCorrected[8]); //offset VCA2



		  //DAC_Control(1,1,UART_reciveCorrected[6]); //SYM1 adjust
		  //DAC_Control(2,1,UART_reciveCorrected[7]); //SYM2 adjust
		  //DAC_Control(3,1,UART_reciveCorrected[8]); //SYM3 adjust
		  //DAC_Control(4,1,UART_reciveCorrected[9]); //SYM4 adjust


		//OSCmessageINTSend("/VALUE/Level/CH1/RMS",  20, voltageRMS[0]*30);

		  OSCmessageINTSend("/VALUE/Level/CH1/RMS",  20, voltageIn1MAX*100);
		  OSCmessageINTSend("/VALUE/Level/CH2/RMS",  20, voltageIn2MAX*100);




//		OSCmessageINTSend("/help/Level/devider",  19, 146);


		  char data[sizeof(float)];
		  float f = -1.236;
		  char a = data[0];char b = data[1];char c = data[2];char d = data[3];

/*

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

		  char p = 48;
		  char k = 48;

*/
/*
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

*/

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

		if(DisplayUpdate == 0){
		HAL_UART_DMAPause(&huart6);
		}
//##########################################################//
		for (int i= 0; i<150;i++){
			UART_transmit[i] = 0x00;
		}

		upcounter++;



		  UART_transmit[0]='#';
		  UART_transmit[1]='s';
		  UART_transmit[2]='t';
		  UART_transmit[3]='a';
		  UART_transmit[4]=upcounter;//3

		  UART_transmit[5]=0x02;//2
		  UART_transmit[6]=voltageIn1MAX*100;//3
		  UART_transmit[7]=voltageIn2MAX*100;//4
		  UART_transmit[8]=voltageIn3MAX*100;//7
		  UART_transmit[9]=voltageIn4MAX*100;//7
		  UART_transmit[10]=voltageIn5MAX*100;//7
		  UART_transmit[11]=voltageIn6MAX*100;//8

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

		  memcpy(data, &dbuMAX[2], sizeof &dbuMAX[2]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[20]=d;
		  UART_transmit[21]=c;
		  UART_transmit[22]=b;
		  UART_transmit[23]=a;

		  memcpy(data, &dbuMAX[3], sizeof &dbuMAX[3]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[24]=d;
		  UART_transmit[25]=c;
		  UART_transmit[26]=b;
		  UART_transmit[27]=a;

		  memcpy(data, &dbuMAX[4], sizeof &dbuMAX[4]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[28]=d;
		  UART_transmit[29]=c;
		  UART_transmit[30]=b;
		  UART_transmit[32]=a;

		  memcpy(data, &dbuMAX[5], sizeof &dbuMAX[5]);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[32]=d;
		  UART_transmit[33]=c;
		  UART_transmit[34]=b;
		  UART_transmit[35]=a;

		  memcpy(data, &RMS_CH1_long, sizeof &RMS_CH1_long);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[36]=d;
		  UART_transmit[37]=c;
		  UART_transmit[38]=b;
		  UART_transmit[39]=a;

		  memcpy(data, &RMS_CH2_long, sizeof &RMS_CH2_long);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[40]=d;
		  UART_transmit[41]=c;
		  UART_transmit[42]=b;
		  UART_transmit[43]=a;

		  memcpy(data, &RMS_CH3_long, sizeof &RMS_CH3_long);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[44]=d;
		  UART_transmit[45]=c;
		  UART_transmit[46]=b;
		  UART_transmit[47]=a;

		  memcpy(data, &RMS_CH4_long, sizeof &RMS_CH4_long);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[48]=d;
		  UART_transmit[49]=c;
		  UART_transmit[50]=b;
		  UART_transmit[51]=a;

		  memcpy(data, &RMS_CH5_long, sizeof &RMS_CH5_long);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[52]=d;
		  UART_transmit[53]=c;
		  UART_transmit[54]=b;
		  UART_transmit[55]=a;

		  memcpy(data, &RMS_CH6_long, sizeof &RMS_CH6_long);    // send data
		  a = data[0]; b = data[1];c = data[2];d = data[3];
		  UART_transmit[56]=d;
		  UART_transmit[57]=c;
		  UART_transmit[58]=b;
		  UART_transmit[59]=a;


		  UART_transmit[60]=reductLeft;
		  UART_transmit[61]=reductRight;

/*
			for(int i = 4; i < 100; i++) {
				UART_transmit[i] = 0x00;
			  }
			//UART_transmit[4]=upcounter;
			//UART_transmit[98]=upcounter;

*/

		  UART_transmit[70]=DisplayReset;

		  char pcIpAddrString[60];
		  char pcBuffer[60];

		  for (int i=0; i<60; i++){
		  		pcBuffer[i] = 0;
		  		pcIpAddrString[i] = 0;
		  	}

		  sprintf(pcBuffer, "This is Value of Watchdog %d \r\n",  l);
		  printf(pcBuffer);

		  checksum = 0;
		  checksum16 = 0;
		for(int i = 0; i < 98; i++) {
				checksum += UART_transmit[i];
				checksum16 += UART_transmit[i];
			  }


		  UART_transmit[98]=checksum16 & 0x00FF; //low byte
		  UART_transmit[99]=checksum16 >> 8; //high byte

		  resetMax=1;


//############# RESMUE the DMA to output the data#########//
		  if(DisplayUpdate == 0){
		  HAL_UART_DMAResume(&huart6);
		  }
//#######################################################//
//Changed Define of MEM_USE_POOLS_TRY_BIGGER_POOL  to 1 (2020.05.20) Better Performance???
		  osDelay(10);


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
	  HAL_UART_Receive_DMA(&huart6, UART_RECIVE,RX_IN_SIZE);
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_ErrorCallback can be implemented in the user file.
   */
}
