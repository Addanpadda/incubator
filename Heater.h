
#ifndef HEATER_H
#define HEATER_H
#include "Arduino.h"
#include "Component.h"
#include "AutoPID.h"

//pid settings and gains
#define OUTPUT_MIN 0
#define OUTPUT_MAX 0.75
#define KP .15
#define KI .0005
#define KD .02

#define HEATER_PIN 7

class Heater: public Component {
private:
  AutoPID *_tempPID;
  double _temperature, _setPoint;
  const int _cycleTimeMS = 10000;
  
public:
  Heater(const double &temperature, const double &setPoint);
  void run() const;
  void setCurrentTemp(const double &temperature);
};

#endif
