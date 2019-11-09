/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "stats_report.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

#define SLEEP_TIME                  50 // (msec)
#define SLEEP_TIME_OFF              50
#define PRINT_AFTER_N_LOOPS         20

// main() runs in its own thread in the OS
int main()
{
    SystemReport sys_state( SLEEP_TIME * PRINT_AFTER_N_LOOPS /* Loop delay time in ms */);

    int count = 0;
    while (true) {
        // Blink LED and wait 0.5 seconds
 
        led1 = true;
        wait_ms(SLEEP_TIME);
        led1 = false;
        wait_ms(SLEEP_TIME_OFF);
        led2 = true;
        wait_ms(SLEEP_TIME);
        led2 = false;
        wait_ms(SLEEP_TIME_OFF);
        led3 = true;
        wait_ms(SLEEP_TIME);
        led3 = false;
        wait_ms(SLEEP_TIME_OFF);

    }
}
