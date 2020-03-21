
typedef struct osc_message {
  char *format;  // a pointer to the format field
  char adressEND;  // the current read head
  char numberSTART;
  float *number;
  int *integer;
  int len;
} osc_message;



int tosc_parseMessage(osc_message *o, char *buffer, const int len);
