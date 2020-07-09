#include <Display.h>
#include <KeyScan.h>
#include <Digits.h>
#include <Blinker.h>

#ifndef CONTROL_H
#define CONTROL_H

extern Blinker blinker;

class Control {
    public:
        Control();
        void begin();
        void check();
        void getKey();
        void select();

        
    private:
        char input;
        Digits digits;
        Display display;
        KeyScan scanner;
};

#endif