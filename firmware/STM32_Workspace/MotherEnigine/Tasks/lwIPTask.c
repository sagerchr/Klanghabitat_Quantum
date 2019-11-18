/*
 * lwIPTask.c
 *
 *  Created on: 08.11.2019
 *      Author: christiansager
 */

#include "main.h"
#include "lwip/apps/httpd.h"
#include "lwip.h"

char UDP_Message[] = {'/','j','u','c','e','/','r','o','t','a','r','y','b','u','t','t','e','r',0x00,0x00,',','i',0x00,0x00,0x00,0x00,0x00,0x08};

static struct udp_pcb *udpPcb;
char str[20];

void lwIPTask(void const * argument){


	uint8_t test;


	/* init code for LWIP */

	  /* USER CODE BEGIN 5 */


	  const char * IPCGIhandler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
	       {
		  	uint32_t i=0;
		  	char IP1[5];
		  	char IP2[5];
		  	char IP3[5];
		  	char IP4[5];
		  	int ind = iIndex;
		    	 	memcpy (IP1, pcValue[0],3);
					memcpy (IP2, pcValue[1],3);
					memcpy (IP3, pcValue[2],3);
					memcpy (IP4, pcValue[3],3);
					HAL_GPIO_TogglePin(GPIOB, LD3_Pin);
		  return "/index.html";
	       }



	     // the function pointer for a CGI script handler is defined in httpd.h as tCGIHandler
	     const char * LedCGIhandler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
	     {
	     uint32_t i=0;
	     // index of the CGI within the theCGItable array passed to http_set_cgi_handlers
	     // Given how this example is structured, this may be a redundant check.
	     // Here there is only one handler iIndex == 0
	     if (iIndex == 0)
	     {
	     // turn off the LEDs
	    	 HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
	     // Check the cgi parameters, e.g., GET /leds.cgi?led=1&led=2
			 for (i=0; i<iNumParams; i++)
			 {
			 //if pcParmeter contains "led", then one of the LED check boxes has been set on
				 if (strcmp(pcParam[i], "led") == 0)
				 {
				 //see if checkbox for LED 1 has been set
					 if(strcmp(pcValue[i], "1") == 0)
					 {
					 // switch led 1 ON if 1
						 HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
					 }
					 //see if checkbox for LED 2 has been set
					 else if(strcmp(pcValue[i], "2") == 0)
					 {
					 // switch led 2 ON if 2
						 HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
					 }
				 } //if
			 } //for
	     } //if
	     //uniform resource identifier to send after CGI call, i.e., path and filename of the response
	     return "/leds.html";
	     } //LedCGIhandler
	     // this structure contains the name of the LED CGI and corresponding handler for the LEDs
	     const tCGI LedCGI={"/leds.cgi", LedCGIhandler};
	     const tCGI IPCGI={"/IP.cgi", IPCGIhandler};
	     //table of the CGI names and handlers
	     tCGI theCGItable[2];
	     // Initialize the CGI handlers
	     void myCGIinit(void)
	     {
	     //add LED control CGI to the table
	     theCGItable[0] = LedCGI;
	     theCGItable[1] = IPCGI;
	     //give the table to the HTTP server
	     http_set_cgi_handlers(theCGItable, 2);
	     } //myCGIinit

	  //==================================SENDING UDP MESSAGE===================================//

	  void SendUDP(uint8_t count){

		ip_addr_t       client1IpAddr; //The Clients IP Adress
		struct pbuf     *ethTxBuffer_p;
		UDP_Message[27] = count;
	    IP4_ADDR(&client1IpAddr, 192, 168, 1, 36); //IP Adress to send UDP to in this CASE BROADCAST!!!


	    ethTxBuffer_p = pbuf_alloc(PBUF_TRANSPORT, sizeof(UDP_Message), PBUF_RAM); //TX BUFFER TO SOMETHING WE CAN SEND
	    if (ethTxBuffer_p == NULL){}

	    memcpy(ethTxBuffer_p->payload, UDP_Message, sizeof(UDP_Message));

	    udp_sendto(udpPcb, ethTxBuffer_p, &client1IpAddr,9002);  //SEND UDP TO PORT 9002

	    pbuf_free(ethTxBuffer_p);  //Free the TX Buffer
	  }
	//=======================================================================================//



	//==================================Recive UDP MESSAGE===================================//

	  void udp_recive(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
	  {
		HAL_GPIO_TogglePin(GPIOB, LD2_Pin); //Blaue LED an
		memcpy(str, p -> payload, p -> len);
	    pbuf_free(p);

	  }
	 //=======================================================================================//

	 //==================================INIT UDP Session===================================//
	    void UDP_init(void){
	      err_t         udpErr;
	      ip_addr_t     ownIPaddr;
	      udpPcb = udp_new();

	      if(udpPcb != NULL)
	      {
	        IP4_ADDR(&ownIPaddr, 192, 168, 1, 205); //The IP Adress of the STM32
	        udpErr = udp_bind(udpPcb, &ownIPaddr, 9001); //Definition of
	        udp_recv(udpPcb, udp_recive, NULL);
	        if (udpErr ==ERR_OK){
	        }
	      }
	    }
	  //=======================================================================================//

	  //==================================SSI Implementation===================================//
	    //array of tags for the SSI handler
	    //these are the tags <!--#tag1--> contained in the shtml file
	    #define numSSItags 2
	    char const *theSSItags[numSSItags] = {"tag1","tag2"};
	    int k = 0;
	    /**** SSI handler ****/
	    // This function is called each time the HTTPD server detects a tag of the form
	    // <!--#name--> in a .shtml, .ssi or .shtm file
	    // It won't work if the file has a .html extension.
	    u16_t mySSIHandler(int iIndex, char *pcInsert, int iInsertLen)
	    {
	    k++;
	    // see which tag in the array theSSItags to handle
	    if (iIndex == 0) //is “tag1”
	    {
	    char myStr1[] = "hello#1!"; //string to be displayed on web page
	    myStr1[5] = k;
	    //copy the string to be displayed to pcInsert
	    strcpy(pcInsert, myStr1);
	    //return number of characters that need to be inserted in html
	    return strlen(myStr1);
	    }
	    else if (iIndex == 1) //is “tag2”
	    {
	    char myStr2[] = "hello#2!"; //string to be displayed on web page
	    //copy string to be displayed
	    strcpy(pcInsert, myStr2);
	    //return number of characters that need to be inserted in html
	    return strlen(myStr2);
	    }
	    return 0;
	    } //mySSIHandler


	    void mySSIinit(void)
	    {
	    //configure SSI handler function
	    //theSSItags is an array of SSI tag strings to search for in SSI-enabled files
	    	http_set_ssi_handler(mySSIHandler, (char const **)theSSItags, numSSItags);
	    } //mySSIinit

	  //=====================================================================================//


	  //=======================CREATE & START all lwIP Services===============================//
	     MX_LWIP_Init();
	     UDP_init(); //INIT the UDP Session
	     httpd_init();//start the web Server
	     myCGIinit();//initialise the CGI handlers
	     udp_recv(udpPcb, udp_recive, NULL);//Create udp_recive callback
	     mySSIinit();
	   //=====================================================================================//




	    uint8_t count = 0;
	  /* Infinite loop */
	  for(;;)
	  {

		count++;
		str[19];
		//SendUDP(str[19]);
		//test = conv_ADC1[0];

		SendUDP(conv_ADC1*3);

		if (count ==127){
			count = 0;
		}
	    osDelay(20);
	  }

}
