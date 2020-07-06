#include <Arduino.h>
#include <KeyScan.h>
#include <Digits.h>

const char SEPARATOR = '.';

String value = "";

bool Digits::isEmpty() {
    return (value.length() == 0);
}

bool Digits::isDecimal() {
    return (value.indexOf(SEPARATOR) > 0);
}

float Digits::getValue() {
    return (value.toFloat());
}

String Digits::getField() {
    return value;
}

void Digits::addNumber(char digit) {
    value.concat(digit);
}

void Digits::addDecimal() {
    value.concat(SEPARATOR);
}

void Digits::trimValue() {
    value = value.substring(0, value.length()-1);
}