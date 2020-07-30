#include <Requests.h>
#include <WiFi.h>

Requests::Requests() {
    timer = Timer();
    http = new HTTPClient();

    payload = "";
}

void Requests::setupClient() {
    netData = params.getWiFiData();
    apiData = params.getAuthData();
}

void Requests::startClient() {
    IPAddress ip;

    WiFi.begin(netData[0].c_str(), netData[1].c_str());
    printer.toSerialSL("\nConnecting ");
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        printer.toSerialSL(". ");
        if (timer.check()) {
            break;
        }
    }
    printer.toSerialNL("");
    if (WiFi.status() == WL_CONNECTED) {
        ip = WiFi.localIP();
        printer.toSerialSL("Connected to WiFi network with IP Address: ");
        printer.toSerialNL(ip.toString());
    }
    else {
        printer.toSerialNL("[TIMEOUT] Network not connected");
    }
}

void Requests::checkStatus() {
    String request = String(SERVER_URL + SERVER_API + apiData[VERSION] + API_CHECKER);
    printer.toSerialNL(request);

    if(WiFi.status()== WL_CONNECTED){
        http->begin(request.c_str());

        addHeaders();

        int httpResponseCode = http->GET();

        if (httpResponseCode == 200) {
            printer.toSerialNL(String(httpResponseCode));
            String payload = http->getString();
            printer.toSerialNL(payload);
        }
        else {
            printer.toSerialSL("Error code: ");
            printer.toSerialNL(String(httpResponseCode));
        }
        http->end();
    }
    else {
        printer.toSerialNL("[STATUS] API is not reachable");
    }
}

void Requests::makePayment(String jsonData) {
    String request = String(SERVER_URL + SERVER_API + apiData[VERSION] + API_PAYMENT);
    printer.toSerialNL(request);

    if(WiFi.status()== WL_CONNECTED){
        http->begin(request.c_str());

        addHeaders();

        int httpResponseCode = http->POST(jsonData);

        if (httpResponseCode == 200) {
            printer.toSerialNL(String(httpResponseCode));
            payload = http->getString();
        }
        else {
            printer.toSerialSL("Error code: ");
            printer.toSerialNL(String(httpResponseCode));
        }
        http->end();
    }
}

void Requests::checkPayment() {

}

void Requests::addHeaders() {
    http->addHeader("Accept", APPLICATION);
    http->addHeader("Content-Type", APPLICATION);
    http->addHeader("X-Api-Key", apiData[APILOGIN]);
    http->addHeader("X-Discrim", apiData[GROUPXDS]);
    http->addHeader("Accept-Language", apiData[LANGUAGE]);
}

void Requests::addRequest() {

}

void Requests::setTimeout(int time) {
    timer.setTimer(time);
}

String Requests::getPayload() {
    return payload;
}