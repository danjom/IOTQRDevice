#include <Arduino.h>

#ifndef DIGITS_H
#define DIGITS_H

class Digits {
    public:
        Digits();
        void trimValue();
        void clearValue();
        void addDecimal();
        void addNumber(char);
        bool isEmpty();
        bool isValid();
        bool isDecimal();
        float getValue();
        String getField();

    private:
        String value;
        char SEPARATOR = '.';
};

#endif
