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
        WINDER_MOVING,
        WINDER_MOVED,
        SENSOR_UNTRIGGERED
    };

    STATE wState = Winder::SENSOR_UNTRIGGERED;

    AccelStepper* WStepper;
    bool direction = true;
    int16_t currentPos = 0;
    uint8_t WinderSpeed = 0;

    float filamentDia;


public:
    Winder(/* args */);

    //this function is blocking untill the endstop is hit.
    void initialize();

    void update(); 

    void setSpoolerSpeedPercent(uint8_t SpeedPercent);

    float getWinderPos_mm();


};
