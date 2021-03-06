
#ifndef TIMEKEEPER_H
#define TIMEHEEPER_H
#include "Arduino.h"

class TimeKeeper {
private:
  unsigned long _lastMillis;
  void updateLastTime();

public:
  TimeKeeper();

  bool secondsHasPassed(const unsigned long &interval);
  static int secondsUntilPassed(const unsigned long long &interval);
  static int daysPast();
};

#endif
