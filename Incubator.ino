
#include "Incubator.h"
Incubator *incubator;

//#include "TimeKeeper.h"

//#include "EggTurner.h"

//EggTurner eggTurner = new EggTurner();


void setup() {
  //pinMode(8, OUTPUT);
  incubator = new Incubator();
  //Serial.begin(9600);
  //eggTurner = new EggTurner();

}

//unsigned int pos = 0;

void loop() {  
  //lcd->setCursor(pos - (pos/16)*16, pos/16);
  //lcd->print(".");
  //eggTurner.turn();
  //delay(8000);
  //pos++;
  //if (pos == 32) pos = 0;

  /*
  lcd->setCursor(0, 0);
  lcd->print("ON ");
  digitalWrite(8, HIGH);
  delay(2000);
  lcd->setCursor(0, 0);
  lcd->print("OFF");
  digitalWrite(8, LOW);
  delay(5000);
  */
  
  incubator->run();
  //Serial.println((double)millis()/3600000);
  //long secondsRun = millis()/1000;
  //const int daysInSeconds = 3600*24;
  //double days = secondsRun/(double)daysInSeconds;
  //Serial.println(days);
  //Serial.println(TimeKeeper::secondsUntilPassed(120));
  //delay(1000);
}

/*
// |———————————————————————————————————————————————————————| 
// |  made by Arduino_uno_guy 11/13/2019                   |
// |   https://create.arduino.cc/projecthub/arduino_uno_guy|
// |———————————————————————————————————————————————————————|


#include "LiquidCrystal_I2C.h"

#include "Wire.h"

//initialize the liquid crystal library
//the first parameter is the I2C address
//the second parameter is how many rows are on your screen
//the third parameter is how many columns are on your screen
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  
  //initialize lcd screen
  lcd.init();
  // turn on the backlight
  lcd.backlight();
}
void loop() {
  //wait for a second
  delay(1000);
  // tell the screen to write on the top row
  lcd.setCursor(0,0);
  // tell the screen to write “hello, from” on the top row
  lcd.print("Hello, From");
  // tell the screen to write on the bottom row
  lcd.setCursor(0,1);
  // tell the screen to write “Arduino_uno_guy” on the bottom row
  // you can change whats in the quotes to be what you want it to be!
  lcd.print("Arduino_uno_guy");
  
}
*/
