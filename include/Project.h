// #include <Arduino.h>
// #include <Blinker.h>
// #include <Signals.h>
// #include <Display.h>
// #include <KeyScan.h>
// #include <Printer.h>
// #include <Options.h>
#include <Arduino.h>
#include <Printer.h>

#ifndef PROJECT_H
#define PROJECT_H

enum class Status {CONFIG, MENU, PAYMENT};

extern Status progress;
extern Printer printer;

// extern Blinker blinker;
// extern Display display;
// extern KeyScan scanner;
// extern Printer printer;
// extern Signals signal;

#endif