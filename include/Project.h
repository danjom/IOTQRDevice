#include <Arduino.h>
#include <Printer.h>
#include <APIData.h>

#ifndef PROJECT_H
#define PROJECT_H

enum class Status {CONFIG, MENU, PAYMENT, HALT};

extern Status progress;
extern Printer printer;
extern APIData params;

#endif