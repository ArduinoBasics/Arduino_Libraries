/*-----------------------------------------------------------------
*                           CPP FILE for ToggleTimer
* Library Descriptionn: 	A special non-blocking library to toggle between two states
*	  	  Library Name:		ToggleTimer
*	
*	            Author: 	Scott C / ArduinoBasics
*		   	   Version:		2.0
*	      Date Created:		14 Dec 2019
-------------------------------------------------------------------*/


#include "Arduino.h"
#include "ToggleTimer.h"

ToggleTimer::ToggleTimer(){
	_delayONE=0;							// Set the delayONE to zero
	_delayTWO=0;							// Set the delayTWO to zero
	_state=3;								// _state: 1=FIRST, 2=SECOND, 3=Disabled
}


int ToggleTimer::getState(){
	return(_state);
}

bool ToggleTimer::duration(unsigned long delay_1, unsigned long delay_2){
    _returnVal2 = false;	
	
	if(_state==3){
		_delayONE = delay_1;				//set the delay for delayONE
		_delayTWO = delay_2;				//set the delay for delayTWO	
		_state = 1;							//now that the variables have been initialised, move to FIRST state
		_startTime = millis();				//start the timer for the FIRST state
	}

	if(_state==1){							//We are now in the FIRST state
		
		_returnVal2 = true;					//Return TRUE while in the FIRST state
		
		if(isTimeExpired(_delayONE)){		//Check if the time has expired
			_delayONE = 0;					//reset the delay to zero
			_state = 2;						//move to SECOND State 
			_startTime = millis();			//start timer for SECOND state
		}
	}

	if(_state==2){							//We are now in the SECOND state
		
		_returnVal2 = false;				//Return FALSE while in the SECOND state
		
		if(isTimeExpired(_delayTWO)){		//Check if the time has expired
			_delayTWO = 0;					//reset the delay to zero
			_state = 3;						//move to Disabled state
		}
	}

	return(_returnVal2);
}


bool ToggleTimer::isTimeExpired(unsigned long delay){
	_returnVal3 = false;					//dafault is false;
	_testTime = millis();					//The time to test against the start time
	
	
	if(_testTime < _startTime) {
		_startTime= millis();				//correct for millis() overflow
	}

	//Check if the the amount of time elapsed during this state has exceeded the delay
	if((_testTime-_startTime)>delay){ 
		_returnVal3 = true;					//time is expired, return TRUE   
	}
	return(_returnVal3);
}
