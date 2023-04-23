#include <Arduino.h>

#include "PhotoElectric.h"

PhotoElectric::PhotoElectric(uint8_t iPin, int iMinCount = 1, bool iReversed = false)
{
    pin = iPin;
    minCount = iMinCount;
    reversed = iReversed;
    pinMode(pin, INPUT);
}

/**
 * Get the value of the photo electric's pin
 *
 * @return bool true if an object obstructs the sensor, false otherwise
 */
bool PhotoElectric::detects()
{
    if (state())
    {
        count++;
        if (count >= minCount)
        {
            count = 0;
            while (state());
            return true;
        }
    }
    else
    {
        count = 0;
    }
    return false;
}

bool PhotoElectric::state()
{
    return digitalRead(pin) == reversed;
}
