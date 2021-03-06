
#include "Thermometer.h"

void Thermometer::readTemp() {
  double reading = 0;

  for(int x = 0; x < 10; x++) {
    reading += analogRead(THERMISTOR_PIN);
    delay(100);
  }
  reading /= 10;
  
  // convert the value to resistance
  reading = (1023 / reading)  - 1;     // (1023/ADC - 1) 
  reading = SERIESRESISTOR / reading;  // 10K / (1023/ADC - 1)
  
  // convert value to temperature
  float steinhart;
  steinhart = reading / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;

  _temperature = steinhart;
}

double Thermometer::getTemp() {
  readTemp();
  return _temperature;
}
