#include "ADC.h"

// TAD = 2 * TPB = 2/64000000

void ADCinit(void) {
    AD1CON1bits.ON = 1;
}

void ADCIdle(void) {
    while (AD1CON1bits.SAMP || AD1CON1bits.DONE);
}

void ADCstartSampling(void) {
    ADCIdle();
    AD1CON1bits.SAMP = 1;
}

int ADCgetData(void) {
    while (!AD1CON2bits.BUFS);   // ADC is filling lower bits
    // get lower bits
    while (AD1CON2bits.BUFS);   // ADC is filling upper bits
    
}

void setReadingA(int a) {
    AD1CHSbits.CH0NA = a;
}

void setReadingB(int b) {
    AD1CHSbits.CH0NB = b;
}