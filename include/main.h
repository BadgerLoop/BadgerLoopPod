/* CANopen Macros */
#define CO_TMR_TMR          TMR2             /* TMR register */
#define CO_TMR_PR           PR2              /* Period register */
#define CO_TMR_CON          T2CON            /* Control register */
#define CO_TMR_ISR_FLAG     IFS0bits.T2IF    /* Interrupt Flag bit */
#define CO_TMR_ISR_PRIORITY IPC2bits.T2IP    /* Interrupt Priority */
#define CO_TMR_ISR_ENABLE   IEC0bits.T2IE    /* Interrupt Enable bit */

#define CO_CAN_ISR() void __ISR(_CAN_1_VECTOR, IPL5SOFT) CO_CAN1InterruptHandler(void)
#define CO_CAN_ISR_FLAG     IFS1bits.CAN1IF  /* Interrupt Flag bit */
#define CO_CAN_ISR_PRIORITY IPC11bits.CAN1IP /* Interrupt Priority */
#define CO_CAN_ISR_ENABLE   IEC1bits.CAN1IE  /* Interrupt Enable bit */

#define CO_CAN_ISR2() void __ISR(_CAN_2_VECTOR, IPL5SOFT) CO_CAN2InterruptHandler(void)
#define CO_CAN_ISR2_FLAG     IFS1bits.CAN2IF  /* Interrupt Flag bit */
#define CO_CAN_ISR2_PRIORITY IPC11bits.CAN2IP /* Interrupt Priority */
#define CO_CAN_ISR2_ENABLE   IEC1bits.CAN2IE  /* Interrupt Enable bit */

#define CO_clearWDT() (WDTCONSET = _WDTCON_WDTCLR_MASK)
