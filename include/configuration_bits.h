/******************************************************************************/
/* Configuration Bits                                                         */
/*                                                                            */
/* Refer to 'C32 Configuration Settings' under the Help > Contents            */
/* > C32 Toolchain in MPLAB X IDE for available C32 PIC32 Configurations. For */
/* additional information about what the hardware configurations mean in      */
/* terms of device operation, refer to the device datasheet 'Special Features'*/
/* chapter. XC32 documentation is available under Help > Contents >           */
/* XC32 C Compiler.                                                           */
/*                                                                            */
/* A feature of MPLAB X is the 'Generate Source Code to Output' utility in    */
/* the Configuration Bits window.  Under Window > PIC Memory Views >          */
/* Configuration Bits, a user controllable configuration bits window is       */
/* available to Generate Configuration Bits source code which the user can    */
/* paste into this project.                                                   */
/******************************************************************************/

/* TODO Fill in your configuration bits from the config bits generator here.  */

    #pragma config FNOSC    = PRIPLL                        // Oscillator Selection
    #pragma config POSCMOD  = XT     //HS                       // Primary Oscillator
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_16 //20                        // PLL multiplier
    #pragma config FPLLODIV = DIV_1                        // PLL output divider
    #pragma config FPBDIV   = DIV_2                         // Peripheral bus clock divider
    #pragma config FSOSCEN  = OFF                           // Secondary Oscillator Enable

    //*    Clock control settings
    #pragma config IESO     = OFF   //ON                         // Internal/External Switch-over
    #pragma config FCKSM    = CSDCMD                        // Clock Switching & Fail Safe Clock Monitor
    #pragma config OSCIOFNC = OFF                           // CLKO Enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                           // Watchdog Timer
    #pragma config WDTPS    = PS1024                        // Watchdog Timer Postscale

    //*    Code Protection settings
    #pragma config CP       = OFF                           // Code Protect
    #pragma config BWP      = OFF                           // Boot Flash Write Protect
    #pragma config PWP      = OFF                           // Program Flash Write Protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx2                      // ICE/ICD Comm Channel Select
    #pragma config DEBUG    = ON                          // DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config FCANIO = OFF //Nick: Alternate CAN Pins