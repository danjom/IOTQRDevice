#include <Project.h>
#include <APIData.h>
#include <Display.h>
#include <Signals.h>
#include <Blinker.h>
#include <Control.h>

APIData params;
Display display;
Signals signal;
Blinker blinker;

Control control;

RunLevel LEVEL = RunLevel::READY;

bool SERIAL_DEBUG = true;
bool DEVICE_RESET = false;
bool DEVICE_TEST = false;

int count = 1;  // for testing purposes

void setup() {
  delay(1000);
  Serial.begin(115000);
  control.begin();
}

void loop() {
  if (DEVICE_TEST) {
    Printer::toSerialSL("Iteration count: ");
    Printer::toSerialNL(String(count));
    control.test();
    count++;
    delay(1000);

  }
  else {
    control.check();
  }
}