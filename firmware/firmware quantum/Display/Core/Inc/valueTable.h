/*
 * valueTable.h
 *
 *  Created on: 10 May 2020
 *      Author: christiansager
 */

#ifndef SRC_VALUETABLE_H_
#define SRC_VALUETABLE_H_



#endif /* SRC_VALUETABLE_H_ */

float f_spectrumLeft_bufferd[50];
float f_spectrumRight_bufferd[50];

//Main Float StreamValues//
float f_inputLeft_DB;
float f_inputRight_DB;
float f_inputLeft_DB_RMS;
float f_inputRight_DB_RMS;

float f_VCALeft_DB;
float f_VCARight_DB;
float f_VCALeft_DB_RMS;
float f_VCARight_DB_RMS;

float f_outputLeft_DB;
float f_outputRight_DB;
float f_outputLeft_DB_RMS;
float f_outputRight_DB_RMS;
//////////////////////
float f_inputLeft_DB_bufferd;
float f_inputRight_DB_bufferd;

float f_VCALeft_DB_bufferd;
float f_VCARight_DB_bufferd;

float f_outputLeft_DB_bufferd;
float f_outputRight_DB_bufferd;
//////////////////////
float f_inputLeft_DB_MAXbufferd;
float f_inputRight_DB_MAXbufferd;

float f_VCALeft_DB_MAXbufferd;
float f_VCARight_DB_MAXbufferd;

float f_outputLeft_DB_MAXbufferd;
float f_outputRight_DB_MAXbufferd;
//MainWaveform StreamValues//
int i_inputLeft_Waveform;
int i_inputRight_Waveform;

int i_VCALeft_Waveform;
int i_VCARight_Waveform;

int i_outputLeft_Waveform;
int i_outputRight_Waveform;

uint8_t inputLeftStream[400];
uint8_t inputRightStream[400];

uint8_t VCALeftStream[400];
uint8_t VCARightStream[400];

uint8_t outputLeftStream[400];
uint8_t outputRightStream[400];

//MainIndicator StreamValues//
int i_inputLeft_Indicator;
int i_inputRight_Indicator;

int i_VCALeft_Indicator;
int i_VCARight_Indicator;

int i_outputLeft_Indicator;
int i_outputRight_Indicator;

float i_inputLeft_Indicator_bufferd;
float i_inputRight_Indicator_bufferd;

float i_VCALeft_Indicator_bufferd;
float i_VCARight_Indicator_bufferd;

float i_outputLeft_Indicator_bufferd;
float i_outputRight_Indicator_bufferd;

float i_inputLeft_Indicator_MAXbufferd;
float i_inputRight_Indicator_MAXbufferd;

float i_VCALeft_Indicator_MAXbufferd;
float i_VCARight_Indicator_MAXbufferd;

float i_outputLeft_Indicator_MAXbufferd;
float i_outputRight_Indicator_MAXbufferd;










