
#include "Incubator.h"
Incubator *incubator;

void setup() {
  incubator = new Incubator();
}

void loop() {  
  incubator->run();
}
