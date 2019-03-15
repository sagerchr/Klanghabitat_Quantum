//Arduino Uno (host controller) + uLCD-32PTU (serial slave device) Basic Demo
//4D Systems: http://www.4dsystems.com.au
//December 13, 2013

//Demonstrates how to display images on a 4D display module using an Arduino host
//You need to configure the display module as a serial slave
//For more information, see the documentation for this sketch: 
//4D-AN-P5005 Serial Displaying Images using an Arduino Host
//http://www.4dsystems.com.au/appnotes/

//This demo is based on the BiGDemo in Workshop
//File --> Samples --> Picaso Serial --> Arduino <open README.txt for instructions on installing the library>
//See the BigDemo sketch for a demonstration of all the SPE functions
//All functions are defined in the PICASO Serial Command Set Reference Manual
//http://www.4dsystems.com.au/downloads/Software/4D-Workshop4-IDE/Docs/Serial/PICASO-SPE-COMMAND-SET-REV1.13.pdf

#include "Picaso_Serial_4DLib.h"
#include "Picaso_const4D.h"

//Setup communication - 1.Hardware serial OR 2.Software serial

//1. Hardware Serial - choose a serial port
//---------------------------------------------------------
//Serial0 cannot be used for the display since it will be used for logging messages
#define DisplaySerial Serial1
//#define DisplaySerial Serial2
//#define DisplaySerial Serial3
//---------------------------------------------------------

//2. Software Serial - set the desired pins
//----------------------------------------------------------------------
//#include <SoftwareSerial.h>
//SoftwareSerial DisplaySerial(10,11) ; // pin 10 = TX of display, pin 11 = RX
//SoftwareSerial is not yet supported by the Arduino Due
//----------------------------------------------------------------------

//use DisplaySerial to communicate with the display.
Picaso_Serial_4DLib Display(&DisplaySerial); 

//enable message logging
#define LOG_MESSAGES  // <-- to disable message logging, comment out this line
#ifdef LOG_MESSAGES
#define HWLOGGING Serial
#else
#define HWLOGGING if (1) {} else Serial
#endif

//global variables
int frame = 0;
int disk;
word hndl;
int iUserimages1 = 0, iUserimages2 = 1, iImage1 = 2;

void setup() {
  //For handling errors
  Display.Callback4D = mycallback ;

  //5 second timeout on all commands  
  Display.TimeLimit4D   = 5000 ;

#ifdef LOG_MESSAGES
  HWLOGGING.begin(115200);
  HWLOGGING.println(F("\nDisplay Images using an Arduino Host Demo w/ Message Logging"));
#endif
  
  //--------------------------------Optional reset routine-----------------------------------
  //Reset the Display using D4 of the Arduino (if using the new 4D Arduino Adaptor - Rev 2)
  //If using the old 4D Arduino Adaptor (Rev 1), change D4 to D2 below.
  //If using jumper wires, reverse the logic states below. 
  //Refer to the accompanying application note for important information.
  pinMode(4, OUTPUT);  // Set D4 on Arduino to Output (4D Arduino Adaptor V2 - Display Reset)
  digitalWrite(4, 1);  // Reset the Display via D4
  delay(100);
  digitalWrite(4, 0);  // unReset the Display via D4
  //-----------------------------------------END---------------------------------------------
  
  delay (5000); //let the display start up  

  //start
  DisplaySerial.begin(9600) ; 
  Display.gfx_ScreenMode(PORTRAIT);

  //uSD card mount routine
  Display.putstr("Mounting...\n");  //print a string
  if(!(disk = Display.file_Mount()))
  {
    while(!(disk = Display.file_Mount()))
    {
      Display.putstr("Drive not mounted...");
      delay(200);
      Display.gfx_Cls();
      delay(200);
    }
  }

  Display.gfx_BGcolour(WHITE) ; //change background color to white
  Display.gfx_Cls();            //clear the screen
  
  //load the graphics files
  hndl = Display.file_LoadImageControl("user_img.dat", "user_img.gci", 1) ;

  Display.img_Show(hndl,iImage1) ;               //show the penguin
  Display.gfx_Set(TRANSPARENCY, ON);             //turn on transparency
  Display.gfx_Set(TRANSPARENT_COLOUR, 0x3000);   //make this color transparent

  Display.img_SetWord(hndl, iUserimages1, IMAGE_INDEX, frame) ; //where frame is 0 to 4
  Display.img_Show(hndl,iUserimages1) ;                         //show the left eye

  Display.img_SetWord(hndl, iUserimages2, IMAGE_INDEX, frame) ; // where frame is 0 to 4
  Display.img_Show(hndl,iUserimages2) ;                         //show the right eye
  
  Display.txt_BGcolour(WHITE); //change text background colour to white (default is black)
  Display.txt_FGcolour(BLACK); //change text foreground colour to black (default is green)
  Display.txt_MoveCursor(23, 6); //move text cursor to and start printing at row 23, col 6
}

void loop() {  
  static int n = 1;  //counter 
  
  frame = 0;   //eyes open
  Display.img_SetWord(hndl, iUserimages1, IMAGE_INDEX, frame) ; // left eye
  Display.img_Show(hndl,iUserimages1) ;
  Display.img_SetWord(hndl, iUserimages2, IMAGE_INDEX, frame) ; // right eye
  Display.img_Show(hndl,iUserimages2) ;
  Display.putstr("  Robot is happy.  \r");
  delay(2000);

  frame = 1;   //eyes closed
  Display.img_SetWord(hndl, iUserimages1, IMAGE_INDEX, frame) ; // left eye
  Display.img_Show(hndl,iUserimages1) ;
  Display.img_SetWord(hndl, iUserimages2, IMAGE_INDEX, frame) ; // right eye
  Display.img_Show(hndl,iUserimages2) ;
  delay(100);

  frame = 2;   //eyes sad
  Display.img_SetWord(hndl, iUserimages1, IMAGE_INDEX, frame) ; // left eye
  Display.img_Show(hndl,iUserimages1) ;
  Display.img_SetWord(hndl, iUserimages2, IMAGE_INDEX, frame) ; // right eye
  Display.img_Show(hndl,iUserimages2) ;
  Display.putstr("   Robot is sad.   \r");
  delay(2000);

  frame = 1;  //eyes closed
  Display.img_SetWord(hndl, iUserimages1, IMAGE_INDEX, frame) ; // left eye
  Display.img_Show(hndl,iUserimages1) ;
  Display.img_SetWord(hndl, iUserimages2, IMAGE_INDEX, frame) ; // right eye
  Display.img_Show(hndl,iUserimages2) ;
  delay(100);

  frame = 3;   //eyes surprised
  Display.img_SetWord(hndl, iUserimages1, IMAGE_INDEX, frame) ; // left eye
  Display.img_Show(hndl,iUserimages1) ;
  Display.img_SetWord(hndl, iUserimages2, IMAGE_INDEX, frame) ; // right eye
  Display.img_Show(hndl,iUserimages2) ;
  Display.putstr("Robot is surprised.\r");
  delay(2000);

  frame = 1;  //eyes closed
  Display.img_SetWord(hndl, iUserimages1, IMAGE_INDEX, frame) ; // left eye
  Display.img_Show(hndl,iUserimages1) ;
  Display.img_SetWord(hndl, iUserimages2, IMAGE_INDEX, frame) ; // right eye
  Display.img_Show(hndl,iUserimages2) ;
  delay(100);

  frame = 4;   //eyes angry
  Display.img_SetWord(hndl, iUserimages1, IMAGE_INDEX, frame) ; // left eye
  Display.img_Show(hndl,iUserimages1) ;
  Display.img_SetWord(hndl, iUserimages2, IMAGE_INDEX, frame) ; // right eye
  Display.img_Show(hndl,iUserimages2) ;
  Display.putstr("  Robot is angry.  \r");
  delay(2000);

  frame = 1;  //eyes closed
  Display.img_SetWord(hndl, iUserimages1, IMAGE_INDEX, frame) ; // left eye
  Display.img_Show(hndl,iUserimages1) ;
  Display.img_SetWord(hndl, iUserimages2, IMAGE_INDEX, frame) ; // right eye
  Display.img_Show(hndl,iUserimages2) ;
  delay(100);   

#ifdef LOG_MESSAGES
  HWLOGGING.print(F("\nCount = "));
  HWLOGGING.print(n);
#endif
  n++;
}

//Error-handling routine
//this will execute when a communication error occurs
void mycallback(int ErrCode, unsigned char Errorbyte)
{
#ifdef LOG_MESSAGES
  const char *Error4DText[] = {
    "OK\0", "Timeout\0", "NAK\0", "Length\0", "Invalid\0"  } 
  ;
  HWLOGGING.print(F("Serial 4D Library reports an error: ")) ;
  HWLOGGING.print(Error4DText[ErrCode]) ;
  HWLOGGING.print(F("\n"));

  if (ErrCode == Err4D_NAK)
  {
    HWLOGGING.print(F("returned data = ")) ;
    HWLOGGING.print(Errorbyte) ;
  }
  else
    HWLOGGING.println(F("")) ;

  HWLOGGING.println(F("Program cannot proceed further. Please reset the display.")) ;
  while(1) ; // you can return here, or you can loop

#else
  // Pin 13 has an LED connected on most Arduino boards. Just give it a name
  int led = 13;
  pinMode(led, OUTPUT);
  while(1)
  {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);                // wait for 200 ms
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(200);                // wait for 200 ms
  }
#endif
}
