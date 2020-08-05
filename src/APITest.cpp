#include <APITest.h>
#include <WiFi.h>

APITest::APITest() {

}

void APITest::begin() {
    HTTPClient http;
    MAX_TRIES = 3;
    WAIT_TIME = 3000;

    SERVER_URL = "https://yoy-valid8api.azurewebsites.net";
    SERVER_API = "/api/v";
    API_CHECKER = "/statuschecker/get";
    APPLICATION = "application/json";

    apiData = params.getAuthData();

    APIReady = false;
    attempts = 0;

    checkStatus(http);
}

void APITest::checkStatus(HTTPClient &http) {
    while (attempts < MAX_TRIES && !APIReady) {
        getResponse(http);
        attempts++;
        delay(WAIT_TIME);
    }
}

void APITest::getResponse(HTTPClient &http) {
    String request = String(SERVER_URL + SERVER_API + apiData[VERSION] + API_CHECKER);
    Printer::toSerialNL(request);

    if(WiFi.status()== WL_CONNECTED){
        http.begin(request.c_str());

        addHeaders(http);

        int httpResponseCode = http.GET();

        if (httpResponseCode == 200) {
            Printer::toSerialSL("[ANSWR] ");
            Printer::toSerialNL(String(httpResponseCode));

            String status = http.getString();
            Printer::toSerialNL(status);

            APIReady = true;
        }
        else {
            Printer::toSerialSL("[ERORR] ");
            Printer::toSerialNL(String(httpResponseCode));

        }
        http.end();
    }
    else {
        Printer::toSerialNL("[ERORR] API is out of reach");
    }
}

void APITest::addHeaders(HTTPClient &http) {
    http.addHeader("Accept", APPLICATION);
    http.addHeader("Content-Type", APPLICATION);
    http.addHeader("X-Api-Key", apiData[APILOGIN]);
    http.addHeader("X-Discrim", apiData[GROUPXDS]);
    http.addHeader("Accept-Language", apiData[LANGUAGE]);
}