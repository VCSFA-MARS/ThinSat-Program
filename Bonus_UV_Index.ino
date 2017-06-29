/////////////////////////////////////
// Calculate UV Index from user input to Serial Monitor
// Uses SL01, CW01, OD01 and IP01 xChips
// Written by J. Singh
/////////////////////////////////////

  #include <xCore.h>    //This library allows us to use the CW01 processor
  #include <xOD01.h>    //This library allows us to use the OD01 screen
  #include <xSL01.h>    //This library makes the light sensor usable
  #include <xSW01.h>

void setup() {
  Wire.begin(2,14);     //Starts the xChips talking to each other
  Serial.begin(9600);   //Define serial monitor connection parameters
  OLED.begin();         //Turn on the OLED screen
  SL01.begin();         //Turn on the light sensor
  SW01.begin();         //Turn on the weather sensor

//These instructions will display on the OLED screen
//These instructions establish a serial monitor connection
  OD01.println("Flick the switch");
  OD01.println("from B to A");
  OD01.println();
  OD01.println("Open the Serial");
  OD01.println("Monitor and type 'go'");

while (!Serial.available()){
//Wait for serial monitor to be opened.
  delay(1000);
  }

//Type any message into the Serial Monitor to establish communication
  Serial.readString();

//This prints to the serial monitor   
  Serial.println("    Connection Established    ");
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  Serial.println("       XinaBox UV Index      ");
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

  delay (1000);   //Dramatic pause

  Serial.println("This program will calculate UV Index.");
  Serial.println("Take a look at the sky. Type a character depending on the rules below.");                 //Initial prompt
  Serial.println("If it is very sunny, type 'a'");
  Serial.println("If it is partly cloudly, type 'b'");
  Serial.println("If it is overcast, raining, or storming, type 'c'");
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");    //Decorative divider

  OD01.clear();   //Clear OLED screen
  OD01.set2X();   //Set font size
}

void loop() {
//Get user input for weather conditions.
//Display data to Serial Monitor
//Display text to OLED

  if (Serial.available() > 0) {   //If the serial monitor is open, do the following
    int text = Serial.read();     //Get text from user
    SL01.poll();                  //Read data from SL01 sensor

    float uva;
    float uvb;
    float sum;
    float altitude;
    float index;
    float fixedA;
    float fixedB;
    
    switch(text){
    //Depending on input text, do one of the following
      
      case 'a': //very sunny
        
        OD01.clear();
        //read uva and uvb
        uva = SL01.getUVA();
        uvb = SL01.getUVB();
        fixedA = 10*0.000542*uva;   //integral average valued weight for UVA over wavelength range 328-400 um. 10 Factor for proper units
        fixedB = 10*uvb;            //1 as weight. 10 factor for proper units
        sum = fixedA+fixedB;
        
        //get altitude
        SW01.poll();
        altitude = SW01.getAltitude();
        
        //add 6% increase for each km above sea level.
        if (altitude<0){
        }
        else{
          sum=sum*(1+(0.06*(altitude/1000)));
        }
       
       //calculate index
        index = sum/25;
        OD01.println(" UV Index:");
        OD01.println(index);
        break;
        
      case 'b': //partly cloudly
        OD01.clear();
        
        //read uva and uvb
        uva = SL01.getUVA();
        uvb = SL01.getUVB();
        fixedA = 10*0.000542*uva;   //integral average valued weight for UVA over wavelength range 328-400 um. 10 Factor for proper units
        fixedB = 10*uvb;            //1 as weight. 10 factor for proper units
        sum = fixedA+fixedB;
        
        //get altitude
        SW01.poll();
        altitude = SW01.getAltitude();
        
        //add 6% increase for each km above sea level.
        if (altitude<0){
        }
        else{
          sum=sum*(1+(0.06*(altitude/1000)));
        }

       //
        index = (sum*0.80)/25;  //case adjustment
        OD01.println(" UV Index:");
        OD01.println(index);
        break;
        
      case 'c': //overcast, raining, storming
         
         OD01.clear();
        //read uva and uvb
        uva = SL01.getUVA();
        uvb = SL01.getUVB();
        fixedA = 10*0.000542*uva;   //integral average valued weight for UVA over wavelength range 328-400 um. 10 Factor for proper units
        fixedB = 10*uvb;            //1 as weight. 10 factor for proper units
        sum = fixedA+fixedB;
        SW01.poll();
        altitude = SW01.getAltitude();
        
        //add 6% increase for each km above sea level.
        if (altitude<0){
        }
        else{
          sum=sum*(1+(0.06*(altitude/1000)));
        }
       
        index = (sum*0.30)/25;  //case adjustment
        OD01.println(" UV Index:");
        OD01.println(index);
        break;
    }
  }
}


//UV Index calculations based on process from https://www.esrl.noaa.gov/gmd/grad/neubrew/docs/UVindex.pdf and https://www.epa.gov/sunsafety/calculating-uv-index-0
