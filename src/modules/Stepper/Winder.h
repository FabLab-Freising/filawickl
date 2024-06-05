#pragma once
#include <Arduino.h>
#include <AccelStepper.h>
#include "conf.h"


class Winder
{
private:

    enum STATE
    {
        SENSOR_TRIGGERD,
        WINDER_MOVED,
        SENSOR_UNTRIGGERED
    };

    STATE wState = Winder::SENSOR_UNTRIGGERED;

    AccelStepper* WStepper;
    bool direction = true;
    int16_t currentPos = 0;

public:
    Winder(/* args */);
    ~Winder();

    //this function is blocking untill the endstop is hit.
    void initialize();

    void update(); 


};
