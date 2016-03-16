#include "usbDebug.h"

#define DESIRED_BAUD 235294    // Odd number, but is almost exact.

void USBDebugInit() {
    // Set the baud rate.
    U1MODEbits.BRGH = 0;
    U1BRG = ((GetPeripheralClock() / DESIRED_BAUD) / 16) - 1;
    // 8 bit, no parity bit, and 1 stop bit (8N1 setup)
    U1MODEbits.PDSEL = 0;
    U1MODEbits.STSEL = 0;
    // configure TX & RX pins as output & input pins
    U1STAbits.UTXEN = 1;
    U1STAbits.URXEN = 1;
    // DO NOT use hardware flow control
    U1MODEbits.UEN = 0;
    // enable the uart
    U1MODEbits.ON = 1;
}

// Read from UART1 until you get a '\r' or '\n'
void ReadUART1(char * message, int maxLength) {
    char data = 0;
    int complete = 0, num_bytes = 0;
    // loop until you get a '\r' or '\n'
    while (!complete) {
        if (U1STAbits.URXDA) {
            data = U1RXREG;
            if ((data == '\n') || (data == '\r')) {
                complete = 1;
            } else {
                message[num_bytes] = data;
                ++num_bytes;
                if (num_bytes >= maxLength) {
                    num_bytes = 0;
                }
            }
        }
    }
    message[num_bytes] = '\0';
}

// Write a character array using UART1
void WriteUART1(const char * string) {
    while (*string != '\0') {
        while (U1STAbits.UTXBF) {
            ; // wait until tx buffer isn't full
        }
        U1TXREG = *string;
        ++string;
    }
}
