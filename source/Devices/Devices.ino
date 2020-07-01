#include "display.h"
#include "project.h"

void setup() {
  Serial.begin(9600);
  Serial.println("\nSystem Started\n");
}


void loop() {
  appBegin();
}
