#include <Signal.h>
#include <Timer.h>

#ifndef BLINKER_H
#define BLINKER_H

class Blinker {
    public:
        Blinker();
        Blinker(Signal, Timer);
        uint8_t getCount();
        void blink();
        void fade();
        void blink(uint8_t);
        void resetCount();

    private:
        void turnLedOn();
        void turnLedOff();
};

#endif