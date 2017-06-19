/////////////////////////////////////////////////////
// This code displays altitude and its moving average
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

  OD01.set2X();                   //Set big font size
  OD01.println("===========");    
  OD01.println("AvgAltitude");    //Print opening message on OLED Screen
  OD01.println("===========");

  delay(5000);                    //Allow SW01 sensor to normalize before starting loop
 
}

void loop() {
  // This is the body of the code. It will repeat indefinitely.
  // Declare variables and initialize at zero

  int counter;             //Used for determining sample size
  float altitude = 0;      //Used for instant sensor value
  float sum = 0;           //Used for average calculations
  float avg_alt = 0;       //Holds average calulated value
  
for (counter=1; counter>0; counter++){
    //create a for loop to take a moving average
  OD01.clear();
  SW01.poll();                  //Tell the SW01 sensor to collect instantaneous data
  
  altitude = (SW01.getAltitude()); //Set pressure variable equal to the instantaneous altitude reading
  sum = sum + altitude;         //Update sum value to include new altitude measurement
  avg_alt = sum/counter;        //Calculate the average 
  
  OD01.print("Count: ");        //Display total amount of data points taken
  OD01.println(counter);
  
  OD01.print("Alt ");           //Display the instantaneous altitude
  OD01.print(altitude);
  OD01.println(" m");
  
  OD01.print("Avg ");           //Display the moving average
  OD01.print(avg_alt);
  OD01.println(" m");
  
  delay(2000);                  //Pause for two seconds before repeating loop
  }

}
