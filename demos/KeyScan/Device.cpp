#include <Arduino.h>
#include <KeyScan.h>
#include <Digits.h>

<<<<<<< HEAD
KeyScan scanner = KeyScan();
Digits digits = Digits();

char input;
void check();

void setup() {
    Serial.begin(9600);
=======
KeyScan scanner;
Digits digits;
int status = 1;

void setup() {
    Serial.begin(9600);
    scanner = KeyScan();
>>>>>>> Keypad and digits logic
    Serial.println("\nProgram Started\n");
}

void loop() {
<<<<<<< HEAD
    input = scanner.getKey();

    if (input) {
        Serial.print("Input is: ");
        Serial.println(input);
        check();
    }
}

void check() {
=======
    char input = scanner.getKey();

    Serial.print("Input is: ");
    Serial.println(input);

>>>>>>> Keypad and digits logic
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
<<<<<<< HEAD
        else if (!digits.isValid()) {  
            Serial.println("[LED] Digits field is less than 1");
            digits.clearValue();
        }
        else {
            if (digits.isDecimal()) {
                Serial.println("Processing payment for USD " + String(digits.getValue()));
=======
        else {
            if (digits.isDecimal()) {
                Serial.println("Processing payment for USD" + String(digits.getValue()));
>>>>>>> Keypad and digits logic
            }
            else {
                digits.addDecimal();
            }
        }
    }
    else {
        digits.addNumber(input);
    }
<<<<<<< HEAD
    Serial.print("Field is: ");
=======
    Serial.print("Value is: ");
>>>>>>> Keypad and digits logic
    Serial.println(digits.getField());
}