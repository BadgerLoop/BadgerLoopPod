#include <xc.h>                     // processor SFR definitions
#include <sys/attribs.h>            // __ISR macro
#include "hardwareProfile.h"

void USBDebugInit(void);
void ReadUART1(char * string, int maxLength);
void WriteUART1(const char * string);