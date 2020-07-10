#include <Control.h>
#include <Project.h>

const char ONE = '1';
const char TWO = '2';
const char THREE = '3';

void Control::begin() {
    state = MENU;
    printer.toSerialNL("Control started");
}

void Control::check() {
    switch (state) {
        case MENU:
            printer.toSerialNL("Waiting for key");
            state = SCAN;
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

    // if (alert) {
    //     blinker.blinkD(125, 125);
    //     if (blinker.getCounter() > 2) {
    //         alert = false;
    //         blinker.setColor(WHITE);
    //         blinker.display();
    //         blinker.reset();
    //     }
    // }
    // getKey();

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

            break;

        case TWO:

            break;

        case THREE:

            break;
        
        default:
            state = SCAN;
            printer.toSerialNL("Invalid option");
    }
}

// void Control::select() {
//     if (input == '*') {
//         if (digits.isEmpty()) {
//             Serial.println("Switching previous screen");
//         }
//         else {
//             digits.trimValue();
//         }
//     }
//     else if (input == '#') {
//         if (digits.isEmpty()) {
//             Serial.println("[LED] Digits field is empty");
//             alert = true;
//             blinker.turnLedOff();
//             blinker.setColor(RED);
//         }
//         else if (!digits.isValid()) {  
//             Serial.println("[LED] Digits field is less than 1");
//             digits.clearValue();
//         }
//         else {
//             if (digits.isDecimal()) {
//                 Serial.println("Processing payment for USD " + String(digits.getValue()));
//             }
//             else {
//                 digits.addDecimal();
//             }
//         }
//     }
//     else {
//         digits.addNumber(input);
//     }
//     Serial.print("Field is: ");
//     Serial.println(digits.getField());
// }
