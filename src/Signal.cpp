#include <Adafruit_NeoPixel.h>
#include <Signal.h>

const uint16_t LED_COUNT = 1;
const uint8_t LED_INDEX = 0;

Adafruit_NeoPixel pixel;

uint32_t hexColor;
uint8_t brightness;

Signal::Signal() {
    
}

Signal::Signal(uint16_t LED_PIN, uint8_t LEVEL) {
    brightness = LEVEL;
    pixel = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);
}

void Signal::init() {
    pixel.begin();
}

void Signal::show() {
    pixel.setBrightness(brightness);
    pixel.setPixelColor(LED_INDEX, hexColor);
    pixel.show();
}

void Signal::setColor(uint32_t color) {
    hexColor = color;
}

void Signal::setLevel(uint8_t level) {
    brightness = level;
}

uint8_t Signal::getLevel() {
    return brightness;
}