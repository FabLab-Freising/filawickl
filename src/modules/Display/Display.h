#pragma once
#include <Arduino.h>
#include "conf.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1305.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define SCREEN_UPDATE_RATE 10 //10Hz Update rate

class Display
{
private:
    // SPI Com: SCK = en = 23, MOSI = rw = 17, CS = di = 16
    Adafruit_SSD1305* display;

    void updateInner();

    uint32_t lastUpdate = 0;
    uint16_t UpdateCycle_ms;

    uint8_t t = 0;

public:
    Display(/* args */);


    void begin();

    void update(); 

};
