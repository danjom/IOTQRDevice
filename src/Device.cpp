#include <Project.h>
#include <APIData.h>
#include <Signals.h>
#include <Blinker.h>
#include <LEDTest.h>

#include <Control.h>

APIData params;
Display display;
Signals signal;
Blinker blinker;
KeyScan scanner;
LEDTest ledtest;
Control control;

RunLevel LEVEL = RunLevel::READY;

bool SERIAL_DEBUG = true;
bool DEVICE_RESET = false;

void setup() {
  delay(250);
  
  Serial.begin(9600);
  control.begin();
}

void loop() {
  control.check();
}