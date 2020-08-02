#include <Control.h>
#include <WClient.h>

const char ONE = '1';
const char TWO = '2';
const char THREE = '3';

void Control::begin() {
    printer.toSerialNL("Control started");
    payment.begin();
    while (true) {
        payment.start(PayCode::PURCHASE);
    }
    signal.display(READY);
    state = MENU;
}

void Control::check() {
    switch (state) {
        case MENU:
            showMenu();
            break;

        case SCAN:
            getKey();
            break;
        
        case SELECT:
            select();
            break;

        default:
            break;
    }
}

void Control::showMenu() {
    printer.toSerialNL("Waiting for key");
    signal.display(READY);
    display.changePage(OPTIONS);
    state = SCAN;
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
    switch (input) {

        case ONE:
            payment.start(PayCode::PURCHASE);
            break;

        case TWO:
            payment.start(PayCode::EXCHANGE);
            break;

        case THREE:
            payment.start(PayCode::HISTORY);
            break;
        
        default:
            state = SCAN;
            signal.display(WRONG);
            signal.display(READY);
            printer.toSerialNL("Invalid option");
    }
    
    if (progress == Status::MENU) {
        state = MENU;
    }
}