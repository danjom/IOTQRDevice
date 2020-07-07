#include <Arduino.h>
#include <Display.h>

void Display::changePage(int index) {
    Serial.print(PAGE + index);
    writeEndBits();
}

void Display::changeData(int block, String data) {
    Serial.print(FIELDS[block] + CHAR + data + CHAR);
    writeEndBits();
}

void Display::writeEndBits() {
    Serial.print("\xFF\xFF\xFF");
}