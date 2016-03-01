/******************************************************************************/
/*  Files to Include                                                          */
/******************************************************************************/
#include <xc.h>          /* Defines special funciton registers, CP0 regs  */
#include <stdint.h>         /* For uint32_t definition                        */
#include <stdbool.h>        /* For true/false definition                      */
#include <sys/attribs.h>        /* for interrupts */

#include "configuration_bits.h"
#include "main.h"
#include "system.h"
#include "user.h"

/* Code added by njaunich */
#include "application.h"
#define CO_NO_CAN_MODULES 1
#include "CANopen.h"

/* Global variables and objects */
    volatile uint16_t CO_timer1ms = 0U; /* variable increments each millisecond */
    const CO_CANbitRateData_t   CO_CANbitRateData[8] = {CO_CANbitRateDataInitializers};

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint32_t <variable_name>; */
    uint8_t test = 0;
/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

/* helpers */
void CANrx_lockCbSync(bool_t syncReceived) {
    if(syncReceived) {
        CO_CAN_ISR_ENABLE = 0;
        CO_CAN_ISR2_ENABLE = 0;
    }
}

int32_t main(void)
{
    
    /* Don't touch this! Ideally, this function should not change
     * when programming each specific module of the pod. This 
     * function should be the same for everyone. - Steve*/

    /* TODO Add user clock/system configuration code if appropriate. 
     * sys_freq and pb_clk added for verification of speeds when
     * debugging. Can be removed later! - Steve */
    //unsigned int sys_freq = SYS_FREQ;
    //unsigned int pb_clk = SYSTEMConfigPerformance(SYS_FREQ);
    INTCONbits.MVEC = 1; // Multi-vector mode
    DDPCONbits.JTAGEN = 0; // Disable JTAG (Not used by us!)
    DDPCONbits.TROEN = 0; // Disable Trace
    

    /* Below is code added by njaunich */
    unsigned int temp_ui;
    CO_NMT_reset_cmd_t reset = CO_RESET_NOT;
    
    __builtin_enable_interrupts();

    /* Verify, if OD structures have proper alignment of initial values */
    if(CO_OD_RAM.FirstWord != CO_OD_RAM.LastWord) while(1) CO_clearWDT();
    if(CO_OD_EEPROM.FirstWord != CO_OD_EEPROM.LastWord) while(1) CO_clearWDT();
    if(CO_OD_ROM.FirstWord != CO_OD_ROM.LastWord) while(1) CO_clearWDT();

    programStart();

    while(reset != CO_RESET_APP){
/* CANopen communication reset - initialize CANopen objects *******************/
        CO_ReturnError_t err;
        uint16_t timer1msPrevious;
        uint16_t TMR_TMR_PREV = 0;
        uint8_t nodeId;
        uint16_t CANBitRate;

        /* disable CAN and CAN interrupts */
        CO_CAN_ISR_ENABLE = 0;
        CO_CAN_ISR2_ENABLE = 0;

        /* Read CANopen Node-ID and CAN bit-rate from object dictionary */
        nodeId = OD_CANNodeID;
        if(nodeId<1 || nodeId>127) nodeId = 0x10;
        
        // The following two lines changes the nodeID's of my two PIC32's so I can
        // stop doing it manually. EMAC1SA0 refers to the last two octets of the 
        // Ethernet MAC address. This won't change anyone elses stuff...  - Steve
        // Side Note: We could potentially use something like this to use the same
        // code to program every microcontroller!
        if(EMAC1SA0 == 0x000056C4) nodeId = 0x40;
        if(EMAC1SA0 == 0x000040DF) nodeId = 0x41;
        
        CANBitRate = OD_CANBitRate;/* in kbps */

        /* initialize CANopen */
        err = CO_init(ADDR_CAN1, nodeId, CANBitRate);
        if(err != CO_ERROR_NO){
            while(1) CO_clearWDT();
            /* CO_errorReport(CO->em, CO_EM_MEMORY_ALLOCATION_ERROR, CO_EMC_SOFTWARE_INTERNAL, err); */
        }

        /* Configure callback functions */
        CO_SYNC_initCallback(CO->SYNC, CANrx_lockCbSync);


        /* initialize variables */
        timer1msPrevious = CO_timer1ms;
        OD_performance[ODA_performance_mainCycleMaxTime] = 0;
        OD_performance[ODA_performance_timerCycleMaxTime] = 0;
        reset = CO_RESET_NOT;



        /* Configure Timer interrupt function for execution every 1 millisecond */
        CO_TMR_CON = 0;
        CO_TMR_TMR = 0;
        #if CO_PBCLK > 65000
            #error Wrong Timer Config!
        #endif
        CO_TMR_PR = CO_PBCLK - 1;  /* Period register */
        CO_TMR_CON = 0x8000;       /* start timer (TON=1) */
        CO_TMR_ISR_FLAG = 0;       /* clear interrupt flag */
        CO_TMR_ISR_PRIORITY = 3;   /* interrupt - set lower priority than CAN (set the same value in interrupt) */

        /* Configure CAN1 Interrupt (Combined) */
        CO_CAN_ISR_FLAG = 0;       /* CAN1 Interrupt - Clear flag */
        CO_CAN_ISR_PRIORITY = 5;   /* CAN1 Interrupt - Set higher priority than timer (set the same value in '#define CO_CAN_ISR_PRIORITY') */
        CO_CAN_ISR2_FLAG = 0;      /* CAN2 Interrupt - Clear flag */
        CO_CAN_ISR2_PRIORITY = 5;  /* CAN Interrupt - Set higher priority than timer (set the same value in '#define CO_CAN_ISR_PRIORITY') */


        CANReset();


        /* start CAN and enable interrupts */
        CO_CANsetNormalMode(CO->CANmodule[0]);
        CO_TMR_ISR_ENABLE = 1;
        CO_CAN_ISR_ENABLE = 1;

#if CO_NO_CAN_MODULES >= 2
        CO_CANsetNormalMode(CO->CANmodule[1]);
        CO_CAN_ISR2_ENABLE = 1;
#endif


        while(reset == CO_RESET_NOT){
/* loop for normal program execution ******************************************/
            uint16_t timer1msCopy, timer1msDiff;

            CO_clearWDT();


            /* calculate cycle time for performance measurement */
            timer1msCopy = CO_timer1ms;
            timer1msDiff = timer1msCopy - timer1msPrevious;
            timer1msPrevious = timer1msCopy;
            uint16_t t0 = CO_TMR_TMR;
            uint16_t t = t0;
            if(t >= TMR_TMR_PREV){
                t = t - TMR_TMR_PREV;
                t = (timer1msDiff * 100) + (t / (CO_PBCLK / 100));
            }
            else if(timer1msDiff){
                t = TMR_TMR_PREV - t;
                t = (timer1msDiff * 100) - (t / (CO_PBCLK / 100));
            }
            else t = 0;
            OD_performance[ODA_performance_mainCycleTime] = t;
            if(t > OD_performance[ODA_performance_mainCycleMaxTime])
                OD_performance[ODA_performance_mainCycleMaxTime] = t;
            TMR_TMR_PREV = t0;


            /* Application asynchronous program */
            CANAsync(timer1msDiff);

            CO_clearWDT();


            /* CANopen process */
            reset = CO_process(CO, timer1msDiff, NULL);

            CO_clearWDT();
        }
    }


/* program exit ***************************************************************/
//    CO_DISABLE_INTERRUPTS();

    /* delete objects from memory */
    programEnd();
    CANEnd();
    CO_delete(ADDR_CAN1);

    /* reset */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
    RSWRSTSET = 1;
    temp_ui = RSWRST;
    while(1);
}

/* timer interrupt function executes every millisecond ************************/
#ifndef USE_EXTERNAL_TIMER_1MS_INTERRUPT
void __ISR(_TIMER_2_VECTOR, IPL3SOFT) CO_TimerInterruptHandler(void){

    CO_TMR_ISR_FLAG = 0;

    CO_timer1ms++;

    if(CO->CANmodule[0]->CANnormal) {
        bool_t syncWas;

        /* Process Sync and read inputs */
        syncWas = CO_process_SYNC_RPDO(CO, 1000);

        /* Re-enable CANrx, if it was disabled by SYNC callback */
        CO_CAN_ISR_ENABLE = 1;
#if CO_NO_CAN_MODULES >= 2
        CO_CAN_ISR2_ENABLE = 1;
#endif

        /* Further I/O or nonblocking application code may go here. */
        CAN1ms();
        
        /* Write outputs */
        CO->TPDO[1]->sendRequest = 1;
        uint8_t dataToSend = test;
        CO->TPDO[1]->mapPointer[0] = &dataToSend;
        test++;
        CO_process_TPDO(CO, syncWas, 1000);

        /* verify timer overflow */
        if(CO_TMR_ISR_FLAG == 1){
            CO_errorReport(CO->em, CO_EM_ISR_TIMER_OVERFLOW, CO_EMC_SOFTWARE_INTERNAL, 0);
            CO_TMR_ISR_FLAG = 0;
        }
   }

    /* calculate cycle time for performance measurement */
    uint16_t t = CO_TMR_TMR / (CO_PBCLK / 100);
    OD_performance[ODA_performance_timerCycleTime] = t;
    if(t > OD_performance[ODA_performance_timerCycleMaxTime])
        OD_performance[ODA_performance_timerCycleMaxTime] = t;
}
#endif


/* CAN interrupt function *****************************************************/
CO_CAN_ISR(){
    CO_CANinterrupt(CO->CANmodule[0]);

    /* Clear combined Interrupt flag */
    CO_CAN_ISR_FLAG = 0;
}


#if CO_NO_CAN_MODULES >= 2
CO_CAN_ISR2(){
    CO_CANinterrupt(CO->CANmodule[1]);
    /* Clear combined Interrupt flag */
    CO_CAN_ISR2_FLAG = 0;
}
#endif