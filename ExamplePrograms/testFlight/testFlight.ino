#include <xSW01.h>
#include <xCore.h>
#include <xOD01.h>

// Constant Defintions

const int RED = 12;
const int GREEN = 13;
const int BLUE = 5;

const int BALLOON_POPPING_PIN    = RED;
const int PARACHUTE_PULLER_PIN   = BLUE;
const int PARACHUTE_DEPLOYED_PIN = GREEN;

// Initial State Definition

bool hasParachuteBeenDeployed = false;

float UVA = 0;
float UVB = 0;
float Temp = 0;
float Humid = 0;
float Altitude = 0;
float dewpoint = 0;


void setup() {
  // Setup for weather sensor and display chip
  // Starts the I2C communication
  Wire.begin(2,14);
  
  // Start the OLED Display OD01
  OLED.begin();

  // Start the  SW01 Sensor
  SW01.begin();

  // send command to clear the display
  OD01.clear();

  
  // put your setup code here, to run once:
  pinMode( BALLOON_POPPING_PIN, OUTPUT);
  pinMode( PARACHUTE_PULLER_PIN, OUTPUT);
  pinMode( PARACHUTE_DEPLOYED_PIN, OUTPUT);

}

void loop() {
  // Collect data
  updateWeatherData();

  // "Transmit data/ update display
  updateDisplay();

  // Are we too high?
  bool isAltitudeViolation = true;

  // Flight Termination 
  if (isAltitudeViolation & !hasParachuteBeenDeployed){
    hasParachuteBeenDeployed = deployParachute();
  }
  delay(3000);  
}

void updateDisplay() {
  // Clear the display 
  OD01.clear();
  
  // Print weather data
  OD01.print("Temp: ");
  OD01.println(Temp);
  
  OD01.print("Humid: ");
  OD01.println(Humid);
  
  OD01.print("Dewpoint: ");
  OD01.println(dewpoint);
  
  OD01.print("Altitude: ");
  OD01.println(Altitude);
}

void updateWeatherData() {

  // request the sensor to read data
  SW01.poll();
  
  UVA;
  UVB;
  Temp      = SW01.getTemperature_C();
  Humid     = SW01.getHumidity();
  Altitude  = SW01.getAltitude();
  
  // Calculate Weather Stuff (dewpoint)
  dewpoint = Temp - (( 100 - Humid) / 5);
  
}

bool deployParachute() {

  bool isGoodDeploy = false;

  // apply power to balloon poppin pin for 2 seconds - RED
    digitalWrite( BALLOON_POPPING_PIN, HIGH);
    delay(2000);
    digitalWrite( BALLOON_POPPING_PIN, LOW);
  
  // wait 2 seconds
    delay(2000);

  // apply power to parachute puller 2 seconds BLUE
    digitalWrite( PARACHUTE_PULLER_PIN, HIGH);
    delay(2000);
    digitalWrite( PARACHUTE_PULLER_PIN, LOW);
  
  // simulate parachute deployed (turn on a light) GREEN
    digitalWrite( PARACHUTE_DEPLOYED_PIN, HIGH);

  // Hooray, it worked! (simulated test to see if parachute worked)
    isGoodDeploy = true;

  // Pass success or failure information back to whoever called the function
    return isGoodDeploy;
}

