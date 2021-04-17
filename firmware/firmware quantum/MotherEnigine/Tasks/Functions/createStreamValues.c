#include "main.h"
#include "ValueTableMotherEngine.h"


void createStreamValue(uint8_t upcounter){

	 	 	  char data[sizeof(float)];
			  float f = -1.236;
			  char a = data[0];char b = data[1];char c = data[2];char d = data[3];

			  UART_TRANSFER[0]='#';
			  UART_TRANSFER[1]='s';
			  UART_TRANSFER[2]='t';
			  UART_TRANSFER[3]='a';
			  UART_TRANSFER[4]=upcounter;//3

			  UART_TRANSFER[5]=0x02;//2
			  UART_TRANSFER[6]=voltageIn1MAX*100;//3
			  UART_TRANSFER[7]=voltageIn2MAX*100;//4
			  UART_TRANSFER[8]=voltageIn3MAX*100;//7
			  UART_TRANSFER[9]=voltageIn4MAX*100;//7
			  UART_TRANSFER[10]=voltageIn5MAX*100;//7
			  UART_TRANSFER[11]=voltageIn6MAX*100;//8

			  memcpy(data, &dbuMAX[0], sizeof &dbuMAX[0]);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[12]=d;
			  UART_TRANSFER[13]=c;
			  UART_TRANSFER[14]=b;
			  UART_TRANSFER[15]=a;

			  memcpy(data, &dbuMAX[1], sizeof &dbuMAX[1]);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[16]=d;
			  UART_TRANSFER[17]=c;
			  UART_TRANSFER[18]=b;
			  UART_TRANSFER[19]=a;

			  memcpy(data, &dbuMAX[2], sizeof &dbuMAX[2]);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[20]=d;
			  UART_TRANSFER[21]=c;
			  UART_TRANSFER[22]=b;
			  UART_TRANSFER[23]=a;

			  memcpy(data, &dbuMAX[3], sizeof &dbuMAX[3]);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[24]=d;
			  UART_TRANSFER[25]=c;
			  UART_TRANSFER[26]=b;
			  UART_TRANSFER[27]=a;

			  memcpy(data, &dbuMAX[4], sizeof &dbuMAX[4]);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[28]=d;
			  UART_TRANSFER[29]=c;
			  UART_TRANSFER[30]=b;
			  UART_TRANSFER[32]=a;

			  memcpy(data, &dbuMAX[5], sizeof &dbuMAX[5]);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[32]=d;
			  UART_TRANSFER[33]=c;
			  UART_TRANSFER[34]=b;
			  UART_TRANSFER[35]=a;

			  memcpy(data, &RMS_CH1_long, sizeof &RMS_CH1_long);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[36]=d;
			  UART_TRANSFER[37]=c;
			  UART_TRANSFER[38]=b;
			  UART_TRANSFER[39]=a;

			  memcpy(data, &RMS_CH2_long, sizeof &RMS_CH2_long);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[40]=d;
			  UART_TRANSFER[41]=c;
			  UART_TRANSFER[42]=b;
			  UART_TRANSFER[43]=a;

			  memcpy(data, &RMS_CH3_long, sizeof &RMS_CH3_long);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[44]=d;
			  UART_TRANSFER[45]=c;
			  UART_TRANSFER[46]=b;
			  UART_TRANSFER[47]=a;

			  memcpy(data, &RMS_CH4_long, sizeof &RMS_CH4_long);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[48]=d;
			  UART_TRANSFER[49]=c;
			  UART_TRANSFER[50]=b;
			  UART_TRANSFER[51]=a;

			  memcpy(data, &RMS_CH5_long, sizeof &RMS_CH5_long);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[52]=d;
			  UART_TRANSFER[53]=c;
			  UART_TRANSFER[54]=b;
			  UART_TRANSFER[55]=a;

			  memcpy(data, &RMS_CH6_long, sizeof &RMS_CH6_long);    // send data
			  a = data[0]; b = data[1];c = data[2];d = data[3];
			  UART_TRANSFER[56]=d;
			  UART_TRANSFER[57]=c;
			  UART_TRANSFER[58]=b;
			  UART_TRANSFER[59]=a;


			  UART_TRANSFER[60]=reductLeft;
			  UART_TRANSFER[61]=reductRight;
}

