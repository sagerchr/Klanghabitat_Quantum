#include "lwip.h"
#include "UDP_SEND_RECIVE.h"
#include "OSC_Lib.h"
#include "main.h"

int IP1_partner;
int IP2_partner;
int IP3_partner;
int IP4_partner;




static struct udp_pcb *udpPcb;
osc_message osc;


//==============RECIVE UDP MESSAGE --> OUTPUT PARSED OSC MEASSAGE=========================//
	void udp_recive(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
	{
		for (int i=0; i<50; i++){OSC_PATH[i] = 0x00;} //clear the OSC_PATH
		HAL_GPIO_TogglePin(GPIOB, LD2_Pin); //Blaue LED an
		memcpy(UDP_RECIVE, p -> payload, p -> len); //put the incoming udp data to UDP_RECIVE
		pbuf_free(p);//clear the udp buffer in the lwIP
		tosc_parseMessage(&osc, p -> payload, p -> len);//Find .adressEND & .format
		OSC_FORMAT = *osc.format; //Find out the format of data
		uint8_t AdressEND = osc.adressEND;//safe the AdressEND to vraiable
		memcpy(OSC_PATH, p -> payload, AdressEND); //Put the Payload until AdressEND as the OSC_PATH
		uint8_t numberSTART = osc.numberSTART; //Find out where the starting of 4 byte number is

		/*****Put the number as a SignedInteger because the Format is 'i'****/
		if(OSC_FORMAT=='i'){
			OSC_SIGNEDINTEGER = UDP_RECIVE[numberSTART+3]	|
					(UDP_RECIVE[numberSTART+2] << 8) 		|
					(UDP_RECIVE[numberSTART+1] << 16) 	  	|
					(UDP_RECIVE[numberSTART] << 24);
		}
		/*********Put the number as a Float because the Format is 'f'*******************/
		else if(OSC_FORMAT=='f'){
			int32_t INT = UDP_RECIVE[numberSTART+3] 	|
					(UDP_RECIVE[numberSTART+2] << 8) 	|
					(UDP_RECIVE[numberSTART+1] << 16) 	|
					(UDP_RECIVE[numberSTART] << 24);

			memcpy(&OSC_FLOAT, &INT, sizeof(OSC_FLOAT));
		}
		/*******************************************************************************/

	}
//=======================================================================================//

	void UDP_deinit(){

	     if(udpPcb != NULL){
	     	udp_remove(&udpPcb);
	    }
	}



//==================================INIT UDP Session===================================//
   void UDP_init(int IP1,int IP2,int IP3,int IP4){
     err_t         udpErr;
     ip_addr_t     ownIPaddr;
     udpPcb = udp_remove();
     udpPcb = udp_new();


     IP1_partner = IP1;
     IP2_partner = IP2;
	 IP3_partner = IP3;
	 IP4_partner = IP4;

     if(udpPcb != NULL)
     {
       IP4_ADDR(&ownIPaddr, IP_READ_FLASH[0], IP_READ_FLASH[1], IP_READ_FLASH[2], IP_READ_FLASH[3]); //The IP Adress of the STM32
       udpErr = udp_bind(udpPcb, &ownIPaddr, 9001); //Definition of
       udp_recv(udpPcb, udp_recive, NULL);
       if (udpErr ==ERR_OK){
    	   HAL_Delay(1);
       }
     }
     //udp_recv(udpPcb, udp_recive, NULL);//Create udp_recive callback
   }
//=======================================================================================//




//==================================SENDING UDP MESSAGE===================================//
  void SendUDP(char *UDP_Message, int size ){

	ip_addr_t       client1IpAddr; //The Clients IP Adress
	struct pbuf     *ethTxBuffer_p;

	//IP4_ADDR(&client1IpAddr, 192, 168, 1, 36); //IP Adress to send UDP
	IP4_ADDR(&client1IpAddr, IP1_partner, IP2_partner, IP3_partner, IP4_partner); //IP Adress to send UDP
	char UDP[size];
	for (int i=0;i<size;i++){
		UDP[i] = UDP_Message[i];
	}


	ethTxBuffer_p = pbuf_alloc(PBUF_TRANSPORT, size, PBUF_RAM); //TX BUFFER TO SOMETHING WE CAN SEND
	if (ethTxBuffer_p == NULL){}

	memcpy(ethTxBuffer_p->payload, UDP, size);

	udp_sendto(udpPcb, ethTxBuffer_p, &client1IpAddr,9002);  //SEND UDP TO PORT 9002

	pbuf_free(ethTxBuffer_p);  //Free the TX Buffer
  }
//=======================================================================================//

  void OSCmessageFLOATSend(char *OSCAdress,int size, int a, int b, int c, int d){

		 int index=0;
		 char UDP_Message[100];

		 for(int i=0; i< 100; i++){
			 UDP_Message[i] = 0x01;
		 }


		 for(int i=0; i< size; i++){
			 UDP_Message[i] = OSCAdress[i];
		 }

		 if(size==35||size==31||size==27||size==23||size == 19||size == 15||size == 11||size == 7||size == 3){
			 UDP_Message[size] = 0x00;
			 index=1;
		 }
		 else if(size==34||size==30||size==26||size==22||size == 18||size == 14||size == 10||size == 6||size == 2){

			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 index=2;
		 }
		 else if(size==33||size==29||size==25||size==21||size == 17||size == 13||size == 9||size == 5||size == 1){
			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 UDP_Message[size+2] = 0x00;
			 index=3;
		 }
		 else if(size==32||size==28||size==24||size==20||size == 16||size == 12||size == 8||size == 4||size == 0){
			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 UDP_Message[size+2] = 0x00;
			 UDP_Message[size+3] = 0x00;
			 index=4;
		 }

		 UDP_Message[size+index] = ',';
		 UDP_Message[size+index+1] = 'f';
		 UDP_Message[size+index+2] = 0x00;
		 UDP_Message[size+index+3] = 0x00;
		 UDP_Message[size+index+4] = d;
		 UDP_Message[size+index+5] = c;
		 UDP_Message[size+index+6] = b;
		 UDP_Message[size+index+7] = a;

		 char UDP_SEND[size+index+8];

		 for(int i=0; i< size+index+8; i++){
			 UDP_SEND[i] = UDP_Message[i];
		 }

		 SendUDP(UDP_SEND, sizeof(UDP_SEND));
	 }







void OSCmessageINTSend(char *OSCAdress,int size, int value){

		 int index=0;
		 char UDP_Message[100];

		 for(int i=0; i< 100; i++){
			 UDP_Message[i] = 0x01;
		 }


		 for(int i=0; i< size; i++){
			 UDP_Message[i] = OSCAdress[i];
		 }

		 if(size==35||size==31||size==27||size==23||size == 19||size == 15||size == 11||size == 7||size == 3){
			 UDP_Message[size] = 0x00;
			 index=1;
		 }
		 else if(size==34||size==30||size==26||size==22||size == 18||size == 14||size == 10||size == 6||size == 2){

			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 index=2;
		 }
		 else if(size==33||size==29||size==25||size==21||size == 17||size == 13||size == 9||size == 5||size == 1){
			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 UDP_Message[size+2] = 0x00;
			 index=3;
		 }
		 else if(size==32||size==28||size==24||size==20||size == 16||size == 12||size == 8||size == 4||size == 0){
			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 UDP_Message[size+2] = 0x00;
			 UDP_Message[size+3] = 0x00;
			 index=4;
		 }

		 UDP_Message[size+index] = ',';
		 UDP_Message[size+index+1] = 'i';
		 UDP_Message[size+index+2] = 0x00;
		 UDP_Message[size+index+3] = 0x00;
		 UDP_Message[size+index+4] = 0x00;
		 UDP_Message[size+index+5] = 0x00;
		 UDP_Message[size+index+6] = 0x00;
		 UDP_Message[size+index+7] = value;

		 char UDP_SEND[size+index+8];

		 for(int i=0; i< size+index+8; i++){
			 UDP_SEND[i] = UDP_Message[i];
		 }

		 SendUDP(UDP_SEND, sizeof(UDP_SEND));
	 }


int OSCmessageDeviceInfo(char *OSCAdress,int size, char *Message, int sizeMessage, char IP1, char IP2, char IP3, char IP4){

		 int index=0;
		 int endMessage=0;
		 char UDP_Message[100];

		 for(int i=0; i< 100; i++){
			 UDP_Message[i] = 0x01;
		 }


		 for(int i=0; i< size; i++){
			 UDP_Message[i] = OSCAdress[i];
		 }



		 if(size==47||size==43||size==39||size==35||size==31||size==27||size==23||size == 19||size == 15||size == 11||size == 7||size == 3){
			 UDP_Message[size] = 0x00;
			 index=1;
		 }
		 else if(size==46||size==42||size==38||size==34||size==30||size==26||size==22||size == 18||size == 14||size == 10||size == 6||size == 2){

			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 index=2;
		 }
		 else if(size==45||size==41||size==37||size==33||size==29||size==25||size==21||size == 17||size == 13||size == 9||size == 5||size == 1){
			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 UDP_Message[size+2] = 0x00;
			 index=3;
		 }
		 else if(size==44||size==40||size==36||size==32||size==28||size==24||size==20||size == 16||size == 12||size == 8||size == 4||size == 0){
			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 UDP_Message[size+2] = 0x00;
			 UDP_Message[size+3] = 0x00;
			 index=4;
		 }

		 UDP_Message[size+index] = ',';
		 UDP_Message[size+index+1] = 's';

		 UDP_Message[size+index+2] = 0x00;
		 UDP_Message[size+index+3] = 0x00;





		 char str[3];
 //________________________________________________________________________________________________________________//
		 sprintf(str, "%d", IP1);
		 if (IP1<10){
			 UDP_Message[size+index+4] = '0';
			 UDP_Message[size+index+5] = '0';
			 UDP_Message[size+index+6] = str[0];
			 }
		 else if (IP1<100 && IP1>=10){
			 UDP_Message[size+index+4] = '0';
			 UDP_Message[size+index+5] = str[0];
			 UDP_Message[size+index+6] = str[1];
			 }
		 else if (IP1>=100){
			 UDP_Message[size+index+4] = str[0];
			 UDP_Message[size+index+5] = str[1];
			 UDP_Message[size+index+6] = str[2];
			 }
		 UDP_Message[size+index+7] = '.';
//________________________________________________________________________________________________________________//
		 sprintf(str, "%d", IP2);
		 if (IP2<10){
			 UDP_Message[size+index+8] = '0';
			 UDP_Message[size+index+9] = '0';
			 UDP_Message[size+index+10] = str[0];
			 }
		 else if (IP2<100 && IP2>=10){
			 UDP_Message[size+index+8] = '0';
			 UDP_Message[size+index+9] = str[0];
			 UDP_Message[size+index+10] = str[1];
			 }
		 else if (IP2>=100){
			 UDP_Message[size+index+8] = str[0];
			 UDP_Message[size+index+9] = str[1];
			 UDP_Message[size+index+10] = str[2];
			 }
		 UDP_Message[size+index+11] = '.';
//________________________________________________________________________________________________________________//
		 sprintf(str, "%d", IP3);
		 if (IP3<10){
			 UDP_Message[size+index+12] = '0';
			 UDP_Message[size+index+13] = '0';
			 UDP_Message[size+index+14] = str[0];
			 }
		 else if (IP3<100 && IP3>=10){
			 UDP_Message[size+index+12] = '0';
			 UDP_Message[size+index+13] = str[0];
			 UDP_Message[size+index+14] = str[1];
			 }
		 else if (IP3>=100){
			 UDP_Message[size+index+12] = str[0];
			 UDP_Message[size+index+13] = str[1];
			 UDP_Message[size+index+14] = str[2];
			 }
		 UDP_Message[size+index+15] = '.';
//________________________________________________________________________________________________________________//
		 sprintf(str, "%d", IP4);
		 if (IP4<10){
			 UDP_Message[size+index+16] = '0';
			 UDP_Message[size+index+17] = '0';
			 UDP_Message[size+index+18] = str[0];
			 }
		 else if (IP4<100 && IP4>=10){
			 UDP_Message[size+index+16] = '0';
			 UDP_Message[size+index+17] = str[0];
			 UDP_Message[size+index+18] = str[1];
			 }
		 else if (IP4>=100){
			 UDP_Message[size+index+16] = str[0];
			 UDP_Message[size+index+17] = str[1];
			 UDP_Message[size+index+18] = str[2];
			 }
		 UDP_Message[size+index+19] = ';';
//________________________________________________________________________________________________________________//





		 for(int i=0; i<sizeMessage; i++){
			 UDP_Message[size+index+20+i] = Message[i];
			 endMessage=size+index+20+i;
		 }




		 if(sizeMessage==47||sizeMessage==43||sizeMessage==39||sizeMessage==35||sizeMessage==31||sizeMessage==27||sizeMessage==23||sizeMessage == 19||sizeMessage == 15||sizeMessage == 11||sizeMessage == 7||sizeMessage == 3){
			 UDP_Message[endMessage+1] = 0x00;
			 index=1;
		 }
		 else if(sizeMessage==46||sizeMessage==42||sizeMessage==38||sizeMessage==34||sizeMessage==30||sizeMessage==26||sizeMessage==22||sizeMessage == 18||sizeMessage == 14||sizeMessage == 10||sizeMessage == 6||sizeMessage == 2){

			 UDP_Message[endMessage+1] = 0x00;
			 UDP_Message[endMessage+2] = 0x00;
			 index=2;
		 }
		 else if(sizeMessage==45||sizeMessage==41||sizeMessage==37||sizeMessage==33||sizeMessage==29||sizeMessage==25||sizeMessage==21||sizeMessage == 17||sizeMessage == 13||sizeMessage == 9||sizeMessage == 5||sizeMessage == 1){
			 UDP_Message[endMessage+1] = 0x00;
			 UDP_Message[endMessage+2] = 0x00;
			 UDP_Message[endMessage+3] = 0x00;
			 index=3;
		 }
		 else if(sizeMessage==44||sizeMessage==40||sizeMessage==36||sizeMessage==32||sizeMessage==28||sizeMessage==24||sizeMessage==20||sizeMessage == 16||sizeMessage == 12||sizeMessage == 8||sizeMessage == 4||sizeMessage == 0){
			 UDP_Message[endMessage+1] = 0x00;
			 UDP_Message[endMessage+2] = 0x00;
			 UDP_Message[endMessage+3] = 0x00;
			 UDP_Message[endMessage+4] = 0x00;
			 index=4;
		 }



		 char UDP_SEND[endMessage+index+1];

		 for(int i=0; i< endMessage+index+1; i++){
			 UDP_SEND[i] = UDP_Message[i];
			 DeviceInfo[i] = UDP_Message[i];
		 }




return endMessage+index+1;

		 //SendUDP(UDP_SEND, sizeof(UDP_SEND));
	 }

