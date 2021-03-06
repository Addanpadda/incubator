
#ifndef EGGTURNER_H
#define EGGTURNER_H
#include "Arduino.h"
#include "TimerOne.h"

#define EGGTURNER_PIN 8
#define TURNTIME 12 // Time the turned should be on (HIGH) each time, needs to be whole seconds

// counter for the interrupt. Needs to be static for the function access.
static unsigned short interruptSeconds;

class EggTurner {
private:
  static void interruptCallback();

public:
  EggTurner();
  void turn();
};

#endif
