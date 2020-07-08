#include <Adafruit_NeoPixel.h>
#include <Colors.h>
#include <Timer.h>

#ifndef BLINKER_H
#define BLINKER_H

class Blinker {
    public:
        Blinker() = default;
        Blinker(uint16_t, unsigned long, unsigned long);
        void setTimers(unsigned long, unsigned long);
        void begin();
        void reset();
        void blink();
        void blink(int);
        void display();
        void setColor(uint32_t);
        void setLevel(uint8_t);

    private:
        Adafruit_NeoPixel pixel;
        Timer ledTimerOn;
        Timer ledTimerOff;
        byte ledState;
        int counter = 0;
        uint8_t ledLevel;
        uint32_t ledColor;
        static const uint16_t LED_INDEX = 0; 
        static const uint16_t LED_COUNT = 1;

        void turnLedOn();
        void turnLedOff();
};

#endif