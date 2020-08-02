#include <WClient.h>

WClient::WClient() {
    WAITSEC = 500; // 0.5 sec
    TIMEOUT = 60; // (TIMEOUT * WAITSEC) = 30 sec
}

void WClient::startClient(String ssid, String pass) {
    int timer = 0;  // elapsed time

    WiFi.begin(ssid.c_str(), pass.c_str());

    printer.toSerialSL("\nConnecting to netork");

    while(WiFi.status() != WL_CONNECTED) {
        delay(WAITSEC);
        timer++;

        printer.toSerialSL(" . ");

        if (timer == TIMEOUT) {
            printer.toSerialNL("Attempt to connect timeout");
            break;
        }
    }

    printer.toSerialNL("");

    if (WiFi.status() == WL_CONNECTED) {
        printer.toSerialSL("Connected to WiFi network with IP Address: ");
        printer.toSerialNL(WiFi.localIP().toString());
        status = true;
    }
    else {
        printer.toSerialNL("Network connection failed");
        status = false;
    }
}

bool WClient::online() {
    return status;
}