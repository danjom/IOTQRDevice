#include <Arduino.h>
#include <Project.h>
#include <Options.h>
#include <Control.h>

bool SERIAL_DEBUG = true;

Blinker blinker = Blinker(22, 500, 500);
Control control = Control();
Project project = Project();
Display display = Display();
KeyScan scanner = KeyScan();
Printer printer = Printer();

void setup() {
    project.begin();
    control.begin();
}

void loop() {
    blinker.blink();
    control.check();
}