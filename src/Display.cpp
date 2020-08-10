#include <Arduino.h>
#include <Display.h>

const String CHAR = "\""; 
const String PAGE = "page ";
const String FIELDS[] = {"QRCode.txt=", "Symbol.txt=", "Digits.txt="};

void Display::changePage(Nextion page) {
    Serial.print(PAGE + (int)page);
    writeEndBits();
}

void Display::changeData(UIBlock block, String data) {
    Serial.print(FIELDS[(int)block] + CHAR + data + CHAR);
    writeEndBits();
}

void Display::writeEndBits() {
    Serial.print("\xFF\xFF\xFF");
}