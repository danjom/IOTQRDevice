#include <Blinker.h>

Blinker::Blinker(uint16_t LED_PIN, unsigned long timeLedOn, unsigned long timeLedOff) {
    pixel = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);
    ledTimerOn = Timer(timeLedOn);
    ledTimerOff = Timer(timeLedOff);
    ledState = HIGH;
}

void Blinker::begin() {
    pixel.begin();
}

void Blinker::reset() {
    counter = 0;
}

void Blinker::display() {
    pixel.show();
}

void Blinker::blink() {
    if (ledState && ledTimerOn.check()) {
            turnLedOff();
            ledState = LOW;
            ledTimerOff.reset();
    }
    if (!ledState && ledTimerOff.check()) {
            turnLedOn();
            ledState = HIGH;
            ledTimerOn.reset();
    }
}

void Blinker::blink(int repetitions) {
    if (counter <= repetitions) {
        this->blink();
    }
}

void Blinker::turnLedOn() {
    pixel.setPixelColor(LED_INDEX, ledColor);
    pixel.show();
}

void Blinker::turnLedOff() {
    pixel.setPixelColor(LED_INDEX, LEDOFF);
    pixel.show();
    counter++;
}

void Blinker::setTimers(unsigned long timeLedOn, unsigned long timeLedOff) {
    ledTimerOn.setTimer(timeLedOn);
    ledTimerOff.setTimer(timeLedOff);
}

void Blinker::setColor(uint32_t color) {
    pixel.setPixelColor(LED_INDEX, color);
    ledColor = color;
}

void Blinker::setLevel(uint8_t level) {
    pixel.setBrightness(level);
    ledLevel = level;
}