
#include "Incubator.h"

Incubator::Incubator() {
  double temperature = thermometer.getTemp();

  // Initialize compontents
  heater     = new Heater(temperature, INCUBATOR_SETPOINT);
  eggTurner  = new EggTurner();
  lcdDisplay = new Display();
  timeKeeper = new TimeKeeper();
  
  fan->setSpeed(1.0);
}

Incubator::~Incubator() {
  delete(heater);
}

void Incubator::run() {
  //lcdDisplay->print("IFTURN");
  turnEggsIfNeeded();
  
  //lcdDisplay->print("TMP");
  double temperature = thermometer.getTemp();
  //lcdDisplay.print("HUM");
  double humidity = humistor.getHumidity();

  //lcdDisplay->print("LCD");
  lcdDisplay->setDay(timeKeeper->daysPast());
  lcdDisplay->setTimeUntilTurn(TimeKeeper::secondsUntilPassed(TURNEVERY)); // Uses seconds
  lcdDisplay->setTemp(temperature);
  lcdDisplay->setHumidity(humidity);

  //lcdDisplay->print("HSET");
  heater->setCurrentTemp(temperature);
  //lcdDisplay->print("HRUN");
  heater->run();
}

void Incubator::turnEggsIfNeeded() {
  if (timeKeeper->secondsHasPassed(TURNEVERY)) {
   //lcdDisplay->print("TRN");
   eggTurner->turn(); // Asynchronous with timer interrupts
  }
}
