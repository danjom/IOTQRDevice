#include <Arduino.h>
#include <Signal.h>

uint32_t red = 0xFF0000;
uint32_t blue = 0x0000FF;
uint32_t green = 0x00FF00;
uint32_t white = 0xFFFFFF;
uint32_t orange = 0xFF4B00; 

Signal led = Signal(22, 125);

void setup() {
    led.init();
}

void loop() {
    led.setColor(orange);
    led.setLevel(125);
    led.show();
    delay(1000);

    led.setLevel(0);
    led.show();
    delay(1000);

    led.setColor(green);
    led.setLevel(125);
    led.show();
    delay(1000);
    
    led.setLevel(0);
    led.show();
    delay(1000);
}