#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

// for ESP32
byte colPins[COLS] = {14, 12, 13}; // connect to the column pinouts of the keypad
byte rowPins[ROWS] = {21, 19, 18, 5}; // connect to the row pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

  
void getKeyPressed(){
  input = customKeypad.getKey();
  
  if (input){
    //Serial.println(input);
    state = READY;
  }
  delay(100); // debounce 
}
