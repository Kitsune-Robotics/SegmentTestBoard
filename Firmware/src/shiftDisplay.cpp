/**
 * @brief Implementations for shiftDisplay
 *
 */

#include "shiftDisplay.h"

shiftDisplay::shiftDisplay(uint8_t _datPin, uint8_t _clkPin, uint8_t _latchPin)
{
    datPin = _datPin;
    clkPin = _clkPin;
    latchPin = _latchPin;
}

void shiftDisplay::begin()
{
    pinMode(datPin, OUTPUT);
    pinMode(clkPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
};

void shiftDisplay::setDigit(uint8_t digit)
{
    digitalWrite(latchPin, LOW); // Set latch low (stop displaying digits)

    shiftOut(datPin, clkPin, MSBFIRST, segChars[digit]); // Write segment out
    // shiftOut(datPin, clkPin, MSBFIRST, 0xff);

    digitalWrite(latchPin, HIGH); // Display it
};