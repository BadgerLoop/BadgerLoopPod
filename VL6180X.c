#include "VL6180X.h"

char *errorMessage = "";
uint8_t errors[2];
uint8_t vlBuffer[255];

void VL_setReg(uint16_t registerAddr, uint8_t value) { I2CwriteByteToRegister(VL_ADDRESS, registerAddr, value); }
void VL_setReg16(uint16_t registerAddr, uint16_t value) { I2CwriteWordToRegister(VL_ADDRESS, registerAddr, value); }

uint8_t VL_getReg(uint16_t registerAddr) { return I2CReadByteFromRegister(VL_ADDRESS, registerAddr); }

void initVL(void) {
    VL_setReg(0x0207, 0x01);
    VL_setReg(0x0208, 0x01);
    VL_setReg(0x0096, 0x00);
    VL_setReg(0x0097, 0xfd);
    VL_setReg(0x00e3, 0x00);
    VL_setReg(0x00e4, 0x04);
    VL_setReg(0x00e5, 0x02);
    VL_setReg(0x00e6, 0x01);
    VL_setReg(0x00e7, 0x03);
    VL_setReg(0x00f5, 0x02);
    VL_setReg(0x00d9, 0x05);
    VL_setReg(0x00db, 0xce);
    VL_setReg(0x00dc, 0x03);
    VL_setReg(0x00dd, 0xf8);
    VL_setReg(0x009f, 0x00);
    VL_setReg(0x00a3, 0x3c);
    VL_setReg(0x00b7, 0x00);
    VL_setReg(0x00bb, 0x3c);
    VL_setReg(0x00b2, 0x09);
    VL_setReg(0x00ca, 0x09);  
    VL_setReg(0x0198, 0x01);
    VL_setReg(0x01b0, 0x17);
    VL_setReg(0x01ad, 0x00);
    VL_setReg(0x00ff, 0x05);
    VL_setReg(0x0100, 0x05);
    VL_setReg(0x0199, 0x05);
    VL_setReg(0x01a6, 0x1b);
    VL_setReg(0x01ac, 0x3e);
    VL_setReg(0x01a7, 0x1f);
    VL_setReg(0x0030, 0x00);
    VL_defautSettings();
    VL_checkStatus();
}

void VL_defautSettings(void) {
  //Recommended settings from datasheet

  //Enable Interrupts on Conversion Complete (any source)
  VL_setReg(VL6180X_SYSTEM_INTERRUPT_CONFIG_GPIO, (4 << 3)|(4) ); // Set GPIO1 high when sample complete

  VL_setReg(VL6180X_SYSTEM_MODE_GPIO1, 0x10); // Set GPIO1 high when sample complete
  VL_setReg(VL6180X_READOUT_AVERAGING_SAMPLE_PERIOD, 0x30); //Set Avg sample period
  VL_setReg(VL6180X_SYSALS_ANALOGUE_GAIN, 0x46); // Set the ALS gain
  VL_setReg(VL6180X_SYSRANGE_VHV_REPEAT_RATE, 0xFF); // Set auto calibration period (Max = 255)/(OFF = 0)
  VL_setReg(VL6180X_SYSALS_INTEGRATION_PERIOD, 0x63); // Set ALS integration time to 100ms
  VL_setReg(VL6180X_SYSRANGE_VHV_RECALIBRATE, 0x01); // perform a single temperature calibration
  
  //Optional settings from datasheet
  VL_setReg(VL6180X_SYSRANGE_INTERMEASUREMENT_PERIOD, 0x09); // Set default ranging inter-measurement period to 100ms
  VL_setReg(VL6180X_SYSALS_INTERMEASUREMENT_PERIOD, 0x0A); // Set default ALS inter-measurement period to 100ms
  VL_setReg(VL6180X_SYSTEM_INTERRUPT_CONFIG_GPIO, 0x24); // Configures interrupt on ?New Sample Ready threshold event? 
  
  //Additional settings defaults from community
  VL_setReg(VL6180X_SYSRANGE_MAX_CONVERGENCE_TIME, 0x32);
  VL_setReg(VL6180X_SYSRANGE_RANGE_CHECK_ENABLES, 0x10 | 0x01);
  VL_setReg16(VL6180X_SYSRANGE_EARLY_CONVERGENCE_ESTIMATE, 0x7B );
  VL_setReg16(VL6180X_SYSALS_INTEGRATION_PERIOD, 0x64);

  VL_setReg(VL6180X_READOUT_AVERAGING_SAMPLE_PERIOD,0x30);
  VL_setReg(VL6180X_SYSALS_ANALOGUE_GAIN,0x40);
  VL_setReg(VL6180X_FIRMWARE_RESULT_SCALER,0x01);
}

uint8_t VL_getDistance() {
    //updateErrors();
    //if (!(errors[0] & 1)) {
    //    println("VL not ready for next operation.");
    //    return 0x00;
    //}  
    uint8_t retval = 0x00;
    VL_setReg(VL6180X_SYSRANGE_START, 0x01);
    delay(10);
    //if (!(VL_getReg(0x4F) & 0x10)) {
    //    println("Sensor wasn't ready for a reading.");
    //    return 0x00;
    //}
    retval = VL_getReg(VL6180X_RESULT_RANGE_VAL);
    //VL_setReg(0x15, 0x07); // need to clear interrupt status bit for range only
    return retval;
}

void updateErrors() { I2CReadConsecutiveRegisters(VL_ADDRESS, 0x4D, 2, errors); }

void VL_checkStatus() {
    updateErrors();
    switch ((errors[0] & 0xf0) >> 4) {
        case 0:
            errorMessage = "No error.";
            break;
        case 1:
            errorMessage = "VCSEL Continuity Test";
            break;
        case 2:
            errorMessage = "VCEL Watchdog Test";
            break;
        case 3:
            errorMessage = "VCEL Watchdog";
            break;
        case 4:
            errorMessage = "PLL1 Lock";
            break;
        case 5:
            errorMessage = "PLL2 Lock";
            break;
        case 6:
            errorMessage = "Early Convergence Estimate";
            break;
        case 7:
            errorMessage = "Max Convergence";
            break;
        case 8:
            errorMessage = "No Target Ignore";
            break;
        case 11:
            errorMessage = "Max Signal To Noise Ratio";
            break;
        case 12:
            errorMessage = "Raw Ranging Algo Underflow";
            break;
        case 13:
            errorMessage = "Raw Ranging Algo Overflow";
            break;
        case 14:
            errorMessage = "Ranging Algo Underflow";
            break;
        case 15:
            errorMessage = "Ranging Algo Overflow";
            break;
    }
    print("Range: ");
    println(errorMessage);
    switch (errors[1]) {
        case 0:
            errorMessage = "No error.";
            break;
        case 1:
            errorMessage = "Overflow error";
            break;
        case 2:
            errorMessage = "Underflow error";
            break;
    }
    print("ALS: ");
    println(errorMessage);
}