#include "Filters/kalman.h"
#include "config.h"


uint16_t temperatureRaw;
uint8_t temperature;
uint8_t i;

void setup() {
  	// put your setup code here, to run once:
  	Serial.begin(115200);
 	delay(INIT_DELAY); 

 	// Converge the kalman filter at startup
 	for (i=0; i<20; i++) {
 		temperatureRaw = (analogRead(A0) >> 1);		// Devide the value by 2 to get the acctual temperature in Celcius
		temperature = kalmanFilter(temperatureRaw);	// Apply kalman filter to smoothen out the values
		delay(100);	
 	}
}

void loop() {
	// Get Raw Temperature sensor(LM35) data from ADC 
	temperatureRaw = (analogRead(A0) >> 1);		// Devide the value by 2 to get the acctual temperature in Celcius
	temperature = kalmanFilter(temperatureRaw);	// Apply kalman filter to smoothen out the values


	Serial.println(TS_connect);
	delay(2000);
	Serial.println(TS_size);
	delay(2000);
	Serial.print(TS_payload);
	if(temperature < 10) {
		Serial.print('0');
	}
	Serial.println(temperature);
	delay(INTERVAL);
}




