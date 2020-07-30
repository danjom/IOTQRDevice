#include <Payment.h>

Payment::Payment() {

}

void Payment::begin() {
    timer = Timer(300);
    digits = Digits();
    request = new Requests();
    request->setTimeout(30000);
    request->setupClient();
    request->startClient();
    makePayment("4500");
    checkPayment();
}

void Payment::start(PayCode type) {
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


void Payment::getKey() {
    input = scanner.getKey();

    if (input) {
        printer.toSerialSL("Input is: ");
        printer.toSerialNL(String(input));
    }
}

void Payment::purchase() {
    this->getKey();
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
                    display.changeData(DIGITS, String(digits.getValue()));
                    delay(1000);
                    display.changePage(QRIMAGE);
                    display.changeData(QRCODE, String(digits.getValue()));
                    signal.display(AwAIT);
                    delay(5000);
                    display.changePage(SUCCESS);
                    signal.display(CORRECT);
                    delay(5000);
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
        printer.toSerialSL("Field is: ");
        printer.toSerialNL(digits.getField());
    }
}

void Payment::exchange() {

}

void Payment::showRecent() {

}

void Payment::makePayment(String amount) {
    String process;
    String deviceid = params.getAuthData()[DEVICEID];

    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();

    root["deviceKey"] = deviceid;
    root["amount"] = amount;
    root["currencyType"] = 1;

    root.printTo(process);
    printer.toSerialNL(String("Process" + process));

    request->makePayment(process);
}

void Payment::checkPayment() {
    String result;
    bool check = true;

    while (check) {
        delay(1000);
        result = request->getPayload();

        if (result.length() > 0) {
            check = false;
        }

        if (timer.check()) {
            check = false;
        }
    }
    printer.toSerialNL(result);
}