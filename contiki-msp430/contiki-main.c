/*
 * Copyright (c) 2003, Adam Dunkels.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution. 
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.  
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
 *
 * This file is part of the Contiki desktop environment 
 *
 * $Id: contiki-main.c,v 1.1 2003/09/04 19:46:32 adamdunkels Exp $
 *
 */

#include <io.h>
#include <signal.h>


#include "ctk.h"
#include "ctk-draw.h"
#include "ctk-vncserver.h"
#include "dispatcher.h"


#include "uip_main.h"
#include "uip.h"
#include "uip_arp.h"
#include "resolv.h"

#include "webserver.h"
#include "program-handler.h"
#include "about-dsc.h"
#include "netconf-dsc.h"
#include "processes-dsc.h"
#include "calc-dsc.h"
#include "www-dsc.h"
#include "webserver-dsc.h"

#include "sensorview-dsc.h"

#include "weblinks-dsc.h"

#include "sensors.h"

#include "uip.h"
#include "uip_arp.h"


#include "rs232.h"
void slip_drv_init(char *arg);




static u16_t addr[2];
static unsigned short count;

/*-----------------------------------------------------------------------------------*/
unsigned short
clock(void)
{
  return count++;
}
/*-----------------------------------------------------------------------------------*/
void
beep(void)
{
  unsigned int i, j;
  
  /* Beep. */
  P2OUT &= 0xFE;
  P2OUT |= 8;
  for(i = 0; i < 140; ++i) {
    j = j * j;
  }
  P2OUT &= 0xf7;
  P2OUT |= 0x01;  
}
/*-----------------------------------------------------------------------------------*/
static void
rs232_print(char *cptr)
{
  while(*cptr != 0) {
    rs232_put(*cptr);
    ++cptr;
  }
}
/*-----------------------------------------------------------------------------------*/
static void
init_hardware(void)
{
  int j;
  char c;

    ////////// Port 1 ////
  P1SEL = 0x00;
  P1DIR = 0x81;       // Outputs: P10=IRSend, P17=RS232RTS
                      // Inputs: P11=Light, P12=IRRec, P13=PIR, P14=Vibration, 
                      //         P15=Clockalarm, P16=RS232CTS
  P1OUT = 0x00;

  ////////// Port 2 ////
  P2SEL = 0x00;       // No Sels
  P2DIR = 0x7F;       // Outpus: P20..P23=Leds+Beeper, P24..P26=Poti
                      // Inputs: P27=Taster
  P2OUT = 0x77;
  
  ////////// Port 3 ////
  P3SEL = 0xE0;       // Sels for P34..P37 to activate UART, 
  P3DIR = 0x5F;       // Inputs: P30..P33=CON4, P35/P37=RXD Transceiver/RS232
                      // OutPuts: P36/P38=TXD Transceiver/RS232
  P3OUT = 0xE0;       // Output a Zero on P34(TXD Transceiver) and turn SELECT off when receiving!!!

  ////////// Port 4 ////
  P4SEL = 0x00;       // CON5 Stecker
  P4DIR = 0xFF;
  P4OUT = 0x00;
  
  ////////// Port 5 ////
  P5SEL = 0x00;       // P50/P51= Clock SDA/SCL, P52/P53/P54=EEPROM SDA/SCL/WP
  P5DIR = 0xDA;       // P56/P57=Transceiver CNTRL0/1
  P5OUT = 0x0F;
  
  ////////// Port 6 ////
  P6SEL = 0x00;       // P60=Microphone, P61=PIR digital (same as P13), P62=PIR analog
  P6DIR = 0x00;       // P63=extern voltage, P64=battery voltage, P65=Receive power
  P6OUT = 0x00;

  /* Red led on */
  P2OUT &= 0xfd;  
  
  eint();   /* Enable interrupts. */

  beep();
}
/*-----------------------------------------------------------------------------------*/
extern  const unsigned char data_index_html[];
int
main(int argc, char **argv)
{

  init_hardware();

  sensors_init();
  
  rs232_print("uip_init()...\n"); 
  uip_init();

  rs232_print("resolv_init()...\n");
  resolv_init();
  

  
#if 1
  uip_ipaddr(addr, 193,10,67,150);
  uip_sethostaddr(addr);
 
  uip_ipaddr(addr, 193,10,66,195);
  resolv_conf(addr);

#else

  uip_ipaddr(addr, 172,16,0,2);
  uip_sethostaddr(addr);
 
  uip_ipaddr(addr, 193,10,66,195);
  resolv_conf(addr);
#endif

  
  rs232_print("dispatcher_init()...\n");
  dispatcher_init();

  
  rs232_print("slip_drv_init()...\n");  
  slip_drv_init(NULL);


  rs232_print("ctk_init()...\n");  
  ctk_init();

  rs232_print("ctk_vncserver_init()...\n");  
  ctk_vncserver_init(NULL);  

  rs232_print("program_handler_init()...\n");  
  program_handler_init();

  /*  rs232_print("processes_init()...\n");  
      processes_init(NULL);*/

  rs232_print("webserver_init()...\n");  
  webserver_init(NULL);

  
  /*  program_handler_add(&directory_dsc, "Directory", 1);*/
  /*  program_handler_add(&about_dsc, "About", 1);*/
  /*  program_handler_add(&webserver_dsc, "Web server", 1);*/
  /*  program_handler_add(&www_dsc, "Web browser", 1);*/
  /*  program_handler_add(&calc_dsc, "Calculator", 0);*/
  /*  program_handler_add(&processes_dsc, "Processes", 0);*/

  rs232_print("program_handler_addd()...\n");  
  program_handler_add(&sensorview_dsc, "Sensors", 1);
  

  rs232_print("dispatcher_run()...\n");
  beep();
  dispatcher_run();
  
  return 0;

  argv = argv;
  argc = argc;



}
/*-----------------------------------------------------------------------------------*/
char *arg_alloc(char size) {return NULL;}
void  arg_init(void) {}
void  arg_free(char *arg) {}
/*-----------------------------------------------------------------------------------*/
