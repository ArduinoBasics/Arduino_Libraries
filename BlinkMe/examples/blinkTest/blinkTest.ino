/*
Filename: 		blinkTest.ino
Example sketch: Testing the BlinkMe library
Author: 		Scott C / ArduinoBasics
Date:			28th Nov 2019
Microcontroller: Arduino UNO
IDE Version: 1.8.5 (Windows 10)
https://github.com/ArduinoBasics/Arduino_Libraries/tree/master/BlinkMe
*/

#include <BlinkMe.h>
BlinkMe bM;

void setup(){
	bM.setOUTPUT(13);        //Blink on Digital Pin 13
}

void loop(){
	bM.blink(1000);           //Blink ON for 1 second, OFF for 1 second (1000 millis)	
	bM.blink(2000);			  //Blink ON for 2 seconds, OFF for 2 seconds
}
