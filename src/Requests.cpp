#include <Requests.h>
#include <WiFi.h>
#include <HTTPClient.h>

Requests::Requests() {
    SERVER_URL = "https://yoy-valid8api.azurewebsites.net";
    SERVER_API = "/api/v";
    API_CHECKER = "/statuschecker/get";
    API_PAYMENT = "/paymentRequest/post";
    API_REQUEST = "/paymentRequest/get?";
    API_PAYDKEY = "deviceKey=";
    API_PAYREQC = "&requestCode=";
    APPLICATION = "application/json";

    payload = "";
}

void Requests::setupClient() {
    netData = params.getWiFiData();
    apiData = params.getAuthData();
}

void Requests::checkStatus() {
    HTTPClient http;
    
    String request = String(SERVER_URL + SERVER_API + apiData[VERSION] + API_CHECKER);
    printer.toSerialNL(request);

    if(WiFi.status()== WL_CONNECTED){
        http.begin(request.c_str());

        http.addHeader("Accept", APPLICATION);
        http.addHeader("Content-Type", APPLICATION);
        http.addHeader("X-Api-Key", apiData[APILOGIN]);
        http.addHeader("X-Discrim", apiData[GROUPXDS]);
        http.addHeader("Accept-Language", apiData[LANGUAGE]);

        int httpResponseCode = http.GET();

        if (httpResponseCode == 200) {
            printer.toSerialSL("[ANSWR] ");
            printer.toSerialNL(String(httpResponseCode));

            String status = http.getString();
            printer.toSerialNL(status);
        }
        else {
            printer.toSerialSL("[ERORR] ");
            printer.toSerialNL(String(httpResponseCode));
        }
        http.end();
    }
    else {
        printer.toSerialNL("[ERORR] API is out of reach");
    }
}

void Requests::makePayment(float value) {
    makePayload(value);

    HTTPClient http;

    String endpoint = String(SERVER_URL + SERVER_API + apiData[VERSION] + API_PAYMENT);
    //printer.toSerialNL(endpoint);

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
            printer.toSerialSL("[ANSWR] ");
            printer.toSerialNL(String(httpResponseCode));
            //printer.toSerialNL(response);
            saveResponse(response);
        }
            else {
            response = http.getString();
            printer.toSerialSL("[ERORR] ");
            printer.toSerialNL(String(httpResponseCode));
        }
        http.end();
    }
}

void Requests::saveResponse(String &json) {
    uint8_t size = (json.length() + 1);
    char response[size]; 
    json.toCharArray(response, size);

    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(response);

    printer.toSerialSL("Request key: "); 
    printer.toSerialNL(root["requestCode"]);

    printer.toSerialSL("Message: "); 
    printer.toSerialNL(root["messageToDisplay"]);
}

void Requests::checkPayment() {
    HTTPClient http;
}

void Requests::makePayload(float value) {
    String deviceid = params.getAuthData()[DEVICEID];

    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();

    root["deviceKey"] = deviceid;
    root["amount"] = value;
    root["currencyType"] = 1;

    root.printTo(payload);

    //printer.toSerialNL(String("JSON Content: " + payload));
}
