#include <Payment.h>

Payment::Payment() {
    TIMEOUT = 300000;
    message = "";
    paycode = "";
    apiTimeout.setTimer(TIMEOUT);
}

void Payment::start(PayCode type) {
    amount = 0;
    jsonData = "";
    codeType = type;
    select();
}

void Payment::select() {
    if (codeType == PayCode::PURCHASE) {
        purchase();
    }
    else if (codeType == PayCode::EXCHANGE) {
        exchange();
    }
    else if (codeType == PayCode::HISTORY) {
        showRecent();
    }
}

void Payment::purchase() {
    amount = numbers.getAmount();
    Printer::toSerialNL(String("Payment amount: " + String(amount)));

    if (amount != 0) {
        makePayment();
    }
}

void Payment::makePayment() {
    paymentPayload();
    paymentRequest();
    paymentVerify();

    if (LEVEL == RunLevel::ERROR) {
        Printer::toSerialNL("Payment request failed or rejected");
        delay(5000);
        LEVEL = RunLevel::MENU;   
    }
}

void Payment::paymentPayload() {
    deviceID = params.getAuthData()[DEVICEID];

    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();

    root["deviceKey"] = deviceID;
    root["amount"] = amount;
    root["currencyType"] = 1;

    root.printTo(jsonData);
}

void Payment::paymentRequest() {
    response = request.makePayment(jsonData);

    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(response);

    String reqcode = root["requestCode"];
    String msgshow = root["messageToDisplay"];

    paycode = reqcode;
    message = msgshow;

    Printer::toSerialSL("Request key: "); 
    Printer::toSerialNL(paycode);

    Printer::toSerialSL("Message: "); 
    Printer::toSerialNL(message);
}

void Payment::paymentVerify() {
    bool paymentCheck = true;
    apiTimeout.reset();

    while (paymentCheck) {
        paymentResponse();

        if (complete == "true") {
            paymentCheck = false;
            Printer::toSerialNL("Payment accepted");
        }
        if (apiTimeout.check()) {
            paymentCheck = false;
            Printer::toSerialNL("Payment timed out");
        }
        delay(1000);
    }
}

void Payment::paymentResponse() {
    response = request.checkPayment(paycode);

    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(response);

    String accepted = root["paymentCompleted"];

    complete = accepted;

    Printer::toSerialSL("Payment completed: "); 
    Printer::toSerialNL(complete);
}

void Payment::exchange() {

}

void Payment::showRecent() {

}