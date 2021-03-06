
#include "Display.h"

Display::Display() {
  // set the LCD address to 0x3F for a 16 chars and 2 line display
  lcd = new LiquidCrystal_I2C(0x3F, 16, 2);
  lcd->init();
  lcd->backlight();
  setupDisplayTitles();
}

void Display::setupDisplayTitles() {
  // Displaying day title
  lcd->setCursor(0,0);
  lcd->print("DAY: ");

  // Displaying turn title
  lcd->setCursor(8,0);
  lcd->print("TURN: ");

  // Displaying temperature title and unit
  lcd->setCursor(7,1);
  lcd->print("T: ");
  lcd->setCursor(14,1);
  lcd->print((char)223); // ° (degree symbol)
  lcd->print("C");

  // Displaying humidity title and unit
  lcd->setCursor(0,1);
  lcd->print("H: ");
  lcd->setCursor(5,1);
  lcd->print("%");
}

void Display::setDay(const int &day) {
  lcd->setCursor(5,0);
  lcd->print(day);
}

void Display::setTimeUntilTurn(const int &secondsToTurn) {
  lcd->setCursor(14,0);
  lcd->print(toMinutes(secondsToTurn));
}

String Display::toMinutes(const unsigned long &secondsToTurn) {
  int minutes = ((int)(secondsToTurn)%3600)/60;

  // Adds extra 0 if needed to fill space, ex. 1 -> 01
  return minutes < 10 ? "0" + String(minutes) : String(minutes);
}

void Display::setTemp(const double &temperature) {
  lcd->setCursor(10,1);
  lcd->print(String(roundTemp(temperature), 1));
}

float Display::roundTemp(const double &temperature) {
  return ((float)((int)(temperature*10)))/10.0;
}


void Display::setHumidity(const double &humidity) {
  lcd->setCursor(3,1);
  lcd->print(String(humidity*100, 0));
}

void Display::print(const String &msg) {
  lcd->setCursor(0,0);
  lcd->print(msg);
}
