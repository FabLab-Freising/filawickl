#include "Display.h"

Display::Display(/* args */)
{
    u8g2 = new U8G2_ST7920_128X64_1_SW_SPI(U8G2_R0, DOGLCD_SCK, DOGLCD_MOSI, DOGLCD_CS);

    u8g2->begin();

    pinMode(SD_DETECT_PIN, INPUT);        // Set SD_DETECT_PIN as an unput
    digitalWrite(SD_DETECT_PIN, HIGH);    // turn on pullup resistors
    pinMode(KILL_PIN, INPUT);             // Set KILL_PIN as an unput
    digitalWrite(KILL_PIN, HIGH);         // turn on pullup resistors
    pinMode(BTN_EN1, INPUT);              // Set BTN_EN1 as an unput, half of the encoder
    digitalWrite(BTN_EN1, HIGH);          // turn on pullup resistors
    pinMode(BTN_EN2, INPUT);              // Set BTN_EN2 as an unput, second half of the encoder
    digitalWrite(BTN_EN2, HIGH);          // turn on pullup resistors
    pinMode(BTN_ENC, INPUT);              // Set BTN_ENC as an unput, encoder button
    digitalWrite(BTN_ENC, HIGH);          // turn on pullup resistors
    u8g2->setFont(u8g_font_helvR08);        //Set the font for the display
    u8g2->setColorIndex(1);                 // Instructs the display to draw with a pixel on.
}

void Display::begin()
{
    u8g2->firstPage();
    u8g2->drawStr(0,24,"Hello World!");
    u8g2->nextPage();
}
