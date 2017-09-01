/////////////////////////////////////
// Establish Serial Monitor Connections
// Take Temperature Measurements and display on Serial Monitor
// Uses SW01, CW01, OD01 and IP01 xChips
// Written by E. Bujold
/////////////////////////////////////

  #include <xCore.h>     //This library allows us to use the CW01 processor
  #include <xOD01.h>     //This library allows us to use the OD01 screen
  #include <xSW01.h>     //This library allows us to use the weather sensor

//Define hardware connections to the LED colors. 
  const int RED = 12;
  const int GREEN = 13;
  const int BLUE = 5;

void setup() {
  Wire.begin(2,14);     //Starts the xChips talking to each other
  Serial.begin(9600);   //Define serial monitor connection parameters
  SW01.begin();         //Turn on the weather sensor
  OLED.begin();         //Turn on the OLED Screen

//Define use of LED, output color
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
//Initial state, Turn all LEDs off
  digitalWrite(RED,   LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

//These instructions will display on the OLED screen
//Flick the switch from B to A and then open the Serial Monitor 
  OD01.println("Flick the switch");
  OD01.println("from B to A");
  OD01.println();
  OD01.println("Open the Serial");
  OD01.println("Monitor and type 'go'");

 while (Serial.available() == 0) {
 //Blink the red LED until connection is esablished
    digitalWrite(RED, HIGH);  // Turn on
    delay(500);               // Stay on for dwell time
    digitalWrite(RED, LOW);   // Turn off
    delay(500);               // Stay off for dwell time
  }             
  
// Type any message into the Serial Monitor to establish communication
  Serial.readString();
  digitalWrite(BLUE, HIGH);    //blue light will turn on after the connection is established
  Serial.println("Connection Established");

//These new instructions print to the LED screen
  OD01.clear();                 //Clear LED screen
  OD01.set2X();                 //Set font size
  OD01.println("Connection");
  OD01.println("Established");
  OD01.set1X();                 //Set font size
  OD01.println();               //Print a blank line
  OD01.println("Flick the switch back");
  OD01.println("to B to upload code");  

//This prints to the serial monitor  
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  Serial.println("         XinaBox SW01         ");
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); 

delay (1000);   //Dramatic pause
}

void loop() {
// Measure Temperture and Humidity, then print results to Serial Monitor

  SW01.poll(); //Read and calculate data from SWO1 sensor

  Serial.print("Humidity: ");
  Serial.print(SW01.getHumidity());
  Serial.println("%");

  Serial.print("Temperature: ");
  Serial.print(SW01.getTemperature_F());
  Serial.println(" Degrees");

  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~");    //Decorative divider  
    
  delay(1000);
}
