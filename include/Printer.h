#include <Arduino.h>

#ifndef PRINTER_H
#define PRINTER_H

extern bool SERIAL_DEBUG;
class Printer {
    public:
        Printer() = default;
        void toSerialSL(String);
        void toSerialNL(String);       
};

#endif