#include <Control.h>

Control::Control() {
    LEVEL = RunLevel::SETUP;
}

void Control::begin() {
    Printer::toSerialNL("\nProgram Started\n");

    scanner.setDebounceTime(50);
    blinker.begin(22, 500, 500);
    blinker.setColor(ORANGE);
    blinker.setLevel(125);
    blinker.display();
    blinker.turnLedOn();

    runSetup();
}

void Control::check() {
    if (LEVEL == RunLevel::SETUP) {
        runSetup();
    }
    else if (LEVEL == RunLevel::MENU) {
        showMenu();
    }
    else if (LEVEL == RunLevel::SCAN) {
        getInput();
    }
    else if (LEVEL == RunLevel::SELECT) {
        select();
    }
    else if (LEVEL == RunLevel::PAYMENT) {
        process();
    }
    else if (LEVEL == RunLevel::READY) {
        Printer::toSerialNL("System is ready");
        LEVEL = RunLevel::MENU;
    }
}

void Control::runSetup() {
    settings.begin();
    network.connect();

    LEVEL = RunLevel::MENU;
}

void Control::showMenu() {
    Printer::toSerialNL("Waiting for key");
    signal.display(READY);
    display.changePage(OPTIONS);

    LEVEL = RunLevel::SCAN;
}

void Control::getInput() {
    scanner.setDebounceTime(50);
    
    input = scanner.getKey();

    if (input) {
        Printer::toSerialSL("Input is: ");
        Printer::toSerialNL(String(input));

        LEVEL = RunLevel::SELECT;
    }
}

void Control::select() {
    switch (input) {
        case '1':
            LEVEL = RunLevel::PAYMENT;
            break;

        case '2':
            LEVEL = RunLevel::PAYMENT;
            break;

        case '3':
            LEVEL = RunLevel::PAYMENT;
            break;
        
        default:
            signal.display(WRONG);
            signal.display(READY);
            Printer::toSerialNL("Invalid option");

            LEVEL = RunLevel::SCAN;
            break;
    }
}

void Control::process() {
    Printer::toSerialSL("Payment selected");
    Request request;
    request.begin();
    request.makePayment(5000);

    LEVEL = RunLevel::READY;
}

void Control::test() {
    Printer::toSerialNL("Status check");

    APITest apitest;
    apitest.begin();

    Printer::toSerialNL("Payment test");

    Request request;
    request.begin();
    request.makePayment(5000);
}