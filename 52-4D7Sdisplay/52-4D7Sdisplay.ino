#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

void setup() {
  byte numDigits = 4;
                   // d1 d2 d3 d4
  byte digitPins[] = {2, 3, 4, 5};
                      //a  b  c  d  e   f   g   .
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default. Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(10);
}

void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;
  
  if (millis() - timer >= 100) {
    timer += 100;
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
    
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }
    sevseg.setNumber(deciSeconds, 1);
  }
  //sevseg.setNumber(8888); // Displays '3.141'
  //delay(1000);
  
  sevseg.refreshDisplay(); // Must run repeatedly
}
