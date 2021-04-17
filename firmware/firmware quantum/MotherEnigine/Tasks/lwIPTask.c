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
#include <stdio.h>  /* needed for printf */
#include <string.h> /* needed for strcmp */
#include "createStreamValues.h"

#include "MessageHandler.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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


int TYP, lock;


int result = 12;
uint8_t toggle=0;

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


	int CASE = 0;


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


	InitMeassageHandler();

	pushToMessageQueue("TESTING#1\r\n");
	pushToMessageQueue("TESTING#2\r\n");
	pushToMessageQueue("TESTING#3\r\n");
	pushToMessageQueue("TESTING#4\r\n");
	pushToMessageQueue("TESTING#5\r\n");
	pushToMessageQueue("TESTING#6\r\n");
	pushToMessageQueue("TESTING#7\r\n");
	pushToMessageQueue("TESTING#8\r\n");
	pushToMessageQueue("TESTING#9\r\n");
	pushToMessageQueue("TESTING#10\r\n");
	pushToMessageQueue("TESTING#11\r\n");
	pushToMessageQueue("TESTING#12\r\n");
	pushToMessageQueue("TESTING#13\r\n");
	pushToMessageQueue("TESTING#14\r\n");
	pushToMessageQueue("TESTING#15\r\n");
	pushToMessageQueue("TESTING#16\r\n");
	pushToMessageQueue("TESTING#17\r\n");
	pushToMessageQueue("TESTING#18\r\n");
	pushToMessageQueue("TESTING#19\r\n");
	pushToMessageQueue("TESTING#20\r\n");
	pushToMessageQueue("TESTING#21\r\n");
	pushToMessageQueue("TESTING#22\r\n");
	pushToMessageQueue("TESTING#23\r\n");
	pushToMessageQueue("TESTING#24\r\n");
	pushToMessageQueue("TESTING#25\r\n");
	pushToMessageQueue("TESTING#26\r\n");
	pushToMessageQueue("TESTING#27\r\n");
	pushToMessageQueue("TESTING#28\r\n");
	pushToMessageQueue("TESTING#29\r\n");
	popFromMessageQueue();



	  /* Infinite loop */
	  for(;;)
	  {



		  l++;
		  if (l == 0){
			  BroadcastDeviceInfo(l);

		  }
			  OSCmessageINTSend("/Watchdog",  9, l);

		  if(UARTDATA_CHECKED[10]){
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

		  OSCmessageINTSend("/VALUE/Level/CH1/RMS",  20, voltageIn1MAX*100);
		  OSCmessageINTSend("/VALUE/Level/CH2/RMS",  20, voltageIn2MAX*100);



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
		for (int i= 0; i<100;i++){
			UART_TRANSFER[i] = 0x00;
		}

		upcounter++;

		createStreamValue(upcounter); //composing the StreamValue Section of UART_transmit


		  UART_TRANSFER[70]=DisplayReset; //Value responsible for resetting the display
//#######################################################//
//################    TEST CODE    ######################//
//#######################################################//
		  toggle++;
/*
		  if(toggle==0||toggle==10||toggle==20||toggle==30||toggle==40||toggle==50||toggle==60||toggle==70||toggle==80||toggle==90
		 ||toggle==100||toggle==110||toggle==120||toggle==130||toggle==140||toggle==150||toggle==160||toggle==170
		 ||toggle==180||toggle==190||toggle==200||toggle==210||toggle==220||toggle==230||toggle==240||toggle==250){
			*/

			  if(toggle==0||toggle==2||toggle==3||toggle==4||toggle==8
			 ||toggle==10||toggle==12||toggle==15||toggle==20
			 ||toggle==25||toggle==26||toggle==30||toggle==35
			 ||toggle==40||toggle==45||toggle==50||toggle==60
			 ||toggle==65||toggle==70||toggle==75||toggle==80){
			  	switch (CASE){

				case 1:
				pushToMessageQueue("TESTING#1\r\n");
				break;
				case 2:
				pushToMessageQueue("TESTING#2\r\n");
				break;
				case 3:
				pushToMessageQueue("TESTING#3\r\n");
				break;
				case 4:
				pushToMessageQueue("TESTING#4\r\n");
				break;
				case 5:
				pushToMessageQueue("TESTING#5\r\n");
				break;
				case 6:
				pushToMessageQueue("TESTING#6\r\n");
				break;
				case 7:
				pushToMessageQueue("TESTING#7\r\n");
				break;
				case 8:
				pushToMessageQueue("TESTING#8\r\n");
				break;
				case 9:
				pushToMessageQueue("TESTING#9\r\n");
				break;
				default:
				pushToMessageQueue("NONSENS\r\n");
			  	}

			  CASE ++;
			  if(CASE >= 20){
				  CASE=0;
			  }

		  }


		  popFromMessageQueue();


		   char *str1 = "hello\r\n";
		   char *str2 = "hello\r\n";

		   result = compare (str1, "hello\r\n");
//#######################################################//

//#######################################################//
//################CHECKSUM CREATION######################//
//#######################################################//
		  checksum = 0;
		  checksum16 = 0;
		for(int i = 0; i < 198; i++) {
				checksum += UART_TRANSFER[i];
				checksum16 += UART_TRANSFER[i];
			  }

		  UART_TRANSFER[198]=checksum16 & 0x00FF; //low byte
		  UART_TRANSFER[199]=checksum16 >> 8; //high byte
//#######################################################//

		  resetMax=1;


//############# RESMUE the DMA to output the data#########//
		  if(DisplayUpdate == 0){
		  HAL_UART_DMAResume(&huart6);
		  }
//#######################################################//
//Changed Define of MEM_USE_POOLS_TRY_BIGGER_POOL  to 1 (2020.05.20) Better Performance???
		  //osDelay(10);
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











