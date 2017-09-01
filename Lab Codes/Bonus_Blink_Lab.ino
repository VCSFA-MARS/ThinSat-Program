/////////////////////////////
// This lab blinks and changes colors on the CW01 xChip
// IP01, CW01 xChips used
// Written by E. Bujold
/////////////////////////////

#include <xCore.h>  // Needed to make CW01 xChip usable
// Define LED locations and variable names
// The LEDs are soldered in place and cannot be changed.
const int RED = 12;
const int GREEN = 13;
const int BLUE = 5;

void setup() {
// Define use of pins
  pinMode( RED,   OUTPUT);  
  pinMode( GREEN, OUTPUT);
  pinMode( BLUE,  OUTPUT);

}

void loop(){
// This function runs repeatedly
int DWELL = 500;  // Everywhere in the code that says DWELL will be replaced by this number.

int pin = GREEN;   // You can change this to RED, GREEN, or BLUE
  digitalWrite(pin, HIGH);  // Turn on
  delay(DWELL);             // Stay on for dwell time
  digitalWrite(pin, LOW);   // Turn off
  delay(DWELL);             // Stay off for dwell time


pin = BLUE;     // Redefine this pin a different color than the one above
  digitalWrite(pin, HIGH);  // Turn on
  delay(DWELL);             // Stay on for dwell time
  digitalWrite(pin, LOW);   // Turn off
  delay(DWELL);             // Stay off for dwell time
}
