#include "OSC_Lib.h"


int tosc_parseMessage(osc_message *o, char *buffer, const int len) {
  // NOTE(mhroth): if there's a comma in the address, that's weird
  int i = 0;
  while (buffer[i] != '\0') ++i; // find the null-terimated address
  o->adressEND = i; //This is Position where the Adress ends.
  while (buffer[i] != ',') ++i; // find the comma which starts the format string
  if (i >= len) return -1; // error while looking for format string
  o->format = &buffer[i+1]; // Putting Format Information
  while (i < len && buffer[i] != '\0') ++i;
  if (i == len) return -2; // format string not null terminated
  i = (i + 4) & ~0x3; // advance to the next multiple of 4 after trailing '\0'
  o->numberSTART = i;


  o->len = len;

  return 0;
}
