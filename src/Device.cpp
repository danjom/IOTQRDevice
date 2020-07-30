#include <Project.h>
#include <APIData.h>
#include <Display.h>
#include <KeyScan.h>
#include <Signals.h>
#include <Blinker.h>
#include <Settings.h>
#include <Network.h>
#include <Requests.h>
#include <Control.h>

bool SERIAL_DEBUG = true;
bool DEVICE_RESET = false;

Status progress = Status::CONFIG;

APIData params = APIData();
Display display = Display();
KeyScan scanner = KeyScan();
Signals signal = Signals();
Blinker blinker = Blinker();
Settings settings = Settings();
// Network network = network;
// Requests request = Requests();
Printer printer = Printer();
Control control = Control();

void start();
void config();

void setup() {
  delay(3000);
  Serial.begin(9600);
  printer.toSerialNL("\nProgram Started\n");

  config();
  start();
}

void loop() {
  control.check();
}

void start() {
  settings.begin();
  control.begin();
}

void config() {
  progress = Status::CONFIG;

  scanner.setDebounceTime(100);

  blinker.begin(22, 500, 500);
  blinker.setColor(ORANGE);
  blinker.setLevel(125);
  blinker.display();
  blinker.turnLedOn();
}