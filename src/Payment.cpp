#include <Payment.h>

void Payment::begin() {
    // request = Requests();
    // request.setupClient();
    // request.checkStatus();
    timer.setTimer(300);
}

void Payment::start(PayCode type) {
    printer.toSerialNL("New request");
    request = Requests();
    request.setupClient();

    progress = Status::PAYMENT;
    payCode = type;
    select();
}

void Payment::select() {
    printer.toSerialNL("Payment mode select");

    while (progress == Status::PAYMENT) {
        choose();
    }
}

void Payment::choose() {
    input = scanner.getKey();
    //printer.toSerialSL("Input is: ");
    //printer.toSerialNL(String(input));

    if (payCode == PayCode::PURCHASE) {
        purchase();
    }
    else if (payCode == PayCode::EXCHANGE) {
        exchange();
    }
    else if (payCode == PayCode::HISTORY) {
        showRecent();
    }
}

void Payment::purchase() {
    if (input) {
        if (input == '*') {
            if (digits.isEmpty()) {
                printer.toSerialNL("Switching previous screen");
                progress = Status::MENU;
            }
            else {
                digits.trimValue();
                display.changeData(DIGITS, digits.getField());
            }
        }
        else if (input == '#') {
            if (digits.isEmpty()) {
                printer.toSerialNL("[LED] Digits field is empty");
                blinker.turnLedOff();
                blinker.setColor(RED);
            }
            else if (!digits.isValid()) {  
                printer.toSerialNL("[LED] Digits field is less than 1");
                digits.clearValue();
                display.changeData(DIGITS, digits.getField());
            }
            else {
                if (digits.isDecimal()) {
                    
                    printer.toSerialNL("Processing payment for USD " + String(digits.getValue()));
                    request.makePayment(digits.getValue());

                    display.changeData(DIGITS, String(digits.getValue()));
                    //delay(1000);
                    display.changePage(QRIMAGE);
                    display.changeData(QRCODE, String(digits.getValue()));
                    signal.display(AwAIT);
                    //delay(5000);
                    display.changePage(SUCCESS);
                    signal.display(CORRECT);
                    //delay(5000);
                    progress = Status::MENU;
                    digits.clearValue();
                }
                else {
                    digits.addDecimal();
                    display.changeData(DIGITS, digits.getField());
                }
            }
        }
        else {
            digits.addNumber(input);
            display.changeData(DIGITS, digits.getField());
        }
        //printer.toSerialSL("Field is: ");
        //printer.toSerialNL(digits.getField());
    }
}

void Payment::exchange() {

}

void Payment::showRecent() {

}

void Payment::makePayment(String amount) {

}

void Payment::checkPayment() {

}