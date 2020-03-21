#include "lwip.h"
#include "UDP_SEND_RECIVE.h"
#include "OSC_Lib.h"

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



//==================================INIT UDP Session===================================//
   void UDP_init(int IP1,int IP2,int IP3,int IP4){
     err_t         udpErr;
     ip_addr_t     ownIPaddr;
     udpPcb = udp_new();


     IP1_partner = IP1;
     IP2_partner = IP2;
	 IP3_partner = IP3;
	 IP4_partner = IP4;

     if(udpPcb != NULL)
     {
       IP4_ADDR(&ownIPaddr, 192, 168, 1, 205); //The IP Adress of the STM32
       udpErr = udp_bind(udpPcb, &ownIPaddr, 9001); //Definition of
       udp_recv(udpPcb, udp_recive, NULL);
       if (udpErr ==ERR_OK){
       }
     }
     udp_recv(udpPcb, udp_recive, NULL);//Create udp_recive callback
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
		 else if(size==34||size==30||size==26||size==22||size == 18||size == 16||size == 12||size == 8||size == 4){

			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 index=2;
		 }
		 else if(size==33||size==29||size==25||size==21||size == 17||size == 15||size == 11||size == 7||size == 3){
			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 UDP_Message[size+2] = 0x00;
			 index=3;
		 }
		 else if(size==32||size==28||size==24||size==20||size == 16||size == 14||size == 10||size == 6||size == 2){
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
		 else if(size==34||size==30||size==26||size==22||size == 18||size == 16||size == 12||size == 8||size == 4){

			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 index=2;
		 }
		 else if(size==33||size==29||size==25||size==21||size == 17||size == 15||size == 11||size == 7||size == 3){
			 UDP_Message[size] = 0x00;
			 UDP_Message[size+1] = 0x00;
			 UDP_Message[size+2] = 0x00;
			 index=3;
		 }
		 else if(size==32||size==28||size==24||size==20||size == 16||size == 14||size == 10||size == 6||size == 2){
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
