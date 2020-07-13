#include <Arduino.h>
#include <Display.h>
#include <KeyScan.h>
#include <Signals.h>
#include <Blinker.h>
#include <Printer.h>

#ifndef PROJECT_H
#define PROJECT_H

extern Blinker blinker;
extern Display display;
extern KeyScan scanner;
extern Printer printer;
extern Signals signal;

extern String currency;

extern int state;
extern int event;

class Project {
    public:
        Project() = default;
        void begin();
};

#endif