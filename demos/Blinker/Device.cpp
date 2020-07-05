#include <Arduino.h>
#include <Signal.h>
#include <Timer.h>
#include <Blinker.h>

Timer ledtime = Timer(125);
Timer period = Timer(3000);
Signal indicator = Signal(22, 125);
Blinker ledblink = Blinker(indicator, ledtime);

uint32_t red = 0xFF0000;
uint32_t blue = 0x0000FF;
uint32_t green = 0x00FF00;
uint32_t white = 0xFFFFFF;
uint32_t orange = 0xFF4B00; 

bool enabled = true;

void setup() {
    indicator.init();
    indicator.setColor(orange);
    indicator.show();
}

void loop() {
    if (ledblink.getCount() <= 3) {
        ledblink.blink();
    }
    if (period.check()) {
        ledblink.resetCount();
    }
}