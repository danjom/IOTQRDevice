#include <Request.h>
#include <WiFi.h>

Request::Request() {

}

void Request::begin() {
    SERVER_URL = "https://yoy-valid8api.azurewebsites.net";
    SERVER_API = "/api/v";
    API_PAYMENT = "/paymentRequest/post";
    API_REQUEST = "/paymentRequest/get?";
    API_PAYDKEY = "deviceKey=";
    API_PAYREQC = "&requestCode=";
    APPLICATION = "application/json";

    payload = "";

    apiData = params.getAuthData();
}

void Request::makePayment(float value) {
    HTTPClient http;
    makePayload(value);

    String endpoint = String(SERVER_URL + SERVER_API + apiData[VERSION] + API_PAYMENT);
    //Printer::toSerialNL(endpoint);

    if(WiFi.status()== WL_CONNECTED){
        http.begin(endpoint.c_str());

        http.addHeader("Accept", APPLICATION);
        http.addHeader("Content-Type", APPLICATION);
        http.addHeader("X-Api-Key", apiData[APILOGIN]);
        http.addHeader("X-Discrim", apiData[GROUPXDS]);
        http.addHeader("Accept-Language", apiData[LANGUAGE]);

        int httpResponseCode = http.POST(payload);

        if (httpResponseCode == 200) {
            response = http.getString();
            Printer::toSerialSL("[ANSWR] ");
            Printer::toSerialNL(String(httpResponseCode));
            //Printer::toSerialNL(response);
            saveResponse(response);
        }
            else {
            response = http.getString();
            Printer::toSerialSL("[ERORR] ");
            Printer::toSerialNL(String(httpResponseCode));
        }
        http.end();
    }
}

void Request::saveResponse(String &json) {
    uint8_t size = (json.length() + 1);
    char response[size]; 
    json.toCharArray(response, size);

    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(response);

    Printer::toSerialSL("Request key: "); 
    Printer::toSerialNL(root["requestCode"]);

    Printer::toSerialSL("Message: "); 
    Printer::toSerialNL(root["messageToDisplay"]);
}

void Request::checkPayment() {
    HTTPClient http;
}

void Request::makePayload(float value) {
    String deviceid = params.getAuthData()[DEVICEID];

    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();

    root["deviceKey"] = deviceid;
    root["amount"] = value;
    root["currencyType"] = 1;

    root.printTo(payload);
}
