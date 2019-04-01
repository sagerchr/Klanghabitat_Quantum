/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "stats_report.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
//DigitalOut led4(LED4);

#define SLEEP_TIME                  1000 // (msec)
#define PRINT_AFTER_N_LOOPS         20

// main() runs in its own thread in the OS
int main()
{
    SystemReport sys_state( SLEEP_TIME * PRINT_AFTER_N_LOOPS /* Loop delay time in ms */);
    led1 = false;
    led2 = false;
    led3 = false;

    
    while (true) {
        
        led1 = !led1;
        led2 = !led2;
        led3 = !led3;
        
        wait_ms(SLEEP_TIME);
    }
}
