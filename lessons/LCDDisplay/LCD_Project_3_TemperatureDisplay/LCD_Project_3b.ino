/*
Display the temperature
 */

// include the library code:
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS A5

#define BUTTON1 9
#define BUTTON2 8

#define LED 6

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

String lcd1="Temp      ";
String lcd2="display  "; 

char tempString[6];

void setup() {

  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // start dallas sensor library
  sensors.begin();
}

void getTemp()
{
  // read temperatures
  sensors.requestTemperatures(); // Send the command to get temperatures
  dtostrf (sensors.getTempCByIndex(0), 5, 2, tempString);
}


void loop() {
  getTemp();
  lcd1 = "Temperature:    ";
  lcd2 = "     " + String(tempString);
  
  // update display
    // Print a startup message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print(lcd1);
  lcd.setCursor(0, 1);
  lcd.print(lcd2);
  delay(5);
}

