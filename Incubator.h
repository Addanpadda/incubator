
#ifndef INCUBATOR_H
#define INCUBATOR_H
#include "Arduino.h"
#include "Thermometer.h"
#include "Humistor.h"
#include "Heater.h"
#include "Fan.h"
#include "EggTurner.h"
#include "Display.h"
#include "TimeKeeper.h"

struct IncubatorTemp
{
  static const double chicken = 37.5;
};

#define TURNEVERY 120 //3600 // Turn egges every hour (in seconds)
#define INCUBATOR_SETPOINT IncubatorTemp::chicken

class Incubator {
private:
  Thermometer thermometer;
  Humistor humistor;
  Heater *heater;
  Fan *fan;
  EggTurner *eggTurner;
  Display *lcdDisplay;
  TimeKeeper *timeKeeper;
  void turnEggsIfNeeded();

public:
    Incubator();
    ~Incubator();
    void run(); 
};

#endif
