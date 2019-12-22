/*-----------------------------------------------------------------
*                           HEADER FILE for ToggleTimer
* Library Descriptionn: 	A special non-blocking library to toggle between two states
*	  Library Name:		ToggleTimer
*	
*	        Author: 	Scott C / ArduinoBasics
*      	       Version:		1.0
*	  Date Created:		14 Dec 2019
-------------------------------------------------------------------*/

// Check to make sure the library is not already defined.
#ifndef ToggleTimer_h 

// Define the header file   
#define ToggleTimer_h  

// Provide access to the standard Arduino types and constants  
#include "Arduino.h" 

//Create the class toggleTimer
class ToggleTimer{
	public:	
		ToggleTimer();
		bool duration(unsigned long delay_1, unsigned long delay_2);
		int getState();
	private:
		unsigned long _delayONE, _delayTWO, _startTime, _testTime;
		bool isTimeExpired(unsigned long delay); 
		bool _returnVal1,_returnVal2,_returnVal3;
		int _state;
};

#endif
