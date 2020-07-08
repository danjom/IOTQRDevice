#include <Arduino.h>
#include <Blinker.h>
#include <Timer.h>

void blinkTest();

Blinker blinker = Blinker(22, 500, 500);
Timer timer = Timer(6000);

void setup() {
    Serial.begin(9600);
    blinker.setColor(GREEN);
    blinker.begin();
    blinker.display();
    blinker.setLevel(255);
}

void loop() {
    blinkTest();
}

void blinkTest() {
    blinker.blink(3);
    if (timer.check()) {
        blinker.reset();
    }
}