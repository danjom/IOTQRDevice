#include "display.h"
#include "project.h"
#include "payment.h"

void setup() {
  Serial.begin(9600);
  if (testmode) {
    runTests();
  }
}

void loop() {
  if (!testmode) {
    appBegin();
  }
}
