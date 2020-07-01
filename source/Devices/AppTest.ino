//int wtime = 1000; // wait time between delays

void runTests() {
  testDisplay();
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
