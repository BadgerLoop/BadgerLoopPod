#include "I2C.h"

uint8_t I1CTXBuffer[255];
uint8_t I1CRXBuffer[255];

void I2CInit() {
    I2C1BRG = BRGVAL100k;
    I2C1CONbits.ON = 1;  
}

void I2CDisable() { I2C1CONbits.ON = 0; }

bool I2CCheckTimeout() {
    if (_CP0_GET_COUNT() > I2C_TIMEOUT) return true;
    return false;
}

void I2CStart() {
    _CP0_SET_COUNT(0);
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN && !I2CCheckTimeout());
    if (I2CCheckTimeout()) println("I2C: Start condition timeout.");
}

void I2CStop() { 
    I2C1CONbits.PEN = 1;            // initiate stop on SDA/SCL
    while (I2C1CONbits.PEN && !I2CCheckTimeout());
    if (I2CCheckTimeout()) println("I2C: Stop condition timeout.");
}

void I2CRepeatedStart() {     
    I2C1CONbits.RSEN = 1;
    _CP0_SET_COUNT(0);
    while (I2C1CONbits.RSEN && !I2CCheckTimeout());
    if (I2CCheckTimeout()) println("I2C: Repeated Start condition timeout.");
}

void I2CSendByte(uint8_t* data) {
    if (I2C1STATbits.BCL || I2C1STATbits.IWCOL) println("Bus/write collision during write."); 
    I2C1TRN = *data;
    while (I2C1STATbits.TRSTAT && !I2CCheckTimeout());
    if (I2CCheckTimeout()) println("I2C: Sending Byte timed out.");
}

bool checkACK() { return !I2C1STATbits.ACKSTAT; } // we WANT a 0 (ACK rec)
bool checkNACK() { return I2C1STATbits.ACKSTAT; } // we WANT a 1 (NACK rec)

void sendACK() {
    I2C1CONbits.ACKDT = 0;          // prepare to send ACK 
    I2C1CONbits.ACKEN = 1;          // send ACKDT
    while (I2C1CONbits.ACKEN && !I2CCheckTimeout());
    if (I2CCheckTimeout()) println("I2C: Sending ACK timed out.");
}

void sendNACK() {
    I2C1CONbits.ACKDT = 1;          // prepare to send ACK 
    I2C1CONbits.ACKEN = 1;          // send ACKDT
    while (I2C1CONbits.ACKEN && !I2CCheckTimeout());
    if (I2CCheckTimeout()) println("I2C: Sending ACK timed out.");
}

uint8_t I2CReceiveByte(void) {
    I2C1CONbits.RCEN = 1; 
    while (I2C1CONbits.RCEN && !I2CCheckTimeout());
    if (I2CCheckTimeout()) println("I2C: Receiving Byte timed out.");
    if (!I2C1STATbits.RBF) println("I2C: Receive buffer not full!");
    uint8_t retval;
    retval = I2C1RCV;
    return retval;
}

void I2CRequestFrom(uint8_t deviceAddress, int numBytes, uint8_t* data) {
    I1CTXBuffer[0] = (deviceAddress << 1) + 1; // add one to signify read
    I2CStart();
    I2CSendByte(I1CTXBuffer);
    if (!checkACK()) println("Slave didn't acknowledge.");
    short i = 0;
    for (i = 0; i < numBytes; i++) {
        data[i] = I2CReceiveByte();
        if (i < numBytes - 1) sendACK();
    }
    sendNACK();
    I2CStop();
}

void I2CWriteBytes(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t numBytes, uint8_t *data) {
    // Prep the I2C TX Buffer with the device address (with write bit) and register.
    I1CTXBuffer[0] = deviceAddress << 1;
    I1CTXBuffer[1] = deviceRegister;
    size_t i;
    size_t iTX = 2;
    for (i = 0; i < numBytes; i++) {
        I1CTXBuffer[iTX] = data[i];
        iTX++;
    }
    uint8_t dataCount = numBytes + 2; // 2 extra, 1 address and 1 register
    
    // Initiate start, if it succeeds the return value will be 0.
    I2CStart();   
    for (i = 0; i < dataCount; i++) I2CSendByte((I1CTXBuffer+i)); 
    I2CStop();
}
