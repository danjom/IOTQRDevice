#include <Keypad.h>

#ifndef KEYSCAN_H
#define KEYSCAN_H

class KeyScan {
    public:
        Keypad keypad;
        KeyScan();
        char getKey();
        char waitForKey();
        void setDebounceTime(uint8_t);
};

#endif
