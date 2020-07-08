#include <Arduino.h>
#include <Signal.h>

void colorTest();

Signal indicator = Signal(22, 125);

void setup() {
    indicator.begin();
    indicator.setColor(WHITE);
}

void loop() {
    colorTest();
}

void colorTest() {
    indicator.setColor(WHITE);
    delay(1000);
    indicator.setLevel(255);
    delay(1000);
    indicator.restart();
    delay(1000);

    indicator.setColor(BLUE);
    delay(1000);
    indicator.setLevel(255);
    delay(1000);
    indicator.restart();
    delay(1000);

    indicator.setColor(GREEN);
    delay(1000);
    indicator.setLevel(255);
    delay(1000);
    indicator.restart();
    delay(1000);

    indicator.setColor(ORANGE);
    delay(1000);
    indicator.setLevel(255);
    delay(1000);
    indicator.restart();
    delay(1000);

    indicator.setColor(RED);
    delay(1000);
    indicator.setLevel(255);
    delay(1000);
    indicator.restart();
    delay(1000);
}