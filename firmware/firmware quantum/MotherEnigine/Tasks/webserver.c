#include "main.h"
#include "lwip/apps/httpd.h"
#include "lwip.h"
#include <string.h>
#include "webserver.h"
#include "MY_FLASH.h"
#include "RelaisControl.h"


char IP1_str[5],IP2_str[5],IP3_str[5],IP4_str[5];
char IP1_str_temp[5],IP2_str_temp[5],IP3_str_temp[5],IP4_str_temp[5];

	  const char * IPCGIhandler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
	       {

		  	memcpy (IP1_str, pcValue[0],3);
		  	memcpy (IP2_str, pcValue[1],3);
		  	memcpy (IP3_str, pcValue[2],3);
		  	memcpy (IP4_str, pcValue[3],3);
		  	HAL_GPIO_TogglePin(GPIOB, LD3_Pin);

		  	int end = 0;
		  	for(int i=0;i<5;i++){
		  		IP1_str_temp[i] = 0x00;
		  		if(IP1_str[i] == 0x00){
		  			end = 1;
		  		}
		  		if(end == 0){
		  			IP1_str_temp[i] = IP1_str[i];
		  		}
		  		if(end != 0){
		  			IP1_str_temp[i] = 0x00;
		  		}
		  	}
		  	end = 0;
		  	for(int i=0;i<5;i++){
		  		IP2_str_temp[i] = 0x00;
		  		if(IP2_str[i] == 0x00){
		  			end = 1;
		  		}
		  		if(end == 0){
		  			IP2_str_temp[i] = IP2_str[i];
		  		}
		  		if(end != 0){
		  			IP2_str_temp[i] = 0x00;
		  		}
		  	}
		  	end = 0;
		  	for(int i=0;i<5;i++){
		  		IP3_str_temp[i] = 0x00;
		  		if(IP3_str[i] == 0x00){
		  			end = 1;
		  		}
		  		if(end == 0){
		  			IP3_str_temp[i] = IP3_str[i];
		  		}
		  		if(end != 0){
		  			IP3_str_temp[i] = 0x00;
		  		}
		  	}
		  	end = 0;
		  	for(int i=0;i<5;i++){
		  		IP4_str_temp[i] = 0x00;
		  		if(IP4_str[i] == 0x00){
		  			end = 1;
		  		}
		  		if(end == 0){
		  			IP4_str_temp[i] = IP4_str[i];
		  		}
		  		if(end != 0){
		  			IP4_str_temp[i] = 0x00;
		  		}
		  	}
		  	IP1 = atoi(IP1_str_temp);
		  	IP2 = atoi(IP2_str_temp);
		  	IP3 = atoi(IP3_str_temp);
		  	IP4 = atoi(IP4_str_temp);

		  	uint8_t IP[4]={IP1,IP2,IP3,IP4};
		  	MY_FLASH_WriteN(0,IP,4,DATA_TYPE_8);

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
	    	 //BypassLeft(bypass);

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
						 //BypassLeft(activate);
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
	     printf("run: myCGIinit()\r\n");
	     //add LED control CGI to the table
	     theCGItable[0] = LedCGI;
	     theCGItable[1] = IPCGI;
	     //give the table to the HTTP server
	     http_set_cgi_handlers(theCGItable, 2);
	     } //myCGIinit


	    //==================================SSI Implementation===================================//
		//array of tags for the SSI handler
		//these are the tags <!--#tag1--> contained in the shtml file
		#define numSSItags 7
		char const *theSSItags[numSSItags] = {"IP1","IP2","IP3","IP4","IP_FLASH","SUB", "NAME"};
		int k = 0;
		/**** SSI handler ****/
		// This function is called each time the HTTPD server detects a tag of the form
		// <!--#name--> in a .shtml, .ssi or .shtm file
		// It won't work if the file has a .html extension.
		u16_t mySSIHandler(int iIndex, char *pcInsert, int iInsertLen)
		{
		k++;
		// see which tag in the array theSSItags to handle
		if (iIndex == 0) //is "IP1"
			{
			int someInt = IP_READ_FLASH[0];
			char str[4];
			sprintf(str, "%d", someInt);
			strcpy(pcInsert, str);
			//return number of characters that need to be inserted in html
			return strlen(str);
			}
		else if (iIndex == 1) //is "IP2"
			{
			int someInt = IP_READ_FLASH[1];
			char str[4];
			sprintf(str, "%d", someInt);
			strcpy(pcInsert, str);
			//return number of characters that need to be inserted in html
			return strlen(str);
			}
		else if (iIndex == 2) //is "IP3"
			{
			int someInt = IP_READ_FLASH[2];
			char str[4];
			sprintf(str, "%d", someInt);
			strcpy(pcInsert, str);
			//return number of characters that need to be inserted in html
			return strlen(str);
			}
		else if (iIndex == 3) //is "IP4"
			{
			int someInt = IP_READ_FLASH[3];
			char str[4];
			sprintf(str, "%d", someInt);
			strcpy(pcInsert, str);
			//return number of characters that need to be inserted in html
			return strlen(str);
			}
		else if (iIndex == 4) //is "IP4"
			{

			char pcIpAddrString[60];
			char pcBuffer[60];

			for (int i=0; i<60; i++){
				pcBuffer[i] = 0;
				pcIpAddrString[i] = 0;
			}
			char *dot = ".";

			char str[3];
			sprintf(str, "%d", IP_READ_FLASH[0]);
			strcat(pcIpAddrString, str);
			strcat(pcIpAddrString, dot);
			sprintf(str, "%d", IP_READ_FLASH[1]);
			strcat(pcIpAddrString, str);
			strcat(pcIpAddrString, dot);
			sprintf(str, "%d", IP_READ_FLASH[2]);
			strcat(pcIpAddrString, str);
			strcat(pcIpAddrString, dot);
			sprintf(str, "%d", IP_READ_FLASH[3]);
			strcat(pcIpAddrString, str);

			sprintf(pcBuffer, "<input type=\"text\" value=\"%s\" name=\"ipaddr\">", pcIpAddrString);
			strcpy(pcInsert, pcBuffer);
			//return number of characters that need to be inserted in html
			return strlen(pcBuffer);
			}
		else if (iIndex == 5) //is "IP4"
			{

			char pcIpAddrString[60];
			char pcBuffer[60];

			for (int i=0; i<60; i++){
				pcBuffer[i] = 0;
				pcIpAddrString[i] = 0;
			}
			char *dot = ".";

			char str[3];
			sprintf(str, "%d", SUBNET_READ_FLASH[0]);
			strcat(pcIpAddrString, str);
			strcat(pcIpAddrString, dot);
			sprintf(str, "%d", SUBNET_READ_FLASH[1]);
			strcat(pcIpAddrString, str);
			strcat(pcIpAddrString, dot);
			sprintf(str, "%d", SUBNET_READ_FLASH[2]);
			strcat(pcIpAddrString, str);
			strcat(pcIpAddrString, dot);
			sprintf(str, "%d", SUBNET_READ_FLASH[3]);
			strcat(pcIpAddrString, str);

			sprintf(pcBuffer, "<input type=\"text\" value=\"%s\" name=\"sub\">", pcIpAddrString);
			strcpy(pcInsert, pcBuffer);
			//return number of characters that need to be inserted in html
			return strlen(pcBuffer);
			}

		else if (iIndex == 6) //is "IP4"
			{

			char pcIpAddrString[60];
			char pcBuffer[60];

			for (int i=0; i<60; i++){
				pcBuffer[i] = 0;
				pcIpAddrString[i] = 0;
			}

			sprintf(pcIpAddrString, "TestDevice");

			sprintf(pcBuffer, "<input type=\"text\" value=\"%s\" name=\"sub\">", pcIpAddrString);
			strcpy(pcInsert, pcBuffer);
			//return number of characters that need to be inserted in html
			return strlen(pcBuffer);
			}
		return 0;
		} //mySSIHandler




		void mySSIinit(void)
		{
		printf("run: mySSIinit()\r\n");
		//configure SSI handler function
		//theSSItags is an array of SSI tag strings to search for in SSI-enabled files
			http_set_ssi_handler(mySSIHandler, (char const **)theSSItags, numSSItags);
		} //mySSIinit * webserver.c



