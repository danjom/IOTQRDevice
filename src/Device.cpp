#include <Arduino.h>
#include <Common.h>
#include <Settings.h>
#include <Network.h>

bool SERIAL_DEBUG = true;

Printer printer = Printer();
Network network = Network();
Settings settings = Settings();

//String password = "T7H4878tNr7F6dq4Jh8HxgmZa";
//String systemid = "NETDEV01";

void start();
void reading();
void connect();

void setup() {
  start();
  reading();
}

void loop() {
  
}

void start() {
  delay(5000);
  Serial.begin(9600);
  printer.toSerialNL("\nProgram Started\n");
}

void connect() {
  // network.setTimeout(30000);
  // network.setupNetwork(systemid, password);
  // network.setupDevice("Dona Dona", "wUEk7Zf38Y79vyBHUJ9KIA", "CRC", "en-US", 1);
  // network.startClient();
  // network.checkStatus();
}

void reading() {
  settings.begin();
  //settings.check();
  // settings.check();
  //settings.clearPassword();
  //settings.readPassword();
  //settings.check();
  //settings.writePassword("HOMEDEV", "HOMEPWD");
  //printer.toSerialNL("Reading device password content");
  //settings.readPassword();
}