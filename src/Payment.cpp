#include <Payment.h>

void Payment::begin() {
    timer.setTimer(300);
}

void Payment::start(PayCode type) {
    Printer::toSerialNL("New request");
    request.makePayment(5000);

    status = PAYMENT;
    payCode = type;
    
    //select();
}

void Payment::select() {
    Printer::toSerialNL("Payment mode select");

    while (status == PAYMENT) {
        choose();
    }
}

void Payment::choose() {
    input = scanner.getKey();
    //Printer::toSerialSL("Input is: ");
    //Printer::toSerialNL(String(input));

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
                Printer::toSerialNL("Switching previous screen");
                status = READY;
            }
            else {
                digits.trimValue();
                display.changeData(DIGITS, digits.getField());
            }
        }
        else if (input == '#') {
            if (digits.isEmpty()) {
                Printer::toSerialNL("[LED] Digits field is empty");
                blinker.turnLedOff();
                blinker.setColor(RED);
            }
            else if (!digits.isValid()) {  
                Printer::toSerialNL("[LED] Digits field is less than 1");
                digits.clearValue();
                display.changeData(DIGITS, digits.getField());
            }
            else {
                if (digits.isDecimal()) {
                    
                    Printer::toSerialNL("Processing payment for USD " + String(digits.getValue()));
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
                    status = READY;
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
        //Printer::toSerialSL("Field is: ");
        //Printer::toSerialNL(digits.getField());
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