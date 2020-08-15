#include <Signals.h>

void Signals::display(int id) {
    switch (id) {
        case CORRECT:
            correct();
        break;

        case AwAIT:
            waiting();
        break;

        case REJECT:
            refused();
        break;

        case WRONG:
            invalid();
        break;

        case READY:
            started();
        break;
    }
    blinker.display();
    delay(1000);
}

void Signals::correct() {
    blinker.setColor(GREEN);
    blinker.display();
}

void Signals::waiting() {
    blinker.setColor(BLUE);
    blinker.display();
}

void Signals::refused() {
    blinker.setColor(RED);
    blinker.display();
}

void Signals::invalid() {
    blinker.setColor(WHITE);
    blinker.strobe(125);
}

void Signals::started() {
    blinker.setColor(WHITE);
    blinker.display();
}