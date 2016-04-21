#include <xc.h>
#include <stdint.h>
#include <cp0defs.h>
#include <stdbool.h>
#include "ledShield.h"
#include "myTimer.h"
#include "usbSerial.h"

#define BRGVAL100k      312ul

// We will be using the core timer. Clocked at 64 MHz, core timer ticks every
// other system clock tick. This makes each tick 31.25 ns, 32 ticks is 1 us,
// so 3.2 million ticks is 0.1 s.
#define I2C_TIMEOUT     3200000ul

void I2Cinit(void);
void I2Cdisable(void);
bool I2CCheckTimeout(void);
void I2CStart(void);
void I2CStop(void);
void I2CRepeatedStart(void);
void I2CSendByte(uint8_t* data);
uint8_t I2CReceiveByte(void);
bool checkACK(void);
bool checkNACK(void);
void sendACK(void);
void sendNACK(void);
void I2CRequestFrom(uint8_t deviceAddress, int numBytes, uint8_t *data);
