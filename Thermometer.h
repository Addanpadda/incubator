
#ifndef THERMOMETER_H
#define THERMOMETER_H
#include "Arduino.h"

// which analog pin to connect
#define THERMISTOR_PIN A0         
// Resistor value used with the thermistor
#define SERIESRESISTOR 5300

// Specific thermistor constants
#define THERMISTORNOMINAL 4890
#define TEMPERATURENOMINAL 25
#define BCOEFFICIENT 3340


class Thermometer {
private:
  double _temperature;
  void readTemp();

public:
  double getTemp();
};

#endif
