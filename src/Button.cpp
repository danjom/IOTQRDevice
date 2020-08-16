#include <Button.h>

Button::Button() {
    BUTTON = 25;
    RESET_TIME = 10000;
    ERASE_TIME = 30000;

    reset.setTimer(RESET_TIME);
    erase.setTimer(ERASE_TIME);

    pinMode(BUTTON, INPUT_PULLDOWN);
}

BtnPress Button::check() {
    BtnPress state = BtnPress::STANDBY;

    erase.reset();
    reset.reset();

    while (digitalRead(BUTTON)) {
        if (reset.check()) {
            state = BtnPress::PRESS;
            Printer::toSerialNL("Short timer");
        }
        if (erase.check()) {
            state = BtnPress::HOLD;
            Printer::toSerialNL("Long timer");
        }
    }
    return state;
}