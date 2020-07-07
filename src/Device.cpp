#include <Arduino.h>
#include <KeyScan.h>
#include <Digits.h>

KeyScan scanner = KeyScan();
Digits digits = Digits();

char input;
void check();

void setup() {
    Serial.begin(9600);
    scanner = KeyScan();
    Serial.println("\nProgram Started\n");
}

void loop() {
    input = scanner.getKey();

    if (input) {
        Serial.print("Input is: ");
        Serial.println(input);
        check();
    }
}

void check() {
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