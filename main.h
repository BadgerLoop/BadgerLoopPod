#include <xc.h>
#include <string.h>
#include "config.h"
#include "ledShield.h"
#include "myTimer.h"
#include "usbSerial.h"
#include "I2C.h"

#define SYSCLK      (64000000ul)    // Hz
#define PBCLK       (64000000ul)

int strcasecmp(const char *s1, const char *s2);