#include <xc.h>                     // processor SFR definitions
#include <stdbool.h>
#include <stdint.h>
#include <cp0defs.h>
#include "USBDebug.h"

#define SYS_CLOCK       64000000ul  // System clock (64MHz for us)
#define PB_CLOCK        64000000ul  // Peripheral clock (64MHz for us)
#define I2C_CLOCK_FREQ  400000      // Typically 100kHz or 400kHz
#define I2C_TIMEOUT     3200000     // In CP0 Ticks. CP0 Ticks are 2/SYS_CLOCK long
                                    // At 64MHz, this is 31.25ns. 32 Ticks is 1us
#define I2C_BUS         1           // PIC32 has 5 I2C busses
#define I2C_READ        1
#define I2C_WRITE       0
// EEPROM Constants
typedef enum
{
#ifdef _I2C1
    // I2C Module 1 ID
    I2C1,
#endif

#ifdef _I2C2
    // I2C Module 2 ID
    I2C2,
#endif

#ifdef _I2C3
    // I2C Module 3 ID
    I2C3,
#endif

#ifdef _I2C4
    // I2C Module 4 ID
    I2C4,
#endif

#ifdef _I2C5
    // I2C Module 5 ID
    I2C5,
#endif

    // Number of available I2C modules.
    I2C_NUMBER_OF_MODULES

} I2C_MODULE;
#define EEPROM_I2C_BUS  I2C1

/* Defines used by the library for determining which I2C bus to use */
#if I2C_BUS == 1
    #define I2C_BRG         I2C1BRG
    #define I2C_CONbits     I2C1CONbits
    #define I2C_TRN         I2C1TRN
    #define I2C_STATbits    I2C1STATbits
    #define I2C_RCV         I2C1RCV
#elif I2C_BUS == 2
    #define I2C_BRG         I2C2BRG
    #define I2C_CONbits     I2C2CONbits
    #define I2C_TRN         I2C2TRN
    #define I2C_STATbits    I2C2STATbits
    #define I2C_RCV         I2C2RCV
#elif I2C_BUS == 3
    #define I2C_BRG         I2C3BRG
    #define I2C_CONbits     I2C3CONbits
    #define I2C_TRN         I2C3TRN
    #define I2C_STATbits    I2C3STATbits
    #define I2C_RCV         I2C3RCV
#elif I2C_BUS == 4
    #define I2C_BRG         I2C4BRG
    #define I2C_CONbits     I2C4CONbits
    #define I2C_TRN         I2C4TRN
    #define I2C_STATbits    I2C4STATbits
    #define I2C_RCV         I2C4RCV
#elif I2C_BUS == 5
    #define I2C_BRG         I2C5BRG
    #define I2C_CONbits     I2C5CONbits
    #define I2C_TRN         I2C5TRN
    #define I2C_STATbits    I2C5STATbits
    #define I2C_RCV         I2C5RCV
#endif

typedef enum {
    I2CSuccess = 0,
    I2CTimeout = 1,
    I2CBusCollision = 2,
    I2CAcknowledgementNotSent = 3,
    I2CReceiveOverflow = 4
} I2CError;

extern I2CError I2CStatus;

I2CError I2CInit();
I2CError I2CDisable();
I2CError I2CStart();
I2CError I2CStop();
I2CError I2CRestart();
I2CError I2CSendByte(uint8_t* data);
I2CError I2CReceiveByte(uint8_t* data);
I2CError I2CAcknowledge(bool ACK);
bool I2CCheckTimeout();
I2CError I2CWriteBit(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t bitNum, uint8_t data);
I2CError I2CWriteBits(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t bitStart, uint8_t length, uint8_t data);
I2CError I2CWriteByte(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t data);
I2CError I2CWriteBytes(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t numBytes, uint8_t* data);
I2CError I2CWriteWord(uint8_t deviceAddress, uint8_t deviceRegister, uint16_t data);
I2CError I2CWriteWords(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t numWords, uint16_t* data);
I2CError I2C16bitWriteBit(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t bitNum, uint8_t data);
I2CError I2C16bitWriteBits(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t bitStart, uint8_t length, uint8_t data);
I2CError I2C16bitWriteByte(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t data);
I2CError I2C16bitWriteBytes(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t numBytes, uint8_t* data);
I2CError I2C16bitWriteWord(uint8_t deviceAddress, uint16_t deviceRegister, uint16_t data);
I2CError I2C16bitWriteDWord(uint8_t deviceAddress, uint16_t deviceRegister, uint32_t data);
I2CError I2CReadBit(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t bitNum, uint8_t* data);
I2CError I2CReadBits(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t bitStart, uint8_t length, uint8_t* data);
I2CError I2CReadByte(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t* data);
I2CError I2CReadBytes(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t numBytes, uint8_t* data);
I2CError I2CReadWord(uint8_t deviceAddress, uint8_t deviceRegister, uint16_t* data);
I2CError I2CReadWords(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t numWords, uint16_t* data);
I2CError I2C16bitReadByte(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t* data);
I2CError I2C16bitReadBytes(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t numBytes, uint8_t* data);
I2CError I2C16bitReadWord(uint8_t deviceAddress, uint16_t deviceRegister, uint16_t* data);
void printI2CStatus();