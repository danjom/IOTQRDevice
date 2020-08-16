#include <Project.h>

#include <Display.h>
#include <KeyScan.h>
#include <LEDTest.h>

#include <APIData.h>
#include <Button.h>
#include <Settings.h>
#include <Connect.h>
#include <Request.h>
#include <Payment.h>

#ifndef CONTROL_H
#define CONTROL_H

extern APIData params;
extern Display display;
extern Signals signal;
extern Blinker blinker;
extern LEDTest ledtest;

class Control {
    public:
        Control();
        void begin();
        void check();

    private:
        void runSetup();
        void getInput();
        void checkRST();
        void showMenu();
        void select();
        void process();

        Settings settings;
        Connect network;
        Payment payment;
        PayCode paycode;
        Button button;
        
        char input;
        
};

#endif