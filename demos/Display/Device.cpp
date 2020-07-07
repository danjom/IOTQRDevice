#include <Arduino.h>
#include <Display.h>

Display display = Display();;

void setup() {
    Serial.begin(9600);
}

void loop() {
    display.changePage(OPTIONS);
    delay(3000);
    display.changePage(PAYMENT);
    display.changeData(SYMBOL, "CRC");
    delay(3000);
    display.changeData(DIGITS, "3500.00");
    delay(3000);
    display.changePage(QRPAGE);
    display.changeData(QRCODE, "3500.00");
    delay(3000);
    display.changePage(SUCCESS);
    delay(3000);
    display.changePage(REFUSED);
    delay(3000);
    display.changePage(WARNING);
    delay(3000);
}