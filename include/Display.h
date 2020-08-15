#include <Project.h>

#ifndef DISPLAY_H
#define DISPLAY_H

enum class UIBlock {QRCODE, SYMBOL, DIGITS};
enum class UILabel {OPTION1, OPTION2, OPTION3, CURRENCY, SYMBOL, BACK, NEXT, SUCCESS, REFUSED, WARNING};
enum class Nextion {START, OPTIONS, PAYMENT, QRIMAGE, SUCCESS, REFUSED, WARNING, HISTORY};

class Display {
    public:
        Display();
        void changePage(Nextion page);
        void changeBlock(UIBlock block, String data);
        void changeField(int index, String data);
        void writeEndBits();
};

#endif