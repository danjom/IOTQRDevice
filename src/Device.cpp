#include <Arduino.h>
#include <Common.h>
#include <Settings.h>
#include <Network.h>
#include <APIData.h>

bool SERIAL_DEBUG = true;
bool DEVICE_RESET = false;

Printer printer = Printer();
Network network = Network();
Settings settings = Settings();
APIData params = APIData();


void start();

void setup() {
  start();
  settings.begin();
}

void loop() {
  
}

void start() {
  delay(3000);
  Serial.begin(9600);
  printer.toSerialNL("\nProgram Started\n");
}