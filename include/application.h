#include <xc.h>
#include <stdint.h>         /* For UINT32 definition                          */
#include <stdbool.h>        /* For true/false definition                      */

#include "USBDebug.h"
#include "CANopen.h"
#include "CAN.h"
#include "I2C.h"
#include "MPU9250.h"
#include "VL6180X.h"


extern void adc1_func(int value);
extern void adc2_func(int value);
extern void programStart(void);
extern void communicationReset(void);
extern void programEnd(void);
extern void programAsync(uint16_t timer1msDiff);
extern void program1ms(void);
extern void program100ms(void);