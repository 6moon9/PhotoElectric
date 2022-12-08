#include <Arduino.h>

#include "PhotoElectric.h"

PhotoElectric::PhotoElectric(uint8_t iPinT, uint8_t iPinE)
{
    pinT = iPinT;
    pinE = iPinE;
    pinMode(pinT, OUTPUT);
    pinMode(pinE, INPUT);
    digitalWrite(pinT, HIGH);
}

/**
 * Get the value of the photo electric's pin
 * 
 * @return bool true if an object obstructs the sensor, false otherwise
 */
bool PhotoElectric::detects()
{
    if (!digitalRead(pinE))
    {
        while (!digitalRead(pinE));
        return true;
    }
    return false;
}
