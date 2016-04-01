#include <xc.h>                     // processor SFR definitions
#include <sys/attribs.h>            // __ISR macro
#include "hardwareProfile.h"

void USBDebugInit(void);
void getMessage(char * string, int maxLength);
void print(const char * string);
void println(const char * string);