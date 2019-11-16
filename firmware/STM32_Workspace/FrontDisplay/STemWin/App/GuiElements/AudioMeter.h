/*
 * AudioMeter.h
 *
 *  Created on: 16.11.2019
 *      Author: christiansager
 */

#ifndef APP_GUIELEMENTS_AUDIOMETER_H_
#define APP_GUIELEMENTS_AUDIOMETER_H_

static void drawFloat (int pos_x, int pos_y, float val, const char * s,const char * h);
void drawBar (int pos_x, int pos_y, float PeakVal,float AvVal, const char * s );
void drawWaveForm();
void drawWaveFormUartLeft(int x,int y, int adc);
void drawWaveFormUartRight(int x,int y, int adc);


#endif /* APP_GUIELEMENTS_AUDIOMETER_H_ */
