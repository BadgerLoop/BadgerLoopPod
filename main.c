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
        
        // Honeywell Pressure Sensor
        //
        //HPprintPressureData();
        //if (I2CcheckError()) I2CprintError(); 
        
        // VL Testing
        //
        distanceData = VL_getDistance(VL_ADDRESS);
        sprintf(message, "Distance: %d", distanceData);
        println(message);
        if (I2CcheckError()) I2CprintError();
        delay(1000);
    }
}

// This code was for the Retro DAQ demo
//
//while(!inputAvailable());
//time1 = getInput();
//while(!inputAvailable());
//time2 = getInput();
//frequency = 250000 / time2;
//sendByte((frequency & 0xff00) >> 8);
//sendByte(frequency & 0xff);
//sprintf(message, "%d", frequency);
//println(message);
