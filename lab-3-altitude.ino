/////////////////////////////////////////////////////
// This code displays altitude on the OLED screen
// Written by E. Bujold and J. Singh
/////////////////////////////////////////////////////

#include <xCore.h>    //This library allows us to use the CW01 processor
#include <xOD01.h>    //This library allows us to use the OD01 screen
#include <xSW01.h>    //This library allows us to use the weather sensor

void setup() {
  // This setup code will prepare our xSystem for use. It will only run once.

  Wire.begin(2,14);               //Start I2C communication with the xSystem
  OLED.begin();                   //Turn on the OLED Screen
  SW01.begin();                   //Turn on the SW01 sensor

  OD01.set2X();
  OD01.println("===========");    
  OD01.println(" Altitude  ");    //Print opening message on OLED Screen
  OD01.println("===========");

  delay(5000);                    //Allow SW01 sensor to normalize before starting loop
}

void loop() {
  // This is the body of the code. It will repeat indefinitely.

int count = 1; //Declare counting variable, used in 'for loop'

OD01.clear();               //Refresh display
OD01.set2X();               //Set font size
OD01.println("Altitude:");  //Print header on LED

//Display Altitude
  for (count = 1; count < 6; count++){  
    //'For Loop', if count is less than 6, run the loop, then add 1 to count
    OD01.set1X();                     //Set font size
    SW01.poll();                      //Get sensor reading
    OD01.print(SW01.getAltitude());   //Display sensor reading
    OD01.println(" m");               //Print units
    delay(2000);                      //Pause for two seconds then repeat
  }

}
