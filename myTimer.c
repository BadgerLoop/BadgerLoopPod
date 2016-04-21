#include "myTimer.h"

void delay(int ms) {
    int i = 0;
    for (i = 0; i < ms; i++) {
        TMR1 = 0;
        while (TMR1 < DELAY1MS);
    }
}

void initTimer1(void) {
    TMR1 = 0;
    T1CON = 0x8030;
    PR1 = 0xffff;
}
