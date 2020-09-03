/*
 * ValueTableMotherEngine.h
 *
 *  Created on: 12 May 2020
 *      Author: christiansager
 */

void calculateDB();


int indexing;
int channel;

float voltageCH1[1200];
float voltageCH2[1200];
float voltageCH3[1200];
float voltageCH4[1200];
float voltageCH5[1200];
float voltageCH6[1200];

float tmp_decibelMaxCH1;
float tmp_decibelMaxCH2;
float tmp_decibelMaxCH3;
float tmp_decibelMaxCH4;
float tmp_decibelMaxCH5;
float tmp_decibelMaxCH6;

float act_decibelMaxCH1;
float act_decibelMaxCH2;
float act_decibelMaxCH3;
float act_decibelMaxCH4;
float act_decibelMaxCH5;
float act_decibelMaxCH6;

float MaxCH1;
float MaxCH2;
float MaxCH3;
float MaxCH4;
float MaxCH5;
float MaxCH6;

float sum_CH1;
float sum_CH2;
float sum_CH3;
float sum_CH4;
float sum_CH5;
float sum_CH6;

float RMS_CH1;
float RMS_CH2;
float RMS_CH3;
float RMS_CH4;
float RMS_CH5;
float RMS_CH6;

float RMS_CH1_long;
float RMS_CH2_long;
float RMS_CH3_long;
float RMS_CH4_long;
float RMS_CH5_long;
float RMS_CH6_long;

float sum_CH1_RMS;
float sum_CH2_RMS;
float sum_CH3_RMS;
float sum_CH4_RMS;
float sum_CH5_RMS;
float sum_CH6_RMS;

float sum_CH1_RMS_long[11];
float sum_CH2_RMS_long[11];
float sum_CH3_RMS_long[11];
float sum_CH4_RMS_long[11];
float sum_CH5_RMS_long[11];
float sum_CH6_RMS_long[11];

int DAC_LEFT;
int DAC_RIGHT;
