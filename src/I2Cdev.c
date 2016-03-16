#include "I2Cdev.h"
#include <peripheral/i2c.h>
#include <hardwareProfile.h>

/*******************************************************************************
  Function:
    BOOL StartTransfer( BOOL restart )

  Summary:
    Starts (or restarts) a transfer to/from the EEPROM.

  Description:
    This routine starts (or restarts) a transfer to/from the EEPROM, waiting (in
    a blocking loop) until the start (or re-start) condition has completed.

  Precondition:
    The I2C module must have been initialized.

  Parameters:
    restart - If FALSE, send a "Start" condition
            - If TRUE, send a "Restart" condition
    
  Returns:
    TRUE    - If successful
    FALSE   - If a collision occured during Start signaling
    
  Example:
    <code>
    StartTransfer(FALSE);
    </code>

  Remarks:
    This is a blocking routine that waits for the bus to be idle and the Start
    (or Restart) signal to complete.
  *****************************************************************************/

BOOL StartTransfer( BOOL restart )
{
    I2C_STATUS  status;

    // Send the Start (or Restart) signal
    if(restart)
    {
        I2CRepeatStart(EEPROM_I2C_BUS);
    }
    else
    {
        // Wait for the bus to be idle, then start the transfer
        while( !I2CBusIsIdle(EEPROM_I2C_BUS) );

        if(I2CStart(EEPROM_I2C_BUS) != I2C_SUCCESS)
        {
            DBPRINTF("Error: Bus collision during transfer Start\n");
            return FALSE;
        }
    }

    // Wait for the signal to complete
    do
    {
        status = I2CGetStatus(EEPROM_I2C_BUS);

    } while ( !(status & I2C_START) );

    return TRUE;
}


/*******************************************************************************
  Function:
    BOOL TransmitOneByte( UINT8 data )

  Summary:
    This transmits one byte to the EEPROM.

  Description:
    This transmits one byte to the EEPROM, and reports errors for any bus
    collisions.

  Precondition:
    The transfer must have been previously started.

  Parameters:
    data    - Data byte to transmit

  Returns:
    TRUE    - Data was sent successfully
    FALSE   - A bus collision occured

  Example:
    <code>
    TransmitOneByte(0xAA);
    </code>

  Remarks:
    This is a blocking routine that waits for the transmission to complete.
  *****************************************************************************/

BOOL TransmitOneByte( UINT8 data )
{
    // Wait for the transmitter to be ready
    while(!I2CTransmitterIsReady(EEPROM_I2C_BUS));

    // Transmit the byte
    if(I2CSendByte(EEPROM_I2C_BUS, data) == I2C_MASTER_BUS_COLLISION)
    {
        DBPRINTF("Error: I2C Master Bus Collision\n");
        return FALSE;
    }

    // Wait for the transmission to finish
    while(!I2CTransmissionHasCompleted(EEPROM_I2C_BUS));

    return TRUE;
}


/*******************************************************************************
  Function:
    void StopTransfer( void )

  Summary:
    Stops a transfer to/from the EEPROM.

  Description:
    This routine Stops a transfer to/from the EEPROM, waiting (in a 
    blocking loop) until the Stop condition has completed.

  Precondition:
    The I2C module must have been initialized & a transfer started.

  Parameters:
    None.
    
  Returns:
    None.
    
  Example:
    <code>
    StopTransfer();
    </code>

  Remarks:
    This is a blocking routine that waits for the Stop signal to complete.
  *****************************************************************************/

void StopTransfer( void )
{
    I2C_STATUS  status;

    // Send the Stop signal
    I2CStop(EEPROM_I2C_BUS);

    // Wait for the signal to complete
    do
    {
        status = I2CGetStatus(EEPROM_I2C_BUS);

    } while ( !(status & I2C_STOP) );
    return;
}

/** Read multiple bytes from an 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr First register regAddr to read from
 * @param length Number of bytes to read
 * @param data Buffer to store read data in
 * @return Number of bytes read (-1 indicates failure)
 */

void init_I2C(void) {
    actualClock = I2CSetFrequency(EEPROM_I2C_BUS, GetPeripheralClock(), I2C_CLOCK_FREQ);
    if ( abs(actualClock-I2C_CLOCK_FREQ) > I2C_CLOCK_FREQ/10 )
    {
        DBPRINTF("Error: I2C1 clock frequency (%u) error exceeds 10%%.\n", (unsigned)actualClock);
    }

    // Enable the I2C bus
    I2CEnable(EEPROM_I2C_BUS, TRUE);
    
}

int8_t I2Cdev_readByte2(uint8_t devAddr, uint16_t regAddr, uint8_t length, uint8_t *data) {

    I2C_FORMAT_7_BIT_ADDRESS(SlaveAddress, devAddr, I2C_WRITE);
    i2cData[0] = SlaveAddress.byte;
    i2cData[1] = (regAddr >> 8);              // EEPROM location to read (high address byte)
    i2cData[2] = (regAddr & 0xFF);            // EEPROM location to read (low address byte)
    DataSz = 3;

    // Start the transfer to read the EEPROM.
    if( !StartTransfer(FALSE) )
    {
        return;
    }

    // Address the EEPROM.
    Index = 0;
    while( Success & (Index < DataSz) )
    {
        // Transmit a byte
        if (TransmitOneByte(i2cData[Index]))
        {
            // Advance to the next byte
            Index++;
        }
        else
        {
            Success = FALSE;
        }

        // Verify that the byte was acknowledged
        if(!I2CByteWasAcknowledged(EEPROM_I2C_BUS))
        {
            DBPRINTF("Error: Sent byte was not acknowledged\n");
            Success = FALSE;
        }
    }
    // Restart and send the EEPROM's internal address to switch to a read transfer
    if(Success)
    {
        // Send a Repeated Started condition
        if( !StartTransfer(TRUE) )
        {
            return;
        }

        // Transmit the address with the READ bit set
        I2C_FORMAT_7_BIT_ADDRESS(SlaveAddress, devAddr, I2C_READ);
        if (TransmitOneByte(SlaveAddress.byte))
        {
            // Verify that the byte was acknowledged
            if(!I2CByteWasAcknowledged(EEPROM_I2C_BUS))
            {
                DBPRINTF("Error: Sent byte was not acknowledged\n");
                Success = FALSE;
            }
        }
        else
        {
            Success = FALSE;
        }
    }

    // Read the data from the desired address
    if(Success)
    {
        if(I2CReceiverEnable(EEPROM_I2C_BUS, TRUE) == I2C_RECEIVE_OVERFLOW)
        {
            DBPRINTF("Error: I2C Receive Overflow\n");
            Success = FALSE;
        }
        else
        {
            int i = 0;
            for (i = 0; i < length; i++)
            {
                while(!I2CReceivedDataIsAvailable(EEPROM_I2C_BUS));
                *(data + i) = I2CGetByte(EEPROM_I2C_BUS);
            }
        }

    }

    // End the transfer (stop here if an error occured)
    StopTransfer();
    if(!Success)
    {
        return;
    }


    // Validate the data read
    if( *(data + 0) != 0xAA )
    {
        DBPRINTF("Error: Verify failed\n");
    }
    else
    {
        DBPRINTF("Success\n");
    }
    return length;
}

int8_t I2Cdev_readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data) {

    return I2Cdev_readByte2(devAddr, (uint16_t)regAddr, length, data);

}


/** Read single byte from an 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register regAddr to read from
 * @param data Container for byte value read from device
 * @return Status of read operation (true = success)
 */
int8_t I2Cdev_readByte(uint8_t devAddr, uint8_t regAddr, uint8_t *data) {
    return I2Cdev_readBytes(devAddr, regAddr, 1, data);
}



/** Read multiple words from a 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr First register regAddr to read from
 * @param length Number of words to read
 * @param data Buffer to store read data in
 * @return Number of words read (-1 indicates failure)
 */
int8_t I2Cdev_readWords(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint16_t *data) {
    return I2Cdev_readByte2(devAddr, (uint16_t) regAddr, length * 2, (uint8_t*)data);
}



/** Read multiple words from a 16-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr First register regAddr to read from
 * @param length Number of words to read
 * @param data Buffer to store read data in
 * @return Number of words read (-1 indicates failure)
 */
int8_t I2Cdev_readWords2(uint8_t devAddr, uint16_t regAddr, uint8_t length, uint16_t *data) {
    return I2Cdev_readByte2(devAddr, regAddr, length * 2, (uint8_t*)data);
}


/** Read single word from a 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register regAddr to read from
 * @param data Container for word value read from device
 * @return Status of read operation (true = success)
 */
int8_t I2Cdev_readWord(uint8_t devAddr, uint8_t regAddr, uint16_t *data) {
    return I2Cdev_readWords(devAddr, regAddr, 1, data);
}

/** Read a single bit from an 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register regAddr to read from
 * @param bitNum Bit position to read (0-7)
 * @param data Container for single bit value
 * @return Status of read operation (true = success)
 */
int8_t I2Cdev_readBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t *data) {
    uint8_t b;
    uint8_t count = I2Cdev_readByte(devAddr, regAddr, &b);
    *data = b & (1 << bitNum);
    return count;
}

/** Read a single bit from a 16-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register regAddr to read from
 * @param bitNum Bit position to read (0-15)
 * @param data Container for single bit value
 * @return Status of read operation (true = success)
 */
int8_t I2Cdev_readBitW(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint16_t *data) {
    uint16_t b;
    uint8_t count = I2Cdev_readWord(devAddr, regAddr, &b);
    *data = b & (1 << bitNum);
    return count;
}

/** Read multiple bits from an 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register regAddr to read from
 * @param bitStart First bit position to read (0-7)
 * @param length Number of bits to read (not more than 8)
 * @param data Container for right-aligned value (i.e. '101' read from any bitStart position will equal 0x05)
 * @return Status of read operation (true = success)
 */
int8_t I2Cdev_readBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t *data) {
    // 01101001 read byte
    // 76543210 bit numbers
    //    xxx   args: bitStart=4, length=3
    //    010   masked
    //   -> 010 shifted
    uint8_t count, b;
    if ((count = I2Cdev_readByte(devAddr, regAddr, &b)) != 0) {
        uint8_t mask = ((1 << length) - 1) << (bitStart - length + 1);
        b &= mask;
        b >>= (bitStart - length + 1);
        *data = b;
    }
    return count;
}

/** Read multiple bits from a 16-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register regAddr to read from
 * @param bitStart First bit position to read (0-15)
 * @param length Number of bits to read (not more than 16)
 * @param data Container for right-aligned value (i.e. '101' read from any bitStart position will equal 0x05)
 * @return Status of read operation (1 = success, 0 = failure, -1 = timeout)
 */
int8_t I2Cdev_readBitsW(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint16_t *data) {
    // 1101011001101001 read byte
    // fedcba9876543210 bit numbers
    //    xxx           args: bitStart=12, length=3
    //    010           masked
    //           -> 010 shifted
    uint8_t count;
    uint16_t w;
    if ((count = I2Cdev_readWord(devAddr, regAddr, &w)) != 0) {
        uint16_t mask = ((1 << length) - 1) << (bitStart - length + 1);
        w &= mask;
        w >>= (bitStart - length + 1);
        *data = w;
    }
    return count;
}

/** Write multiple bytes to an 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr First register address to write to
 * @param length Number of bytes to write
 * @param data Buffer to copy new data from
 * @return Status of operation (true = success)
 */
BOOL I2Cdev_writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t* data) {

    return I2Cdev_writeByte2(devAddr, (uint16_t)regAddr, length, data);

}

BOOL I2Cdev_writeByte2(uint8_t devAddr, uint16_t regAddr, uint8_t length, uint8_t* data) {

    I2C_FORMAT_7_BIT_ADDRESS(SlaveAddress, devAddr, I2C_WRITE);
    i2cData[0] = SlaveAddress.byte;
    i2cData[1] = (regAddr >> 8);              // EEPROM location to read (high address byte)
    i2cData[2] = (regAddr & 0xFF);            // EEPROM location to read (low address byte)

    int i = 0;
    for (i = 0; i < length; i++)
    {
        i2cData[3 + i] = *(data + i); 
    }

    DataSz = 3 + length;

    // Start the transfer to write data to the EEPROM
    if( !StartTransfer(FALSE) )
    {
        return;
    }

    // Transmit all data
    Index = 0;
    while( Success && (Index < DataSz) )
    {
        // Transmit a byte
        if (TransmitOneByte(i2cData[Index]))
        {
            // Advance to the next byte
            Index++;

            // Verify that the byte was acknowledged
            if(!I2CByteWasAcknowledged(EEPROM_I2C_BUS))
            {
                DBPRINTF("Error: Sent byte was not acknowledged\n");
                Success = FALSE;
            }
        }
        else
        {
            Success = FALSE;
        }
    }

    // End the transfer (hang here if an error occured)
    StopTransfer();
    if(!Success)
    {
        return;
    }

    // Wait for EEPROM to complete write process, by polling the ack status.
    Acknowledged = FALSE;
    do
    {
        // Start the transfer to address the EEPROM
        if( !StartTransfer(FALSE) )
        {
            while(1);
        }
        
        // Transmit just the EEPROM's address
        if (TransmitOneByte(SlaveAddress.byte))
        {
            // Check to see if the byte was acknowledged
            Acknowledged = I2CByteWasAcknowledged(EEPROM_I2C_BUS);
        }
        else
        {
            Success = FALSE;
        }

        // End the transfer (stop here if an error occured)
        StopTransfer();
        if(!Success)
        {
            while(1);
        }

    } while (Acknowledged != TRUE);

    return true;
}


/** Write single byte to an 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register address to write to
 * @param data New byte value to write
 * @return Status of operation (true = success)
 */
BOOL I2Cdev_writeByte(uint8_t devAddr, uint8_t regAddr, uint8_t data) {
    return I2Cdev_writeBytes(devAddr, regAddr, 1, data);
}

/** Write multiple words to a 16-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr First register address to write to
 * @param length Number of words to write
 * @param data Buffer to copy new data from
 * @return Status of operation (true = success)
 */
BOOL I2Cdev_writeDWord(uint8_t devAddr, uint16_t regAddr, uint8_t length, uint32_t* data){
    return I2Cdev_writeByte2(devAddr, regAddr, length * 4, (uint8_t*)data);
}

/** Write multiple words to a 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr First register address to write to
 * @param length Number of words to write
 * @param data Buffer to copy new data from
 * @return Status of operation (true = success)
 */
BOOL I2Cdev_writeWords(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint16_t* data) {
    return I2Cdev_writeByte2(devAddr, (uint16_t)regAddr, length * 2, (uint8_t*)data);
}

/** Write multiple words to a 16-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr First register address to write to
 * @param length Number of words to write
 * @param data Buffer to copy new data from
 * @return Status of operation (true = success)
 */
BOOL I2Cdev_writeWord2(uint8_t devAddr, uint16_t regAddr, uint8_t length, uint16_t* data) {
    return I2Cdev_writeByte2(devAddr, regAddr, length * 2, (uint8_t*)data);
}

/** Write single word to a 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register address to write to
 * @param data New word value to write
 * @return Status of operation (true = success)
 */
BOOL I2Cdev_writeWord(uint8_t devAddr, uint8_t regAddr, uint16_t data) {
    return I2Cdev_writeWords(devAddr, regAddr, 1, &data);
}

/** write a single bit in an 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register regAddr to write to
 * @param bitNum Bit position to write (0-7)
 * @param value New bit value to write
 * @return Status of operation (true = success)
 */
BOOL I2Cdev_writeBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t data) {
    uint8_t b;
    I2Cdev_readByte(devAddr, regAddr, &b);
    b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
    return I2Cdev_writeByte(devAddr, regAddr, b);
}

/** write a single bit in a 16-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register regAddr to write to
 * @param bitNum Bit position to write (0-15)
 * @param value New bit value to write
 * @return Status of operation (true = success)
 */
BOOL I2Cdev_writeBitW(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint16_t data) {
    uint16_t w;
    I2Cdev_readWord(devAddr, regAddr, &w);
    w = (data != 0) ? (w | (1 << bitNum)) : (w & ~(1 << bitNum));
    return I2Cdev_writeWord(devAddr, regAddr, w);
}

/** Write multiple bits in an 8-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register regAddr to write to
 * @param bitStart First bit position to write (0-7)
 * @param length Number of bits to write (not more than 8)
 * @param data Right-aligned value to write
 * @return Status of operation (true = success)
 */
BOOL I2Cdev_writeBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t data) {
    //      010 value to write
    // 76543210 bit numbers
    //    xxx   args: bitStart=4, length=3
    // 00011100 mask byte
    // 10101111 original value (sample)
    // 10100011 original & ~mask
    // 10101011 masked | value
    uint8_t b;
    if (I2Cdev_readByte(devAddr, regAddr, &b) != 0) {
        uint8_t mask = ((1 << length) - 1) << (bitStart - length + 1);
        data <<= (bitStart - length + 1); // shift data into correct position
        data &= mask; // zero all non-important bits in data
        b &= ~(mask); // zero all important bits in existing byte
        b |= data; // combine data with existing byte
        return I2Cdev_writeByte(devAddr, regAddr, b);
    } else {
        return false;
    }
}

/** Write multiple bits in a 16-bit device register.
 * @param devAddr I2C slave device address
 * @param regAddr Register regAddr to write to
 * @param bitStart First bit position to write (0-15)
 * @param length Number of bits to write (not more than 16)
 * @param data Right-aligned value to write
 * @return Status of operation (true = success)
 */
BOOL I2Cdev_writeBitsW(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint16_t data) {
    //              010 value to write
    // fedcba9876543210 bit numbers
    //    xxx           args: bitStart=12, length=3
    // 0001110000000000 mask word
    // 1010111110010110 original value (sample)
    // 1010001110010110 original & ~mask
    // 1010101110010110 masked | value
    uint16_t w;
    if (I2Cdev_readWord(devAddr, regAddr, &w) != 0) {
        uint16_t mask = ((1 << length) - 1) << (bitStart - length + 1);
        data <<= (bitStart - length + 1); // shift data into correct position
        data &= mask; // zero all non-important bits in data
        w &= ~(mask); // zero all important bits in existing word
        w |= data; // combine data with existing word
        return I2Cdev_writeWord(devAddr, regAddr, w);
    } else {
        return false;
    }
}
