#ifndef PROJECT_H
#define PROJECT_H

#include <Arduino.h>
#include <Printer.h>

enum class RunLevel {SETUP, SCAN, SELECT, MENU, PAYMENT, READY, ERROR};
extern RunLevel LEVEL;

#endif