#include <xc.h>
#include "main.h"

#define MAX_LENGTH 255

void main(void) {
    DDPCONbits.JTAGEN = 0;
    initTimer1();
    initLEDs();
    beginSerial();
    //ADCinit();
    I2CInit();
    initVL(VL_ADDRESS);
    //initVL(VL_TRANSLATED);
    char message[MAX_LENGTH];
    
    uint8_t myByte = 0; 
    int getData = 1;
    //println("Program started.");
    YELLOW2 = 1;
    while(!readButton());
    YELLOW2 = 0;
    GREEN1 = 1;
    delay(500);
    while (1) {
        if (getData) {
            if (readButton()){
                GREEN1 = 0;
                RED1 = 1;
                getData = 0;
                delay(500);
            }
            myByte = VL_getDistance(VL_ADDRESS);
            sprintf(message, "%d", myByte);
            println(message);
            //delay(100);
        }
        else {
            if (readButton()) {
                GREEN1 = 1;
                RED1 = 0;
                getData = 1;
                delay(500);
            }
        }
        checkSerialErrors();    
    }
}

            //getAndPrintPressureData(PRESSURE_ADDRESS);
            //data = readThermistor(0, 1);
            //sprintf(message, "Reading: %d", data);
            //println(message);
            //delay(500);
            //myByte = VL_getDistance(VL_TRANSLATED);
            //print("VL 2: ");
            //printByte(myByte);
            //println("");