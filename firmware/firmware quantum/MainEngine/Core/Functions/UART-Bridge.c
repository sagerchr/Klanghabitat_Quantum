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
#include "../Functions/MY_FLASH.h"
#include "UART-Bridge.h"
#if LWIP_TCP


extern UART_HandleTypeDef huart1;




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
  tcp_setprio(newpcb, TCP_PRIO_MIN);

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
        HAL_FLASH_Lock();
        return ERR_OK;
    }


	char buffer[p->len];
	char buffer2[p->len];
    /* indicate that the packet has been received */
    tcp_recved(tpcb, p->len);
    //memcpy(buffer, p->payload,p->len);
    /* echo back the payload */
    /* in this case, we assume that the payload is < TCP_SND_BUF */

    //err = tcp_write(tpcb, p->payload, p->len, 1);
    /* free the received pbuf */

    pbuf_free(p);
    //MY_FLASH_WriteN(count, p->payload, p->len, DATA_TYPE_8);
    count = count + p->len;

    for(int i=0;i<100;i++){
    	pData[i]=0x00;
    }
    HAL_UART_DMAStop(&huart1);
    huart1.hdmarx->Instance->NDTR = 100;
    HAL_UART_Receive_DMA(&huart1, pData, 100);


    HAL_UART_Transmit(&huart1, p->payload, p->len, 10);
    char cmd[p->len];
    memcpy(cmd, p->payload,p->len);

    if((cmd[1] == 0xD1)||(cmd[1] == 0xD0)||(cmd[1] == 0xF6)||(cmd[1] == 0x0F)){
        while(pData[1] == 0x00){

        }
    }
    else
    {

        	HAL_Delay(10);

    }

   tcp_write(tpcb, pData, pData[0]+1, 1);

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
