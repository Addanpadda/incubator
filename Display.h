
#ifndef DISPLAY_H
#define DISPLAY_H
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

class Display {
private:
  LiquidCrystal_I2C *lcd;
  void setupDisplayTitles();
  float roundTemp(const double &temperature);
  String toMinutes(const unsigned long &secondsToTurn);
  
public:
  Display();
  void setDay(const int &day);
  void setTimeUntilTurn(const int &secondsToTurn);
  void setTemp(const double &temperature);
  void setHumidity(const double &humidity);
  void print(const String &msg);
};

#endif
