#pragma once
#include <Arduino.h>
#include "conf.h"
#include <U8g2lib.h>

class Display
{
private:
    // SPI Com: SCK = en = 23, MOSI = rw = 17, CS = di = 16
    U8G2_ST7920_128X64_1_SW_SPI* u8g2;
public:
    Display(/* args */);


    void begin();
};
