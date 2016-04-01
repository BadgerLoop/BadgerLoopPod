/******************************************************************************
 * SparkFun_VL6180x.c
 * Library for VL6180x time of flight range finder.
 * Originally written by Casey Kuhns @ SparkFun Electronics on 10/29/2014
 * https://github.com/sparkfun/SparkFun_ToF_Range_Finder-VL6180_Arduino_Library
 * 
 * The VL6180x by ST micro is a time of flight range finder that
 * uses pulsed IR light to determine distances from object at close
 * range.  The average range of a sensor is between 0-200mm
 * 
 * In this file are the functions in the VL6180x class
 ******************************************************************************/
#include "VL6180X.h"

// Only for testing... not exact and should be deleted soon!
void delay(uint16_t ms) {
    uint32_t counter = 0;
    while (counter < 32000*ms) {
        counter++;
    }
}

void VL6180XInit(VL6180X* self, uint8_t deviceAddress) {
    self->address = deviceAddress;
    self->distance = 0;
    self->ambientLight = 0;
    self->getDistance = &getDistance;
    self->getAmbientLight = &getAmbientLight;
    VL6180XInitialize(self);
}

bool VL6180XInitialize(VL6180X* self){
    // Get ID info
    I2C16bitReadByte(self->address, VL6180X_IDENTIFICATION_MODEL_ID, &(self->idModel));
    I2C16bitReadByte(self->address, VL6180X_IDENTIFICATION_MODEL_REV_MAJOR, &(self->idModelRevMajor));
    I2C16bitReadByte(self->address, VL6180X_IDENTIFICATION_MODEL_REV_MINOR, &(self->idModelRevMinor));
    I2C16bitReadByte(self->address, VL6180X_IDENTIFICATION_MODULE_REV_MAJOR, &(self->idModuleRevMajor));
    I2C16bitReadByte(self->address, VL6180X_IDENTIFICATION_MODULE_REV_MINOR, &(self->idModuleRevMinor));
    I2C16bitReadWord(self->address, VL6180X_IDENTIFICATION_DATE_HI, &(self->idDate));
    I2C16bitReadWord(self->address, VL6180X_IDENTIFICATION_TIME_HI, &(self->idTime));
    
    uint8_t data;
    I2C16bitReadByte(self->address, VL6180X_SYSTEM_FRESH_OUT_OF_RESET, &data);
    if (data != 1) return false;
    // Mandatory register settings, required by datasheet at:
    //    http://www.st.com/st-web-ui/static/active/en/resource/technical/document/application_note/DM00122600.pdf
    I2C16bitWriteByte(self->address, 0x0207, 0x01);
    I2C16bitWriteByte(self->address, 0x0208, 0x01);
    I2C16bitWriteByte(self->address, 0x0096, 0x00);
    I2C16bitWriteByte(self->address, 0x0097, 0xfd);
    I2C16bitWriteByte(self->address, 0x00e3, 0x00);
    I2C16bitWriteByte(self->address, 0x00e4, 0x04);
    I2C16bitWriteByte(self->address, 0x00e5, 0x02);
    I2C16bitWriteByte(self->address, 0x00e6, 0x01);
    I2C16bitWriteByte(self->address, 0x00e7, 0x03);
    I2C16bitWriteByte(self->address, 0x00f5, 0x02);
    I2C16bitWriteByte(self->address, 0x00d9, 0x05);
    I2C16bitWriteByte(self->address, 0x00db, 0xce);
    I2C16bitWriteByte(self->address, 0x00dc, 0x03);
    I2C16bitWriteByte(self->address, 0x00dd, 0xf8);
    I2C16bitWriteByte(self->address, 0x009f, 0x00);
    I2C16bitWriteByte(self->address, 0x00a3, 0x3c);
    I2C16bitWriteByte(self->address, 0x00b7, 0x00);
    I2C16bitWriteByte(self->address, 0x00bb, 0x3c);
    I2C16bitWriteByte(self->address, 0x00b2, 0x09);
    I2C16bitWriteByte(self->address, 0x00ca, 0x09);  
    I2C16bitWriteByte(self->address, 0x0198, 0x01);
    I2C16bitWriteByte(self->address, 0x01b0, 0x17);
    I2C16bitWriteByte(self->address, 0x01ad, 0x00);
    I2C16bitWriteByte(self->address, 0x00ff, 0x05);
    I2C16bitWriteByte(self->address, 0x0100, 0x05);
    I2C16bitWriteByte(self->address, 0x0199, 0x05);
    I2C16bitWriteByte(self->address, 0x01a6, 0x1b);
    I2C16bitWriteByte(self->address, 0x01ac, 0x3e);
    I2C16bitWriteByte(self->address, 0x01a7, 0x1f);
    I2C16bitWriteByte(self->address, 0x0030, 0x00);
   
    // Recommended settings from datasheet:
    //    http://www.st.com/st-web-ui/static/active/en/resource/technical/document/application_note/DM00122600.pdf
    I2C16bitWriteByte(self->address, VL6180X_SYSTEM_INTERRUPT_CONFIG_GPIO, 0x24 );
    I2C16bitWriteByte(self->address, VL6180X_SYSTEM_MODE_GPIO1, 0x10); // Sets GPIO for interrupt output
    I2C16bitWriteByte(self->address, VL6180X_READOUT_AVERAGING_SAMPLE_PERIOD, 0x30); //Set Avg sample period
    I2C16bitWriteByte(self->address, VL6180X_SYSALS_ANALOGUE_GAIN, 0x46); // Set the ALS gain of 1
    I2C16bitWriteByte(self->address, VL6180X_SYSRANGE_VHV_REPEAT_RATE, 0xFF); // Set auto calibration period (Max = 255)/(OFF = 0)
    I2C16bitWriteByte(self->address, VL6180X_SYSALS_INTEGRATION_PERIOD, 0x63); // Set ALS integration time to 100ms
    I2C16bitWriteByte(self->address, VL6180X_SYSRANGE_VHV_RECALIBRATE, 0x01); // perform a single temperature calibration
    // Additional settings from Arduino community
    I2C16bitWriteByte(self->address, VL6180X_SYSRANGE_INTERMEASUREMENT_PERIOD, 0x09); // Set default ranging inter-measurement period to 10ms
    I2C16bitWriteByte(self->address, VL6180X_SYSALS_INTERMEASUREMENT_PERIOD, 0x0A); // Set default ALS inter-measurement period to 10ms
    I2C16bitWriteByte(self->address, VL6180X_SYSTEM_INTERRUPT_CONFIG_GPIO, 0x24); // Configures interrupt on ‘New Sample Ready threshold event’ 
    I2C16bitWriteByte(self->address, VL6180X_SYSRANGE_MAX_CONVERGENCE_TIME, 0x32);
    I2C16bitWriteByte(self->address, VL6180X_SYSRANGE_RANGE_CHECK_ENABLES, 0x10 | 0x01);
    I2C16bitWriteWord(self->address, VL6180X_SYSRANGE_EARLY_CONVERGENCE_ESTIMATE, 0x007B );
    I2C16bitWriteWord(self->address, VL6180X_SYSALS_INTEGRATION_PERIOD, 0x0064);
    I2C16bitWriteByte(self->address, VL6180X_READOUT_AVERAGING_SAMPLE_PERIOD,0x30);
    I2C16bitWriteByte(self->address, VL6180X_SYSALS_ANALOGUE_GAIN,0x40);
    I2C16bitWriteByte(self->address, VL6180X_FIRMWARE_RESULT_SCALER,0x01);
    // Clears the FRESH_OUT_OF_RESET bit to signal initialization is complete.
    //I2C16bitWriteByte(self->address, VL6180X_SYSTEM_FRESH_OUT_OF_RESET, 0x00);
    return true;
}

uint8_t getDistance(VL6180X* self) {
    I2C16bitWriteByte(self->address, VL6180X_SYSRANGE_START, 0x01);
    delay(100);
    uint8_t dis;
    I2C16bitReadByte(self->address, VL6180X_RESULT_RANGE_VAL, &dis);
    self->distance = dis;
    return dis;
    //I2C16bitWriteByte(self->address, VL6180X_SYSTEM_INTERRUPT_CLEAR, 0x07);
    //	return distance;
}

/* Need to test/fix - Steve */
float getAmbientLight(VL6180X* self, vl6180x_als_gain VL6180X_ALS_GAIN) { //vl6180x_als_gain VL6180X_ALS_GAIN))
    //First load in Gain we are using, do it everytime incase someone changes it on us.
    //Note: Upper nibble shoudl be set to 0x4 i.e. for ALS gain of 1.0 write 0x46
    I2C16bitWriteByte(self->address, VL6180X_SYSALS_ANALOGUE_GAIN, (0x40 | VL6180X_ALS_GAIN)); // Set the ALS gain

    //Start ALS Measurement 
    I2C16bitWriteByte(self->address, VL6180X_SYSALS_START, 0x01);

    delay(100); //give it time... 

    I2C16bitWriteByte(self->address, VL6180X_SYSTEM_INTERRUPT_CLEAR, 0x07);

    //Retrieve the Raw ALS value from the sensoe
    unsigned int alsRaw;
    I2C16bitReadByte(self->address, VL6180X_RESULT_ALS_VAL, &alsRaw);

    //Get Integration Period for calculation, we do this everytime incase someone changes it on us.
    unsigned int alsIntegrationPeriodRaw;
    I2C16bitReadByte(self->address, VL6180X_SYSALS_INTEGRATION_PERIOD, &alsIntegrationPeriodRaw);

    float alsIntegrationPeriod = 100.0 / alsIntegrationPeriodRaw ;

    //Calculate actual LUX from Appnotes

    float alsGain = 0.0;

    switch (VL6180X_ALS_GAIN){
        case GAIN_20: alsGain = 20.0; break;
        case GAIN_10: alsGain = 10.32; break;
        case GAIN_5: alsGain = 5.21; break;
        case GAIN_2_5: alsGain = 2.60; break;
        case GAIN_1_67: alsGain = 1.72; break;
        case GAIN_1_25: alsGain = 1.28; break;
        case GAIN_1: alsGain = 1.01; break;
        case GAIN_40: alsGain = 40.0; break;
    }

    //Calculate LUX from formula in AppNotes

    float alsCalculated = (float)0.32 * ((float)alsRaw / alsGain) * alsIntegrationPeriod;
    self->ambientLight = alsCalculated;
    return alsCalculated;
}