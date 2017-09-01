/////////////////////////////////////
// Establish Serial Monitor Connections
// Send text to OLED
// Uses CW01, OD01 and IP01 xChips
// Written by E. Bujold
/////////////////////////////////////

  #include <xCore.h>     //This library allows us to use the CW01 processor
  #include <xOD01.h>     //This library allows us to use the OD01 screen
  #include <xSW01.h>     //This library allows us to use the weather sensor
  
  String text;          //Initialize variable

void setup() {
  Wire.begin(2,14);     //Starts the xChips talking to each other
  Serial.begin(9600);   //Define serial monitor connection parameters
  OLED.begin();         //Turn on the OLED Screen

//These instructions will display on the OLED screen
//Instructions to establish serial connection
  OD01.println("Flick the switch");
  OD01.println("from B to A");
  OD01.println();
  OD01.println("Open the Serial");
  OD01.println("Monitor and type 'go'");

  while (!Serial.available()){
  //Wait for serial monitor to be opened
    delay(1000);
  }
  
// Type any message into the Serial Monitor to establish communication
 Serial.readString();

//This prints to the serial monitor  
  Serial.println("     Connection Established   ");
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  Serial.println("         XinaBox OLED         ");
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); 

  delay (1000);   //Dramatic pause

  Serial.println("Type a message and look at the OLED!");    //Initial instructions
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");    //Decorative divider 

  OD01.clear();   //Clear the text from OLED screen
}

void loop() {

  text = Serial.readString();   //Get text from the Serial Monitor
  
  if (text != 0){
  //If something is typed in, follow these instructions
    OD01.println(text);
    Serial.println("Type a new message!");    //New Instructions
    Serial.println("~~~~~~~~~~~~~~~~~~~");    //Decorative divider  
  }
}
