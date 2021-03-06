
#ifndef FAN_H
#define  FAN_H
#include "Arduino.h"
#include "Component.h"
#define FAN_PIN 6 // Needs to be PWM

class Fan: public Component {
private:
  void applySpeed() const;
  
public:
  Fan();
  void setSpeed(const double &powerFactor);
};

#endif
