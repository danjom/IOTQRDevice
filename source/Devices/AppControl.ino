String digits;
int wtime = 3000; // wait time between delays

void appBegin() {
  checkState();
}

void checkState() {
  switch (state) {
    case MENU:
      menuControl();
      break;

    case PURCHASE:
      purchase();
      break;

    case PROCESS:
      process();
      break;

    case HISTORY:
      showRecent();
      break;

    case REDEEM:
      redeem();
      break;
  }
}

void menuControl() {
  //Serial.println("STATE: MENU");
  changePage(OPTIONS);
  scanKeypad();

  switch (input) {
    case '1':
      //Serial.println("1 - PAYMENT");
      state = PURCHASE;
      break;

    case '2':
      //Serial.println("2 - REDEEM");
      state = REDEEM;
      break;

    case '3':
      //Serial.println("3 - HISTORY");
      state = HISTORY;
      break;
  }
}

void scanKeypad() {
  while (state != READY) {
    getKeyPressed();
  }
}

void purchase() {
  //Serial.println("STATE: PURCHASE");
  changePage(PAYMENT);

  changeData(CURRENCY, "CRC");
  delay(3000);

  changeData(DIGITS, "2580.00");

  scanKeypad();

  switch (input) {
    case '#':
      state = PROCESS;
      break;

    case '*':
      //Serial.println("USER CANCELED");
      state = MENU;
      break;
  }
}

void process() {
  //Serial.println("SELECTED PROCESS");
  //Serial.println("GENERATING QRCODE");
  changePage(QRIMAGE);
  changeData(QRCODE, "CRC 2580.00");
  delay(wtime);

  //Serial.println("PAYMENT SUCCESS");
  changePage(SUCCESS);
  delay(wtime);

  state = MENU;
}

void showRecent() {
  //Serial.println("STATE: HISTORY");
  changePage(RECENT);
  delay(5000);

  state = MENU;
}

void redeem() {
  state = MENU;
}
