#include <Arduino.h>

#include "PhotoElectric.h"

PhotoElectric::PhotoElectric(uint8_t iPin)
{
    pin = iPin;
    pinMode(pin, INPUT);
}

/**
 * Get the value of the photo electric's pin
 * 
 * @return bool true if an object obstructs the sensor, false otherwise
 */
bool PhotoElectric::detects()
{
    if (!state())
    {
        while (!state());
        return true;
    }
    return false;
}

bool PhotoElectric::state()
{
    return digitalRead(pin);
}
