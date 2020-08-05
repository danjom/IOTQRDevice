#include <Request.h>
#include <WiFi.h>

Request::Request() {
    response = "";
    httpCode = 0;
}

void Request::begin() {
    SERVER_URL = "https://yoy-valid8api.azurewebsites.net";
    SERVER_API = "/api/v";
    API_PAYMENT = "/paymentRequest/post";
    API_REQUEST = "/paymentRequest/get?";
    API_PAYDKEY = "deviceKey=";
    API_PAYREQC = "&requestCode=";
    APPLICATION = "application/json";

    apiData = params.getAuthData();
}

String Request::makePayment(String json) {
    HTTPClient http;

    String endpoint = String(SERVER_URL + SERVER_API + apiData[VERSION] + API_PAYMENT);
    //Printer::toSerialNL(endpoint);
    Printer::toSerialNL(json);

    if(WiFi.status()== WL_CONNECTED){
        http.begin(endpoint.c_str());
        
        addHeaders(http);

        httpCode = http.POST(json);

        if (httpCode == 200) {
            response = http.getString();
            Printer::toSerialSL("[ANSWR] ");
            Printer::toSerialNL(String(httpCode));
        }
        else {
            response = http.getString();
            Printer::toSerialSL("[ERORR] ");
            Printer::toSerialNL(String(httpCode));
            Printer::toSerialNL(response);
            LEVEL = RunLevel::ERROR;
        }
        http.end();
    }
    return response;
}

String Request::checkPayment(String json) {
    return response;
}

void Request::addHeaders(HTTPClient &http) {
    http.addHeader("Accept", APPLICATION);
    http.addHeader("Content-Type", APPLICATION);
    http.addHeader("X-Api-Key", apiData[APILOGIN]);
    http.addHeader("X-Discrim", apiData[GROUPXDS]);
    http.addHeader("Accept-Language", apiData[LANGUAGE]);
}