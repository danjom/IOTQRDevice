int wtime = 1000; // wait time between delays

void runTests() {
  //testDisplay();
  testDigits();
}

void testDisplay() {
  changePage(OPTIONS);
  delay(wtime);

  changePage(PAYMENT);
  changeData(CURRENCY, "CRC");
  delay(wtime);
  changeData(DIGITS, "2580.00");
  delay(wtime);

  changePage(QRIMAGE);
  changeData(QRCODE, "CRC 2580.00");
  delay(wtime);

  changePage(SUCCESS);
  delay(wtime);

  changePage(REFUSED);
  delay(wtime);

  changePage(WARNING);
  delay(wtime);
}

void testDigits() {
  Serial.println();
  Serial.print("Value: ");
  getValue();
  delay(1000);

  Serial.print("Empty: ");
  isEmpty();
  delay(1000);

  Serial.println("Adding 5");
  addNumber('5');
  delay(1000);

  Serial.println("Adding 0");
  addNumber('0');
  delay(1000);

  Serial.print("Empty: ");
  isEmpty();
  delay(1000);

  Serial.print("Value: ");
  getValue();
  delay(1000);

  Serial.println("Deleting 0");
  trimValue();
  delay(1000);

  Serial.print("Value: ");
  getValue();
  delay(1000);

  Serial.println("Deleting 5");
  trimValue();
  delay(1000);

  Serial.print("Value: ");
  getValue();
  delay(1000);

  Serial.print("Empty: ");
  isEmpty();
  delay(1000);
}
