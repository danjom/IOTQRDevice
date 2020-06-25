int sleep = 5000;

void runTests() {
  testDisplay();
}

void testDisplay() {
  changePage(OPTIONS);
  delay(sleep);

  changePage(PAYMENT);
  changeData(CURRENCY, "CRC");
  delay(sleep);
  changeData(DIGITS, "2580.00");
  delay(sleep);

  changePage(QRIMAGE);
  changeData(QRCODE, "CRC 2580.00");
  delay(sleep);

  changePage(SUCCESS);
  delay(sleep);

  changePage(REFUSED);
  delay(sleep);

  changePage(WARNING);
  delay(sleep);
}
