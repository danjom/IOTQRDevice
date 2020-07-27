#include <Printer.h>

void Printer::toSerialSL(String msgs) {
    if (SERIAL_DEBUG) {
        Serial.print(msgs);
    }
}

void Printer::toSerialNL(String msgs) {
    if (SERIAL_DEBUG) {
        Serial.println(msgs);
    }
}