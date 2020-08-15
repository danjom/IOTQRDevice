#include <Numbers.h>

Numbers::Numbers() {
    DELETE = '*';
    CONFIRM = '#';
}

float Numbers::getAmount() {
    amount = 0;
    status = SCAN;

    while (status == SCAN) {
        input = scanner.getKey();

        if (input) {
            Printer::toSerialSL("Input is: ");
            Printer::toSerialNL(String((char)input));
            setAmount();
        }
    }

    return amount;
}

void Numbers::setAmount() {
    if (input == DELETE) {
        keyDelete();
    }
    else if (input == CONFIRM) {
        keyAccept();
    }
    else {
        handlerAdd();
    }
}

void Numbers::keyDelete() {
    if (digits.isEmpty()) {
        status = READY;
        Printer::toSerialNL("Status is READY");
    }
    else {
        handlerTrim();
    }
}

void Numbers::keyAccept() {
    if (digits.isEmpty()) {
        handlerLED();
    }
    else if (!digits.isValid()) {  
        handlerKey();
    }
    else {
        if (digits.isDecimal()) {
            handlerPay();
        }
        else {
            handlerDot();
        }
    }
}

void Numbers::handlerAdd() {
    digits.addNumber(input);
}

void Numbers::handlerDot() {
    digits.addDecimal();
    display.changeBlock(UIBlock::DIGITS, digits.getField());
}

void Numbers::handlerTrim() {
    digits.trimValue();
    display.changeBlock(UIBlock::DIGITS, digits.getField());
}

void Numbers::handlerPay() {
    amount = digits.getValue();
    display.changeBlock(UIBlock::DIGITS, String(digits.getValue()));
    digits.clearValue();
    status = READY;
}

void Numbers::handlerKey() {
    // LED -> Alert
    digits.clearValue();
    display.changeBlock(UIBlock::DIGITS, digits.getField());
}

void Numbers::handlerLED() {
    // LED -> Alert
}