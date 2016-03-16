#include "CANopen.h"
#include <xc.h>
//#include <plib.h>
#include <stdint.h>         /* For UINT32 definition                          */
#include <stdbool.h>        /* For true/false definition                      */
#include <MPU6050.h>
#include "application.h"
#include "CAN.h"

/* Global variables */

/******************************************************************************/
void programStart(void){ 
    
    // Initialize CAN
    CANinit();
    
    /* Initialize test LEDs*/
    DATA_LED0_DIR = 0; DATA_LED0 = 0;
    DATA_LED1_DIR = 0; DATA_LED1 = 0;
    DATA_LED2_DIR = 0; DATA_LED2 = 0;
    DATA_LED3_DIR = 0; DATA_LED3 = 0;
    DATA_LED4_DIR = 0; DATA_LED4 = 0;
    DATA_LED5_DIR = 0; DATA_LED5 = 0;
    
    // Initialize the ADC code
    //ADCInit(5, true); // 5Hz (visible testing made easy) and using the Timer
    //ADCAdd(0, adc1_func);
    //ADCAdd(1, adc2_func);
    
    init_I2C(); //Start I2C
    MPU6050(MPU6050_DEFAULT_ADDRESS);
    MPU6050_initialize();
    int16_t ax, ay, az, gx, gy, gz; //MPU6050 values
    ay = 11;
    MPU6050_getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    uint8_t MPUAccelRange = MPU6050_getFullScaleAccelRange();
}

/******************************************************************************/
void programEnd(void){
    // Shutdown functions
}

/******************************************************************************/
void programAsync(uint16_t timer1msDiff){
    
}


/******************************************************************************/
void program1ms(void){
    /*MPU6050_getMotion6(&MPUData.ax, &MPUData.ay, &MPUData.az, &MPUData.gx, &MPUData.gy, &MPUData.gz);
    if (MPUData.ay > 0) {
        DATA_LED0 = 1;
    } else {
        DATA_LED0 = 0;
    }*/
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