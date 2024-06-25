#include "Display.h"

Display::Display(/* args */)
{

}

void Display::begin()
{
    Serial.println("Initialize Display");

    display = new Adafruit_SSD1305(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


    if(!display->begin(0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    }

    display->begin();
    display->setRotation(180);
    display->display();
    display->clearDisplay();


    display->setCursor(2,0);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->println("Filawickl Starting...");

    // Show the display buffer on the screen. You MUST call display() after
    // drawing commands to make them visible on screen!
    display->display();

    lastUpdate = millis();

    UpdateCycle_ms = 1000/SCREEN_UPDATE_RATE;

}

void Display::update()
{
    uint32_t m = millis();

    if (m - lastUpdate > UpdateCycle_ms)
    {
        updateInner();
        lastUpdate = millis();
    }
}

void Display::updateInner()
{
    display->clearDisplay();
    display->setCursor(2,0);
    display->setTextSize(2);
    display->println(t);
    display->display();

    t++;
}