#pragma once
#include <Arduino.h>
#include "modules/Stepper/Winder.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1305.h>
#include "Frames.h"

class UI
{



private:

    Winder* _winder;
    Adafruit_SSD1305* display;

    unsigned char* winder_animation[3] = {Winder_Left_bits, Winder_Middle_bits, Winder_Right_bits};
    uint8_t WinderAnimationFrame = 0;


    uint32_t lastDisplayUpdate = 0;
    uint16_t DisplayCycle_ms;

    uint32_t lastAnimationUpdate = 0;
    uint16_t AnimationCycle_ms;

    void InnerUpdate();

    void AnimationUpdate();


public:
    UI(Winder* winderinstance);

    void begin();
    void update();

    float GetWinderPositionMM()
    {
        return _winder->getWinderPos_mm();
    }

};
