#include <Adafruit_NeoPixel.h>
#include <Signals.h>

const int LED_PIN = 22;
const int LED_COUNT = 1;

Adafruit_NeoPixel led = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

void Signals::init() {
    led.begin();
}

void Signals::blinkLED() {

}

void Signals::setColor() {

}