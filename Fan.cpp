
#include "Fan.h"

Fan::Fan() {
  pinMode(FAN_PIN, OUTPUT);
}

void Fan::setSpeed(const double &powerFactor) {
  _powerFactor = powerFactor;
  applySpeed();
}

void Fan::applySpeed() const {
  const int analogSpeed = (int)(255 * _powerFactor);
  
  analogWrite(FAN_PIN, analogSpeed);
}
