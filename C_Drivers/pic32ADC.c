#include <math.h>

void DisplayTemperature(void)
{
	
	const float Vcc = 3.3;
	const float R2 = 10, R3 = 10;
	unsigned int ADC_Value = 0;
	float VoltageOutput = 0.0;
	unsigned int TemperatureResistance = 0;

	const float A = 1.032935491,
				B = 2.384223307,
				C = 1.601529131
				
				R25 = 980.0;

	float ResistanceRatio = 0.0;
		Temperature = 0.0;

	unsigned char Unit = 0;

	//ADC_Value = adc function call

	VoltageOutput = ((float)(ADC_Value))* 0.0032226;

	TemperatureResistance = (unsigned int)(((R2 * Vcc) - ((R2 + R3) * VoltageOutput)) / (VoltageOutput - Vcc));

	ResistanceRatio = TemperatureResistance/R25;

	Temperature = (A * powf(ResistanceRatio, 3.0) - (B * powf(ResistanceRatio, 2.0)) + ((C * ResistanceRatio) - D));

	
	float Vin = 3.3;
	float Vout = 0;
	float R1 = 10000;
	float R2 = 10000;
	float R3 = 10000;
	float Rx = 10000;
	float Vb = Vin*((Rx / (R3 + Rx)) - (R2 / (R1 + R2)));
	float Resistance = 0;

  	Vout = analogRead(A0) * (Vin / 1023.0);  // Vout = 0. (assuming all resistors are 1000

  	float Rg = (( R3 * Vin) / (Vout + (( R2 * Vin) / (R1 + R2))) - R3);

  	int analogRead(char analogPin)
  	{
  		AD1CHS = analogPIN << 16;

  		AD1CON1bits.SAMP = 1;
  		while(AD1CON1bits.SAMP);
  		while (! AD1CON1bits.DONE);

  		return ADC1BUF0;
  	}

  	void delay_us( unsigned t)          // See Timers tutorial for more info on this function
	{
    	T1CON = 0x8000;                 // enable Timer1, source PBCLK, 1:1 prescaler
 
    	// delay 100us per loop until less than 100us remain
    	while( t >= 100)
    	{
        	t-=100;
        	TMR1 = 0;
        	while( TMR1 < SYSCLK/10000);
    	}
 
    	// delay 10us per loop until less than 10us remain
    	while( t >= 10){
        	t-=10;
        	TMR1 = 0;
        	while( TMR1 < SYSCLK/100000);
    	}
 
    	// delay 1us per loop until finished
   	 	while( t > 0)
    	{
        	t--;
        	TMR1 = 0;
        	while( TMR1 < SYSCLK/1000000);
    	}
 
    	// turn off Timer1 so function is self-contained
    	T1CONCLR = 0x8000;

	} // END delay_us()
 
	void adcConfigureManual()
	{
    	AD1CON1CLR = 0x8000;    // disable ADC before configuration
 
    	AD1CON1 = 0x00E0;       // internal counter ends sampling and starts conversion (auto-convert), manual sample
    	AD1CON2 = 0;            // AD1CON2<15:13> set voltage reference to pins AVSS/AVDD
    	AD1CON3 = 0x0f01;       // TAD = 4*TPB, acquisition time = 15*TAD
	} // END adcConfigureManual()
 
 	
int main( void)
{
	SYSTEMConfigPerformance(SYSCLK);
 
        // Configure pins as analog inputs
        ANSELBbits.ANSB3 = 1;   // set RB3 (AN5) to analog
        TRISBbits.TRISB3 = 1;   // set RB3 as an input
        TRISBbits.TRISB5 = 0;   // set RB5 as an output (note RB5 is a digital only pin)
 
        adcConfigureManual();   // Configure ADC
        AD1CON1SET = 0x8000;    // Enable ADC
 
        int foo;
	while ( 1)
	{
            foo = analogRead( 5); // note that we call pin AN5 (RB3) by it's analog number
            delay_us( foo);       // delay according to the voltage at RB3 (AN5)
            LATBINV = 0x0020;     // invert the state of RB5
	}
 
	return 0;
}


