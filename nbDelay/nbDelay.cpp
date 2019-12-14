/*-----------------------------------------------------------------
*                           CPP FILE for nbDelay
* Library Descriptionn: 	A special non-blocking delay library
*	  	  Library Name:		nbDelay
*	
*	        Programmer: 	Scott C / ArduinoBasics
*		   	   Version:		1.0
*	      Date Created:		14 Dec 2019
-------------------------------------------------------------------*/


#include "Arduino.h"
#include "nbDelay.h"

nbDelay::nbDelay(){
	_delayUP=0;				 // Set the delayUP to zero
	_delayDOWN=0;            // Set the delayDOWN to zero
	_state=3;                // _state: 1=UP, 2=DOWN, 3=Disabled
}

bool nbDelay::Delay(unsigned long delay_1, unsigned long delay_2){
    _returnVal1 = false;	
	
	if(_state==3){
		_delayUP = delay_1;     //set the delay for the UP state
		_delayDOWN = delay_2;   //set the delay for the DOWN state	
		_state = 1;             //now that the variables have been initialised, move to UP state
		_startTime = millis();  //start the timer for the UP state
	}

	if(_state==1){						//We are now in the UP state
		
		_returnVal1 = true;				//Return TRUE while in the UP state
		
		if(isTimeExpired(_delayUP)){    //Check if the time has expired
			_delayUP = 0;         		//reset the delay to zero
			_state = 2;                 //move to DOWN State 
			_startTime = millis();      //start timer for DOWN state
		}
	}

	if(_state==2){						  //We are now in the DOWN state
		
		_returnVal1 = false;			  //Return FALSE while in the DOWN state
		
		if(isTimeExpired(_delayDOWN)){    //Check if the time has expired
			_delayDOWN = 0;         	  //reset the delay to zero
			_state = 3;                   //move to Disabled state
		}
	}

	return(_returnVal1);
}


bool nbDelay::isTimeExpired(unsigned long delay){
	_returnVal2 = false;       //dafault is false;
	
	_testTime = millis();	   //The time to test against the start time
	
	//Check if the the amount of time elapsed during this state has exceeded the delay
	if((_testTime-_startTime)>delay){ 

		//time is expired, return TRUE
		_returnVal2 = true;       
	
	}
	return(_returnVal2);
}
