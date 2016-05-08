#include <xc.h>
#include "main.h"

#define MAX_LENGTH 255

// variables
int run = 0;
char message[MAX_LENGTH];

void initializers(void) {
    DDPCONbits.JTAGEN = 0;
    initTimer1();
    initLEDs();
    initSPI();
    beginSerial();
    //ADCinit();
    //I2CInit();
    //initVL(VL_ADDRESS);
    //initVL(VL_TRANSLATED);
    //inputCapInit();
    TRISFbits.TRISF0 = 0;
}

int getBoardNumber(void) {
    switch(EMAC1SA0) {
        case MAC1: return 1;
        case MAC2: return 2;
        case MAC3: return 3;
        case MAC4: return 4;
        default: return -1;
    }
}

void printMAC(void) {
    sprintf(message, "MAC: %x", EMAC1SA0);
    println(message);
}

void printBoardNumber() {
    sprintf(message, "Board %d connected.", getBoardNumber());
    println(message);
}

void waitForButton(void) {
    println("Press button to continue.");
    YELLOW2 = 1;
    while(!readButton());                       // push to start
    YELLOW2 = 0;
}

int main(void) {
    initializers();
    LATFbits.LATF0 = 0;
    println("Program started.");
    printBoardNumber();
    waitForButton();
    GREEN1 = 1;
    //int i = 1;
    while (1) {
        //for (i = 1; i < 11; i++) {
            sendDACsignal(1023, 1);
            LATFbits.LATF0 = 1;
            delay1us(250);
            LATFbits.LATF0 = 0;
            delay(100);
            waitForButton();
            
            sendDACsignal(1, 1);
            LATFbits.LATF0 = 1;
            delay1us(250);
            LATFbits.LATF0 = 0;
            delay(100);
            waitForButton();
        //}
    }
    return 0;
}
