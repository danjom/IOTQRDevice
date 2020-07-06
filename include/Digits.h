#include <Arduino.h>

#ifndef DIGITS_H
#define DIGITS_H

class Digits {
    public:
<<<<<<< HEAD
        Digits();
        bool isEmpty();
        bool isValid();
        bool isDecimal();
        float getValue();
        String getField();
        void trimValue();
        void clearValue();
        void addDecimal();
        void addNumber(char);

    private:
        String value;
        const char SEPARATOR = '.';
=======
    bool isEmpty();
    bool isDecimal();
    float getValue();
    String getField();
    void trimValue();
    void addDecimal();
    void addNumber(char);
>>>>>>> Keypad and digits logic
};

#endif
