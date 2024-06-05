#pragma once
#include <Arduino.h>

class DiameterSensor
{
private:
    /* data */
public:
    DiameterSensor(/* args */);
    ~DiameterSensor();

    void begin();

    //get the measured diameter of the filament in mm
    double getActualDiameter_mm();

};
