#include <xc.h>

// for calculating delay: Tdelay (seconds) = (Fpb) * 256 * DELAY
// Fpb must be around 500kHz because a delay constant of 500 produces about a
// quarter second delay

#define DELAY1MS   250    // in ms

void delay(int ms);
void initTimer1(void);
