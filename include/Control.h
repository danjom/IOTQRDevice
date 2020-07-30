#include <Project.h>
#include <Display.h>
#include <KeyScan.h>
#include <Signals.h>
#include <Payment.h>

#ifndef CONTROL_H
#define CONTROL_H

extern Display display;
extern KeyScan scanner;
extern Signals signal;

class Control {
    enum options {MENU, SCAN, SELECT};
    public:
        Control() = default;
        void begin();
        void check();
        void getKey();
        void select();

    private:
        int state;
        char input;

        Payment payment;
};

#endif