#include <Control.h>
#include <Project.h>
#include <Options.h>

const char ONE = '1';
const char TWO = '2';
const char THREE = '3';

void Control::begin() {
    printer.toSerialNL("Control started");
    state = MENU;
}


void Control::check() {
    switch (state) {
        case MENU:
            printer.toSerialNL("Waiting for key");
            signal.display(READY);
            display.changePage(OPTIONS);
            state = SCAN;
            break;

        case SCAN:
            getKey();
            break;
        
        case SELECT:
            select();
            break;

        case EVENT:
            payment.check();
            break;

        case DONE:
            state = MENU;
            break;
    }
}

void Control::getKey() {
    input = scanner.getKey();

    if (input) {
        printer.toSerialSL("Input is: ");
        printer.toSerialNL(String(input));
        state = SELECT;
    }
}

void Control::select() {
    state = EVENT;
    switch (input) {
        case ONE:
            display.changePage(PAYMENT);
            display.changeData(SYMBOL, currency);
            event = PAYMENT;
            break;

        case TWO:
            event = REDEEM;
            break;

        case THREE:
            event = HISTORY;
            break;
        
        default:
            state = SCAN;
            signal.display(WRONG);
            signal.display(READY);
            printer.toSerialNL("Invalid option");
    }
}