/*  Example Sketch to test the non-blocking delay library (nbDelay)
 *  by: Scott C / ArduinoBasics
 *  Created: 14 Dec 2019
 *  Microcontroller: Arduino UNO
 *  IDE Version: 1.8.5 (Windows)
 *  https://github.com/ArduinoBasics/Arduino_Libraries/tree/master/nbDelay
 */

#include <nbDelay.h>
nbDelay nb;           //Non-blocking delay 

void setup() {
  pinMode(13,OUTPUT); //Set digital pin 13 as an OUTPUT
}

void loop() {
  
  //BLINK WITHOUT DELAY ---------- 
  //  HIGH: 500 millis, 
  //   LOW: 100 millis
  // -----------------------------
  if(nb.Delay(500,100)){      
    digitalWrite(13,HIGH);     //High for 500 millis
  } else {
    digitalWrite(13,LOW);      // Low for 100 millis
  }
}
