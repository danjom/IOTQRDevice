#include "display.h"

void setup() {
  Serial.begin(9600);
  
  while(!Serial.available()) {
    delay(1000);
  }
  runTests();
}


void loop() {
  
}
