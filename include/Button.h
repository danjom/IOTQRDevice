#include <Project.h>
#include <Timer.h>

#ifndef BUTTON_H
#define BUTTON_H

enum class BtnPress {STANDBY, PRESS, HOLD};

class Button {
    public:
        Button();
        BtnPress check();
    private:
        byte BUTTON;
        Timer reset;
        Timer erase;
        unsigned long RESET_TIME;
        unsigned long ERASE_TIME;
};

#endif