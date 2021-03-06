
#ifndef THERMOMETER_H
#define THERMOMETER_H
#include "Arduino.h"

// which analog pin to connect
#define THERMISTOR_PIN A0         
// resistance at 37.5 degrees C (but almost always 25 C)
#define THERMISTORNOMINAL 3119.10
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 37.5
// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3175
// the value of the 'other' resistor
#define SERIESRESISTOR 5300

class Thermometer {
private:
  double _temperature;
  void readTemp();

public:
  double getTemp();
};

#endif
