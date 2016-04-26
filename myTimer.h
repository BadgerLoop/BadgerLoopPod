#include <xc.h>

// for calculating delay: Tdelay (seconds) = (Tpb) * 8 * DELAY

#define DELAY1MS        8000
#define DELAY1US        8
#define T1CONSETTING    0x8010      // 1:8 prescale

void delay(int ms);
void delay1us(int us);
void initTimer1(void);
