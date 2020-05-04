
#include "GUI_App.h"
#include "DIALOG.h"
#include "GUI.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "GuiElements/AudioMeter.h"
#include "GuiElements/Controlls.h"
#include "../tasks/SerialHandleTask/UART_IO.h"
#include "recources/buttons/menu.h"

int start=0;
uint32_t lineStart,lineEnd;
uint32_t lineStart2,lineEnd2;
int x=700, y;

TS_StateTypeDef TS_State;

uint8_t runner = 0;
static void _cbDialog(WM_MESSAGE * pMsg) {

  switch (pMsg->MsgId) {
  case WM_PAINT:

    break;
  default:
    WM_DefaultProc(pMsg);

  }
  	  GUI_DCACHE_Clear(0);
	  GUI_Clear();
	  GUI_SetBkColor(GUI_DARKGRAY);






GUI_SetColor( GUI_LIGHTGRAY );






//GUI_DrawBitmap(&bmmaintenance, 665, 8);




  int x1=345;
  x=465;
  //y=-346;


 if(Waveform){
/*
	if(pots[3]<20&&pots[3]>0){
		y=-1146;
	  	for(int i=300; i<400;i++){
	  	   GUI_SetColor( GUI_GRAY );
	  	   GUI_SetColor(GUI_GRAY);
	  	   GUI_DrawHLine(y+(i*4),x1-RightStream[699-i], x1);
	  	   GUI_DrawHLine(y+(i*4),x, x+LeftStream[699-i]);
	  	   }
	}
	if(pots[3]<40&&pots[3]>=20){
		y=-346;
		for(int i=200; i<400;i++){
		   GUI_SetColor( GUI_GRAY );
		   GUI_SetColor(GUI_GRAY);
		   GUI_DrawHLine(y+(i*2),x1-RightStream[599-i], x1);
		   GUI_DrawHLine(y+(i*2),x, x+LeftStream[599-i]);
		   }
	}

	if(pots[3]>=40){
		y=54;
		for(int i=0; i<400;i++){
			GUI_SetColor( GUI_GRAY );
			GUI_SetColor(GUI_GRAY);
			GUI_DrawHLine(y+(i*1),x1-RightStream[399-i], x1);
			GUI_DrawHLine(y+(i*1),x, x+LeftStream[399-i]);
			}
	}
*/
		y=-348;
		for(int i=200; i<400;i++){
		   GUI_SetColor( GUI_GRAY );
		   GUI_SetColor(GUI_GRAY);
		   GUI_DrawHLine(y+(i*2),x1-RightStream[599-i], x1);
		   GUI_DrawHLine(y+(i*2),x, x+LeftStream[599-i]);
		}
 }

	  drawBarDottedVertical (350, 30,val1MAXbuffered/1,val1buffered/1);
	  drawBarDottedVertical (410, 30,val2MAXbuffered/1,val2buffered/1);




  //drawFloatNumber (400, 200, TouchDetected, "", "");

  //drawFloatNumber (300, 200, touch, "", "");

  //drawFloatNumber (20, 220, TouchXCoordinate, "", "");
  //drawFloatNumber (20, 260, TouchYCoordinate, "", "");

 ArcControl(80,160,pots[1],"Attack");
 ArcControl(80,340,pots[2],"Ratio");


 ArcControl(720,160,pots[4],"Volume");
 ArcControl(720,340,pots[3],"Thresh");

 //GUI_DrawBitmap(&bmmenu, 50, 360);

 GUI_AA_SetFactor(3);
 GUI_SetPenSize(30);
 GUI_SetColor(GUI_GRAY);


 static int radius = 400;

 GUI_SetPenSize(30);
 GUI_SetColor(GUI_GRAY);
 GUI_DrawArc(1000, 240, radius, radius, 150, 210);
 //GUI_AA_DrawArc(1000, 240, radius, radius, 150, 210);
 GUI_SetColor(GUI_ORANGE);
 GUI_DrawArc(1000, 240, radius, radius, 150+(250-pots[4]), 210);
 //GUI_AA_DrawArc(1000, 240, radius, radius, 150+(250-pots[4]), 210);


 GUI_SetColor(GUI_GRAY);
 GUI_DrawArc(-200, 240, radius, radius, -30, 30);
 GUI_SetColor(GUI_ORANGE);
 GUI_DrawArc(-200, 240, radius, radius, -30+(250-pots[2]), 30);
 /*

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
 */









  BSP_LED_Toggle(LED3);
}









WM_HWIN CreateMainWindow(void) {

  WM_HWIN Window;

  Window = WM_CreateWindow(0, 0, 1, 1,WM_CF_SHOW, _cbDialog, 0);

  WM_MULTIBUF_Enable(1);

  return Window;
}
