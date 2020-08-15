#include <Project.h>
#include <FastLED.h>

#ifndef LEDTEST_H
#define LEDTEST_H

    class LEDTest {
        public:
            LEDTest();
            void begin();
            void show(void * parameter);
        private:
            CRGB leds[1];
    };

#endif