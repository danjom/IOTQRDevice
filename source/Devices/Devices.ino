#include "display.h"
<<<<<<< Updated upstream
#include "project.h"

void setup() {
  Serial.begin(9600);
  Serial.println("\nSystem Started\n");
=======
<<<<<<< Updated upstream
=======
#include "payment.h"
#include "project.h"
>>>>>>> Stashed changes

void setup() {
  Serial.begin(9600);
  
<<<<<<< Updated upstream
  while(!Serial.available()) {
    delay(1000);
  }
  runTests();
=======
  if (testmode) {
    runTests();
  }
>>>>>>> Stashed changes
>>>>>>> Stashed changes
}

void loop() {
<<<<<<< Updated upstream
  appBegin();
=======
<<<<<<< Updated upstream
  
=======
  if (!testmode) {
    appBegin();
  }
>>>>>>> Stashed changes
>>>>>>> Stashed changes
}
