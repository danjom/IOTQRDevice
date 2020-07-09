#include <Project.h>

void Project::begin() {
    Serial.begin(9600);
    Serial.println("\nProgram Started\n");

    blinker.begin();
    blinker.setColor(BLUE);
    blinker.setLevel(125);
    blinker.display();
    blinker.turnLedOn();
}