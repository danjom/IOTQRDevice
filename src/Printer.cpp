#include <Printer.h>

void Printer::toSerialSL(String msg) {
    if (SERIAL_DEBUG) {
        Serial.print(msg);
    }
}

void Printer::toSerialNL(String msg) {
    if (SERIAL_DEBUG) {
        Serial.println(msg);
    }
}