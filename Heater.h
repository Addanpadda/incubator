
#ifndef HEATER_H
#define HEATER_H
#include "Arduino.h"
#include "Component.h"
#include "AutoPID.h"

//pid settings and gains
#define OUTPUT_MIN 0
#define OUTPUT_MAX 0.75
//#define KP .15
//#define KI .0005
//#define KD .02
//#define KP .05
//#define KI 0//.0001
//#define KD .005

//const double KP = .15;
//const double KI = 0;//.0002;
//const double KD = .02;

//#define KP 1.9 // 15->25, 25->20, 20->23, 23->25, 25->24, 24->25
//#define KI 0//0002 // 000002->002, 002->0002
//#define KD 0//12 // 0002->05, 05-> 10, 10->12

#define KP .15
#define KI .0005
#define KD .02

#define HEATER_PIN 7

class Heater: public Component {
private:
  AutoPID *_tempPID;
  double _temperature, _setPoint;
  
public:
  const int cycleTimeMS = 10000;
  
  Heater(const double &temperature, const double &setPoint);
  void run() const;
  void setCurrentTemp(const double &temperature);
};

#endif
