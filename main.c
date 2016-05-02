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
    //inputCapInit();
    
    char message[MAX_LENGTH];
    
    println("Program started.");
    
    YELLOW2 = 1;
    while(!readButton());                       // push to start
    YELLOW2 = 0;
    GREEN1 = 1;
    delay(500);
    uint8_t distanceData = 0x00;
    while (1) {
        // VL Testing
        distanceData = VL_getDistance(VL_ADDRESS);
        sprintf(message, "Distance: %d", distanceData);
        println(message);
        if (I2CcheckError()) I2CprintError();
        delay(1000);
    }
}
