#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <CoreServices/CoreServices.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <unistd.h>
#include <inttypes.h>

int calculateTemperatureEquation(void)
{
    int resistance = 10000;
    float voltage = (310);	//(readThermistorVoltage())*
    float inputVoltage = 3.3;
    float thermistorResistance;
    float inverseTemperature;
    int temperature;
    float a = 1.032935491E-3;
    float b = 2.384223307E-4;
    float c = 1.601529131E-7;
    
    thermistorResistance = resistance*((inputVoltage*resistance - voltage*
            (2*resistance))/(inputVoltage*resistance + voltage*(2*resistance)));
    
    inverseTemperature = a + b*log(thermistorResistance) + 
            c*(pow(log(thermistorResistance), 3));
    
    temperature = (int)1/inverseTemperature;
    return temperature;
}

int main(int argc, char *argv[])
{
    uint64_t        start;
    uint64_t        end;
    uint64_t        elapsed;
    uint64_t        elapsedNano;
	int result;

    static mach_timebase_info_data_t sTimebaseInfo;

    // Start the clock.

    start = mach_absolute_time();

    // Call getpid. This will produce inaccurate results because 
    // we're only making a single system call. For more accurate 
    // results you should call getpid multiple times and average 
    // the results.

    result = calculateTemperatureEquation();
	

    // Stop the clock.

    end = mach_absolute_time();

    // Calculate the duration.

    elapsed = end - start;

    // Convert to nanoseconds.

    // If this is the first time we've run, get the timebase.
    // We can use denom == 0 to indicate that sTimebaseInfo is 
    // uninitialised because it makes no sense to have a zero 
    // denominator is a fraction.

    if ( sTimebaseInfo.denom == 0 ) {
        (void) mach_timebase_info(&sTimebaseInfo);
    }

    // Do the maths. We hope that the multiplication doesn't 
    // overflow; the price you pay for working in fixed point.

    elapsedNano = elapsed * sTimebaseInfo.numer / sTimebaseInfo.denom;

    
	printf("%" PRIu64 "\n", elapsedNano);
	return 0;
	
	

}







