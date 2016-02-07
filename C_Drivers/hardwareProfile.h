/*********************************************************************
 *
 *   Hardware specific definitions
 *
 *********************************************************************
 * FileName:        HardwareProfile.h
 * Dependencies:    None
 * Processor:       PIC18, PIC24F, PIC24H, dsPIC30F, dsPIC33F, PIC32
 * Compiler:        Microchip C32 v1.10 or higher
 *               Microchip C30 v3.12 or higher
 *               Microchip C18 v3.34 or higher
 *               HI-TECH PICC-18 PRO 9.63PL2 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright (C) 2002-2009 Microchip Technology Inc.  All rights
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and
 * distribute:
 * (i)  the Software when embedded on a Microchip microcontroller or
 *      digital signal controller product ("Device") which is
 *      integrated into Licensee's product; or
 * (ii) ONLY the Software driver source files ENC28J60.c, ENC28J60.h,
 *      ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device
 *      used in conjunction with a Microchip ethernet controller for
 *      the sole purpose of interfacing with the ethernet controller.
 *
 * You should refer to the license agreement accompanying this
 * Software for additional information regarding your rights and
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date      Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Howard Schlunder      10/03/06   Original, copied from Compiler.h
 * Ken Hesky            07/01/08    Added ZG2100-specific features
 ********************************************************************/
#ifndef __HARDWARE_PROFILE_H
#define __HARDWARE_PROFILE_H

#include <xc.h>
// Choose which hardware profile to compile for here.  See 
// the hardware profiles below for meaning of various options.  
//#define PICDEMNET2
//#define PIC18_EXPLORER
//#define HPC_EXPLORER
//#define PIC24FJ64GA004_PIM      // Explorer 16, but with the PIC24FJ64GA004 PIM module, which has significantly differnt pin mappings
//#define EXPLORER_16            // PIC24FJ128GA010, PIC24HJ256GP610, dsPIC33FJ256GP710, PIC32MX360F512L, PIC32MX460F512L, PIC32MX795F512L, etc. PIMs
//#define DSPICDEM11
//#define PIC32_STARTER_KIT      // PIC32MX360F512L Starter Kit, PIC32MX460F512L USB Starter Board, or PIC32MX795F512L USB Starter Kit II
//#define PIC32_ETH_STARTER_KIT   // PIC32MX795F512L Ethernet Starter Kit board with embedded Ethernet controller
// If no hardware profiles are defined, assume that we are using 
// a Microchip demo board and try to auto-select the correct profile
// based on processor selected in MPLAB
#if !defined(PICDEMNET2) && !defined(PIC18_EXPLORER) && !defined(HPC_EXPLORER) && !defined(EXPLORER_16) && !defined(PIC24FJ64GA004_PIM) && !defined(DSPICDEM11) && !defined(PICDEMNET2) && !defined(INTERNET_RADIO) && !defined(YOUR_BOARD) && !defined(__PIC24FJ128GA006__) && !defined(PIC32_STARTER_KIT) && !defined(PIC32_ETH_STARTER_KIT)
   #if defined(__18F97J60) || defined(_18F97J60)
      #define PICDEMNET2
   #elif defined(__18F67J60) || defined(_18F67J60)
      #define INTERNET_RADIO
   #elif defined(__18F8722) || defined(__18F87J10) || defined(_18F8722) || defined(_18F87J10) || defined(__18F87J11) || defined(_18F87J11)|| defined(__18F87J50) || defined(_18F87J50)
      #define PIC18_EXPLORER
      //#define HPC_EXPLORER
   #elif defined(__PIC24FJ64GA004__)
      #define PIC24FJ64GA004_PIM
   #elif defined(__PIC24F__) || defined(__PIC24H__) || defined(__dsPIC33F__) || defined(__PIC32MX__)
      #define EXPLORER_16
   #elif defined(__dsPIC30F__)
      #define DSPICDEM11
   #endif
#endif

// Set configuration fuses (but only once)
#if defined(THIS_IS_STACK_APPLICATION)
   #if defined(__18CXX)
      #if defined(__EXTENDED18__)
         #pragma config XINST=ON
      #elif !defined(HI_TECH_C)
         #pragma config XINST=OFF
      #endif
   
      #if defined(__18F8722) && !defined(HI_TECH_C)
         // PICDEM HPC Explorer or PIC18 Explorer board
         #pragma config OSC=HSPLL, FCMEN=OFF, IESO=OFF, PWRT=OFF, WDT=OFF, LVP=OFF
      #elif defined(_18F8722)   // HI-TECH PICC-18 compiler
         // PICDEM HPC Explorer or PIC18 Explorer board with HI-TECH PICC-18 compiler
         __CONFIG(1, HSPLL);
         __CONFIG(2, WDTDIS);
         __CONFIG(3, MCLREN);
         __CONFIG(4, XINSTDIS & LVPDIS);
      #elif defined(__18F87J10) && !defined(HI_TECH_C)
         // PICDEM HPC Explorer or PIC18 Explorer board
         #pragma config WDTEN=OFF, FOSC2=ON, FOSC=HSPLL
      #elif defined(__18F87J11) && !defined(HI_TECH_C)
         // PICDEM HPC Explorer or PIC18 Explorer board
         #pragma config WDTEN=OFF, FOSC=HSPLL
      #elif defined(__18F87J50) && !defined(HI_TECH_C)
         // PICDEM HPC Explorer or PIC18 Explorer board
         #pragma config WDTEN=OFF, FOSC=HSPLL, PLLDIV=3, CPUDIV=OSC1
      #elif (defined(__18F97J60) || defined(__18F96J65) || defined(__18F96J60) || defined(__18F87J60) || defined(__18F86J65) || defined(__18F86J60) || defined(__18F67J60) || defined(__18F66J65) || defined(__18F66J60)) && !defined(HI_TECH_C)
         // PICDEM.net 2 or any other PIC18F97J60 family device
         #pragma config WDT=OFF, FOSC2=ON, FOSC=HSPLL, ETHLED=ON
      #elif defined(_18F97J60) || defined(_18F96J65) || defined(_18F96J60) || defined(_18F87J60) || defined(_18F86J65) || defined(_18F86J60) || defined(_18F67J60) || defined(_18F66J65) || defined(_18F66J60) 
         // PICDEM.net 2 board with HI-TECH PICC-18 compiler
         __CONFIG(1, WDTDIS & XINSTDIS);
         __CONFIG(2, HSPLL);
         __CONFIG(3, ETHLEDEN);
      #elif defined(__18F4620) && !defined(HI_TECH_C)
         #pragma config OSC=HSPLL, WDT=OFF, MCLRE=ON, PBADEN=OFF, LVP=OFF
      #endif
   #elif defined(__PIC24F__)
      // Explorer 16 board
      _CONFIG2(FNOSC_PRIPLL & POSCMOD_XT)      // Primary XT OSC with 4x PLL
      _CONFIG1(JTAGEN_OFF & FWDTEN_OFF)      // JTAG off, watchdog timer off
   #elif defined(__dsPIC33F__) || defined(__PIC24H__)
      // Explorer 16 board
      _FOSCSEL(FNOSC_PRIPLL)         // PLL enabled
      _FOSC(OSCIOFNC_OFF & POSCMD_XT)   // XT Osc
      _FWDT(FWDTEN_OFF)            // Disable Watchdog timer
      // JTAG should be disabled as well
   #elif defined(__dsPIC30F__)
      // dsPICDEM 1.1 board
      _FOSC(XT_PLL16)               // XT Osc + 16X PLL
      _FWDT(WDT_OFF)               // Disable Watchdog timer
      _FBORPOR(MCLR_EN & PBOR_OFF & PWRT_OFF)
   #elif defined(__PIC32MX__)
      #pragma config FPLLODIV = DIV_1, FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FWDTEN = OFF, FPBDIV = DIV_1, POSCMOD = XT, FNOSC = PRIPLL, CP = OFF
      #if defined(PIC32_ETH_STARTER_KIT)
         #pragma config FMIIEN = OFF, FETHIO = OFF   // external PHY in RMII/alternate configuration
      #endif
   #endif
#endif // Prevent more than one set of config fuse definitions

// Clock frequency value.
// This value is used to calculate Tick Counter value
#if defined(__18CXX)
   // All PIC18 processors
   #if defined(PICDEMNET2) || defined(INTERNET_RADIO)
      #define GetSystemClock()      (41666667ul)      // Hz
      #define GetInstructionClock()   (GetSystemClock()/4)
      #define GetPeripheralClock()   GetInstructionClock()
   #elif defined(__18F87J50) || defined(_18F87J50)
      #define GetSystemClock()      (48000000ul)      // Hz
      #define GetInstructionClock()   (GetSystemClock()/4)
      #define GetPeripheralClock()   GetInstructionClock()
   #else
      #define GetSystemClock()      (40000000ul)      // Hz
      #define GetInstructionClock()   (GetSystemClock()/4)
      #define GetPeripheralClock()   GetInstructionClock()
   #endif
#elif defined(__PIC24F__)   
   // PIC24F processor
   #define GetSystemClock()      (32000000ul)      // Hz
   #define GetInstructionClock()   (GetSystemClock()/2)
   #define GetPeripheralClock()   GetInstructionClock()
#elif defined(__PIC24H__)   
   // PIC24H processor
   #define GetSystemClock()      (80000000ul)      // Hz
   #define GetInstructionClock()   (GetSystemClock()/2)
   #define GetPeripheralClock()   GetInstructionClock()
#elif defined(__dsPIC33F__)   
   // dsPIC33F processor
   #define GetSystemClock()      (80000000ul)      // Hz
   #define GetInstructionClock()   (GetSystemClock()/2)
   #define GetPeripheralClock()   GetInstructionClock()
#elif defined(__dsPIC30F__)
   // dsPIC30F processor
   #define GetSystemClock()      (117920000ul)      // Hz
   #define GetInstructionClock()   (GetSystemClock()/4)
   #define GetPeripheralClock()   GetInstructionClock()
#elif defined(__PIC32MX__)
   // PIC32MX processor
   #define GetSystemClock()      (80000000ul)      // Hz
   #define GetInstructionClock()   (GetSystemClock()/1)
   #define GetPeripheralClock()   (GetInstructionClock()/(1<<OSCCONbits.PBDIV))   // Set your divider according to your Peripheral Bus Frequency configuration fuse setting
#endif

// Hardware mappings
#if defined(PIC18_EXPLORER) && !defined(HI_TECH_C)
// PIC18 Explorer + Fast 100Mbps Ethernet PICtail Plus or Ethernet PICtail
   // I/O pins
   #define LED0_TRIS         (TRISDbits.TRISD0)
   #define LED0_IO            (LATDbits.LATD0)
   #define LED1_TRIS         (TRISDbits.TRISD1)
   #define LED1_IO            (LATDbits.LATD1)
   #define LED2_TRIS         (TRISDbits.TRISD2)
   #define LED2_IO            (LATDbits.LATD2)
   #define LED3_TRIS         (TRISDbits.TRISD3)
   #define LED3_IO            (LATDbits.LATD3)
   #define LED4_TRIS         (TRISDbits.TRISD4)
   #define LED4_IO            (LATDbits.LATD4)
   #define LED5_TRIS         (TRISDbits.TRISD5)
   #define LED5_IO            (LATDbits.LATD5)
   #define LED6_TRIS         (TRISDbits.TRISD6)
   #define LED6_IO            (LATDbits.LATD6)
   #define LED7_TRIS         (TRISDbits.TRISD7)
   #define LED7_IO            (LATDbits.LATD7)
   #define LED_GET()         (LATD)
   #define LED_PUT(a)         (LATD = (a))

   #define BUTTON0_TRIS      (TRISAbits.TRISA5)
   #define   BUTTON0_IO         (PORTAbits.RA5)
   #define BUTTON1_TRIS      (TRISBbits.TRISB0)
   #define   BUTTON1_IO         (PORTBbits.RB0)
   #define BUTTON2_TRIS      (PRODL)            // No Button2 on this board
   #define   BUTTON2_IO         (1u)
   #define BUTTON3_TRIS      (PRODL)            // No Button3 on this board
   #define   BUTTON3_IO         (1u)


//   // ENC424J600/624J600 Fast 100Mbps Ethernet PICtail Plus defines
//   #define ENC100_INTERFACE_MODE         0      // Uncomment this line to use the ENC424J600/624J600 Ethernet controller (SPI mode) or comment it out to use some other network controller
//   
//   // ENC100_MDIX, ENC100_POR, and ENC100_INT are all optional.  Simply leave 
//   // them commented out if you don't have such a hardware feature on your 
//   // board.
//   #define ENC100_MDIX_TRIS            (TRISBbits.TRISB4)
//   #define ENC100_MDIX_IO               (LATBbits.LATB4)
////   #define ENC100_POR_TRIS               (TRISBbits.TRISB5)
////   #define ENC100_POR_IO               (LATBbits.LATB5)
////   #define ENC100_INT_TRIS               (TRISBbits.TRISB2)
////   #define ENC100_INT_IO               (PORTBbits.RB2)
//
//   // ENC424J600/624J600 SPI pinout
//   #define ENC100_CS_TRIS               (TRISBbits.TRISB3)
//   #define ENC100_CS_IO               (LATBbits.LATB3)
//   #define ENC100_SO_WR_B0SEL_EN_TRIS      (TRISCbits.TRISC4)   // NOTE: SO is ENC624J600 Serial Out, which needs to connect to the PIC SDI pin for SPI mode
//   #define ENC100_SO_WR_B0SEL_EN_IO      (PORTCbits.RC4)
//   #define ENC100_SI_RD_RW_TRIS         (TRISCbits.TRISC5)   // NOTE: SI is ENC624J600 Serial In, which needs to connect to the PIC SDO pin for SPI mode
//   #define ENC100_SI_RD_RW_IO            (LATCbits.LATC5)
//   #define ENC100_SCK_AL_TRIS            (TRISCbits.TRISC3)
//   #define ENC100_SCK_AL_IO            (PORTCbits.RC3)      // NOTE: This must be the PORT, not the LATch like it is for the PSP interface.
//
//   // ENC424J600/624J600 SPI SFR register selection (controls which SPI 
//   // peripheral to use on PICs with multiple SPI peripherals).
////   #define ENC100_ISR_ENABLE      (INTCON3bits.INT2IE)
////   #define ENC100_ISR_FLAG         (INTCON3bits.INT2IF)
////   #define ENC100_ISR_POLARITY      (INTCON2bits.INTEDG2)
////   #define ENC100_ISR_PRIORITY      (INTCON3bits.INT2IP)
//   #define ENC100_SPI_ENABLE      (ENC100_SPISTATbits.SPIEN)
//   #define ENC100_SPI_IF         (PIR1bits.SSPIF)
//   #define ENC100_SSPBUF         (SSP1BUF)
//   #define ENC100_SPISTAT         (SSP1STAT)
//   #define ENC100_SPISTATbits      (SSP1STATbits)
//   #define ENC100_SPICON1         (SSP1CON1)
//   #define ENC100_SPICON1bits      (SSP1CON1bits)
//   #define ENC100_SPICON2         (SSP1CON2)

   // ENC28J60 I/O pins
   #define ENC_RST_TRIS      (TRISBbits.TRISB5)
   #define ENC_RST_IO         (LATBbits.LATB5)
   #define ENC_CS_TRIS         (TRISBbits.TRISB3)   // Uncomment this line to use the ENC28J60 Ethernet controller or comment it out to use some other network controller
   #define ENC_CS_IO         (LATBbits.LATB3)
   #define ENC_SCK_TRIS      (TRISCbits.TRISC3)
   #define ENC_SDI_TRIS      (TRISCbits.TRISC4)
   #define ENC_SDO_TRIS      (TRISCbits.TRISC5)
   #define ENC_SPI_IF         (PIR1bits.SSPIF)
   #define ENC_SSPBUF         (SSP1BUF)
   #define ENC_SPISTAT         (SSP1STAT)
   #define ENC_SPISTATbits      (SSP1STATbits)
   #define ENC_SPICON1         (SSP1CON1)
   #define ENC_SPICON1bits      (SSP1CON1bits)
   #define ENC_SPICON2         (SSP1CON2)

   // 25LC256 I/O pins
   #define EEPROM_CS_TRIS      (TRISAbits.TRISA3)
   #define EEPROM_CS_IO      (LATAbits.LATA3)
   #define EEPROM_SCK_TRIS      (TRISCbits.TRISC3)
   #define EEPROM_SDI_TRIS      (TRISCbits.TRISC4)
   #define EEPROM_SDO_TRIS      (TRISCbits.TRISC5)
   #define EEPROM_SPI_IF      (PIR1bits.SSPIF)
   #define EEPROM_SSPBUF      (SSP1BUF)
   #define EEPROM_SPICON1      (SSP1CON1)
   #define EEPROM_SPICON1bits   (SSP1CON1bits)
   #define EEPROM_SPICON2      (SSP1CON2)
   #define EEPROM_SPISTAT      (SSP1STAT)
   #define EEPROM_SPISTATbits   (SSP1STATbits)

   // LCD I/O pins
   // TODO: Need to add support for LCD behind MCP23S17 I/O expander.  This 
   // requires code that isn't in the TCP/IP stack, not just a hardware 
   // profile change.

   // Serial Flash/SRAM/UART PICtail
//   #define SPIRAM_CS_TRIS         (TRISBbits.TRISB5)
//   #define SPIRAM_CS_IO         (LATBbits.LATB5)
//   #define SPIRAM_SCK_TRIS         (TRISCbits.TRISC3)
//   #define SPIRAM_SDI_TRIS         (TRISCbits.TRISC4)
//   #define SPIRAM_SDO_TRIS         (TRISCbits.TRISC5)
//   #define SPIRAM_SPI_IF         (PIR1bits.SSPIF)
//   #define SPIRAM_SSPBUF         (SSP1BUF)
//   #define SPIRAM_SPICON1         (SSP1CON1)
//   #define SPIRAM_SPICON1bits      (SSP1CON1bits)
//   #define SPIRAM_SPICON2         (SSP1CON2)
//   #define SPIRAM_SPISTAT         (SSP1STAT)
//   #define SPIRAM_SPISTATbits      (SSP1STATbits)
//
//   // NOTE: You must also set the SPI_FLASH_SST/SPI_FLASH_SPANSION, 
//   //       SPI_FLASH_SECTOR_SIZE, and SPI_FLASH_PAGE_SIZE macros in 
//   //       SPIFlash.h to match your particular Flash memory chip!!!
//   #define SPIFLASH_CS_TRIS      (TRISBbits.TRISB4)
//   #define SPIFLASH_CS_IO         (LATBbits.LATB4)
//   #define SPIFLASH_SCK_TRIS      (TRISCbits.TRISC3)
//   #define SPIFLASH_SDI_TRIS      (TRISCbits.TRISC4)
//   #define SPIFLASH_SDI_IO         (PORTCbits.RC4)
//   #define SPIFLASH_SDO_TRIS      (TRISCbits.TRISC5)
//   #define SPIFLASH_SPI_IF         (PIR1bits.SSPIF)
//   #define SPIFLASH_SSPBUF         (SSP1BUF)
//   #define SPIFLASH_SPICON1      (SSP1CON1)
//   #define SPIFLASH_SPICON1bits   (SSP1CON1bits)
//   #define SPIFLASH_SPICON2      (SSP1CON2)
//   #define SPIFLASH_SPISTAT      (SSP1STAT)
//   #define SPIFLASH_SPISTATbits   (SSP1STATbits)

   // Register name fix up for certain processors
   #define SPBRGH            SPBRGH1
   #if defined(__18F87J50) || defined(_18F87J50) || defined(__18F87J11) || defined(_18F87J11)
      #define ADCON2      ADCON1
   #endif

#elif defined(PIC18_EXPLORER) && defined(HI_TECH_C)
// PIC18 Explorer + Fast 100Mbps Ethernet PICtail Plus or Ethernet PICtail + HI-TECH PICC-18 compiler
   // I/O pins
   #define LED0_TRIS         (TRISD0)
   #define LED0_IO            (LATD0)
   #define LED1_TRIS         (TRISD1)
   #define LED1_IO            (LATD1)
   #define LED2_TRIS         (TRISD2)
   #define LED2_IO            (LATD2)
   #define LED3_TRIS         (TRISD3)
   #define LED3_IO            (LATD3)
   #define LED4_TRIS         (TRISD4)
   #define LED4_IO            (LATD4)
   #define LED5_TRIS         (TRISD5)
   #define LED5_IO            (LATD5)
   #define LED6_TRIS         (TRISD6)
   #define LED6_IO            (LATD6)
   #define LED7_TRIS         (TRISD7)
   #define LED7_IO            (LATD7)
   #define LED_GET()         (LATD)
   #define LED_PUT(a)         (LATD = (a))

   #define BUTTON0_TRIS      (TRISA5)
   #define   BUTTON0_IO         (RA5)
   #define BUTTON1_TRIS      (TRISB0)
   #define   BUTTON1_IO         (RB0)
   #define BUTTON2_TRIS      (PRODL)            // No Button2 on this board
   #define   BUTTON2_IO         (1u)
   #define BUTTON3_TRIS      (PRODL)            // No Button3 on this board
   #define   BUTTON3_IO         (1u)

//   // ENC424J600/624J600 Fast 100Mbps Ethernet PICtail Plus defines
//   #define ENC100_INTERFACE_MODE         0      // Uncomment this line to use the ENC424J600/624J600 Ethernet controller (SPI mode) or comment it out to use some other network controller
//
//   // ENC100_MDIX, ENC100_POR, and ENC100_INT are all optional.  Simply leave 
//   // them commented out if you don't have such a hardware feature on your 
//   // hardware.
//   #define ENC100_MDIX_TRIS            (TRISB4)
//   #define ENC100_MDIX_IO               (LATB4)
////   #define ENC100_POR_TRIS               (TRISB5)
////   #define ENC100_POR_IO               (LATB5)
////   #define ENC100_INT_TRIS               (TRISB2)
////   #define ENC100_INT_IO               (RB2)
//
//   // ENC424J600/624J600 SPI pinout
//   #define ENC100_CS_TRIS               (TRISB3)
//   #define ENC100_CS_IO               (LATB3)
//   #define ENC100_SO_WR_B0SEL_EN_TRIS      (TRISC4)   // NOTE: SO is ENC624J600 Serial Out, which needs to connect to the PIC SDI pin for SPI mode
//   #define ENC100_SO_WR_B0SEL_EN_IO      (RC4)
//   #define ENC100_SI_RD_RW_TRIS         (TRISC5)   // NOTE: SI is ENC624J600 Serial In, which needs to connect to the PIC SDO pin for SPI mode
//   #define ENC100_SI_RD_RW_IO            (LATC5)
//   #define ENC100_SCK_AL_TRIS            (TRISC3)
//   #define ENC100_SCK_AL_IO            (RC3)      // NOTE: This must be the PORT, not the LATch like it is for the PSP interface.
//
//   // ENC424J600/624J600 SPI SFR register selection (controls which SPI 
//   // peripheral to use on PICs with multiple SPI peripherals).
////   #define ENC100_ISR_ENABLE      (INT2IE)
////   #define ENC100_ISR_FLAG         (INT2IF)
////   #define ENC100_ISR_POLARITY      (INTEDG2)
////   #define ENC100_ISR_PRIORITY      (INT2IP)
//   #define ENC100_SPI_ENABLE      (ENC100_SPISTATbits.SPIEN)
//   #define ENC100_SPI_IF         (SSP1IF)
//   #define ENC100_SSPBUF         (SSP1BUF)
//   #define ENC100_SPISTAT         (SSP1STAT)
//   #define ENC100_SPISTATbits      (SSP1STATbits)
//   #define ENC100_SPICON1         (SSP1CON1)
//   #define ENC100_SPICON1bits      (SSP1CON1bits)
//   #define ENC100_SPICON2         (SSP1CON2)

   // ENC28J60 I/O pins
   #define ENC_RST_TRIS      (TRISB5)
   #define ENC_RST_IO         (LATB5)
   #define ENC_CS_TRIS         (TRISB3)   // Uncomment this line to use the ENC28J60 Ethernet controller or comment it out to use some other network controller
   #define ENC_CS_IO         (LATB3)
   #define ENC_SCK_TRIS      (TRISC3)
   #define ENC_SDI_TRIS      (TRISC4)
   #define ENC_SDO_TRIS      (TRISC5)
   #define ENC_SPI_IF         (SSP1IF)
   #define ENC_SSPBUF         (SSP1BUF)
   #define ENC_SPISTAT         (SSP1STAT)
   #define ENC_SPISTATbits      (SSP1STATbits)
   #define ENC_SPICON1         (SSP1CON1)
   #define ENC_SPICON1bits      (SSP1CON1bits)
   #define ENC_SPICON2         (SSP1CON2)

   // 25LC256 I/O pins
   #define EEPROM_CS_TRIS      (TRISA3)
   #define EEPROM_CS_IO      (LATA3)
   #define EEPROM_SCK_TRIS      (TRISC3)
   #define EEPROM_SDI_TRIS      (TRISC4)
   #define EEPROM_SDO_TRIS      (TRISC5)
   #define EEPROM_SPI_IF      (SSP1IF)
   #define EEPROM_SSPBUF      (SSP1BUF)
   #define EEPROM_SPICON1      (SSP1CON1)
   #define EEPROM_SPICON1bits   (SSP1CON1bits)
   #define EEPROM_SPICON2      (SSP1CON2)
   #define EEPROM_SPISTAT      (SSP1STAT)
   #define EEPROM_SPISTATbits   (SSP1STATbits)

   // LCD I/O pins
   // TODO: Need to add support for LCD behind MCP23S17 I/O expander.  This 
   // requires code that isn't in the TCP/IP stack, not just a hardware 
   // profile change.

   // Register name fix up for certain processors
   #define SPBRGH            SPBRGH1
   #define TXSTAbits         TXSTA1bits
   #define RCSTAbits         RCSTA1bits
   #define BAUDCONbits         BAUDCON1bits
   #define GO               GODONE
   #if defined(__18F87J50) || defined(_18F87J50) || defined(__18F87J11) || defined(_18F87J11)
      #define ADCON2      ADCON1
   #endif

#elif defined(HPC_EXPLORER) && !defined(HI_TECH_C)
// PICDEM HPC Explorer + Fast 100Mbps Ethernet PICtail Plus or Ethernet PICtail
   // I/O pins
   #define LED0_TRIS         (TRISDbits.TRISD0)
   #define LED0_IO            (LATDbits.LATD0)
   #define LED1_TRIS         (TRISDbits.TRISD1)
   #define LED1_IO            (LATDbits.LATD1)
   #define LED2_TRIS         (TRISDbits.TRISD2)
   #define LED2_IO            (LATDbits.LATD2)
   #define LED3_TRIS         (TRISDbits.TRISD3)
   #define LED3_IO            (LATDbits.LATD3)
   #define LED4_TRIS         (TRISDbits.TRISD4)
   #define LED4_IO            (LATDbits.LATD4)
   #define LED5_TRIS         (TRISDbits.TRISD5)
   #define LED5_IO            (LATDbits.LATD5)
   #define LED6_TRIS         (TRISDbits.TRISD6)
   #define LED6_IO            (LATDbits.LATD6)
   #define LED7_TRIS         (TRISDbits.TRISD7)
   #define LED7_IO            (LATDbits.LATD7)
   #define LED_GET()         (LATD)
   #define LED_PUT(a)         (LATD = (a))


   #define BUTTON0_TRIS      (TRISBbits.TRISB0)
   #define   BUTTON0_IO         (PORTBbits.RB0)
   #define BUTTON1_TRIS      (TRISBbits.TRISB0)   // No Button1 on this board, remap to Button0
   #define   BUTTON1_IO         (PORTBbits.RB0)
   #define BUTTON2_TRIS      (TRISBbits.TRISB0)   // No Button2 on this board, remap to Button0
   #define   BUTTON2_IO         (PORTBbits.RB0)
   #define BUTTON3_TRIS      (TRISBbits.TRISB0)   // No Button3 on this board, remap to Button0
   #define   BUTTON3_IO         (PORTBbits.RB0)

//   // ENC424J600/624J600 Fast 100Mbps Ethernet PICtail Plus defines
//   #define ENC100_INTERFACE_MODE         0      // Uncomment this line to use the ENC424J600/624J600 Ethernet controller (SPI mode) or comment it out to use some other network controller
//
//   // ENC424J600/624J600 Fast 100Mbps Ethernet PICtail Plus I/O pins
//   #define ENC100_MDIX_TRIS            (TRISBbits.TRISB4)
//   #define ENC100_MDIX_IO               (LATBbits.LATB4)
//   #define ENC100_POR_TRIS               (TRISBbits.TRISB5)
//   #define ENC100_POR_IO               (LATBbits.LATB5)
////   #define ENC100_INT_TRIS               (TRISBbits.TRISB2)
////   #define ENC100_INT_IO               (PORTBbits.RB2)
//
//   // ENC424J600/624J600 SPI pinout
//   #define ENC100_CS_TRIS               (TRISBbits.TRISB3)
//   #define ENC100_CS_IO               (LATBbits.LATB3)
//   #define ENC100_SO_WR_B0SEL_EN_TRIS      (TRISCbits.TRISC4)   // NOTE: SO is ENC624J600 Serial Out, which needs to connect to the PIC SDI pin for SPI mode
//   #define ENC100_SO_WR_B0SEL_EN_IO      (PORTCbits.RC4)
//   #define ENC100_SI_RD_RW_TRIS         (TRISCbits.TRISC5)   // NOTE: SI is ENC624J600 Serial In, which needs to connect to the PIC SDO pin for SPI mode
//   #define ENC100_SI_RD_RW_IO            (LATCbits.LATC5)
//   #define ENC100_SCK_AL_TRIS            (TRISCbits.TRISC3)
//   #define ENC100_SCK_AL_IO            (PORTCbits.RC3)      // NOTE: This must be the PORT, not the LATch like it is for the PSP interface.
//
//   // ENC424J600/624J600 SPI SFR register selection (controls which SPI 
//   // peripheral to use on PICs with multiple SPI peripherals).
////   #define ENC100_ISR_ENABLE      (INTCON3bits.INT2IE)
////   #define ENC100_ISR_FLAG         (INTCON3bits.INT2IF)
////   #define ENC100_ISR_POLARITY      (INTCON2bits.INTEDG2)
////   #define ENC100_ISR_PRIORITY      (INTCON3bits.INT2IP)
//   #define ENC100_SPI_ENABLE      (ENC100_SPISTATbits.SPIEN)
//   #define ENC100_SPI_IF         (PIR1bits.SSPIF)
//   #define ENC100_SSPBUF         (SSP1BUF)
//   #define ENC100_SPISTAT         (SSP1STAT)
//   #define ENC100_SPISTATbits      (SSP1STATbits)
//   #define ENC100_SPICON1         (SSP1CON1)
//   #define ENC100_SPICON1bits      (SSP1CON1bits)
//   #define ENC100_SPICON2         (SSP1CON2)

   // ENC28J60 I/O pins
   #define ENC_RST_TRIS      (TRISBbits.TRISB5)
   #define ENC_RST_IO         (LATBbits.LATB5)
   #define ENC_CS_TRIS         (TRISBbits.TRISB3)   // Uncomment this line to use the ENC28J60 Ethernet controller or comment it out to use some other network controller
   #define ENC_CS_IO         (LATBbits.LATB3)
   #define ENC_SCK_TRIS      (TRISCbits.TRISC3)
   #define ENC_SDI_TRIS      (TRISCbits.TRISC4)
   #define ENC_SDO_TRIS      (TRISCbits.TRISC5)
   #define ENC_SPI_IF         (PIR1bits.SSPIF)
   #define ENC_SSPBUF         (SSP1BUF)
   #define ENC_SPISTAT         (SSP1STAT)
   #define ENC_SPISTATbits      (SSP1STATbits)
   #define ENC_SPICON1         (SSP1CON1)
   #define ENC_SPICON1bits      (SSP1CON1bits)
   #define ENC_SPICON2         (SSP1CON2)

   // 25LC256 I/O pins
   #define EEPROM_CS_TRIS      (TRISBbits.TRISB4)
   #define EEPROM_CS_IO      (LATBbits.LATB4)
   #define EEPROM_SCK_TRIS      (TRISCbits.TRISC3)
   #define EEPROM_SDI_TRIS      (TRISCbits.TRISC4)
   #define EEPROM_SDO_TRIS      (TRISCbits.TRISC5)
   #define EEPROM_SPI_IF      (PIR1bits.SSPIF)
   #define EEPROM_SSPBUF      (SSP1BUF)
   #define EEPROM_SPICON1      (SSP1CON1)
   #define EEPROM_SPICON1bits   (SSP1CON1bits)
   #define EEPROM_SPICON2      (SSP1CON2)
   #define EEPROM_SPISTAT      (SSP1STAT)
   #define EEPROM_SPISTATbits   (SSP1STATbits)

   // Register name fix up for certain processors
   #define SPBRGH            SPBRGH1
   #if defined(__18F87J50) || defined(_18F87J50) || defined(__18F87J11) || defined(_18F87J11)
      #define ADCON2      ADCON1
   #endif


#elif defined(PIC32_ETH_STARTER_KIT)
// PIC32 Ethernet Starter Kit (04-02146) with PIC32MX795F512L processor and National DP83848 10/100 PHY
   // External SMSC PHY configuration
   #define   PHY_RMII            // external PHY runs in RMII mode
   #define   PHY_CONFIG_ALTERNATE   // alternate configuration used
   #define   PHY_ADDRESS         0x1   // the address of the National DP83848 PHY

   // I/O pins configuration
   #define BUTTON1_TRIS      (TRISDbits.TRISD6)
   #define   BUTTON1_IO         (PORTDbits.RD6)
   #define BUTTON2_TRIS      (TRISDbits.TRISD7)
   #define   BUTTON2_IO         (PORTDbits.RD7)
   #define BUTTON3_TRIS      (TRISDbits.TRISD13)
   #define   BUTTON3_IO         (PORTDbits.RD13)

   #define BUTTON0_TRIS      BUTTON1_TRIS      // no button 0. map to 1
   #define   BUTTON0_IO         BUTTON1_IO

   #define LED0_TRIS         (TRISDbits.TRISD0)
   #define LED0_IO            (LATDbits.LATD0)
   #define LED1_TRIS         (TRISDbits.TRISD1)
   #define LED1_IO            (LATDbits.LATD1)
   #define LED2_TRIS         (TRISDbits.TRISD2)
   #define LED2_IO            (LATDbits.LATD2)
   // no other LED's
   #define LED3_TRIS         LED2_TRIS
   #define LED3_IO            LED2_IO
   #define LED4_TRIS         LED2_TRIS
   #define LED4_IO            LED2_IO
   #define LED5_TRIS         LED2_TRIS
   #define LED5_IO            LED2_IO
   #define LED6_TRIS         LED2_TRIS
   #define LED6_IO            LED2_IO
   #define LED7_TRIS         LED2_TRIS
   #define LED7_IO            LED2_IO

   #define LED_GET()         (*((volatile unsigned char*)(&LATD)))
   #define LED_PUT(a)         (*((volatile unsigned char*)(&LATD)) = (a))

   // Note, it is not possible to use a ZeroG ZG2100M 802.11 WiFi PICtail 
   // Plus card with this starter kit.  The required interrupt signal, among 
   // possibly other I/O pins aren't available on the Starter Kit board.  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#elif defined(YOUR_BOARD)
// Define your own board hardware profile here
      #if defined(__18F4520)&&!defined(HI_TECH_C)
         #pragma config OSC=HSPLL, FCMEN=OFF, IESO=OFF, PWRT=OFF, WDT=OFF, LVP=OFF

   #define LED0_TRIS TRISBbits.TRISB0
   #define LED0_IO     LATBbits.LATB0
   #define LED1_TRIS TRISBbits.TRISB1
   #define LED1_IO     LATBbits.LATB1
   #define LED2_TRIS TRISBbits.TRISB2
   #define LED2_IO   LATBbits.LATB2
   #define LED3_TRIS TRISBbits.TRISB3
   #define LED3_IO     LATBbits.LATB3
   #define LED4_TRIS TRISBbits.TRISB4
   #define LED4_IO     LATBbits.LATB4
   #define LED5_TRIS TRISBbits.TRISB5
   #define LED5_IO     LATBbits.LATB5
   #define LED6_TRIS TRISBbits.TRISB6
   #define LED6_IO   LATBbits.LATB6
   #define LED7_TRIS TRISBbits.TRISB7
   #define LED7_IO   LATBbits.LATB7

   #define LED_GET()         (LATB)
   #define LED_PUT(a)         (LATB = (a))

   #define BUTTON0_TRIS      TRISAbits.TRISA0
   #define   BUTTON0_IO         PORTAbits.RA0

   #define BUTTON1_TRIS      TRISAbits.TRISA1
   #define   BUTTON1_IO         PORTAbits.RA1

   #define BUTTON2_TRIS      TRISAbits.TRISA2
   #define   BUTTON2_IO         PORTAbits.RA2

   #define BUTTON3_TRIS      TRISAbits.TRISA3
   #define   BUTTON3_IO         PORTAbits.RA3

   #define BUTTON4_TRIS      TRISAbits.TRISA4
   #define   BUTTON4_IO         PORTAbits.RA4

   #define BUTTON5_TRIS      TRISAbits.TRISA5
   #define   BUTTON5_IO         PORTAbits.RA5

   // ENC28J60 I/O pins
   #define ENC_RST_TRIS      TRISC0
   #define ENC_RST_IO         LATC0

   #define ENC_CS_TRIS         TRISC2   
   #define ENC_CS_IO         LATC2

   #define ENC_SCK_TRIS      TRISC3

   #define ENC_SDI_TRIS      TRISC4

   #define ENC_SDO_TRIS      TRISC5

   #define ENC_SPI_IF         SSPIF
   #define ENC_SSPBUF         SSP1BUF
   #define ENC_SPISTAT         SSP1STAT
   #define ENC_SPISTATbits      SSP1STATbits
   #define ENC_SPICON1         SSP1CON1
   #define ENC_SPICON1bits      SSP1CON1bits
   #define ENC_SPICON2         SSP1CON2

   // 25LC256 I/O pins
   #define EEPROM_CS_TRIS      TRISC6
   #define EEPROM_CS_IO      LATC6

   #define EEPROM_SCK_TRIS      TRISC3

   #define EEPROM_SDI_TRIS      TRISC4

   #define EEPROM_SDO_TRIS      TRISC5

   #define EEPROM_SPI_IF      SSP1IF
   #define EEPROM_SSPBUF      SSP1BUF
   #define EEPROM_SPICON1      SSP1CON1
   #define EEPROM_SPICON1bits   SSP1CON1bits
   #define EEPROM_SPICON2      SSP1CON2
   #define EEPROM_SPISTAT      SSP1STAT
   #define EEPROM_SPISTATbits   SSP1STATbits

   // LCD I/O pins
   #define LCD_DATA_TRIS      TRISD
   #define LCD_DATA_IO         LATD

   #define LCD_RD_WR_TRIS      TRISE1
   #define LCD_RD_WR_IO      LATE1
   #define LCD_RS_TRIS         TRISE0
   #define LCD_RS_IO         LATE0
   #define LCD_E_TRIS          TRISE2
   #define LCD_E_IO          LATE2

#else
   #error "Hardware profile not defined.  See available profiles in HardwareProfile.h and modify or create one."
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(__18CXX)   // PIC18
   // UART mapping functions for consistent API names across 8-bit and 16 or 
   // 32 bit compilers.  For simplicity, everything will use "UART" instead 
   // of USART/EUSART/etc.
   #define BusyUART()            BusyUSART()
   #define CloseUART()            CloseUSART()
   #define ConfigIntUART(a)      ConfigIntUSART(a)
   #define DataRdyUART()         DataRdyUSART()
   #define OpenUART(a,b,c)         OpenUSART(a,b,c)
   #define ReadUART()            ReadUSART()
   #define WriteUART(a)         WriteUSART(a)
   #define getsUART(a,b,c)         getsUSART(b,a)
   #define putsUART(a)            putsUSART(a)
   #define getcUART()            ReadUSART()
   #define putcUART(a)            WriteUSART(a)
   #define putrsUART(a)         putrsUSART((far rom char*)a)

#else    // PIC24F, PIC24H, dsPIC30, dsPIC33, PIC32
   // Some A/D converter registers on dsPIC30s are named slightly differently 
   // on other procesors, so we need to rename them.
   #if defined(__dsPIC30F__)
      #define ADC1BUF0         ADCBUF0
      #define AD1CHS            ADCHS
      #define   AD1CON1            ADCON1
      #define AD1CON2            ADCON2
      #define AD1CON3            ADCON3
      #define AD1PCFGbits         ADPCFGbits
      #define AD1CSSL            ADCSSL
      #define AD1IF            ADIF
      #define AD1IE            ADIE
      #define _ADC1Interrupt      _ADCInterrupt
   #endif

   // Select which UART the STACK_USE_UART and STACK_USE_UART2TCP_BRIDGE 
   // options will use.  You can change these to U1BRG, U1MODE, etc. if you 
   // want to use the UART1 module instead of UART2.
   #define UBRG               U2BRG
   #define UMODE               U2MODE
   #define USTA               U2STA
   #define BusyUART()            BusyUART2()
   #define CloseUART()            CloseUART2()
   #define ConfigIntUART(a)      ConfigIntUART2(a)
   #define DataRdyUART()         DataRdyUART2()
   #define OpenUART(a,b,c)         OpenUART2(a,b,c)
   #define ReadUART()            ReadUART2()
   #define WriteUART(a)         WriteUART2(a)
   #define getsUART(a,b,c)         getsUART2(a,b,c)
   #if defined(__C32__)
      #define putsUART(a)         putsUART2(a)
   #else
      #define putsUART(a)         putsUART2((unsigned int*)a)
   #endif
   #define getcUART()            getcUART2()
   #define putcUART(a)            do{while(BusyUART()); WriteUART(a); while(BusyUART()); }while(0)
   #define putrsUART(a)         putrsUART2(a)
#endif


#endif
#endif