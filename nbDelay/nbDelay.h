/*-----------------------------------------------------------------
*                           HEADER FILE for nbDelay
* Library Descriptionn: 	A special non-blocking delay library
*	  	  Library Name:		nbDelay
*	
*	        Programmer: 	Scott C / ArduinoBasics
*		   	   Version:		1.0
*	      Date Created:		14 Dec 2019
-------------------------------------------------------------------*/

// Check to make sure the library is not already defined.
#ifndef nbDelay_h 

// Define the header file   
#define nbDelay_h  

// Provide access to the standard Arduino types and constants  
#include "Arduino.h" 

//Create the class nbDelay
class nbDelay{
	public:	
		nbDelay();
		bool Delay(unsigned long delay_1, unsigned long delay_2);
	private:
		unsigned long _delayUP, _delayDOWN, _startTime, _testTime;
		bool isTimeExpired(unsigned long delay); 
		bool _returnVal1,_returnVal2;
		int _state;
};

#endif
