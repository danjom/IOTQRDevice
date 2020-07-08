#include <Signal.h>

Signal::Signal(uint16_t LED_PIN) {
    Signal(LED_PIN, MAX_LEVEL);
}

Signal::Signal(uint16_t LED_PIN, uint8_t LEVEL) {
    brightness = LEVEL;
    pixel = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);
}

void Signal::begin() {
    pixel.begin();
}

void Signal::show() {
    pixel.setPixelColor(LED_INDEX, hexColor);
    pixel.setBrightness(brightness);
    pixel.show();
}

void Signal::setColor(uint32_t color) {
    hexColor = color;
    this->show();
}

void Signal::setLevel(uint8_t level) {
    pixel.setBrightness(level);
    pixel.show();
}

void Signal::restart() {
    pixel.setBrightness(brightness);
    pixel.show();
}