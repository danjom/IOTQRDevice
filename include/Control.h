#include <Project.h>
#include <Display.h>
#include <KeyScan.h>
#include <Signals.h>
#include <Payment.h>
#include <Printer.h>

#ifndef CONTROL_H
#define CONTROL_H

extern Display display;
extern KeyScan scanner;
extern Signals signal;
extern Payment payment;
extern Printer printer;

class Control {
    enum options {MENU, SCAN, SELECT};
    public:
        Control() = default;
        void begin();
        void check();

    private:
        void showMenu();
        void getKey();
        void select();

        int state;
        char input;
};

#endif