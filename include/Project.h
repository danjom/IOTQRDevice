#include <Arduino.h>
#include <Blinker.h>
#include <Signals.h>
#include <Display.h>
#include <KeyScan.h>
#include <Printer.h>
#include <Options.h>

#ifndef PROJECT_H
#define PROJECT_H

extern Blinker blinker;
extern Display display;
extern KeyScan scanner;
extern Printer printer;
extern Signals signal;

class Project {
    public:
        Project() = default;
        void begin();
};

#endif