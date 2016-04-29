#include "inputCapture.h"

void inputCapInit(void) {
    // first setup timer2
    T2CONbits.TCKPS = 7;        // 1:256 = 250000 Hz
    T2CONbits.ON = 1;
    
    // Input Capture 1 (Pin 48 on Max32)
    TRISDbits.TRISD8 = 1;
    
    IC1CON = 0;
    IC1CONbits.ICM = 3;         // every rising edge
    //mIC1CLearIntFlag();
    
    IC1CONbits.ON = 1;          // turn the module on
}

int inputCheckOverflow(void) {
    return IC1CONbits.ICOV;
}

int inputCheckAvailable(void) {
    return IC1CONbits.ICBNE;
}

void __ISR (_INPUT_CAPTURE_1_VECTOR, ipl1) IC1Interrupt (void) {
    
}