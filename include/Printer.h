#include <Arduino.h>

#ifndef PRINTER_H
#define PRINTER_H

extern bool SERIAL_DEBUG;

class Printer final {
    public:
        Printer() = delete;
        static void toSerialSL(String message);
        static void toSerialNL(String message);       
};

#endif