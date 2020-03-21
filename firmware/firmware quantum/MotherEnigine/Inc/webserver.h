const char * IPCGIhandler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

const char * LedCGIhandler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

void myCGIinit(void);

u16_t mySSIHandler(int iIndex, char *pcInsert, int iInsertLen);

void mySSIinit(void);

uint8_t IP1,IP2,IP3,IP4;
