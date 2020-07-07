#include <Arduino.h>
#include <KeyScan.h>
#include <Digits.h>

<<<<<<< HEAD
<<<<<<< HEAD
KeyScan scanner = KeyScan();
Digits digits = Digits();

char input;
void check();

void setup() {
    Serial.begin(9600);
=======
=======
>>>>>>> master
KeyScan scanner;
Digits digits;
int status = 1;

void setup() {
    Serial.begin(9600);
    scanner = KeyScan();
<<<<<<< HEAD
>>>>>>> Keypad and digits logic
=======
>>>>>>> master
    Serial.println("\nProgram Started\n");
}

void loop() {
<<<<<<< HEAD
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
=======
>>>>>>> master
    char input = scanner.getKey();

    Serial.print("Input is: ");
    Serial.println(input);

<<<<<<< HEAD
>>>>>>> Keypad and digits logic
=======
>>>>>>> master
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
=======
        else {
            if (digits.isDecimal()) {
                Serial.println("Processing payment for USD" + String(digits.getValue()));
>>>>>>> master
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
<<<<<<< HEAD
    Serial.print("Field is: ");
=======
    Serial.print("Value is: ");
>>>>>>> Keypad and digits logic
=======
    Serial.print("Value is: ");
>>>>>>> master
    Serial.println(digits.getField());
}