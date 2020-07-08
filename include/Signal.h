#include <Adafruit_NeoPixel.h>
#include <Colors.h>

#ifndef SIGNAL_H
#define SIGNAL_H

class Signal {
    public:
        Signal() = default;
        Signal(uint16_t);
        Signal(uint16_t, uint8_t);
        void begin();
        void show();
        void restart();
        void setColor(uint32_t);
        void setLevel(uint8_t);
        uint8_t getLevel();

    private:
        static const uint16_t LED_INDEX = 0; 
        static const uint16_t LED_COUNT = 1;
        static const uint8_t MAX_LEVEL = 255;
        Adafruit_NeoPixel pixel;
        uint8_t brightness = MAX_LEVEL;
        uint32_t hexColor;
        
};

#endif