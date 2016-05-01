#include <xc.h>
#include "main.h"

#define MAX_LENGTH 255

//extern numOverflow;
//extern presses;

//volatile int time1 = 0;
//volatile int time2 = 0;
//volatile int frequency = 0;

uint8_t byte1 = 0;
uint8_t byte2 = 0;
uint8_t pressureData[4];
int thermistorData = 0;

int calculateTemperatureEquation(void)
{
    int resistance = 10000;
    float voltage = (readThermistor(60, 61))*(1/310);
    float inputVoltage = 3.3;
    float thermistorResistance;
    float inverseTemperature;
    int temperature;
//    float a = 1.032935491E-3;
//    float b = 2.384223307E-4;
//    float c = 1.601529131E-7;
    float a = 1.02450504524715E-3;
    float b = 2.40087964067526E-4;
    float c = 1.49079434102731E-7;
    
    thermistorResistance = resistance*((inputVoltage*resistance - voltage*
            (2*resistance))/(inputVoltage*resistance + voltage*(2*resistance)));
    
    inverseTemperature = a + b*log(thermistorResistance) + 
            c*(pow(log(thermistorResistance), 3));
    
    temperature = (int)1/inverseTemperature;
    return temperature;
}

void main(void) {
    
    DDPCONbits.JTAGEN = 0;
    initTimer1();
    initLEDs();
    beginSerial();
    ADCinit();
    
    TRISB = 1;  // all port B is input
    
    //I2CInit();
    //initVL(VL_ADDRESS);
    //initVL(VL_TRANSLATED);
    
    //inputCapInit();
    
    char message[MAX_LENGTH];
    
    println("Program started.");
    
    YELLOW2 = 1;
    while(!readButton());                       // push to start
    YELLOW2 = 0;
    GREEN1 = 1;
    delay(500);
    
    //startTimer2();
    println("Voltage Difference (10 bit resolution, 0-3.3V)");
    while (1) {
        sprintf(message, "%d", readADC(PORTBbits.RB0));
        println(message);
        delay(500);
        
        //byte1 = VL_getDistance(VL_ADDRESS);
        //byte2 = VL_getDistance(VL_TRANSLATED);
        //sprintf(message, "VL1: %d VL2: %d", byte1, byte2);
        //println(message);
        //getPressureData(PRESSURE_ADDRESS, pressureData);
        //printPressureData(pressureData);
        //delay(500);
        
        
        
        //while(!inputAvailable());
        //time1 = getInput();
        //while(!inputAvailable());
        //time2 = getInput();
        //frequency = 250000 / time2;
        //sendByte((frequency & 0xff00) >> 8);
        //sendByte(frequency & 0xff);
        //sprintf(message, "%d", frequency);
        //println(message);
    }
}
