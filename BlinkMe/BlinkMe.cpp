/*-----------------------------------------------------------------
*                           CPP FILE for BlinkMe
* Library Descriptionn: 	Simplifying LED blinking
*	  	  Library Name:		BlinkMe
*	
*	            Author: 	Scott C / ArduinoBasics
*		   	   Version:		2.0
*	      Date Created:		28 Dec 2019
-------------------------------------------------------------------*/

#inlcude <Arduino.h>
#inlcude <BlinkMe.h>

BlinkMe::BlinkMe(){
	_dPin = 13;   						//default pin is D13 (onboard LED)
}

void setOUTPUT(int dPin){
	_dPin = dPin;
	pinMode(_dPin, OUTPUT);				//Set the digital pin to an OUTPUT
}

void blink(unsigned long delay_1){
	_delay_1 = delay_1;
	digitalWrite(_dPin, HIGH);			//Turn the LED on
	delay(_delay_1);					//Delay
	digitalWrite(_dPin, LOW);			//Turn the LED off
	delay(_delay_1);					//Delay
}
