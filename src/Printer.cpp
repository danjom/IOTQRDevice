#include <Printer.h>

void Printer::toSerialSL(String message) {
    if (SERIAL_DEBUG) {
        Serial.print(message);
    }
}

void Printer::toSerialNL(String message) {
    if (SERIAL_DEBUG) {
        Serial.println(message);
    }
}