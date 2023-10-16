/**
 * @file shiftDisplay.h
 * @author Joe
 * @brief Library for ShiftSegmentBoard
 */

// Libs
#include <Arduino.h>

class shiftDisplay
{
private:
    uint8_t datPin;
    uint8_t clkPin;
    uint8_t latchPin;

    // Segments
    enum Seg
    {
        s_A = 0b00000001,
        s_B = 0b00000010,
        s_C = 0b00000100,
        s_D = 0b00001000,
        s_E = 0b00010000,
        s_F = 0b00100000,
        s_G = 0b01000000,
        s_DP = 0b10000000,
    };

    // Segment Lookup table
    const uint8_t segChars[37] = {
        s_A | s_B | s_C | s_D | s_E | s_F,       // 0
        s_B | s_C,                               // 1
        s_A | s_B | s_D | s_E | s_G,             // 2
        s_A | s_B | s_C | s_D | s_G,             // 3
        s_B | s_C | s_F | s_G,                   // 4
        s_A | s_C | s_D | s_F | s_G,             // 5
        s_A | s_C | s_D | s_E | s_F | s_G,       // 6
        s_A | s_B | s_C,                         // 7
        s_A | s_B | s_C | s_D | s_E | s_F | s_G, // 8
        s_A | s_B | s_C | s_D | s_F | s_G,       // 9
        0,                                       // null
        s_A | s_B | s_C | s_E | s_F | s_G,       // A
        s_C | s_D | s_E | s_F | s_G,             // b
        s_A | s_D | s_E | s_F,                   // C
        s_B | s_C | s_D | s_E | s_G,             // d
        s_A | s_D | s_E | s_F | s_G,             // E
        s_A | s_E | s_F | s_G,                   // F
        s_A | s_C | s_D | s_E | s_F,             // G
        s_C | s_E | s_F | s_G,                   // h
        s_B | s_C,                               // i
        s_B | s_C | s_D,                         // j
        s_A | s_C | s_E | s_F | s_G,             // k
        s_D | s_E | s_F,                         // L
        s_A | s_C | s_E,                         // M
        s_A | s_B | s_C | s_E | s_F,             // N
        s_A | s_B | s_C | s_D | s_E | s_F,       // O
        s_A | s_B | s_E | s_F | s_G,             // p
        s_A | s_B | s_C | s_F | s_G,             // q
        s_E | s_G,                               // r
        s_A | s_C | s_D | s_F | s_G,             // s
        s_D | s_E | s_F | s_G,                   // t
        s_B | s_C | s_D | s_E | s_F,             // U
        s_B | s_C | s_D | s_F,                   // V
        s_B | s_D | s_F,                         // W
        s_B | s_C | s_E | s_F | s_G,             // X
        s_B | s_C | s_D | s_F | s_G,             // Y
        s_A | s_B | s_D | s_G,                   // Z
    };

public:
    shiftDisplay(uint8_t _datPin, uint8_t _clkPin, uint8_t _latchPin);

    /**
     * @brief Initalize pins and begin
     *
     */
    void begin();

    /**
     * @brief Set the current digit
     *
     * @param digit A number or char corrsponding to the lookup chart.
     */
    void setDigit(uint8_t digit);
};
