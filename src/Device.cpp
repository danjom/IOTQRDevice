#include <Arduino.h>
#include <Project.h>
#include <Control.h>

Blinker blinker = Blinker(22, 500, 500);
Control control = Control();
Project project = Project();

void setup() {
    project.begin();
    control.begin();
}

void loop() {
    //control.check();
}