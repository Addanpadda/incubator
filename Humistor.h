
#ifndef HUMISTOR_H
#define HUMISTOR_H
#include "Arduino.h"
#include "Common.h"

#define HUMISTOR_PIN A1
#define SERIESRESISTOR 5300

class Humistor {
private:
  double resistanceToHumidity(unsigned const int &resistance);

public:
  double getHumidity();
};

#endif HUMISTOR_H
