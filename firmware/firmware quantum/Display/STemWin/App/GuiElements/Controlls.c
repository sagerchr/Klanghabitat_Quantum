/*
 * Controlls.c
 *
 *  Created on: 16.11.2019
 *      Author: christiansager
 */
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
/*
int pox[6]={0,50,100,150,200,250};
int poy[6]={100,100,100,100,100,100};
const char *header[6] = {"Input","Threshold","Attack","Ratio","Release","Output"};
const char *units[6] = {"dB","dB","ms","","ms","dB"};
*/
int pox[2]={0,200};
int poy[2]={100,100};
const char *header[2] = {"Input","Threshold"};
const char *units[2] = {"dB","dB"};


int delay[6];
int poti[2];

void drawControllBar (int pos_x, int pos_y, float PeakVal,float AvVal,  const char * s ){

		int lastLine = 0;
		int bottomX = 0;

		GUI_SetColor(GUI_LIGHTGRAY);
		for (int i=0; i<25; i++){
				lastLine = pos_x+(i*10);
				GUI_DrawVLine(lastLine+0,pos_y, pos_y+10);
				GUI_DrawVLine(lastLine+5,pos_y, pos_y+5);
			}
			GUI_DrawVLine(lastLine+10,pos_y, pos_y+10);
			bottomX = lastLine+10;

			GUI_DrawGradientV(pos_x, pos_y-10, pos_x+AvVal, pos_y, 0xFFFF8000, 0xFFFFA500);
	}

drawFloatNumber (int pos_x, int pos_y, float val, const char * s, const char * h){

		GUI_GotoXY(pos_x, pos_y);
	  	GUI_DispFloatMin(val, 1);
	  	GUI_SetFont(&GUI_Font24B_1);

	  	if(val < 10.0 && val >= 0) {
	  		GUI_DispStringAt(s, 80+pos_x, 10+pos_y);
	  		}
	    else if (val >= 10.0 || val<0){
	    	GUI_DispStringAt(s, 105+pos_x, 10+pos_y);
	    	}
	  	GUI_SetFont(&GUI_Font32B_1);
	  	GUI_DispStringAt(h, pos_x, pos_y-35);
	  	  }

void ENCODER_UPDATE(){
	for(int i = 1; i<3; i++){
		 if(poti[i]!=pots[i]){
			delay[i] = 50;
		 }
		 if (delay[i]>0){
			 delay[i] --;
			 GUI_SetColor(GUI_ORANGE);
		 }
		 else {GUI_SetColor(GUI_LIGHTGRAY);}

		 poti[i] = pots[i];

		 GUI_SetFont(&GUI_FontD24x32);
		 drawFloatNumber(pox[i],poy[i],poti[i], units[i],header[i]);
		 drawControllBar (pox[i], poy[i]+45,0,poti[i], "");
	}
}


void drawDashedLine(int x0, int y0, int x1, int y1){

	 GUI_SetLineStyle(GUI_LS_DASH);
	 GUI_SetColor(GUI_RED);

	 GUI_DrawLine(x0, y0+1, x1, y1+1);
	 GUI_DrawLine(x0, y0+2, x1, y1+2);
	 GUI_DrawLine(x0, y0+3, x1, y1+3);
	 GUI_DrawLine(x0, y0+4, x1, y1+4);
	 GUI_DrawLine(x0, y0+5, x1, y1+5);
}


void ArcControl(int pos_x, int pos_y, float val,const char * s){



	  GUI_SetPenSize(20);
	  GUI_SetColor(GUI_GRAY);

	  int x0 = pos_x;
	  int y0 = pos_y;
	  static int radius = 50;


	  GUI_DrawArc(x0, y0, radius, radius, -0, 260);

	  float a = (-0+val*1)*3.1415926/180;
	  int x = -radius*cos(a)+x0;
	  int y = -radius*sin(a)+y0;

	  GUI_SetPenSize(20);
	  GUI_SetColor(GUI_ORANGE);
	  GUI_DrawArc(x0, y0, radius, radius, -0+(250-val), 260);

	  GUI_SetColor(GUI_LIGHTGRAY);
	  GUI_SetFont(&GUI_Font24B_1);
      GUI_DispStringAt(s, pos_x-10, pos_y);
	  GUI_GotoXY(pos_x-10, pos_y+25);
	  GUI_DispFloatMin(val, 1);


/*
	  GUI_SetColor(GUI_LIGHTRED);
	  GUI_SetPenSize(40);
	  GUI_DrawPoint(x,y);
*/

}