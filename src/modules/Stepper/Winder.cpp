
#include "Winder.h"

Winder::Winder()
{
    WStepper = new AccelStepper(AccelStepper::DRIVER, WINDER_STEP_PIN, WINDER_DIR_PIN, WINDER_EN_PIN, WINDER_ENDSTOP_MIN);

    WStepper->setMaxSpeed(1000);
    WStepper->setAcceleration(8000);

    WStepper->setEnablePin(WINDER_EN_PIN);
    WStepper->setPinsInverted(false, false, true); // invert logic of enable pin
    WStepper->enableOutputs();
}

void Winder::initialize()
{
    Serial.println("Initialize Winder");

    bool initializing = true;

    pinMode(WINDER_SPOOL_ROTATION_SEN, INPUT_PULLUP);
    pinMode(WINDER_ENDSTOP_MIN, INPUT_PULLUP);
    pinMode(WINDER_ENDSTOP_MAX, INPUT_PULLUP);

    pinMode(WINDER_SPOOLER_MOTOR, OUTPUT);



    while (initializing == true)
    {
        WStepper->setSpeed(-500);
        WStepper->runSpeed();
        if (digitalRead(WINDER_ENDSTOP_MIN))
        {
            WStepper->setCurrentPosition(0);
            WStepper->setSpeed(0);
            initializing = false;
        }
    }
    Serial.println("Winder @ Position 0");

    analogWrite(WINDER_SPOOLER_MOTOR, WinderSpeed);
}


void Winder::setSpoolerSpeedPercent(uint8_t SpeedPercent)
{
    WinderSpeed = (float)SpeedPercent/100 * 255.0f;
    //Below a raw value of 100 the motor stalls.
    //To prevent the motor from degrading to much everyting under raw=100 is reduced to zero
    if (WinderSpeed < 100)
        WinderSpeed = 0;
    
}

void Winder::update()
{
    //WStepper->run();

    // change direction if a endstop is detected
    if (digitalRead(WINDER_ENDSTOP_MIN) == 1)
    {
        direction = true;
        //Serial.println("Direction Change: true");
    }
    if (digitalRead(WINDER_ENDSTOP_MAX) == 1)
    {
        direction = false;
        //Serial.println("Direction Change: false");
    }

    switch (wState)
    {
    case SENSOR_UNTRIGGERED:
        //Serial.println("SENSOR_UNTRIGGERED");
        if (digitalRead(WINDER_SPOOL_ROTATION_SEN) == HIGH)
            wState = STATE::SENSOR_TRIGGERD;

        break;
    case SENSOR_TRIGGERD:
         //Serial.println("SENSOR_TRIGGERD");
        // move winder
        if (direction)
            currentPos += WINDER_FILAMENT_WIDTH_STEPS;
        else
            currentPos -= WINDER_FILAMENT_WIDTH_STEPS;

        WStepper->moveTo(currentPos);

        wState = WINDER_MOVING;
        //WStepper->runToPosition();

        break;
    case WINDER_MOVING:
         //Serial.println("WINDER_MOVING");
         //winder is in moving progress
         //this state enables asynchronus movement
        if (!WStepper->run())
        {
            wState = STATE::WINDER_MOVED;
        }
        break;
    case WINDER_MOVED:
        // Serial.println("WINDER_MOVED");
        // wait for sensor to be low again
        if (digitalRead(WINDER_SPOOL_ROTATION_SEN) == LOW)
            wState = STATE::SENSOR_UNTRIGGERED;

        break;
    default:
        break;
    }

    // Switch debugging - will drastically slowdown steppers
    // Serial.print(digitalRead(Y_MIN_PIN));
    // Serial.println(digitalRead(X_MIN_PIN));
    // Serial.println(currentPos);

    analogWrite(WINDER_SPOOLER_MOTOR, WinderSpeed);
}