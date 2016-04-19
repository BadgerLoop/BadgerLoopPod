// These are mostly for testing and may have different values later. - Steve

// CAN LEDs
#define CAN_RUN_LED_DIR     TRISDbits.TRISD5
#define CAN_RUN_LED         LATDbits.LATD5
#define CAN_ERROR_LED_DIR   TRISBbits.TRISB13
#define CAN_ERROR_LED       LATBbits.LATB13
#define CAN_STATUS_LED_DIR  TRISGbits.TRISG8
#define CAN_STATUS_LED      LATGbits.LATG8

// CAN Buttons
#define CAN_BUTTON0_DIR     TRISDbits.TRISD10
#define CAN_BUTTON0         PORTDbits.RD10
#define CAN_BUTTON1_DIR     TRISBbits.TRISB11
#define CAN_BUTTON1         PORTBbits.RB11

extern void CANinit(void);
extern void CANReset(void);
extern void CANEnd(void);
extern void CANAsync(uint16_t timer1msDiff);
extern void CAN1ms(void);