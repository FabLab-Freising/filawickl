#include <Arduino.h>
#include "modules/Stepper/Winder.h"
#include "modules/Stepper/Brake.h"
#include "modules/Regulator/Regulator.h"
#include "modules/DiameterSensor/DiameterSensor.h"
#include "modules/Display/Display.h"
#include <AccelStepper.h>


Winder oWinder;
Brake oBrake;
Regulator oRegulator;
DiameterSensor oDiameterSensor;
Display oDisplay;


void setup() {

delay(2000);

  Serial.begin(115200);

  oDisplay.begin();

  oWinder.initialize();
  oBrake.begin();
  oRegulator.begin();
  oDiameterSensor.begin();



  

  //1.75mm initial diameter
  //oRegulator.setSetpoint_mm(1.75);

  //oWinder.setSpoolerSpeedPercent(40);

  //oBrake.SetSpeed(200);


}

void loop() {

  //update the winder mechanism
  oWinder.update();
  oBrake.update();



  //get the actual diameter reading from diameterSensor in mm
  //double FilamentDiameter = oDiameterSensor.getActualDiameter_mm();
  //feed the regulator
  //uint16_t speed_mm_per_min = oRegulator.update(FilamentDiameter);
  //update the puller so that it'll make the right diameter
  

  //print Info on screen?
  //change Parameters on the fly?

  //update Display
  oDisplay.update(); 

}