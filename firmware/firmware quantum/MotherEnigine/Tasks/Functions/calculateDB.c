/*
 * calculateDB.c
 *
 *  Created on: 12 Jun 2020
 *      Author: christiansager
 */
#include "main.h"
#include "ValueTableMotherEngine.h"

calculateDB(){

	  voltageCH1[indexing]=(int16_t)analogIN[0]*(10.0/32767);
	  if (voltageCH1[indexing]<0){voltageCH1[indexing] = voltageCH1[indexing]*(-1.0);}
	  sum_CH1 = sum_CH1 + (voltageCH1[indexing]*voltageCH1[indexing]);

	  voltageCH2[indexing]=(int16_t)analogIN[1]*(10.0/32767);
	  if (voltageCH2[indexing]<0){voltageCH2[indexing] = voltageCH2[indexing]*(-1.0);}
	  sum_CH2 = sum_CH2 + (voltageCH2[indexing]*voltageCH2[indexing]);

	  voltageCH3[indexing]=(int16_t)analogIN[2]*(10.0/32767);
	  if (voltageCH3[indexing]<0){voltageCH3[indexing] = voltageCH3[indexing]*(-1.0);}
	  sum_CH3 = sum_CH3 + (voltageCH3[indexing]*voltageCH3[indexing]);

	  voltageCH4[indexing]=(int16_t)analogIN[3]*(10.0/32767);
	  if (voltageCH4[indexing]<0){voltageCH4[indexing] = voltageCH4[indexing]*(-1.0);}
	  sum_CH4 = sum_CH4 + (voltageCH4[indexing]*voltageCH4[indexing]);

	  voltageCH5[indexing]=(int16_t)analogIN[4]*(10.0/32767);
	  if (voltageCH5[indexing]<0){voltageCH5[indexing] = voltageCH5[indexing]*(-1.0);}
	  sum_CH5 = sum_CH5 + (voltageCH5[indexing]*voltageCH5[indexing]);

	  voltageCH6[indexing]=(int16_t)analogIN[5]*(10.0/32767);
	  if (voltageCH6[indexing]<0){voltageCH6[indexing] = voltageCH6[indexing]*(-1.0);}
	  sum_CH6 = sum_CH6 + (voltageCH6[indexing]*voltageCH6[indexing]);

	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////



	  	  switch (channel){
	  case 1:

		  MaxCH1=0.0;

		  for (int i=0; i<6;i++){
	//Exception on overflow when indexing is exact 0 for Channel1//////////////////////////


				  if(MaxCH1 < voltageCH1[indexing-5+i]){MaxCH1 = voltageCH1[indexing-5+i];}


		  }

		  tmp_decibelMaxCH1  = 20*log10(MaxCH1/1.095); //1.5 µsec!!!

		  if (voltageIn1MAX < MaxCH1){voltageIn1MAX=MaxCH1;}
		  if (voltageIn2MAX < MaxCH2){voltageIn2MAX=MaxCH2;}
		  if (voltageIn3MAX < MaxCH3){voltageIn3MAX=MaxCH3;}
		  if (voltageIn4MAX < MaxCH4){voltageIn4MAX=MaxCH4;}
		  if (voltageIn5MAX < MaxCH5){voltageIn5MAX=MaxCH5;}
		  if (voltageIn6MAX < MaxCH6){voltageIn6MAX=MaxCH6;}

		  if (dbuMAX[0]<tmp_decibelMaxCH1){dbuMAX[0]=tmp_decibelMaxCH1;}
		  if (dbuMAX[1]<tmp_decibelMaxCH2){dbuMAX[1]=tmp_decibelMaxCH2;}
		  if (dbuMAX[2]<tmp_decibelMaxCH3){dbuMAX[2]=tmp_decibelMaxCH3;}
		  if (dbuMAX[3]<tmp_decibelMaxCH4){dbuMAX[3]=tmp_decibelMaxCH4;}
		  if (dbuMAX[4]<tmp_decibelMaxCH5){dbuMAX[4]=tmp_decibelMaxCH5;}
		  if (dbuMAX[5]<tmp_decibelMaxCH6){dbuMAX[5]=tmp_decibelMaxCH6;}
		  channel=2;

		  break;
	  case 2:
		  MaxCH2=0.0;
		  for (int i=0; i<6;i++){
	//Exception on overflow when indexing is exact 0 for Channel2//////////////////////////
			if(indexing == 0){
					if(i<1){
						if(MaxCH2 < voltageCH2[i]){MaxCH1 = voltageCH2[i];}
					}else{
						if(MaxCH2 < voltageCH2[1200-i]){MaxCH2 = voltageCH2[1200-i];}
					}
				}
	///////////////////////////////////////////////////////////////////////////////////////
				else {
					if(MaxCH2 < voltageCH2[indexing-6+i]){MaxCH2 = voltageCH2[indexing-6+i];}
				}
			}

		  tmp_decibelMaxCH2  = 20*log10(MaxCH2/1.095); //1.5 µsec!!!

		  channel=3;

		  break;
	  case 3:
		  MaxCH3=0.0;
		  for (int i=0; i<6;i++){
	//Exception on overflow when indexing is exact 1 for Channel3//////////////////////////
			if(indexing == 1){
					if(i<2){
						if(MaxCH3 < voltageCH3[i]){MaxCH3 = voltageCH3[i];}
					}else{
						if(MaxCH3 < voltageCH3[1201-i]){MaxCH3 = voltageCH3[1201-i];}
					}
				}
	///////////////////////////////////////////////////////////////////////////////////////
				else {
					if(MaxCH3 < voltageCH3[indexing-6+i]){MaxCH3 = voltageCH3[indexing-6+i];}
				}
			}

		  tmp_decibelMaxCH3  = 20*log10(MaxCH3/1.095); //1.5 µsec!!!


		  channel=4;

		  break;
	  case 4:
		  MaxCH4=0.0;
		  for (int i=0; i<6;i++){
	//Exception on overflow when indexing is exact 2 for Channel4//////////////////////////
			if(indexing == 2){
					if(i<3){
						if(MaxCH4 < voltageCH4[i]){MaxCH4 = voltageCH4[i];}
					}else{
						if(MaxCH4 < voltageCH4[1202-i]){MaxCH4 = voltageCH4[1202-i];}
					}
				}
	///////////////////////////////////////////////////////////////////////////////////////
				else {
					if(MaxCH4 < voltageCH4[indexing-6+i]){MaxCH4 = voltageCH4[indexing-6+i];}
				}
			}


		  tmp_decibelMaxCH4  = 20*log10(MaxCH4/1.095); //1.5 µsec!!!


		  channel=5;

		  break;
	  case 5:
		  MaxCH5=0.0;
		  for (int i=0; i<6;i++){
	//Exception on overflow when indexing is exact 3 for Channel5//////////////////////////
			if(indexing == 3){
					if(i<4){
						if(MaxCH5 < voltageCH5[i]){MaxCH5 = voltageCH5[i];}
					}else{
						if(MaxCH5 < voltageCH5[1203-i]){MaxCH5 = voltageCH5[1203-i];}
					}
				}
	///////////////////////////////////////////////////////////////////////////////////////
				else {
					if(MaxCH5 < voltageCH5[indexing-6+i]){MaxCH5 = voltageCH5[indexing-6+i];}
				}
			}

		  tmp_decibelMaxCH5  = 20*log10(MaxCH5/1.095); //1.5 µsec!!!


		  channel=6;
		  break;
	  case 6:
		  MaxCH6=0.0;
		  for (int i=0; i<6;i++){
	//Exception on overflow when indexing is exact 4 for Channel6//////////////////////////
			if(indexing == 4){
					if(i<5){
						if(MaxCH6 < voltageCH6[i]){MaxCH6 = voltageCH6[i];}
					}else{
						if(MaxCH6 < voltageCH6[1204-i]){MaxCH6 = voltageCH6[1204-i];}
					}
				}
	///////////////////////////////////////////////////////////////////////////////////////
				else {
					if(MaxCH6 < voltageCH6[indexing-6+i]){MaxCH6 = voltageCH6[indexing-6+i];}
				}
			}

		  tmp_decibelMaxCH6  = 20*log10(MaxCH6/1.095); //1.5 µsec!!!




		  channel=1;
		  break;
	  }

	  indexing++;

	  if (indexing > 1199) {
		  indexing = 0;

		 RMS_CH1 = (20*log10((sqrt (sum_CH1/1200))/1.095))+3;
		 RMS_CH2 = (20*log10((sqrt (sum_CH2/1200))/1.095))+3;
		 RMS_CH3 = (20*log10((sqrt (sum_CH3/1200))/1.095))+3;
		 RMS_CH4 = (20*log10((sqrt (sum_CH4/1200))/1.095))+3;
		 RMS_CH5 = (20*log10((sqrt (sum_CH5/1200))/1.095))+3;
		 RMS_CH6 = (20*log10((sqrt (sum_CH6/1200))/1.095))+3;

		  sum_CH1_RMS_long[3]=RMS_CH1;
		  sum_CH2_RMS_long[3]=RMS_CH2;
		  sum_CH3_RMS_long[3]=RMS_CH3;
		  sum_CH4_RMS_long[3]=RMS_CH4;
		  sum_CH5_RMS_long[3]=RMS_CH5;
		  sum_CH6_RMS_long[3]=RMS_CH6;

		  for(int i=0;i<3;i++){
			  sum_CH1_RMS_long[i] = sum_CH1_RMS_long[i+1];
			  sum_CH1_RMS = sum_CH1_RMS + sum_CH1_RMS_long[i];

			  sum_CH2_RMS_long[i] = sum_CH2_RMS_long[i+1];
			  sum_CH2_RMS = sum_CH2_RMS + sum_CH2_RMS_long[i];

			  sum_CH3_RMS_long[i] = sum_CH3_RMS_long[i+1];
			  sum_CH3_RMS = sum_CH3_RMS + sum_CH3_RMS_long[i];

			  sum_CH4_RMS_long[i] = sum_CH4_RMS_long[i+1];
			  sum_CH4_RMS = sum_CH4_RMS + sum_CH4_RMS_long[i];

			  sum_CH5_RMS_long[i] = sum_CH5_RMS_long[i+1];
			  sum_CH5_RMS = sum_CH5_RMS + sum_CH5_RMS_long[i];

			  sum_CH6_RMS_long[i] = sum_CH6_RMS_long[i+1];
			  sum_CH6_RMS = sum_CH6_RMS + sum_CH6_RMS_long[i];

		  }
		  RMS_CH1_long=sum_CH1_RMS/3;
		  RMS_CH2_long=sum_CH2_RMS/3;
		  RMS_CH3_long=sum_CH3_RMS/3;
		  RMS_CH4_long=sum_CH4_RMS/3;
		  RMS_CH5_long=sum_CH5_RMS/3;
		  RMS_CH6_long=sum_CH6_RMS/3;

		  sum_CH1=0.0;
		  sum_CH2=0.0;
		  sum_CH3=0.0;
		  sum_CH4=0.0;
		  sum_CH5=0.0;
		  sum_CH6=0.0;

		  sum_CH1_RMS=0.0;
		  sum_CH2_RMS=0.0;
		  sum_CH3_RMS=0.0;
		  sum_CH4_RMS=0.0;
		  sum_CH5_RMS=0.0;
		  sum_CH6_RMS=0.0;

	  }





	  if (resetMax==1){
	  	resetMax=0;
	  	voltageIn1MAX=0;
	  	voltageIn2MAX=0;
	  	voltageIn3MAX=0;
	  	voltageIn4MAX=0;
	  	voltageIn5MAX=0;
	  	voltageIn6MAX=0;
	  	for (int i=0; i<8;i++){
	  		dbuMAX[i] = -130.0;
	  	}


	}
}
