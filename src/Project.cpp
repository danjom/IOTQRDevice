#include <Project.h>

void Project::begin() {
    Serial.begin(9600);
    printer.toSerialNL("\n\nProgram Started");

    blinker.begin();
    blinker.setColor(ORANGE);
    blinker.setLevel(125);
    blinker.display();
    blinker.turnLedOn();

    scanner.setDebounceTime(100);
}