#include <xc.h>
#include <sys/attribs.h>
#include <stdbool.h>

#include "adc.h"
#include "system.h"

struct ADC ADCData;

void ADCInit(int frequency, bool useTimer) {
    
    int i;
    for (i = 0; i < 16; ++i) {
        ADCData.ADCEnabled[i] = 0;
        ADCData.ADCValue[i] = 0;
    }
    ADCData.count = 0;
    ADCData.frequency = frequency;
    ADCData.useTimer = useTimer;
    
    __builtin_disable_interrupts();
    if (useTimer) { // Use the timer for interrupts vice the automatic sampling
        // Find the correct period and prescaler
        int prescaler = 1, prescalerSetting = 0, period;
        while (prescaler <= 256) {
            period = PBCLK / frequency / prescaler;
            if (period < 65535) {
                break;
            }
            prescaler *= 2;
            if(prescaler == 128) { // 128 is _not_ a valid prescaler!
                prescaler = 256;
            } 
            prescalerSetting += 1;
        }
        // Setup the appropriate bits
        ADC_TIMER_TMR = 0; // Clear timer1
        ADC_TIMER_PR = period - 1;
        ADC_TIMER_TCKPS = prescalerSetting;
        ADC_TIMER_TGATE = 0; // Not timing an external pulse
        ADC_TIMER_TCS = 0; // Use PBCLK
        ADC_TIMER_INTPRI = 5; // Primary priority
        ADC_TIMER_INTSECPRI = 0; // Secondary priority
        ADC_TIMER_ON = 1; // Turn it on!
        ADC_TIMER_INTFLAG = 0; // Clear Timer1 interrupt flag
        ADC_TIMER_INTENABLE = 1; // Enable Timer1 interrupts
        // Turn the ADC one!
        AD1CON3bits.ADCS = 2;
        AD1CON1bits.ADON = 1;
    } else { // Use automatic sampling with interrupts
        AD1CON1bits.SSRC = 0b111; // Conversion begins immediately after sampling
        AD1CON1bits.ASAM = 1; // Autosampling
        AD1CON1bits.FORM = 0; // 16-bit Integer (is there a reason for 32-bit?)
        AD1CON2bits.CSCNA = 1; // Enable scan mode so we can look at multiple inputs
        AD1CON2bits.BUFM = 0; // Choosing to use the entire (16 word) buffer
        AD1CON2bits.SMPI = 0; // Interrupt after every conversion (just ensuring default..)
        AD1CON2bits.VCFG = 0; // Using default reference bits for now!
        AD1CON3bits.ADCS = 2; // Minimum required for Tad (Tad == 75ns)
        AD1CON3bits.SAMC = 2; // Length of time sample (2 * Tad = 150ns)
        AD1CSSL = 0; // Clear, bits are set when inputs are enabled
        IPC6bits.AD1IP = 5; // ADC priority
        IFS1bits.AD1IF = 0; // Clear ADC Interrupt flag
        IEC1bits.AD1IE = 1; // Enable ADC Interrupt    
        
        AD1CON1bits.ADON = 0; // Don't turn this on until we're ready to use it (add 1)
    }
    __builtin_enable_interrupts();
    
}

int ADCAdd(unsigned char pin, void (*func)(int)) {
    __builtin_disable_interrupts();
    // Enabled specific ADC
    if (pin > 15) {
        return 0; // Valid select is 0-15
    }
    // Enable pin for interrupt functionality
    ADCData.ADCEnabled[pin] = 1;
    ADCData.ADCFunction[pin] = func;
    ADCData.count = 0;
    int i;
    for (i = 0; i < 16; i++) {
        if (ADCData.ADCEnabled[i]) ADCData.count += 1;
    }
    
    // Enable physical pin for analog input
    if (AD1PCFG == 0) {
        AD1PCFG = 0b1 << (pin);
    } else {
        AD1PCFG = AD1PCFG | (0b1 << (pin)); 
    }
    
    // When using the timer, everything is automatic from here
    // But fancy stuff needs to happen for automatic conversion
    if (!ADCData.useTimer) {
        switch(ADCData.count) {
            case 1:
                ADC_SET_1_INPUT_TIMING
                break;
            case 2:
                ADC_SET_2_INPUT_TIMING
                break;
            case 3:
                ADC_SET_3_INPUT_TIMING
                break;
            case 4:
                ADC_SET_4_INPUT_TIMING
                break;
            case 5:
                ADC_SET_5_INPUT_TIMING
                break;
            case 6:
                ADC_SET_6_INPUT_TIMING
                break;
            case 7:
                ADC_SET_7_INPUT_TIMING
                break;
            case 8:
                ADC_SET_8_INPUT_TIMING
                break;
            case 9:
                ADC_SET_9_INPUT_TIMING
                break;
            case 10:
                ADC_SET_10_INPUT_TIMING
                break;
            case 11:
                ADC_SET_11_INPUT_TIMING
                break;
            case 12:
                ADC_SET_12_INPUT_TIMING
                break;
            case 13:
                ADC_SET_13_INPUT_TIMING
                break;
            case 14:
                ADC_SET_14_INPUT_TIMING
                break;
            case 15:
                ADC_SET_15_INPUT_TIMING
                break;
            case 16:
                ADC_SET_16_INPUT_TIMING
                break;
        }
        // Set the scanning bits
        if (AD1CSSL == 0) {
            AD1CSSL = 0b1 << (pin);
        } else {
            AD1CSSL = AD1CSSL | (0b1 << (pin)); 
        }
        AD1CON2bits.SMPI = ADCData.count - 1; // Samples per count
        AD1CON1bits.ADON = 1; // Turn it on!
    }
    __builtin_enable_interrupts();
    return 1;
}

int ADCRead(unsigned char pin) {
    unsigned int elapsed = 0, finish_time = 0;
    AD1CHSbits.CH0SA = pin;
    AD1CON1bits.SAMP = 1;
    elapsed = _CP0_GET_COUNT();
    finish_time = elapsed + 10;
    while (_CP0_GET_COUNT() < finish_time) {
        ;
    }
    AD1CON1bits.SAMP = 0;
    while (!AD1CON1bits.DONE) {
        ;
    }
    return ADC1BUF0;
}

ADC_AUTO_INTERRUPT() {
    int i;
    int j = 0;
    for (i = 0; i < 16; ++i) {
        if (ADCData.ADCEnabled[i]) {
            // A buffer holds the values, find it here!
            int value;
            switch(j) {
                case 0:
                    value = ADC1BUF0;
                    break;
                case 1:
                    value = ADC1BUF1;
                    break;
                case 2:
                    value = ADC1BUF2;
                    break;
                case 3:
                    value = ADC1BUF3;
                    break;
                case 4:
                    value = ADC1BUF4;
                    break;
                case 5:
                    value = ADC1BUF5;
                    break;
                case 6:
                    value = ADC1BUF6;
                    break;
                case 7:
                    value = ADC1BUF7;
                    break;
                case 8:
                    value = ADC1BUF8;
                    break;
                case 9:
                    value = ADC1BUF9;
                    break;
                case 10:
                    value = ADC1BUFA;
                    break;
                case 11:
                    value = ADC1BUFB;
                    break;
                case 12:
                    value = ADC1BUFC;
                    break;
                case 13:
                    value = ADC1BUFD;
                    break;
                case 14:
                    value = ADC1BUFE;
                    break;
                case 15:
                    value = ADC1BUFF;
                    break;
            }
            ADCData.ADCFunction[i]( value );
            j++;
        }
    }
    IFS1bits.AD1IF = 0;
}
ADC_TIMER_INTERRUPT() {
    // This is where we'll check the ADC....
    int i;
    for (i = 0; i < 16; ++i) {
        if (ADCData.ADCEnabled[i]) {
            ADCData.ADCFunction[i]( ADCRead(i) );
        }
    }
    ADC_TIMER_INTFLAG = 0; // Clear Timer1 interrupt flag
}
