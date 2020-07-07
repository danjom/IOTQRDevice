#include <Keypad.h>

#ifndef KEYSCAN_H
#define KEYSCAN_H

class KeyScan {
    public:
        KeyScan();
        Keypad keypad;
        char getKey();
        char waitForKey();
        void setDebounceTime(uint8_t);
};

#endif