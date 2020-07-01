<<<<<<< Updated upstream
enum states {READY, SETUP, MENU, KEYPAD, PURCHASE, REDEEM, HISTORY, PROCESS};

String symbol = "CRC";
int state = MENU;
char input = ' ';
=======
String currency = "CRC"; 
String digitval = "";      // amount to be paid on LCD display
char keyinput = ' ';       // reading of single key press
bool testmode = 0;         // test mode toggle
>>>>>>> Stashed changes
