#pragma once
#include <Arduino.h>
#include <AccelStepper.h>
#include "conf.h"

class Brake
{
private:
    AccelStepper* BStepper;

    uint16_t speed = 0;

public:
    Brake(/* args */);


    void begin();
    void update();

    void SetSpeed(uint16_t mm_per_min);

};
