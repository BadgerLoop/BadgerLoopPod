#include <stdbool.h>

struct ADC ADCData;

void ADCInit(int frequency, bool useTimer);
int ADCAdd(unsigned char pin, void (*func)(int));
int ADCRead(unsigned char);

// TODO: We could use a single integer for the enabled bits...
struct ADC {
    int ADCEnabled[16];
    void (*ADCFunction[16])(int);
    int ADCValue[16];
    int count;
    int frequency;
    bool useTimer;
};

/* IMPORTANT! Use only timers 2-5 for this, the prescalar for timer 1
 * is different from the others! */
#define ADC_TIMER_INTERRUPT() void __ISR(_TIMER_5_VECTOR, IPL5SOFT) ADCTimerISR(void)
#define ADC_TIMER_TMR       TMR5
#define ADC_TIMER_PR        PR5
#define ADC_TIMER_TCKPS     T5CONbits.TCKPS
#define ADC_TIMER_TGATE     T5CONbits.TGATE
#define ADC_TIMER_TCS       T5CONbits.TCS
#define ADC_TIMER_ON        T5CONbits.ON
#define ADC_TIMER_INTPRI    IPC5bits.T5IP
#define ADC_TIMER_INTSECPRI IPC5bits.T5IS
#define ADC_TIMER_INTFLAG   IFS0bits.T5IF
#define ADC_TIMER_INTENABLE IEC0bits.T5IE

/* Automatic ADC Conversions
 * In order to get a decent sampling frequency with automatic sampling
 * we must first do some fancy math to get a good sampling time. It's
 * important to note that the ADC operates off of a clock called Tad.
 * This clock (for our case) is based off of the PBCLK and can be
 * determined via:
 *                  Tad = 2 * Tpb * (AD1CON3bits.ADCS + 1)
 * Where Tpb is 1/PBCLK and bit ADCS is set by us with a range of
 * 0-255. 
 * 
 * Now we're only half way there! Tad is used for two main things.
 *  1) Sampling Time
 *  2) Convert Time
 * The sampling time is determined via bit AD1CON3bits.SAMC and has a range
 * of 1-31. The convert time is automatic and has a length of 12 Tad. Tad can
 * also be a rough estimate as to the length of time required to start the
 * sampling and start the conversion (delay between the two), and is usually
 * just 1 Tad. I'm not yet sure if this will decrease in our usage since Tad
 * will be fairly long. Tests should give us a better approximation.
 * 
 * This means that each conversion takes approximately:
 *          Time/Input = SAMC * Tad + 12 * Tad + 1 * Tad (delay)
 *          Time/Input = Tad * (SAMC + 12 + 1)
 *          Time/Input = Tad * (SAMC + 13)
 *          Time/Input = 2 * Tpb * (ADCS + 1) * (SAMC + 13)
 * 
 * Time/Input has it's own individual formula as well - it is determined by
 * both the frequency at which we want to sample and how many inputs we have:
 *          Time/Input = 1 / frequency / inputs
 * i.e. if we want to sample at 1kHz and we only have 1 input, that one input
 * will be sampled for 1ms before an interrupt should be thrown. If we have 2
 * inputs, then each input needs to be sampled for 0.5ms before throw an
 * interrupt.
 * 
 * As a final note, it is important to understand that there is a minimum
 * frequency possible with this method. Given a PBCLK of 64MHz, a max ADCS
 * value of 255, and a max SAMC value of 31 - the maximum time you can 
 * sample a single input is about 0.35ms, or 2852Hz - you can't do 1kHz!
 * With 2 inputs, the slowest you can sample is 1426 Hz. At 3 inputs, you
 * can just barely sample at 1kHz.
 * 
 * The following macros were created using the ADC_auto_calc worksheet
 * in the utils directory.
 */
#define ADC_SET_1_INPUT_TIMING AD1CON3bits.ADCS = 255; AD1CON3bits.SAMC = 31;
#define ADC_SET_2_INPUT_TIMING AD1CON3bits.ADCS = 255; AD1CON3bits.SAMC = 31;
#define ADC_SET_3_INPUT_TIMING AD1CON3bits.ADCS = 255; AD1CON3bits.SAMC = 30;
#define ADC_SET_4_INPUT_TIMING AD1CON3bits.ADCS = 255; AD1CON3bits.SAMC = 19;
#define ADC_SET_5_INPUT_TIMING AD1CON3bits.ADCS = 255; AD1CON3bits.SAMC = 13;
#define ADC_SET_6_INPUT_TIMING AD1CON3bits.ADCS = 255; AD1CON3bits.SAMC = 9;
#define ADC_SET_7_INPUT_TIMING AD1CON3bits.ADCS = 255; AD1CON3bits.SAMC = 6;
#define ADC_SET_8_INPUT_TIMING AD1CON3bits.ADCS = 250; AD1CON3bits.SAMC = 4;
#define ADC_SET_9_INPUT_TIMING AD1CON3bits.ADCS = 237; AD1CON3bits.SAMC = 3;
#define ADC_SET_10_INPUT_TIMING AD1CON3bits.ADCS = 213; AD1CON3bits.SAMC = 3;
#define ADC_SET_11_INPUT_TIMING AD1CON3bits.ADCS = 208; AD1CON3bits.SAMC = 2;
#define ADC_SET_12_INPUT_TIMING AD1CON3bits.ADCS = 190; AD1CON3bits.SAMC = 2;
#define ADC_SET_13_INPUT_TIMING AD1CON3bits.ADCS = 164; AD1CON3bits.SAMC = 3;
#define ADC_SET_14_INPUT_TIMING AD1CON3bits.ADCS = 152; AD1CON3bits.SAMC = 3;
#define ADC_SET_15_INPUT_TIMING AD1CON3bits.ADCS = 142; AD1CON3bits.SAMC = 3;
#define ADC_SET_16_INPUT_TIMING AD1CON3bits.ADCS = 133; AD1CON3bits.SAMC = 3;
#define ADC_AUTO_INTERRUPT() void __ISR(_ADC_VECTOR, IPL5SOFT) ADCAutoISR(void)