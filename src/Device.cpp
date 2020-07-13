#include <Control.h>
#include <Project.h>
#include <Options.h>

bool SERIAL_DEBUG = false;

Blinker blinker = Blinker(22, 500, 500);
Control control = Control();
Project project = Project();
Display display = Display();
KeyScan scanner = KeyScan();
Payment payment = Payment();
Printer printer = Printer();
Signals signal = Signals();

String currency = "CRC";

int state = MENU;
int event = READY;

void setup() {
    project.begin();
    control.begin();
}

void loop() {
    control.check();
}