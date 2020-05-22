#include "main.h"

#include "valueTable.h"

#include "../tasks/SerialHandleTask/UART_IO.h"

void BUFFERVALUEUPDATE(){


	  if (i_inputLeft_Indicator > i_inputLeft_Indicator_bufferd){i_inputLeft_Indicator_bufferd = i_inputLeft_Indicator;}
	  else {i_inputLeft_Indicator_bufferd -=0.01*(i_inputLeft_Indicator_bufferd-i_inputLeft_Indicator);}

	  if (i_inputLeft_Waveform > i_inputLeft_Indicator_MAXbufferd){i_inputLeft_Indicator_MAXbufferd = i_inputLeft_Indicator;}
	  else {i_inputLeft_Indicator_MAXbufferd -=0.001*(i_inputLeft_Indicator_MAXbufferd-i_inputLeft_Indicator);}


	  if (i_inputRight_Indicator > i_inputRight_Indicator_bufferd){i_inputRight_Indicator_bufferd = i_inputRight_Indicator;}
	  else {i_inputRight_Indicator_bufferd -=0.01*(i_inputRight_Indicator_bufferd-i_inputRight_Indicator);}

	  if (i_inputRight_Indicator > i_inputRight_Indicator_MAXbufferd){i_inputRight_Indicator_MAXbufferd = i_inputRight_Indicator;}
	  else {i_inputRight_Indicator_MAXbufferd -=0.001*(i_inputRight_Indicator_MAXbufferd-i_inputRight_Indicator);}


	  if (i_outputLeft_Indicator > i_outputLeft_Indicator_bufferd){i_outputLeft_Indicator_bufferd = i_outputLeft_Indicator;}
	  else {i_outputLeft_Indicator_bufferd -=0.01*(i_outputLeft_Indicator_bufferd-i_outputLeft_Indicator);}

	  if (i_outputLeft_Indicator> i_outputLeft_Indicator_MAXbufferd){i_outputLeft_Indicator_MAXbufferd = i_outputLeft_Indicator;}
	  else {i_outputLeft_Indicator_MAXbufferd -=0.001*(i_outputLeft_Indicator_MAXbufferd-i_outputLeft_Indicator);}


	  if (i_outputRight_Indicator > i_outputRight_Indicator_bufferd){i_outputRight_Indicator_bufferd = i_outputRight_Indicator;}
	  else {i_outputRight_Indicator_bufferd -=0.01*(i_outputRight_Indicator_bufferd-i_outputRight_Indicator);}

	  if (i_outputRight_Indicator > i_outputRight_Indicator_MAXbufferd){i_outputRight_Indicator_MAXbufferd = i_outputRight_Indicator;}
	  else {i_outputRight_Indicator_MAXbufferd -=0.001*(i_outputRight_Indicator_MAXbufferd-i_outputRight_Indicator);}


//*****************************************************************************************************************//
//***********************************INPUT SECTION FLOAT BUFFERED***********************************************************//
//*****************************************************************************************************************//


/////////INPUT LEFT
	  float diff1=0;
	  diff1 = (f_inputLeft_DB_bufferd-f_inputLeft_DB);
	  if(diff1<0){diff1=(-1)*diff1;}
	  if (f_inputLeft_DB > f_inputLeft_DB_bufferd){f_inputLeft_DB_bufferd = f_inputLeft_DB;}
	  else {f_inputLeft_DB_bufferd -=p_Bufferd*diff1;}

	  float diff2=0;
	  diff2 = (f_inputLeft_DB_MAXbufferd-f_inputLeft_DB);
	  if(diff2<0){diff2=(-1)*diff2;}
	  if (f_inputLeft_DB > f_inputLeft_DB_MAXbufferd){f_inputLeft_DB_MAXbufferd = f_inputLeft_DB;}
	  else {f_inputLeft_DB_MAXbufferd -=p_MAXBufferd*diff2;}
/////////INPUT RIGHT
	  float diff3=0;
	  diff3 = (f_inputRight_DB_bufferd-f_inputRight_DB);
	  if(diff3<0){diff3=(-1)*diff3;}
	  if (f_inputRight_DB > f_inputRight_DB_bufferd){f_inputRight_DB_bufferd = f_inputRight_DB;}
	  else {f_inputRight_DB_bufferd -=p_Bufferd*diff3;}

	  float diff4=0;
	  diff4 = (f_inputRight_DB_MAXbufferd-f_inputRight_DB);
	  if(diff4<0){diff4=(-1)*diff4;}
	  if (f_inputRight_DB > f_inputRight_DB_MAXbufferd){f_inputRight_DB_MAXbufferd = f_inputRight_DB;}
	  else {f_inputRight_DB_MAXbufferd -=p_MAXBufferd*diff4;}

/////////INPUT LEFT_RMS
	  float diff5=0;
	  diff5 = (f_inputLeft_DB_RMS_bufferd-f_inputLeft_DB_RMS);
	  if(diff5<0){diff5=(-1)*diff5;}
	  if (f_inputLeft_DB_RMS > f_inputLeft_DB_RMS_bufferd){f_inputLeft_DB_RMS_bufferd = f_inputLeft_DB_RMS;}
	  else {f_inputLeft_DB_RMS_bufferd -=p_Bufferd*diff5;}

	  float diff6=0;
	  diff6 = (f_inputLeft_DB_RMS_MAXbufferd-f_inputLeft_DB_RMS);
	  if(diff6<0){diff6=(-1)*diff6;}
	  if (f_inputLeft_DB_RMS > f_inputLeft_DB_RMS_MAXbufferd){f_inputLeft_DB_RMS_MAXbufferd = f_inputLeft_DB_RMS;}
	  else {f_inputLeft_DB_RMS_MAXbufferd -=p_MAXBufferd*diff6;}
/////////INPUT RIGHT_RMS
	  float diff7=0;
	  diff7 = (f_inputRight_DB_RMS_bufferd-f_inputRight_DB_RMS);
	  if(diff7<0){diff7=(-1)*diff7;}
	  if (f_inputRight_DB_RMS > f_inputRight_DB_RMS_bufferd){f_inputRight_DB_RMS_bufferd = f_inputRight_DB_RMS;}
	  else {f_inputRight_DB_RMS_bufferd -=p_Bufferd*diff7;}

	  float diff8=0;
	  diff8 = (f_inputRight_DB_RMS_MAXbufferd-f_inputRight_DB_RMS);
	  if(diff8<0){diff8=(-1)*diff8;}
	  if (f_inputRight_DB_RMS > f_inputRight_DB_RMS_MAXbufferd){f_inputRight_DB_RMS_MAXbufferd = f_inputRight_DB_RMS;}
	  else {f_inputRight_DB_RMS_MAXbufferd -=p_MAXBufferd*diff8;}

//*****************************************************************************************************************//
//*****************************************************************************************************************//
//*****************************************************************************************************************//

/////////VCA LEFT
	  float diff9=0;
	  diff9 = (f_VCALeft_DB_bufferd-f_VCALeft_DB);
	  if(diff9<0){diff9=(-1)*diff9;}
	  if (f_VCALeft_DB > f_VCALeft_DB_bufferd){f_VCALeft_DB_bufferd = f_VCALeft_DB;}
	  else {f_VCALeft_DB_bufferd -=p_Bufferd*diff9;}

	  float diff10=0;
	  diff10 = (f_VCALeft_DB_MAXbufferd-f_VCALeft_DB);
	  if(diff10<0){diff10=(-1)*diff10;}
	  if (f_VCALeft_DB > f_VCALeft_DB_MAXbufferd){f_VCALeft_DB_MAXbufferd = f_VCALeft_DB;}
	  else {f_VCALeft_DB_MAXbufferd -=p_MAXBufferd*diff10;}
/////////VCA RIGHT
	  float diff11=0;
	  diff11 = (f_VCARight_DB_bufferd-f_VCARight_DB);
	  if(diff11<0){diff11=(-1)*diff11;}
	  if (f_VCARight_DB > f_VCARight_DB_bufferd){f_VCARight_DB_bufferd = f_VCARight_DB;}
	  else {f_VCARight_DB_bufferd -=p_Bufferd*diff11;}

	  float diff12=0;
	  diff12 = (f_VCARight_DB_MAXbufferd-f_VCARight_DB);
	  if(diff12<0){diff12=(-1)*diff12;}
	  if (f_VCARight_DB > f_VCARight_DB_MAXbufferd){f_VCARight_DB_MAXbufferd = f_VCARight_DB;}
	  else {f_VCARight_DB_MAXbufferd -=p_MAXBufferd*diff12;}

/////////VCA LEFT RMS
	  float diff13=0;
	  diff13 = (f_VCALeft_DB_RMS_bufferd-f_VCALeft_DB_RMS);
	  if(diff13<0){diff13=(-1)*diff13;}
	  if (f_VCALeft_DB_RMS > f_VCALeft_DB_RMS_bufferd){f_VCALeft_DB_RMS_bufferd = f_VCALeft_DB_RMS;}
	  else {f_VCALeft_DB_RMS_bufferd -=p_Bufferd*diff13;}

	  float diff14=0;
	  diff14 = (f_VCALeft_DB_RMS_MAXbufferd-f_VCALeft_DB_RMS);
	  if(diff14<0){diff14=(-1)*diff14;}
	  if (f_VCALeft_DB_RMS > f_VCALeft_DB_RMS_MAXbufferd){f_VCALeft_DB_RMS_MAXbufferd = f_VCALeft_DB_RMS;}
	  else {f_VCALeft_DB_RMS_MAXbufferd -=p_MAXBufferd*diff14;}
/////////VCA RIGHT RMS
	  float diff15=0;
	  diff15 = (f_VCARight_DB_RMS_bufferd-f_VCARight_DB_RMS);
	  if(diff15<0){diff15=(-1)*diff15;}
	  if (f_VCARight_DB_RMS > f_VCARight_DB_RMS_bufferd){f_VCARight_DB_RMS_bufferd = f_VCARight_DB_RMS;}
	  else {f_VCARight_DB_RMS_bufferd -=p_Bufferd*diff15;}

	  float diff16=0;
	  diff16 = (f_VCARight_DB_RMS_MAXbufferd-f_VCARight_DB_RMS);
	  if(diff16<0){diff16=(-1)*diff16;}
	  if (f_VCARight_DB_RMS > f_VCARight_DB_RMS_MAXbufferd){f_VCARight_DB_RMS_MAXbufferd = f_VCARight_DB_RMS;}
	  else {f_VCARight_DB_RMS_MAXbufferd -=p_MAXBufferd*diff16;}

//*****************************************************************************************************************//
//*****************************************************************************************************************//
//*****************************************************************************************************************//

	  float diff=0;
/////////OUTPUT LEFT
	  diff=0;
	  diff = (f_outputLeft_DB_bufferd-f_outputLeft_DB);
	  if(diff<0){diff=(-1)*diff;}
	  if (f_outputLeft_DB > f_outputLeft_DB_bufferd){f_outputLeft_DB_bufferd = f_outputLeft_DB;}
	  else {f_outputLeft_DB_bufferd -=p_Bufferd*diff;}

	  diff=0;
	  diff = (f_outputLeft_DB_MAXbufferd-f_outputLeft_DB);
	  if(diff<0){diff=(-1)*diff;}
	  if (f_outputLeft_DB > f_outputLeft_DB_MAXbufferd){f_outputLeft_DB_MAXbufferd = f_outputLeft_DB;}
	  else {f_outputLeft_DB_MAXbufferd -=p_MAXBufferd*diff;}
/////////OUTPUT RIGHT
	  diff=0;
	  diff = (f_outputRight_DB_bufferd-f_outputRight_DB);
	  if(diff<0){diff=(-1)*diff;}
	  if (f_outputRight_DB > f_outputRight_DB_bufferd){f_outputRight_DB_bufferd = f_outputRight_DB;}
	  else {f_outputRight_DB_bufferd -=p_Bufferd*diff;}

	  diff=0;
	  diff = (f_outputRight_DB_MAXbufferd-f_outputRight_DB);
	  if(diff<0){diff=(-1)*diff;}
	  if (f_outputRight_DB > f_outputRight_DB_MAXbufferd){f_outputRight_DB_MAXbufferd = f_outputRight_DB;}
	  else {f_outputRight_DB_MAXbufferd -=p_MAXBufferd*diff;}

/////////OUTPUT LEFT RMS
	  diff=0;
	  diff = (f_outputLeft_DB_RMS_bufferd-f_outputLeft_DB_RMS);
	  if(diff<0){diff=(-1)*diff;}
	  if (f_outputLeft_DB_RMS > f_outputLeft_DB_RMS_bufferd){f_outputLeft_DB_RMS_bufferd = f_outputLeft_DB_RMS;}
	  else {f_outputLeft_DB_RMS_bufferd -=p_Bufferd*diff;}

	  diff=0;
	  diff = (f_outputLeft_DB_RMS_MAXbufferd-f_outputLeft_DB_RMS);
	  if(diff<0){diff=(-1)*diff;}
	  if (f_outputLeft_DB_RMS > f_outputLeft_DB_RMS_MAXbufferd){f_outputLeft_DB_RMS_MAXbufferd = f_outputLeft_DB_RMS;}
	  else {f_outputLeft_DB_RMS_MAXbufferd -=p_MAXBufferd*diff;}
/////////OUTPUT RIGHT RMS
	  diff=0;
	  diff = (f_outputRight_DB_RMS_bufferd-f_outputRight_DB_RMS);
	  if(diff<0){diff=(-1)*diff;}
	  if (f_outputRight_DB_RMS > f_outputRight_DB_RMS_bufferd){f_outputRight_DB_RMS_bufferd = f_outputRight_DB_RMS;}
	  else {f_outputRight_DB_RMS_bufferd -=p_Bufferd*diff;}

	  diff=0;
	  diff = (f_outputRight_DB_RMS_MAXbufferd-f_outputRight_DB_RMS);
	  if(diff<0){diff=(-1)*diff;}
	  if (f_outputRight_DB_RMS > f_outputRight_DB_RMS_MAXbufferd){f_outputRight_DB_RMS_MAXbufferd = f_outputRight_DB_RMS;}
	  else {f_outputRight_DB_RMS_MAXbufferd -=p_MAXBufferd*diff;}




		for(int i=0; i<50; i++){
			if (f_spectrumLeft_bufferd[i]<UARTDATA[i+50]){f_spectrumLeft_bufferd[i] = UARTDATA[i+50];}
			else {f_spectrumLeft_bufferd[i] -=p_Bufferd*(f_spectrumLeft_bufferd[i]-UARTDATA[i+50]);}
		}
}

