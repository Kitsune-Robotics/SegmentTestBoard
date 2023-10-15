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
shiftDisplay disp = shiftDisplay(7, 8);

void setup()
{
    // Setup serial
    delay(200);

    // Pins
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    // Flash LED
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
