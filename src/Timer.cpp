#include <Timer.h>

const unsigned long DEFAULT_TIME = 1000;

Timer::Timer() {
    interval = DEFAULT_TIME;
}

Timer::Timer(unsigned long time) {
    interval = time;
}

void Timer::setTimer(unsigned long time) {
    interval = time;
}

void Timer::reset() {
    current = millis();
    previous = millis();
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