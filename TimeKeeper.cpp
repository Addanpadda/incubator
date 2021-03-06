
#include "TimeKeeper.h"

TimeKeeper::TimeKeeper() {
  updateLastTime();
}

void TimeKeeper::updateLastTime() {
  _lastMillis = millis();
}

bool TimeKeeper::secondsHasPassed(const unsigned long &interval) {
  // Integer division, only changes when fully turned to next number
  bool hasPassed = (int)((_lastMillis/1000)/interval) != (int)((millis()/1000)/interval);

  updateLastTime();
  return hasPassed;
}

static int TimeKeeper::secondsUntilPassed(const unsigned long long &interval) {
  long secondsRun = millis()/1000;
  return (secondsRun/interval+1-((double)secondsRun/interval))*interval;
}

static int TimeKeeper::daysPast() {
  long secondsRun = millis()/1000;
  const int daysInSeconds = 3600*24;
  return secondsRun/daysInSeconds;
}
