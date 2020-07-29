#include <Adafruit_NeoPixel.h>
#include <Colors.h>
#include <Timer.h>

#ifndef BLINKER_H
#define BLINKER_H

class Blinker {
    public:
        Blinker() = default;
        void setTimers(unsigned long, unsigned long);
        void begin(uint16_t, unsigned long, unsigned long);
        void reset();
        void blink();
        void display();
        void turnLedOn();
        void turnLedOff();
        void strobe(uint32_t);
        void setColor(uint32_t);
        void setLevel(uint8_t);
        int getCounter();

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
};

#endif