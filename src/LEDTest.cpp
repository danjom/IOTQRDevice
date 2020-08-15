#define LED_PIN 23
#define LED_NUM 1
#define FASTLED_ALLOW_INTERRUPTS 0

#include <LEDTest.h>


LEDTest::LEDTest() {
    FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, LED_NUM);
}

void LEDTest::begin() {
    leds[0] = CRGB::LimeGreen;
    FastLED.show();
    Printer::toSerialNL("LED is ON");
}