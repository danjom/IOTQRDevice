#include <Arduino.h>
#include <Timer.h>

unsigned long current;
unsigned long previous;
unsigned int timing;

Timer::Timer(unsigned int interval) {
    timing = interval;
}

boolean Timer::check() {
    current = millis();

    if ((current - previous) >= timing) {
        previous = current;
        return true;
    }
    else {
        return false;
    }
}