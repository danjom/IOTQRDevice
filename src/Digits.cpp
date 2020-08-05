#include <Digits.h>

Digits::Digits() {
    value = "";
}

bool Digits::isEmpty() {
    return (value.length() == 0);
}

bool Digits::isValid() {
    return (getValue() >= 1);
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
    value.remove(value.length()-1, 1);
    //value = value.substring(0, value.length()-1);
}

void Digits::clearValue() {
    value = "";
}