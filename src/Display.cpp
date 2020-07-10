#include <Arduino.h>
#include <Display.h>

const String CHAR = "\""; 
const String PAGE = "page ";
const String FIELDS[] = {"QRCode.txt=", "Symbol.txt=", "Digits.txt="};

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