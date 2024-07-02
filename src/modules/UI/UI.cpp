#include "UI.h"

UI::UI(Winder *winderinstance)
{
    _winder = winderinstance;
}


void UI::begin()
{
    lastDisplayUpdate = millis();
    DisplayCycle_ms = 1000 / DISPLAY_UPDATE_RATE;
    AnimationCycle_ms = 1000 / DISPLAY_ANIMATION_RATE;

    display = new Adafruit_SSD1305(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

    if (!display->begin(0x3C))
    {
        Serial.println(F("SSD1306 allocation failed"));
    }
    display->display();
    display->clearDisplay();

    display->setCursor(2, 0);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->println("Filawickl Starting...");

    _encoder = new Encoder(32,47);

}

void UI::update()
{
    if (millis() - lastDisplayUpdate > DisplayCycle_ms)
    {
        InnerUpdate();
        lastDisplayUpdate = millis();
    }

    if (millis() - lastAnimationUpdate > AnimationCycle_ms)
    {
        AnimationUpdate();
        lastAnimationUpdate = millis();
    }

}

void UI::InnerUpdate()
{
    display->clearDisplay();

    //draw "Base" Screen
    display->drawXBitmap(2,4, winder_animation[WinderAnimationFrame], Winder_Icon_width, Winder_Icon_height, WHITE);

    //draw winder Position
    display->setTextSize(1);
    display->setCursor(15, 4);
    display->print(_winder->getWinderPos_mm());


    //display->display();
}


void UI::AnimationUpdate()
{
    WinderAnimationFrame++;
    if (WinderAnimationFrame > 2)
    {
        WinderAnimationFrame = 0;
    }
    
}