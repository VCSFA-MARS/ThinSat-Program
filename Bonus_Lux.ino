//////////////////////////////////////////////
// This code reads LUX and displays the data on the OLED
// Uses OD01, CW01, IP01, SL01 xChips
// Written by E. Bujold
/////////////////////////////////////////////

#include <xCore.h>  //This library makes the processor usable
#include <xSL01.h>  //This library makes the light sensor usable
#include <xOD01.h>  //This library makes the OLED screen usable

int max_val = 0;    // Define max variable
int RED = 12;       
int GREEN = 13;

void setup() {
// These first commands prepare the xSystem, by starting the chips
// This section will run only once

Wire.begin(2,14); // Start the I2C Communication with xSystem
OLED.begin();     // Turn on the OLED display
SL01.begin();     // Start the  SL01 Sensor

pinMode (GREEN, OUTPUT); 
pinMode (RED, OUTPUT);

OD01.set2X();     // Set the font size to large
OD01.println("===========");
OD01.println(" Bonus LUX ");
OD01.println("===========");
OD01.set1X();     // Set the font size to small

delay(5000);    //delay before beginning loop function
}

void loop() {
// This is where the body of the program is
// This section will repeat indefinitely

OD01.clear();                         // Clear the display
SL01.poll();                          // Poll Sensor for collect data

OD01.println("Current Light Level: ");  
OD01.print(SL01.getLUX());            // Print current value
OD01.println(" lux");

  if (SL01.getLUX() <= 150){          // If the lux level is less than 150
    digitalWrite (RED, HIGH);         // Turn LED on
    OD01.println ("~~~~~~~~~~~~~~~~~");
    OD01.println ("It's dark!");      // Then print this information
  }  

  if (SL01.getLUX()> max_val) {       // If Lux is greater than previous max
    max_val = SL01.getLUX();          // Update max value
    digitalWrite (GREEN, HIGH);       // Turn LED on
    OD01.println ("~~~~~~~~~~~~~~~~~");
    OD01.println ("It's Bright!");    // Then print this information
  }
  
OD01.println ("~~~~~~~~~~~~~~~~~");
OD01.println ("Max Light Level:");
OD01.print( max_val);                 // Print Max value
OD01.println(" lux");


delay(2000);                          // Two second delay before restarting the loop
digitalWrite (GREEN, LOW);            // Turn off any LEDs that are on
digitalWrite (RED, LOW);
}
