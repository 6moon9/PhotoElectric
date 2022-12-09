#include <Arduino.h>

class PhotoElectric
{
    public:
        PhotoElectric(uint8_t iPin);
        bool detects();
        bool state();
        uint8_t pin;
};
