const char CONFIRM = '#'; // insert decimals or continue
const char DELETE = '*';   // delete last digit or cancel

void purchase() {
  changePage(PAYMENT);
  changeData(CURRENCY, currency);

  while (appstate != READY) {
    scanKeypad();
    checkDigit();
  }
}

void checkDigit() {
  switch (keyinput) {
    case CONFIRM:   // process action key #
      if (!isEmpty() && (getValue() > 1)) {
        process();
      }
      else {
        //led warning
      }
      break;

    case DELETE:   // process action key *
      if(isEmpty()) {
        appstate = READY;
      }
      else {
        trimValue();
        changeData(DIGITS, digitval);
      }
      break;

    default:    // if input is number
      addNumber(keyinput);
      changeData(DIGITS, digitval);
      break;
  }
}

void process() {
  changePage(QRIMAGE);
  changeData(QRCODE, "CRC 2580.00");
  delay(3000);

  changePage(SUCCESS);
  delay(3000);

  // add API logic
  appstate = READY;
}

void redeem() {
  // add API logic
}

void showRecent() {
  // add API logic
  changePage(RECENT);
}
