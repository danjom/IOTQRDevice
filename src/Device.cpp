#include <Arduino.h>
#include <Project.h>

#include <Display.h>
#include <KeyScan.h>
#include <Signals.h>
#include <Blinker.h>
#include <Runner.h>

Printer printer;
APIData params;
Display display;
KeyScan scanner;
Signals signal;
Blinker blinker;
Runner runner;

Status progress = Status::CONFIG;
bool SERIAL_DEBUG = true;
bool DEVICE_RESET = false;

void setup() {
  delay(3000);
  Serial.begin(9600);
  runner.begin();
}

void loop() {
  runner.check();
}