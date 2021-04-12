#include "main.h"
#include "ValueTableMotherEngine.h"


void createStreamValue(uint8_t upcounter){

	 	 	  char data[sizeof(float)];
			  float f = -1.236;
			  char a = data[0];char b = data[1];char c = data[2];char d = data[3];

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
}

