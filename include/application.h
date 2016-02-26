extern void delayzz(void);
extern void programStart(void);
extern void communicationReset(void);
extern void programEnd(void);
extern void ledChange(void);
extern void programAsync(uint16_t timer1msDiff);
extern void program1ms(void);

// CAN LEDs
#define CAN_RUN_LED_DIR     TRISDbits.TRISD5
#define CAN_RUN_LED         LATDbits.LATD5
#define CAN_ERROR_LED_DIR   TRISBbits.TRISB13
#define CAN_ERROR_LED       LATBbits.LATB13
#define CAN_STATUS_LED_DIR  TRISGbits.TRISG8
#define CAN_STATUS_LED      LATGbits.LATG8

#define CAN_RPD0_LED0_DIR   TRISEbits.TRISE2
#define CAN_RPD0_LED0       LATEbits.LATE2
#define CAN_RPD0_LED1_DIR   TRISEbits.TRISE3
#define CAN_RPD0_LED1       LATEbits.LATE3
#define CAN_RPD0_LED2_DIR   TRISEbits.TRISE4
#define CAN_RPD0_LED2       LATEbits.LATE4
#define CAN_RPD0_LED3_DIR   TRISEbits.TRISE5
#define CAN_RPD0_LED3       LATEbits.LATE5
#define CAN_RPD0_LED4_DIR   TRISEbits.TRISE6
#define CAN_RPD0_LED4       LATEbits.LATE6
#define CAN_RPD0_LED5_DIR   TRISEbits.TRISE7
#define CAN_RPD0_LED5       LATEbits.LATE7

// CAN Buttons
#define CAN_BUTTON0_DIR     TRISDbits.TRISD10
#define CAN_BUTTON0         PORTDbits.RD10
#define CAN_BUTTON1_DIR     TRISBbits.TRISB11
#define CAN_BUTTON1         PORTBbits.RB11
