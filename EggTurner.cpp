
#include "EggTurner.h"

EggTurner::EggTurner() {
  pinMode(EGGTURNER_PIN, OUTPUT);
}

void EggTurner::turn() {
  interruptSeconds = 0;
  
  digitalWrite(EGGTURNER_PIN, HIGH);
  Timer1.initialize(); // 1 second each interrupt (default), for counting the turner
  Timer1.attachInterrupt(interruptCallback);
}

static void EggTurner::interruptCallback() {
  if (interruptSeconds++ == TURNTIME) {
    digitalWrite(EGGTURNER_PIN, LOW);
    Timer1.detachInterrupt();
  }
}
