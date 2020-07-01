
String digits;
int wtime = 3000; // wait time between delays

void appBegin() {
  checkappstate();
}

void checkappstate() {
  switch (appstate) {

int appappstate = MENU;       // program appstate execution
int wtime = 3000; // wait time between delays

void appBegin() {
  checkappappstate();
}

void checkappappstate() {
  switch (appappstate) {

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

  //Serial.println("appstate: MENU");
  changePage(OPTIONS);
  scanKeypad();

  switch (input) {
    case '1':
      //Serial.println("1 - PAYMENT");
      appstate = PURCHASE;

  //Serial.println("appappstate: MENU");
  changePage(OPTIONS);
  scanKeypad();

  switch (keyinput) {
    case '1':
      //Serial.println("1 - PAYMENT");
      appappstate = PURCHASE;
      break;

    case '2':
      //Serial.println("2 - REDEEM");
      appappstate = REDEEM;
      break;

    case '3':
      //Serial.println("3 - HISTORY");
      appstate = HISTORY;
      break;
  }
}

void scanKeypad() {
  while (appstate != READY) {
    getKeyPressed();
  }
}

void purchase() {
  //Serial.println("appstate: PURCHASE");

      appappstate = HISTORY;
      break;

    default:
      appappstate = MENU;
      break;
  }
}


void purchase() {
  //Serial.println("appappstate: PURCHASE");

  changePage(PAYMENT);

  changeData(CURRENCY, "CRC");
  delay(3000);

  changeData(DIGITS, "2580.00");

  scanKeypad();

  switch (input) {
    case '#':
      appstate = PROCESS;

  switch (keyinput) {
    case '#':
      appappstate = PROCESS;
      break;

    case '*':
      //Serial.println("USER CANCELED");
      appstate = MENU;
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
  appstate = MENU;
}

void showRecent() {
  //Serial.println("appstate: HISTORY");
  changePage(RECENT);
  delay(5000);
  appstate = MENU;
}

void redeem() {
  appstate = MENU;
  appappstate = MENU;
}

void showRecent() {
  //Serial.println("appappstate: HISTORY");
  changePage(RECENT);
  delay(5000);
  appappstate = MENU;
}

void redeem() {
  appappstate = MENU;
}
