#include <Arduino.h>
#include <AccelStepper.h>

#define X_STEP_PIN 54
#define X_DIR_PIN 55
#define X_ENABLE_PIN 38
#define X_MIN_PIN 3
#define X_MAX_PIN 2

#define Y_MIN_PIN 14

#define FILAMENT_WIDTH_STEPS 100
bool isSetup = true;
bool direction = true;
int16_t currentPos = 0;
bool lastSpoolSensor = false;
bool spoolSensor = false;

AccelStepper stepper(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, X_MIN_PIN);

void setup() {
pinMode(X_MIN_PIN, INPUT_PULLUP);
pinMode(X_MAX_PIN, INPUT_PULLUP);
pinMode(Y_MIN_PIN, INPUT_PULLUP);
stepper.setMaxSpeed(1000);
stepper.setAcceleration(2000);

stepper.setEnablePin(X_ENABLE_PIN);
stepper.setPinsInverted(false, false, true); //invert logic of enable pin
stepper.enableOutputs();
Serial.begin(9600);
while (isSetup == true) {
  stepper.setSpeed(-500);
  stepper.runSpeed();
  if (digitalRead(Y_MIN_PIN)) {
    stepper.setCurrentPosition(0);
    stepper.setSpeed(0);
    isSetup = false;
  } 
}
}

void loop() {
//stepper.runSpeed();

if (digitalRead(X_MIN_PIN) == 1) {
  direction = false;
}
if(digitalRead(Y_MIN_PIN) == 1) {
  direction = true;
}


spoolSensor = digitalRead(X_MAX_PIN);

if (!lastSpoolSensor && spoolSensor) {
  if (direction) {
    currentPos += FILAMENT_WIDTH_STEPS;
  } else {
    currentPos -= FILAMENT_WIDTH_STEPS;
  }
  stepper.moveTo(currentPos);
  stepper.runToPosition();
}

lastSpoolSensor = spoolSensor;

//Switch debugging - will drastically slowdown steppers
//Serial.print(digitalRead(Y_MIN_PIN));
//Serial.println(digitalRead(X_MIN_PIN));
Serial.println(currentPos);
}