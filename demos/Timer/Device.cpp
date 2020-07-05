#include <Arduino.h>
#include <Timer.h>

Timer indicator = Timer(3000);

void setup() {
    Serial.begin(9600);
    Serial.println("\nProgram Started\n");
}

void loop() {
    if (indicator.check()) {
        Serial.println("CHECK");
    }
}