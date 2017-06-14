///////////////////////////////////////////////
//This program prints "Hello World" on xChip OD01
//This is the code pre-modification
//Written by E. Bujold
//////////////////////////////////////////////

#include "xCore.h"  //This library makes the processor usable
#include "xOD01.h"  //This library makes the OLED screen usable

void setup() {  
// These first commands prepare the xSystem, by starting the chips
// This section will run only once

Wire.begin(2,14); // Starts the communication with the xSystem
OLED.begin();     // Turn on the OLED Display OD01
}

void loop() {
// This is where the body of the program is
// This is the section we will be modifying
// This section will repeat indefinitely

OD01.set1X();   // set display text to normal size

OD01.println("Hello World") ; // Display text on the OLED Screen

delay(2000);   // two second delay before executing the next command

OD01.clear();  // Sends a command to the OD01 to clear the display

//The program will now repeat from the top of void loop()
}
