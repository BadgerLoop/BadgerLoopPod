#include "honeywellPressure.h"

uint8_t pressureData[4];

void getPressureData(uint8_t addr, uint8_t *data) { I2CRequestFrom(addr, 4, data); }

void printPressureData(uint8_t *data) {
    char toPrint[255];
    uint16_t pressureReading = 0x0000;
    uint16_t temperatureReading = 0x0000;
    int status = (data[0] >> 6) & 3;    // first two bits are status
    pressureReading = (((data[0] & 0x3f) << 8) | data[1]);
    //float pressure = (float) ((data[0] << 8) | data[1]);
    
    double kPa = pressureReading*160.00;
    kPa = kPa / OUTMAX;

    temperatureReading = ((data[2] << 8) | data[3]) >> 5;
    //float temperature = (float) ((data[2] << 8) | data[3]);
    
    double celcius = temperatureReading*200.00;
    celcius = celcius / 2047.00;
    
    sprintf(toPrint, "Status: %d Temperature: %f, Pressure: %f", status, celcius, kPa);
    println(toPrint);
}

void getAndPrintPressureData(uint8_t addr) {
    I2CRequestFrom(addr, 4, pressureData);
    printPressureData(pressureData);
}