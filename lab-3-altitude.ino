/////////////////////////////////////////////////////
// This code displays altitude on the OLED screen
// Written by J. Singh
/////////////////////////////////////////////////////

#include <xCore.h>                //This library allows us to use the CW01 processor
#include <xOD01.h>                //This library allows us to use the OD01 screen
#include <xSW01.h>                //This library allows us to use the weather sensor

void setup() {
  // This setup code will prepare our xSystem for use. It will only run once.

  Wire.begin(2,14);               //Start I2C communication with the xSystem
  OLED.begin();                   //Turn on the OLED Screen
  SW01.begin();                   //Turn on the SW01 sensor

  OD01.set2X();
  OD01.println("===========");    
  OD01.println(" Altitude  ");    //print opening message on OLED Screen
  OD01.println("===========");



  delay(5000);                    //allow SW01 sensor to normalize before starting loop
  OD01.clear();
}

void loop() {
  // This is the body of the code. It will repeat indefinitely.

  OD01.clear();


 //Display Altitude
  float altitude1 = 0;              //declare altitude variable and initialize as zero
  float altitude2 = 0;              //declare second altitude variable for tracking change
  SW01.poll();                      //Tell the SW01 sensor to read and store data
  altitude1 = (SW01.getAltitude()); //set pressure variable equal to the current altitude reading
  delay(500);
  SW01.poll();                      //repeat for second variable
  altitude2 = (SW01.getAltitude());

  float diff= abs(altitude2 - altitude1);   //track change over short period of time

   if(diff>1){                              //if reading spikes very quickly, someone is probably blowing on the sensor
    OD01.println("Altitude");
    OD01.print(altitude2);
    OD01.println(" m");
    OD01.println("It's windy!");
  }
  else{
    OD01.println("Altitude");
    OD01.print(altitude2);
    OD01.println(" m");
  }



  delay(1000);                    //pause for one second then repeat

}
