#include <Arduino.h>
#include <Printer.h>

#ifndef PROJECT_H
#define PROJECT_H

enum class Status {CONFIG, MENU, PAYMENT};

extern Status progress;
extern Printer printer;

#endif