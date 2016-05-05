#include <xc.h>
#include <sys/attribs.h>
#include <stdint.h>
#include <string.h>

// If we want a baud of 115200,

#define BRATE   138
#define DELAY1MS        64000
#define DELAY1US        64
#define T1CONSETTING    0x8000      // 1:1 prescale

void beginSerial(void);
int SerialAvailable(void);
void getMessage(char * string, int maxLength);
void print(const char * string);
void println(const char * string);
void checkSerialErrors(void);
void printByte(uint8_t byte);
void printWord(uint16_t word);
void sendByte(uint8_t byte);

// For Shield
#define RED1        LATAbits.LATA3
#define RED2        LATAbits.LATA2
#define YELLOW1     LATCbits.LATC4
#define YELLOW2     LATDbits.LATD4
#define GREEN1      LATDbits.LATD3
#define GREEN2      LATDbits.LATD12
#define BUTTONPWR   LATGbits.LATG1
#define BUTTONSIG   PORTGbits.RG0