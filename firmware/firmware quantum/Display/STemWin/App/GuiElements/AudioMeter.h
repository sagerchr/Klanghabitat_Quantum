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
void drawBarDotted (int pos_x, int pos_y, float PeakVal,float AvVal);
void drawBarDottedVertical (int pos_x, int pos_y, float PeakVal,float AvVal);
void drawBarHorizontal (int pos_x, int pos_y, float PeakVal,float AvVal,  const char * s , int invert);
void drawWaveForm();
void drawWaveFormUartLeft(int x,int y, int adc, int clear);
void drawWaveFormUartRight(int x,int y, int adc, int clear);
void clearBuffer();

#endif /* APP_GUIELEMENTS_AUDIOMETER_H_ */
