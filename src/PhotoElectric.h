#include <Arduino.h>

class PhotoElectric
{
    public:
        PhotoElectric(uint8_t iPinT, uint8_t iPinE);
        bool detects();
        uint8_t pinT;
        uint8_t pinE;
};
