//////////////////////////////////////////////
// This code oscillates the blue LED.
// Uses  CW01, IP01 xChips
// Written by E. Bujold
/////////////////////////////////////////////

#include <xCore.h>  //This library makes the processor usable

// Only the blue LED is an analog connection
int BLUE = 5;

void setup() {
Wire.begin(2,14); // Start the I2C Communication with xSystem

pinMode( BLUE,  OUTPUT);
}

void loop() {

  for (int i = 0; i < 256; i++) {
  // Increase brightness from min to max
    analogWrite(BLUE, i);
    delay(5);
    if (i == 255){
    // When max brightness is reached:
       for (i; i > 0; i--) {
       // Decrease brightness from max to min
          analogWrite(BLUE, i);
          delay(5);
       }
     }
   }
 }
