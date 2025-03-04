#include <Arduino.h>
#include "modules/Stepper/Winder.h"
#include "modules/Stepper/Brake.h"
#include "modules/Regulator/Regulator.h"
#include "modules/DiameterSensor/DiameterSensor.h"
#include <Encoder.h>
#include <AccelStepper.h>


Winder oWinder;
Brake oBrake;
Regulator oRegulator;
DiameterSensor oDiameterSensor;
Encoder* oEncoder;


void setup() {

delay(2000);

  Serial.begin(250000);
  Serial2.begin(115200);

  //UI_Instance = new UI(&oWinder);
  //UI_Instance->begin();

  oWinder.initialize();
  oBrake.begin();
  oRegulator.begin();
  oDiameterSensor.begin();

  oEncoder = new Encoder(32,47);

  oWinder.setSpoolerSpeedPercent(100);


  //1.75mm initial diameter
  //oRegulator.setSetpoint_mm(1.75);

  //oWinder.setSpoolerSpeedPercent(40);

  //oBrake.SetSpeed(200);


}

void loop() {

  //update the winder mechanism
  oWinder.update();
  oBrake.update();

  int32_t speedScaled = oEncoder->read()*8;
  //sanity Check
  if (speedScaled < 0)
    speedScaled = 0;
  

  oBrake.SetSpeed(speedScaled);



  //get the actual diameter reading from diameterSensor in mm
  //double FilamentDiameter = oDiameterSensor.getActualDiameter_mm();
  //feed the regulator
  //uint16_t speed_mm_per_min = oRegulator.update(FilamentDiameter);
  //update the puller so that it'll make the right diameter
  

  //print Info on screen?
  //change Parameters on the fly?


  if (Serial2.available())
  {
      Serial.println(Serial2.read());
  }

}