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
    apitest.begin();
    
    LEVEL = RunLevel::MENU;

    //Test payment before menu
    //LEVEL = RunLevel::PAYMENT;
}

void Control::showMenu() {
    Printer::toSerialNL("Waiting for key");
    //signal.display(READY);
    display.changePage(Nextion::OPTIONS);

    LEVEL = RunLevel::SCAN;

    //Test payment before key scan
    //LEVEL = RunLevel::PAYMENT;
}

void Control::getInput() {
    scanner.setDebounceTime(50);
    
    input = scanner.getKey();

    if (input) {
        Printer::toSerialSL("Menu option is: ");
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
            //signal.display(WRONG);
            //signal.display(READY);
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

void Control::test() {
    Printer::toSerialNL("Status check");
    apitest.begin();
}