#include "I2C.h"

uint8_t I1CTXBuffer[255];
uint8_t I1CRXBuffer[255];
char message[255];

void I2CInit() {
    I2C1BRG = BRGVAL100k;
    I2C1CONbits.ON = 1;  
}

void I2CDisable() { I2C1CONbits.ON = 0; }

bool I2CCheckTimeout() {
    if (_CP0_GET_COUNT() > I2C_TIMEOUT) return true;
    return false;
}

void IdleI2C1(void) { while(I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RCEN || I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT); }

void I2CStart() {
    IdleI2C1();
    _CP0_SET_COUNT(0);
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN && !I2CCheckTimeout());
    if (I2CCheckTimeout()) println("I2C: Start condition timeout.");
}

void I2CStop() {
    _CP0_SET_COUNT(0);
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
    _CP0_SET_COUNT(0);
    while (I2C1STATbits.TBF);
    if (I2C1STATbits.BCL || I2C1STATbits.IWCOL) {
        println("Bus/write collision during write. Aborting write."); // it won't do it anyways
        return;
    }
    I2C1TRN = *data;
    while (I2C1STATbits.TRSTAT && !I2CCheckTimeout());
    if (I2CCheckTimeout()) println("I2C: Sending Byte timed out.");
}

bool checkACK() { return !I2C1STATbits.ACKSTAT; } // we WANT a 0 (ACK rec)
bool checkNACK() { return I2C1STATbits.ACKSTAT; } // we WANT a 1 (NACK rec)

void sendACK() {
    _CP0_SET_COUNT(0);
    I2C1CONbits.ACKDT = 0;          // prepare to send ACK 
    I2C1CONbits.ACKEN = 1;          // send ACKDT
    while (I2C1CONbits.ACKEN && !I2CCheckTimeout());
    if (I2CCheckTimeout()) println("I2C: Sending ACK timed out.");
}

void sendNACK() {
    _CP0_SET_COUNT(0);
    I2C1CONbits.ACKDT = 1;          // prepare to send ACK 
    I2C1CONbits.ACKEN = 1;          // send ACKDT
    while (I2C1CONbits.ACKEN && !I2CCheckTimeout());
    if (I2CCheckTimeout()) println("I2C: Sending ACK timed out.");
}

uint8_t I2CReceiveByte(void) {
    _CP0_SET_COUNT(0);
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

void I2CwriteByteToRegister(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t data) {
    uint8_t i = 0;
    I1CTXBuffer[0] = deviceAddress << 1;
    I1CTXBuffer[1] = (deviceRegister & 0xff00) >> 8;
    I1CTXBuffer[2] = deviceRegister & 0x00ff;
    I1CTXBuffer[3] = data;
    I2CStart();
    for (i = 0; i < 4; i++) {
        I2CSendByte((I1CTXBuffer+i));
        if (!checkACK) {
            sprintf(message, "Sensor %d didn't acknowledge byte %d.", deviceAddress, i);
            println(message);
        }
    }
    I2CStop();
}

uint8_t I2CReadByteFromRegister(uint8_t deviceAddress, uint16_t deviceRegister) {
    uint8_t i = 0;
    I1CTXBuffer[0] = deviceAddress << 1;
    I1CTXBuffer[1] = (deviceRegister & 0xff00) >> 8;
    I1CTXBuffer[2] = deviceRegister & 0x00ff;
    I2CStop();
    I2CStart();
    for (i = 0; i < 3; i++) {
        I2CSendByte((I1CTXBuffer+i));
        if (!checkACK) {
            sprintf(message, "Sensor %d didn't acknowledge byte %d.", deviceAddress, i);
            println(message);
        }
    }
    I2CStop();
    I1CTXBuffer[0] = (deviceAddress << 1) + 1; // set read indication
    I2CStart();
    I2CSendByte(I1CTXBuffer); 
    if (!checkACK) {
            sprintf(message, "Sensor %d didn't acknowledge its address + read indication.", deviceAddress);
            println(message);
        }
    i = I2CReceiveByte();
    sendACK();
    I2CStop();
    return i;
}

void I2CReadConsecutiveRegisters(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t numBytes, uint8_t *data) {
    uint8_t i = 0;
    I1CTXBuffer[0] = deviceAddress << 1;
    I1CTXBuffer[1] = (deviceRegister & 0xff00) >> 8;
    I1CTXBuffer[2] = deviceRegister & 0x00ff;
    I2CStart();
    for (i = 0; i < 3; i++) {
        I2CSendByte((I1CTXBuffer+i));
        if (!checkACK) {
            sprintf(message, "Sensor %d didn't acknowledge byte %d.", deviceAddress, i);
            println(message);
        }
    }
    I2CStop();
    delay(10);
    I2CStart();
    I1CTXBuffer[0] = I1CTXBuffer[0] + 1; // read indication
    I2CSendByte(I1CTXBuffer);
    if (!checkACK) {
        sprintf(message, "Sensor %d didn't acknowledge byte %d.", deviceAddress, i);
        println(message);
    }
    for (i = 0; i < numBytes; i++) {
        *(data + i) = I2CReceiveByte();
        sendACK();
    }
    I2CStop();
}

void I2CwriteWordToRegister(uint8_t deviceAddress, uint16_t deviceRegister, uint16_t data) {
    uint8_t i = 0;
    I1CTXBuffer[0] = deviceAddress << 1;
    I1CTXBuffer[1] = (deviceRegister & 0xff00) >> 8;
    I1CTXBuffer[2] = deviceRegister & 0x00ff;
    I1CTXBuffer[3] = (data & 0xff00) >> 8;
    I1CTXBuffer[4] = data & 0x00ff;
    I2CStart();
    for (i = 0; i < 5; i++) {
        I2CSendByte((I1CTXBuffer+i));
        if (!checkACK) {
            sprintf(message, "Sensor %d didn't acknowledge byte %d.", deviceAddress, i);
            println(message);
        }
    }
    I2CStop();
}
