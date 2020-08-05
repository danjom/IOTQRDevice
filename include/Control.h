#include <Project.h>

#include <Display.h>
#include <KeyScan.h>
#include <Signals.h>
#include <Blinker.h>

#include <APIData.h>
#include <Settings.h>
#include <Connect.h>
#include <APITest.h>
#include <Request.h>
#include <Payment.h>

#ifndef CONTROL_H
#define CONTROL_H

extern APIData params;
extern Display display;
extern Signals signal;
extern Blinker blinker;

class Control {
    public:
        Control();
        void begin();
        void check();
        void test();

    private:
        void runSetup();
        void getInput();
        void showMenu();
        void select();
        void process();

        KeyScan scanner;
        Settings settings;
        Connect network;
        APITest apitest;
        Request request;
        Payment payment;
        PayCode paycode;
        
        char input;
        
};

#endif