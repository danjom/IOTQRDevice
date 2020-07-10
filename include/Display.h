#include <Arduino.h>

#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
    public:
        void changePage(int);
        void changeData(int, String);
        void writeEndBits();

    private:
        String CHAR = "\""; 
        String PAGE = "page ";
        String FIELDS[3] = {"QRCode.txt=", "Symbol.txt=", "Digits.txt="};
};

#endif