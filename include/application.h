extern void adc1_func(int value);
extern void adc2_func(int value);
extern void programStart(void);
extern void communicationReset(void);
extern void programEnd(void);
extern void programAsync(uint16_t timer1msDiff);
extern void program1ms(void);

#define DATA_LED0_DIR   TRISEbits.TRISE0
#define DATA_LED0       LATEbits.LATE0
#define DATA_LED1_DIR   TRISEbits.TRISE1
#define DATA_LED1       LATEbits.LATE1
#define DATA_LED2_DIR   TRISEbits.TRISE2
#define DATA_LED2       LATEbits.LATE2
#define DATA_LED3_DIR   TRISEbits.TRISE3
#define DATA_LED3       LATEbits.LATE3
#define DATA_LED4_DIR   TRISEbits.TRISE4
#define DATA_LED4       LATEbits.LATE4
#define DATA_LED5_DIR   TRISEbits.TRISE5
#define DATA_LED5       LATEbits.LATE5