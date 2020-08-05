#include <Payment.h>

Payment::Payment() {
    request.begin();
    message = "";
    paycode = "";
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

    if (LEVEL != RunLevel::ERROR) {
        paymentResponse();
        paymentVerify();
    }
    else {
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
}

void Payment::paymentResponse() {
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

}

void Payment::checkPayment() {

}

void Payment::exchange() {

}

void Payment::showRecent() {

}