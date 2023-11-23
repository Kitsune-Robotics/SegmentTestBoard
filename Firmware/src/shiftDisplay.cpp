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

    // Write segment out (checking with showDecimal to draw the decimal dot)
    shiftOut(datPin, clkPin, MSBFIRST, showDecimal ? segChars[digit] | s_DP : segChars[digit]);

    digitalWrite(latchPin, HIGH); // Display it
};

void shiftDisplay::setRaw(uint8_t raw)
{
    digitalWrite(latchPin, LOW); // Set latch low (stop displaying digits)

    // Write segment out
    shiftOut(datPin, clkPin, MSBFIRST, raw);

    digitalWrite(latchPin, HIGH); // Display it
}

void shiftDisplay::setDecimal(bool dec)
{
    showDecimal = dec;
}