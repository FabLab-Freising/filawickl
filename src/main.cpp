#include <Arduino.h>
#include "modules/Stepper/Winder.h"


Winder oWinder;


void setup() {

delay(2000);

  Serial.begin(115200);

  oWinder.initialize();

}

void loop() {

  oWinder.update();

}