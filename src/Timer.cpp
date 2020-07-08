#include <Arduino.h>
#include <Timer.h>

Timer::Timer(unsigned int time) {
    interval = time;
}

void Timer::setTimer(unsigned int time) {
    interval = time;
}

bool Timer::check() {
    current = millis();

    if ((current - previous) >= interval) {
        previous = current;
        return true;
    }
    else {
        return false;
    }
}