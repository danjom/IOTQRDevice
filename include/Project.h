#include <Arduino.h>
#include <Blinker.h>
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

class Project {
    public:
        Project() = default;
        void begin();
};

#endif