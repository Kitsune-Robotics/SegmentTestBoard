/**
 * @file main.cpp
 * @author Joe
 * @brief Source code for ShiftSegmentBoard
 */

// Libs
#include <Arduino.h>

// Display
#include <shiftDisplay.h>

// Objects
const uint8_t DIN_PIN = 7;
const uint8_t CLK_PIN = 9;
const uint8_t LAT_PIN = 8;
shiftDisplay disp = shiftDisplay(DIN_PIN, CLK_PIN, LAT_PIN);

void setup()
{
    // Setup serial
    delay(200);
    Serial.begin(115200);

    // Setup disp
    disp.begin();

    // Pins
    pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;

void loop()
{
    // Flash LED
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);

    disp.setDigit(i);
    Serial.println(i);
    i++;
    if (i >= 37)
    {
        i = 0;
    }
}
