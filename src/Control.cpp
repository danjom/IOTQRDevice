#include <Control.h>

Control::Control() {
    LEVEL = RunLevel::SETUP;
}

void Control::begin() {
    Printer::toSerialNL("\nProgram Started\n");
    display.changePage(Nextion::START);
    scanner.setDebounceTime(50);
    blinker.begin(22, 500, 500);
    blinker.setColor(ORANGE);
    blinker.setLevel(125);
    blinker.display();
    blinker.display();
    
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
        checkRST();
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
    else if (LEVEL == RunLevel::HALT) {
        checkRST();
    }
}

void Control::runSetup() {
    settings.begin();
    network.connect();
    payment.setup();
    
    LEVEL = RunLevel::MENU;
}

void Control::showMenu() {
    ledtest.begin();
    Printer::toSerialNL("Waiting for key");
    display.changePage(Nextion::OPTIONS);

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
    LEVEL = RunLevel::PAYMENT;

    switch (input) {
        case '1':
            paycode = PayCode::PURCHASE;
            break;

        case '2':
            paycode = PayCode::EXCHANGE;
            break;

        case '3':
            paycode = PayCode::HISTORY;
            break;
        
        default:
            Printer::toSerialNL("Invalid option");

            LEVEL = RunLevel::SCAN;
            break;
    }
}

void Control::process() {
    Printer::toSerialNL("Payment selected");
    payment.start(paycode);
    LEVEL = RunLevel::READY;
}

void Control::checkRST() {
    BtnPress state = button.check();

    if (state == BtnPress::PRESS) {
        Printer::toSerialNL("Device restart");
        ESP.restart();

    }
    if (state == BtnPress::HOLD) {
        Printer::toSerialNL("Settings reset");
        settings.resetSettings();
    }
}