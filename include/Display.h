#include <Arduino.h>

#ifndef DISPLAY_H
#define DISPLAY_H

enum GUI_BLOCKS {QRCODE, SYMBOL, DIGITS};
enum GUI_PAGES {OPTIONS, PAYMENT, QRPAGE, SUCCESS, REFUSED, WARNING};

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