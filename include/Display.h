#include <Arduino.h>

#ifndef DISPLAY_H
#define DISPLAY_H

enum class UIBlock {QRCODE, SYMBOL, DIGITS};
enum class Nextion {OPTIONS, PAYMENT, QRIMAGE, SUCCESS, REFUSED, WARNING, HISTORY};

class Display {
    public:
        void changePage(Nextion page);
        void changeData(UIBlock block, String data);
        void writeEndBits();

    private:
        String CHAR = "\""; 
        String PAGE = "page ";
        String FIELDS[3] = {"QRCode.txt=", "Symbol.txt=", "Digits.txt="};
};

#endif