
#include "Incubator.h"

Incubator::Incubator() {
  double temperature = thermometer.getTemp();

  // Initialize compontents
  fan              = new Fan();
  heater           = new Heater(temperature, INCUBATOR_SETPOINT);
  eggTurner        = new EggTurner();
  lcdDisplay       = new Display();
  turnerTimeKeeper = new TimeKeeper();
  
  fan->setSpeed(1.0);
}

Incubator::~Incubator() {
  delete(heater);
}

void Incubator::run() {
  double temperature = thermometer.getTemp();
  double humidity = humistor.getHumidity();

  lcdDisplay->setDay(TimeKeeper::daysPast());
  lcdDisplay->setTimeUntilTurn(TimeKeeper::secondsUntilPassed(TURNEVERY)); // Uses seconds
  lcdDisplay->setTemp(temperature);
  lcdDisplay->setHumidity(humidity);

  heater->setCurrentTemp(temperature);
  heater->run();

  turnEggsIfNeeded();
}

void Incubator::turnEggsIfNeeded() {
  if (turnerTimeKeeper->secondsHasPassed(TURNEVERY)) {
   eggTurner->turn(); // Asynchronous with timer interrupts
  }
}
