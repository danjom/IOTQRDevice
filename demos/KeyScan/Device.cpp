#include <Arduino.h>
#include <KeyScan.h>
#include <Digits.h>

KeyScan scanner;
Digits digits;
int status = 1;

void setup() {
    Serial.begin(9600);
    scanner = KeyScan();
    Serial.println("\nProgram Started\n");
}

void loop() {
    char input = scanner.getKey();

    Serial.print("Input is: ");
    Serial.println(input);

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
        else {
            if (digits.isDecimal()) {
                Serial.println("Processing payment for USD" + String(digits.getValue()));
            }
            else {
                digits.addDecimal();
            }
        }
    }
    else {
        digits.addNumber(input);
    }
    Serial.print("Value is: ");
    Serial.println(digits.getField());
}