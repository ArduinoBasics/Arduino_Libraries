/*-------------------------------------------------	----------------
*                           HEADER FILE for BlinkMe
* Library Descriptionn: 	Simplifying LED blinking
*	  	  Library Name:		BlinkMe
*	
*	            Author: 	Scott C / ArduinoBasics
*		   	   Version:		1.0
*	      Date Created:		28 Dec 2019
-------------------------------------------------------------------*/

// Check to make sure the library is not already defined.
#ifndef BlinkMe_h 

// Define the header file   
#define BlinkMe_h  

// Provide access to the standard Arduino types and constants  
#include "Arduino.h" 

//Create the class BlinkMe
class BlinkMe{
	public:	
		BlinkMe();
		void setOUTPUT(int dPin);
		void blink(unsigned long delay_1);
	private:
		int _dPin;
		unsigned long _delay_1;
};

#endif
