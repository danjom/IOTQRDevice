void appBegin() {
  digitval = "";
  menuControl();
}

void menuControl() {
  changePage(OPTIONS);
  appstate = MENU;
  while(appstate == MENU) {
    scanKeypad();
    checkOption();
  }
}

void checkOption() {
  switch (keyinput) {
    case '1':
      appstate = PURCHASE;
      purchase();
      break;

    case '2':

      break;

    case '3':

      break;

    default:
      //led warning
      break;
  }
}
