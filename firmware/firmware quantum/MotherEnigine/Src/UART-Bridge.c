/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of and a contribution to the lwIP TCP/IP stack.
 *
 * Credits go to Adam Dunkels (and the current maintainers) of this software.
 *
 * Christiaan Simons rewrote this file to get a more stable echo example.
 */

/**
 * @file
 * TCP echo server example using raw API.
 *
 * Echos all bytes sent by connecting client,
 * and passively closes when client is done.
 *
 */



#include "main.h"
#include "lwip/debug.h"
#include "lwip/stats.h"
#include "lwip/tcp.h"
#include "UART-Bridge.h"
#include "stm32_hal_legacy.h"
#if LWIP_TCP


extern UART_HandleTypeDef huart6;
extern TIM_HandleTypeDef htim7;
void
UartBridge_init(void)
{
  echo_pcb = tcp_new();
  if (echo_pcb != NULL)
  {
    err_t err;

    err = tcp_bind(echo_pcb, IP_ADDR_ANY, 7);
    if (err == ERR_OK)
    {
      echo_pcb = tcp_listen(echo_pcb);
      tcp_accept(echo_pcb, echo_accept);
    }
    else
    {
      /* abort? output diagnostic? */
    }
  }
  else
  {
    /* abort? output diagnostic? */
  }
}
uint32_t count = 0;

err_t
echo_accept(void *arg, struct tcp_pcb *newpcb, err_t err)
{
  err_t ret_err;
  struct echo_state *es;

  LWIP_UNUSED_ARG(arg);
  LWIP_UNUSED_ARG(err);

  /* commonly observed practive to call tcp_setprio(), why? */
  tcp_setprio(newpcb, TCP_PRIO_MAX);

  es = (struct echo_state *)mem_malloc(sizeof(struct echo_state));
  if (es != NULL)
  {
    es->state = ES_ACCEPTED;
    es->pcb = newpcb;
    es->retries = 0;
    es->p = NULL;
    /* pass newly allocated es to our callbacks */
    tcp_arg(newpcb, es);
    tcp_recv(newpcb, echo_recv);
    count = 0;
    ret_err = ERR_OK;
    HAL_TIM_Base_Stop(&htim7);

    DisplayReset = 1;
    osDelay(100);



    DisplayUpdate =1;
    HAL_UART_DMAStop(&huart6); //Stop the HUART


	USART6 -> CR1 &= ~(USART_CR1_UE);
	USART6 -> BRR = 0x3AA; //This will give Baudrate 115200
	USART6 -> CR1 |= USART_CR1_UE;


    DisplayReset = 0;


  }
  else
  {
    ret_err = ERR_MEM;
  }
  return ret_err;
}



err_t
echo_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{


	if (!p) {
        tcp_close(tpcb);
        tcp_recv(tpcb, NULL);
        HAL_TIM_Base_Start_IT(&htim7);
        return ERR_OK;
    }

    /* indicate that the packet has been received */
    tcp_recved(tpcb, p->len);



    //count = count + p->len;
    HAL_UART_DMAStop(&huart6); //Stop the HUART
    for(int i=0;i<100;i++){
    	pData[i]=0x00;
    }


    huart6.hdmarx->Instance->NDTR = 100; //Set DMA counter back to Strat posotion

    HAL_UART_Receive_DMA(&huart6, pData, 100); //Init the DMA to Recive data

    char send[19];



    char cmd[p->len]; //Identify the CMD

    memcpy(cmd, p->payload,p->len); //Save the CMD to variable
/*
    if(cmd[1]==0xD0){

    	send[0]=0x12;
    	send[1]=0xD0;
    	send[2]=0x00;
    	send[3]=0x01;
    	send[4]=0x02;
    	send[5]=0x03;
    	send[6]=0x04;
    	send[7]=0x05;
    	send[8]=0x06;
    	send[9]=0x07;
    	send[10]=0x08;
    	send[11]=0x09;
    	send[12]=0x10;
    	send[13]=0x0A;
    	send[14]=0x0B;
    	send[15]=0x0C;
    	send[16]=0x0D;
    	send[17]=0x0E;
    	send[18]=0x0F;

    	 HAL_UART_Transmit(&huart6, send, 19, 1000); //Send data to Display recived via Ethernet
    }
    else{

    	HAL_UART_Transmit(&huart6, p->payload, p->len, 1000); //Send data to Display recived via Ethernet
    }

*/
    HAL_UART_Transmit(&huart6, p->payload, p->len, 10); //Send data to Display recived via Ethernet
    pbuf_free(p);


    if((cmd[1] == 0xD1)||(cmd[1] == 0xD0)||(cmd[1] == 0xF6)||(cmd[1] == 0x0F)){
        while(pData[1] == 0x00)
        {

        }
   }
   else
   {
        	HAL_Delay(20);
   }

   tcp_write(tpcb, pData, pData[0]+1, 1); //Write back answer to HOST Software

   if (cmd[1] == 0xCF){
   	NVIC_SystemReset();
   	HAL_Delay(1);
   }

    return ERR_OK;
}

void
echo_error(void *arg, err_t err)
{
  struct echo_state *es;

  LWIP_UNUSED_ARG(err);

  es = (struct echo_state *)arg;
  if (es != NULL)
  {
    mem_free(es);
  }
}



void
echo_close(struct tcp_pcb *tpcb, struct echo_state *es)
{
  tcp_arg(tpcb, NULL);
  //tcp_sent(tpcb, NULL);
  tcp_recv(tpcb, NULL);
  tcp_err(tpcb, NULL);
  //tcp_poll(tpcb, NULL, 0);

  if (es != NULL)
  {
    mem_free(es);
  }
  tcp_close(tpcb);
}


#endif /* LWIP_TCP */
