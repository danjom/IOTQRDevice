#include <Arduino.h>
#include <Keypad.h>
#include <KeyScan.h>

const byte ROWS = 4;
const byte COLS = 3;

// for ESP32
byte colPins[COLS] = {14, 12, 13}; // connect to the column pinouts of the keypad
byte rowPins[ROWS] = {21, 19, 18, 5}; // connect to the row pinouts of the keypad

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char KeyScan::getKey() {
    char keyinput = '\0';

    bool pressed = false;

    while (!pressed) {
        keyinput = customKeypad.getKey();

        if (keyinput) {
            pressed = true;
        }
        delay(100); // debounce
    }
    return keyinput;
}
