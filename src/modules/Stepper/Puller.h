#pragma once
#include <Arduino.h>

class Puller
{
private:
    /* data */
public:
    Puller(/* args */);
    ~Puller();

    void begin();

    void updateSpeed(uint32_t mm_per_minute);

};
