#pragma once
#include <Arduino.h>

class Regulator
{
private:
    /* data */
public:
    Regulator(/* args */);
    ~Regulator();

    //sets the target setpoint in mm
    void setSetpoint_mm(double Setpoint_mm);

    void begin();

    //gets the measured value and compares it to the setpoint.
    //feeds the PID-Loop
    uint16_t update(double actual_mm);


};


