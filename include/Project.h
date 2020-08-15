#ifndef PROJECT_H
#define PROJECT_H

#include <Arduino.h>
#include <Printer.h>
#include <Display.h>
#include <KeyScan.h>

enum class RunLevel {SETUP, SCAN, SELECT, MENU, PAYMENT, READY, ERROR, HALT};

extern RunLevel LEVEL;
extern Display display;
extern KeyScan scanner;

#endif