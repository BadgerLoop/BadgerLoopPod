#include <xc.h>
#include "main.h"

#define MAX_LENGTH 255

void main(void) {
    DDPCONbits.JTAGEN = 0;
    initTimer1();
    initLEDs();
    beginSerial();
    ADCinit();
    //I2CInit();
    //initVL();
    char message[MAX_LENGTH];
    uint8_t myByte = 0;
    uint8_t sensorAddr = 0x78;
    int i = 0;
    int data = 0;
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
            data = readThermistor(0, 1);
            sprintf(message, "Reading: %d", data);
            println(message);
            delay(500);
            //getAndPrintPressureData(sensorAddr);
            //myByte = VL_getDistance();
            //print("VL: ");
            //printByte(myByte);
            //println("");
            
            
            delay(100);
        }
        checkSerialErrors();
    }
}