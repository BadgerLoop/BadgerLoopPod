#include "application.h"

#define DATA_LED0_DIR   TRISEbits.TRISE0
#define DATA_LED0       LATEbits.LATE0
#define DATA_LED1_DIR   TRISEbits.TRISE1
#define DATA_LED1       LATEbits.LATE1

// Makes testing individual parts easy! Comment out what you don't want
#define I2C
//#define MPU9250Test
#define VL6180XTest

#ifdef VL6180XTest
VL6180X mainProx;
#endif

uint32_t dataCount = 0;

/******************************************************************************/
void programStart(void){ 
    
    // Initialize the ADC
    /*
    ADCInit(5, true); // 5Hz (visible testing made easy) and using the Timer
    ADCAdd(0, adc1_func);
    ADCAdd(1, adc2_func);
    */
    
#ifdef I2C
    // Initialize the I2C bus
    //I2CInit();
    init_I2C_Nick();
#endif
    
#ifdef MPU9250Test
    /* Initialize the MPU9250 - default addresses used.*/
    MPU9250(0x68);
    MPU9250Compass(0x0C);
    MPU9250_initialize();
    printI2CStatus();
#endif
    
#ifdef VL6180XTest
    VL6180XInit(&mainProx, 0x29);
    //nick_init(&mainProx, 0x29);
#endif
}

/******************************************************************************/
void programEnd(void){
    // Shutdown functions
}

/******************************************************************************/
void programAsync(uint16_t timer1msDiff){
    
}


/******************************************************************************/
void program100ms(void){
    char output[100] = {};
    
#ifdef MPU9250Test
    int16_t ax, ay, az, gx, gy, gz, mx, my, mz;
    MPU9250_getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
    sprintf(output, "Data Reading %8d: %6d %6d %6d %6d %6d %6d %6d %6d %6d", dataCount, ax, ay, az, gx, gy, gz, mx, my, mz);
    println(output);
#endif
#ifdef VL6180XTest
    uint8_t dis = mainProx.getDistance(&mainProx);
    sprintf(output, "Distance Reading (mm): %3d", dis);
    println(output);
#endif     

#ifdef I2C
    if (I2CStatus == I2CBusCollision) {
        I2CDisable();
        print("Resetting the I2C Bus. :-(");
        _CP0_SET_COUNT(0);
        while (_CP0_GET_COUNT() < 3200000) { // 100ms?
            ;
        }
        //I2CInit();
        init_I2C_Nick();
    }
#endif
    
    dataCount++;
}

void program1ms(void){
}

void adc1_func(int newValue) {
    if (newValue > 128) { //!= temp) {
        DATA_LED0 = !DATA_LED0;
    }
}

void adc2_func(int newValue) {
    if (newValue > 128) { //!= temp) {
        DATA_LED1 = !DATA_LED1;
    }
}