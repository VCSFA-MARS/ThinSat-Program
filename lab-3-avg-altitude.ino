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
  OD01.println("AvgAltitude");    //print opening message on OLED Screen
  OD01.println("===========");



  delay(5000);                    //allow SW01 sensor to normalize before starting loop
  OD01.clear();
}

void loop() {
  // This is the body of the code. It will repeat indefinitely.

  

  //create a for loop to take a moving average
  int counter;

  for (counter=1; counter>0; counter++){
  OD01.clear();
  float sum;
  float avg_alt;


  float altitude = 0;             //declare altitude variable and initialize as zero
  SW01.poll();                    //Tell the SW01 sensor to read and store data
  altitude = (SW01.getAltitude());  //set pressure variable equal to the current altitude reading
  avg_alt = (altitude + sum)/counter;
  OD01.print("Count: ");        //display amount of data points taken
  OD01.println(counter);
  OD01.print("Alt ");           //display the pressure on the OLED screen
  OD01.print(altitude);
  OD01.println(" m");
  OD01.print("Avg ");           //display the moving average
  OD01.print(avg_alt);
  OD01.println(" m");
  sum = sum + altitude;

  delay(2000);                    //pause for two seconds
  }


}
