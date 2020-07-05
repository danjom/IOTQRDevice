#include <Arduino.h>
#include <Timer.h>

unsigned long current;
unsigned long previous;
unsigned int timing;

Timer::Timer() {
    
}

Timer::Timer(unsigned int interval) {
    timing = interval;
}

bool Timer::check() {
    current = millis();

    if ((current - previous) >= timing) {
        previous = current;
        return true;
    }
    else {
        return false;
    }
}