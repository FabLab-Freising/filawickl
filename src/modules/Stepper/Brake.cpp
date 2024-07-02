#include "Brake.h"

Brake::Brake(/* args */)
{

    BStepper = new AccelStepper(AccelStepper::DRIVER, BRAKE_STEP_PIN, BRAKE_DIR_PIN, BRAKE_EN_PIN);

    BStepper->setMaxSpeed(100000);
    BStepper->setAcceleration(8000);

    BStepper->setEnablePin(BRAKE_EN_PIN);
    BStepper->setPinsInverted(false, false, true); // invert logic of enable pin
    BStepper->enableOutputs();
}


void Brake::begin()
{

    BStepper->setSpeed(0);
}

void Brake::SetSpeed(uint16_t mm_per_min)
{

    if (speed != mm_per_min)
    {
        BStepper->setSpeed(mm_per_min);
        speed = mm_per_min;
        Serial.println(mm_per_min);

    }
    

    
}

void Brake::update()
{
    BStepper->runSpeed();
}