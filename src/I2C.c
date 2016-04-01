#include "I2C.h"

I2CError I2CStatus;
uint8_t I2CTXBuffer[255];
uint8_t I2CRXBuffer[255];

/*******************************************************************************
 * Function:
 *  I2CError I2CInit()
 *
 * Description:
 *  Initializes the I2C bus. Be sure to set the appropriate #define directives
 *  at the top of the I2C.h file. This includes PB_CLOCK, I2C_CLOCK_FREQ,
 *  and I2C_BUS.
 *
 * Parameters:
 *  None
 * 
 * Returns:
 *  I2CError    - Status of operation
 * 
 ******************************************************************************/
I2CError I2CInit() {
    I2C_BRG = (I2C_CLOCK_FREQ/PB_CLOCK/2) - 2;
    I2C_CONbits.ON = 1;
    return I2CStatus = I2CSuccess;
}

/*******************************************************************************
 * Function:
 *  I2CError I2CDisable()
 *
 * Description:
 *  Disables the I2C bus.
 *
 * Parameters:
 *  None
 * 
 * Returns:
 *  I2CError    - Status of operation
 * 
 ******************************************************************************/
I2CError I2CDisable() {
    I2C_CONbits.ON = 0;
    return I2CStatus = I2CSuccess;
}

/*******************************************************************************
 * Function:
 *  I2CError I2CStart()
 *
 * Description:
 *  Sends a start bit over the bus. When the I2CxCON.SEN bit is set, the PIC32
 *  will send the start bit over the bus and then clear I2CxCON.SEN. This
 *  function will hang the program if a problem occurs and no timeout is set.
 *
 * Parameters:
 *  None
 * 
 * Returns:
 *  I2CError    - Status of operation
 * 
 ******************************************************************************/
I2CError I2CStart() {
    I2C_CONbits.SEN = 1;            // Initiates a START
    _CP0_SET_COUNT(0);
    while (I2C_CONbits.SEN) {
        if (I2CCheckTimeout()) {
            I2CStatus = I2CTimeout;
            printI2CStatus();
            return I2CStatus;
        }
    }
    if (I2C_STATbits.BCL) {
        I2CStatus = I2CBusCollision;
        printI2CStatus();
        return I2CStatus;
    }
    return I2CStatus = I2CSuccess;
}

/*******************************************************************************
 * Function:
 *  I2CError I2CStop()
 *
 * Description:
 *  Sends a stop bit over the bus. When the I2CxCON.PEN bit is set, the PIC32
 *  will send the stop bit over the bus and then clear I2CxCON.PEN. This
 *  function will hang the program if a problem occurs and no timeout is set.
 *
 * Parameters:
 *  None
 * 
 * Returns:
 *  I2CError    - Status of operation
 * 
 ******************************************************************************/
I2CError I2CStop() {
    I2C_CONbits.PEN = 1;
    _CP0_SET_COUNT(0);
    while (I2C_CONbits.PEN && !I2CCheckTimeout()) {
        if (I2CCheckTimeout()) {
            I2CStatus = I2CTimeout;
            printI2CStatus();
            return I2CStatus;
        }
    }  
}

/*******************************************************************************
 * Function:
 *  I2CError I2CRestart()
 *
 * Description:
 *  Sends a restart bit over the bus. When the I2CxCON.RSEN bit is set, the
 *  PIC32 will send the restart bit over the bus and then clear I2CxCON.RSEN.
 *  This function will hang the program if a problem occurs and no timeout is set.
 *
 * Parameters:
 *  None
 * 
 * Returns:
 *  I2CError    - Status of operation
 * 
 ******************************************************************************/
I2CError I2CRestart() {     
    I2C_CONbits.RSEN = 1;
    while (I2C_CONbits.RSEN && !I2CCheckTimeout()) {
        if (I2CCheckTimeout()) {
            I2CStatus = I2CTimeout;
            printI2CStatus();
            return I2CStatus;
        }
    }  
}

/*******************************************************************************
 * Function:
 *  I2CError I2CSendByte(unsigned char data)
 *
 * Description:
 *  Sends a byte of data over the bus.
 *
 * Parameters:
 *  None
 * 
 * Returns:
 *  I2CError    - Status of operation
 * 
 ******************************************************************************/
I2CError I2CSendByte(uint8_t* data) {
    I2C_TRN = *data;
    _CP0_SET_COUNT(0);
    while(I2C_STATbits.TRSTAT && !I2CCheckTimeout()) {
        if (I2CCheckTimeout()) {
            I2CStatus = I2CTimeout;
            printI2CStatus();
            return I2CStatus;
        }
    } 
    if(I2C_STATbits.ACKSTAT) {
        I2CStatus = I2CAcknowledgementNotSent;
        printI2CStatus();
        return I2CStatus;
    }
    return I2CStatus = I2CSuccess;
}

/*******************************************************************************
 * Function:
 *  I2CError I2CReceiveByte(unsigned char* data)
 *
 * Description:
 *  Receives a byte of data and saves in it *data.
 *
 * Parameters:
 *  None
 * 
 * Returns:
 *  I2CError    - Status of operation
 * 
 ******************************************************************************/
I2CError I2CReceiveByte(unsigned char* data) {
    I2C_CONbits.RCEN = 1;
    _CP0_SET_COUNT(0);
    while(!I2C_STATbits.RBF && !I2CCheckTimeout()) {
        if (I2CCheckTimeout()) {
            I2CStatus = I2CTimeout;
            printI2CStatus();
            return I2CStatus;
        }
    }
    *data = I2C_RCV;
    return I2CStatus = I2CSuccess;
}

/*******************************************************************************
 * Function:
 *  I2CError I2CAcknowledge(bool ACK)
 *
 * Description:
 *  Sends an ACK if true, NACK if false.
 *
 * Parameters:
 *  None
 * 
 * Returns:
 *  I2CError    - Status of operation
 * 
 ******************************************************************************/
I2CError I2CAcknowledge(bool ACK) {
    if (ACK) {
        I2C_CONbits.ACKDT = 0;
    } else {
        I2C_CONbits.ACKDT = 1;
    }
    I2C_CONbits.ACKEN = 1;
    _CP0_SET_COUNT(0);
    while(I2C_CONbits.ACKEN && !I2CCheckTimeout()) {
        if (I2CCheckTimeout()) {
            I2CStatus = I2CTimeout;
            printI2CStatus();
            return I2CStatus;
        }
    }
    return I2CStatus = I2CSuccess;
}

/*******************************************************************************
 * Function:
 *  bool I2CCheckTimeout()
 *
 * Description:
 *  Returns true if a timeout has occurred, false otherwise. If I2C_TIMEOUT
 *  is set to 0, this function will always return false.
 *
 * Parameters:
 *  None
 * 
 * Returns:
 *  I2CError    - Status of operation
 * 
 ******************************************************************************/
bool I2CCheckTimeout() {
    if(!I2C_TIMEOUT) {
        return false;
    }
    if(_CP0_GET_COUNT() > I2C_TIMEOUT) {
        return true;
    }
    return false;
}

I2CError I2CWriteBit(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t bitNum, uint8_t data) {
    uint8_t b;
    if (I2CReadByte(deviceAddress, deviceRegister, &b)) {
        return I2CStatus;
    }
    b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
    return I2CWriteByte(deviceAddress, deviceRegister, b);
}

I2CError I2CWriteBits(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t bitStart, uint8_t length, uint8_t data) {
    uint8_t b;
    if (I2CReadByte(deviceAddress, deviceRegister, &b)) {
        return I2CStatus;
    }
    uint8_t mask = ((1 << length) - 1) << (bitStart - length + 1);
    data <<= (bitStart - length + 1);
    data &= mask;
    b &= ~(mask);
    b |= data;
    return I2CWriteByte(deviceAddress, deviceRegister, b);
}

I2CError I2CWriteByte(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t data) {
    uint8_t d[] = {data};
    return I2CWriteBytes(deviceAddress, deviceRegister, 1, d);
}

I2CError I2CWriteBytes(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t numBytes, uint8_t* data) {
    // Prep the I2C TX Buffer with the device address (with write bit) and register.
    I2CTXBuffer[0] = deviceAddress << 1;
    I2CTXBuffer[1] = deviceRegister;
    size_t i;
    size_t iTX = 2;
    for (i = 0; i < numBytes; i++) {
        I2CTXBuffer[iTX] = data[i];
        iTX++;
    }
    uint8_t dataCount = numBytes + 2; // 2 extra, 1 address and 1 register
    
    // Initiate start, if it succeeds the return value will be 0.
    if(I2CStart()) {
        return I2CStatus;
    }
    
    for (i = 0; i < dataCount; i++) {
        if (I2CSendByte((I2CTXBuffer+i))) {
            return I2CStatus;
        }
    }
    
    return I2CStop();
}

I2CError I2CWriteWord(uint8_t deviceAddress, uint8_t deviceRegister, uint16_t data) {
    uint8_t d[2];
    d[0] = (data >> 8) & 0xFF;
    d[1] = data & 0xFF;
    return I2CWriteBytes(deviceAddress, deviceRegister, 2, d);
}

I2CError I2CWriteWords(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t numWords, uint16_t* data) {
    return I2CWriteBytes(deviceAddress, deviceRegister, numWords * 2, (uint8_t*)data);
}

I2CError I2C16bitWriteBit(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t bitNum, uint8_t data) {
    uint8_t b;
    if (I2C16bitReadByte(deviceAddress, deviceRegister, &b)) {
        return I2CStatus;
    }
    b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
    return I2C16bitWriteByte(deviceAddress, deviceRegister, b);
}

I2CError I2C16bitWriteBits(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t bitStart, uint8_t length, uint8_t data) {
    uint8_t b;
    if (I2C16bitReadByte(deviceAddress, deviceRegister, &b)) {
        return I2CStatus;
    }
    uint8_t mask = ((1 << length) - 1) << (bitStart - length + 1);
    data <<= (bitStart - length + 1);
    data &= mask;
    b &= ~(mask);
    b |= data;
    return I2C16bitWriteByte(deviceAddress, deviceRegister, b);
}

I2CError I2C16bitWriteByte(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t data) {
    uint8_t d[] = {data};
    return I2C16bitWriteBytes(deviceAddress, deviceRegister, 1, d);
}

I2CError I2C16bitWriteBytes(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t numBytes, uint8_t* data) {
    // Prep the I2C TX Buffer with the device address (with write bit) and register.
    I2CTXBuffer[0] = deviceAddress << 1;
    I2CTXBuffer[1] = (deviceRegister >> 8) & 0xFF;
    I2CTXBuffer[2] = deviceRegister & 0xFF;
    size_t i;
    size_t iTX = 3;
    for (i = 0; i < numBytes; i++) {
        I2CTXBuffer[iTX] = data[i];
        iTX++;
    }
    uint8_t dataCount = numBytes + 3; // 3 extra, 1 address and 1 register
    
    // Initiate start, if it succeeds the return value will be 0.
    if(I2CStart()) {
        return I2CStatus;
    }
    
    for (i = 0; i < dataCount; i++) {
        if (I2CSendByte((I2CTXBuffer+i))) {
            return I2CStatus;
        }
    }
    
    return I2CStop();
}

I2CError I2C16bitWriteWord(uint8_t deviceAddress, uint16_t deviceRegister, uint16_t data) {
    uint8_t d[2];
    d[0] = (data >> 8) & 0xFF;
    d[1] = data & 0xFF;
    return I2C16bitWriteBytes(deviceAddress, deviceRegister, 2, d);
}

I2CError I2C16bitWriteDWord(uint8_t deviceAddress, uint16_t deviceRegister, uint32_t data) {
    uint8_t d[4];
    d[0] = (data >> 24) & 0xFF;
    d[1] = (data >> 16) & 0xFF;
    d[2] = (data >> 8) & 0xFF;
    d[3] = data & 0xFF;
    return I2C16bitWriteBytes(deviceAddress, deviceRegister, 4, d);
}

I2CError I2CReadBit(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t bitNum, uint8_t* data) {
    uint8_t b;
    if(I2CReadByte(deviceAddress, deviceRegister, &b)) {
        return I2CStatus;
    }
    *data = b & (1 << bitNum);
    return I2CSuccess;
}

I2CError I2CReadBits(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t bitStart, uint8_t length, uint8_t* data) {
    uint8_t b;
    if(I2CReadByte(deviceAddress, deviceRegister, &b)) {
        return I2CStatus;
    }
    uint8_t mask = ((1 << length) - 1) << (bitStart - length + 1);
    b &= mask;
    b >>= (bitStart - length + 1);
    *data = b;
    return I2CSuccess;
}

I2CError I2CReadByte(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t* data) {
    uint8_t d[1];
    if(I2CReadBytes(deviceAddress, deviceRegister, 1, d)) {
        return I2CStatus;
    }
    *data = d[0];
    return I2CSuccess;
}

I2CError I2CReadBytes(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t numBytes, uint8_t* data) {
    // Prep the I2C TX Buffer with the device address (with write bit) and register.
    I2CTXBuffer[0] = deviceAddress << 1;
    I2CTXBuffer[1] = deviceRegister;
    
    // Initial Start
    if(I2CStart()) {
        return I2CStatus;
    }
    
    // Send the address and register we want to read
    if (I2CSendByte(I2CTXBuffer)) {
        return I2CStatus;
    }
    if (I2CSendByte((I2CTXBuffer+1))) {
        return I2CStatus;
    }
    
    // Restart, needed to retrieve the data!
    if(I2CRestart()) {
        return I2CStatus;
    }
    
    I2CTXBuffer[0] = (deviceAddress << 1) + 1;
    if (I2CSendByte(I2CTXBuffer)) {
        return I2CStatus;
    }
    
    size_t i;
    for (i = 0; i < numBytes; i++) {
        if (i != 0) {
            if (I2CAcknowledge(true)) {
                return I2CStatus;
            }
        }
        if (I2CReceiveByte((data+i))) {
            return I2CStatus;
        }
    }
    
    if (I2CAcknowledge(false)) {
        return I2CStatus;
    }
    return I2CStop();
}

I2CError I2CReadWord(uint8_t deviceAddress, uint8_t deviceRegister, uint16_t* data) {
    return I2CReadWords(deviceAddress, deviceRegister, 1, data);
}

I2CError I2CReadWords(uint8_t deviceAddress, uint8_t deviceRegister, uint8_t numWords, uint16_t* data) {
    const uint8_t numBytes = numWords * 2;
    uint8_t d[numBytes];
    if(I2CReadBytes(deviceAddress, deviceRegister, numBytes, d)) {
        return I2CStatus;
    }
    size_t i;
    for (i = 0; i < numBytes; i += 2) {
        *(data+i) = ((d[i] << 8) | d[i+1]) & 0xFFFF;
    }
    return I2CSuccess;
}

I2CError I2C16bitReadByte(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t* data) {
    return I2C16bitReadBytes(deviceAddress, deviceRegister, 1, data);
}

I2CError I2C16bitReadBytes(uint8_t deviceAddress, uint16_t deviceRegister, uint8_t numBytes, uint8_t* data) {
    I2CTXBuffer[0] = deviceAddress << 1;
    I2CTXBuffer[1] = (deviceRegister >> 8) & 0xFF;
    I2CTXBuffer[2] = deviceRegister & 0xFF;
    
    // Initial Start
    if(I2CStart()) {
        return I2CStatus;
    }
    
    // Send the address and register we want to read
    if (I2CSendByte(I2CTXBuffer)) {
        return I2CStatus;
    }
    if (I2CSendByte((I2CTXBuffer+1))) {
        return I2CStatus;
    }
    if (I2CSendByte((I2CTXBuffer+2))) {
        return I2CStatus;
    }
    
    // Restart, needed to retrieve the data!
    if(I2CRestart()) {
        return I2CStatus;
    }
    
    I2CTXBuffer[0] = (deviceAddress << 1) + 1;
    if (I2CSendByte(I2CTXBuffer)) {
        return I2CStatus;
    }
    
    size_t i;
    for (i = 0; i < numBytes; i++) {
        if (i != 0) {
            if (I2CAcknowledge(true)) {
                return I2CStatus;
            }
        }
        if (I2CReceiveByte((data+i))) {
            return I2CStatus;
        }
    }
    
    if (I2CAcknowledge(false)) {
        return I2CStatus;
    }
    return I2CStop();
}

I2CError I2C16bitReadWord(uint8_t deviceAddress, uint16_t deviceRegister, uint16_t* data) {
    return I2C16bitReadBytes(deviceAddress, deviceRegister, 2, (uint8_t*)data);
}

void printI2CStatus() {
    if (I2CStatus == I2CSuccess) {
        ;//println("Success!");
    } else if (I2CStatus == I2CTimeout) {
        println("Timeout!");
    } else if (I2CStatus == I2CBusCollision) {
        println("Bus Collision!");
    } else if (I2CStatus == I2CAcknowledgementNotSent) {
        println("Slave Acknowledgement Not Sent!");
    } else if (I2CStatus == I2CReceiveOverflow) {
        println("Receiver Overflow!");
    }
}