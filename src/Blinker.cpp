#include <Arduino.h>
#include <Signal.h>
#include <Timer.h>
#include <Blinker.h>

Signal signal;
Timer timer;

byte state;
uint8_t level;
uint8_t count;

Blinker::Blinker() {

}

Blinker::Blinker(Signal control, Timer time) {
    level = signal.getLevel();
    signal = control;
    timer = time;
}


uint8_t Blinker::getCount() {
    return count;
}

void Blinker::resetCount() {
    count = 0;
}

void Blinker::blink() {
    if (timer.check()) {
        // if LED is HIGH
        if (state) {
            turnLedOn();
        }
        // if LED is LOW
        else {
            turnLedOff();
        }
    }
}

void Blinker::blink(uint8_t period) {
    while (count <= period) {
        this->blink();
    } 
}

void Blinker::fade() {

}

void Blinker::turnLedOn() {
    state = LOW;
    signal.setLevel(0);
    signal.show();
}

void Blinker::turnLedOff() {
    state = HIGH;
    signal.setLevel(level);
    signal.show();
    count++;
}