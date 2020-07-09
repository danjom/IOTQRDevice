#include <Control.h>

bool alert = false;

Control::Control() {
    
}

void Control::begin() {
    display = Display();
    scanner = KeyScan();
    scanner.setDebounceTime(100);
    // blinker.begin();
    // blinker.setColor(WHITE);
    // blinker.setLevel(80);
    // blinker.display();
    // blinker.turnLedOn();
}

void Control::check() {
    if (alert) {
        blinker.blinkD(125, 125);
        if (blinker.getCounter() > 2) {
            alert = false;
            blinker.setColor(WHITE);
            blinker.display();
            blinker.reset();
        }
    }
    getKey();
}

void Control::getKey() {
    input = scanner.getKey();

    if (input) {
        select();
    }
}

void Control::select() {
    if (input == '*') {
        if (digits.isEmpty()) {
            Serial.println("Switching previous screen");
        }
        else {
            digits.trimValue();
        }
    }
    else if (input == '#') {
        if (digits.isEmpty()) {
            Serial.println("[LED] Digits field is empty");
            alert = true;
            blinker.turnLedOff();
            blinker.setColor(RED);
        }
        else if (!digits.isValid()) {  
            Serial.println("[LED] Digits field is less than 1");
            digits.clearValue();
        }
        else {
            if (digits.isDecimal()) {
                Serial.println("Processing payment for USD " + String(digits.getValue()));
            }
            else {
                digits.addDecimal();
            }
        }
    }
    else {
        digits.addNumber(input);
    }
    Serial.print("Field is: ");
    Serial.println(digits.getField());
}
