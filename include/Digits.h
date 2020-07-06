#include <Arduino.h>

#ifndef DIGITS_H
#define DIGITS_H

class Digits {
    public:
    bool isEmpty();
    bool isDecimal();
    float getValue();
    String getField();
    void trimValue();
    void addDecimal();
    void addNumber(char);
};

#endif
