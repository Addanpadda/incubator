
#include "Humistor.h"

// Himistor specific, and for 37.5*C
double Humistor::resistanceToHumidity(unsigned const int &resistance) {
  return  resistance >= 2000000 ? 0.20 :
          resistance >= 977500  ? 0.25 :
          resistance >= 492500  ? 0.30 :
          resistance >= 247500  ? 0.35 :
          resistance >= 127000  ? 0.40 :
          resistance >= 69750   ? 0.45 :
          resistance >= 40250   ? 0.50 :
          resistance >= 24375   ? 0.55 :
          resistance >= 15500   ? 0.60 :
          resistance >= 10375   ? 0.65 :
          resistance >= 7200    ? 0.70 :
          resistance >= 5000    ? 0.75 :
          resistance >= 3525    ? 0.80 :
          resistance >= 2525    ? 0.85 :
          resistance <  2525    ? 0.90 :
                           OUT_OF_RANGE;
}

double Humistor::getHumidity() {
  float reading = 0;
  
  for(int x = 0; x < 10; x++) {
    reading += analogRead(HUMISTOR_PIN);
    delay(100);
  }
  reading /= 10;

  // convert the value to resistance
  reading = (1023 / reading)  - 1;     // (1023/ADC - 1) 
  if (reading == 0) return 0.1; // If resistance is too high, must be little humidity
  reading = int(SERIESRESISTOR / reading);  // 5.3K / (1023/ADC - 1)

  double humidity = resistanceToHumidity(reading);
  if (humidity == OUT_OF_RANGE) return 0.1; // If resistance is too high, must be little humidity (or bad connection?)
  else return humidity;
}
