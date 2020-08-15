#include <Payment.h>

Payment::Payment() {
    TIMEOUT = 30000;    // 0.5 min
    //TIMEOUT = 60000;  // 1 min
    //TIMEOUT = 300000; // 5 min
    apiTimeout.setTimer(TIMEOUT);
    deviceID = params.getAuthData()[DEVICEID];
}

void Payment::setCurrency(uint8_t type) {
    currency = type;
}

void Payment::start(PayCode type) {
    codeType = type;

    message = "";
    paycode = "";
    complete = "";

    amount = 0;
    jsonData = "";
    response = "";

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
    //deviceID = params.getAuthData()[DEVICEID];

    //StaticJsonBuffer<200> jsonBuffer;
    //JsonObject& root = jsonBuffer.createObject();

    DynamicJsonDocument doc(512);

    doc["deviceKey"] = deviceID;
    doc["amount"] = amount;
    doc["currencyType"] = 1;

    serializeJson(doc, jsonData);
    //root.printTo(jsonData);
}

void Payment::paymentRequest() {
    response = request.makePayment(jsonData);

    //DynamicJsonBuffer jsonBuffer;
    //JsonObject& root = jsonBuffer.parseObject(response);

    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, response);

    if (error) {
        Serial.print(F("DeserializeJson() failed: Request"));
        Serial.println(error.c_str());
    }
    else {
        String reqcode = doc["requestCode"];
        String msgshow = doc["messageToDisplay"];

        paycode = reqcode;
        message = msgshow;

        Printer::toSerialSL("Request key: "); 
        Printer::toSerialNL(paycode);

        Printer::toSerialSL("Message: "); 
        Printer::toSerialNL(message);
    }
}

void Payment::paymentVerify() {
    bool paymentCheck = true;
    apiTimeout.reset();

    while (paymentCheck) {
        if (LEVEL == RunLevel::ERROR) {
            paymentCheck = false;
        }
        else {
            paymentResponse();
        }

        if (complete == "true") {
            paymentCheck = false;
            Printer::toSerialNL("Payment accepted");
        }

        if (apiTimeout.check()) {
            paymentCheck = false;
            LEVEL = RunLevel::ERROR;
            Printer::toSerialNL("Payment timed out");
        }
        delay(1000);
    }
}

void Payment::paymentResponse() {
    response = request.checkPayment(paycode);

    // DynamicJsonBuffer jsonBuffer;
    // JsonObject& root = jsonBuffer.parseObject(response);

    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, response);

    if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.c_str());
    }

    String accepted = doc["paymentCompleted"];

    complete = accepted;

    Printer::toSerialSL("Payment completed: "); 
    Printer::toSerialNL(complete);
}

void Payment::exchange() {

}

void Payment::showRecent() {
    
}