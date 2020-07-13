#include <Payment.h>

Payment::Payment() {
    digits = Digits();
}

void Payment::check() {
    input = scanner.getKey();

    if (input) {
        printer.toSerialSL("Input is: ");
        printer.toSerialNL(String(input));
        select();
    }
}

void Payment::charge() {
    if (input == '*') {
        if (digits.isEmpty()) {
            printer.toSerialNL("Switching previous screen");
            state = DONE;
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
                state = DONE;

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

void Payment::redeem() {

}

void Payment::recent() {

}

void Payment::confirm() {

}

void Payment::verify() {

}

void Payment::select() {
    switch (event) {
    case PAYMENT:
        charge();
        break;
    }
}