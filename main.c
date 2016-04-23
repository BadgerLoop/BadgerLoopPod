#include <xc.h>
#include "main.h"

#define MAX_LENGTH 255

void main(void) {
    DDPCONbits.JTAGEN = 0;
    initTimer1();
    initLEDs();
    beginSerial();
    I2CInit();
    initVL();
    char message[MAX_LENGTH];
    uint8_t I2Cdata[] = {0x12, 0x23, 0x34, 0x45};
    uint8_t myByte = 0x88;
    uint8_t sensorAddr = 0x78;
    int i = 0;
    println("Program started.");
    while (1) {
        
        // get messages over UART
        if (SerialAvailable()) {
            changeLED(3, 1);
            getMessage(message, MAX_LENGTH);
            delay(200);
            println(message);
            changeLED(3, 0);
        }
        
        if (readButton()) {
            //getAndPrintPressureData(sensorAddr);
            myByte = VL_getDistance();
            print("Byte received: ");
            printByte(myByte);
            println("");
            delay(500);
        }
        checkSerialErrors();
        delay(500);
    }
}