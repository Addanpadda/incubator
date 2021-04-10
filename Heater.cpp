
#include "Heater.h"

Heater::Heater(const double &temperature, const double &setPoint) {
  _setPoint = setPoint;
  setCurrentTemp(temperature);
  
  pinMode(HEATER_PIN, OUTPUT);
  _tempPID = new AutoPID(&_temperature, &_setPoint, &_powerFactor, OUTPUT_MIN, OUTPUT_MAX, KP, KI, KD);

  //if temperature is more than 0.5 degrees below or above setpoint, OUTPUT will be set to min or max respectively
  _tempPID->setBangBang(0.5);
  //set PID update interval to 5000ms
  _tempPID->setTimeStep(5000);
}

void Heater::run() const {
  int heatingTime = cycleTimeMS * _powerFactor;
  int cooldownTime = cycleTimeMS - heatingTime;
  
  digitalWrite(HEATER_PIN, HIGH);
  delay(heatingTime);
  
  digitalWrite(HEATER_PIN, LOW);
  delay(cooldownTime);
}

void Heater::setCurrentTemp(const double &temperature) {
  _temperature = temperature;
  _tempPID->run();
}
