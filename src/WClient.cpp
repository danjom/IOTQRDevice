#include <WClient.h>

WClient::WClient() {
    WAITSEC = 500; // 0.5 sec
    TIMEOUT = 60; // (TIMEOUT * WAITSEC) = 30 sec
}

void WClient::startClient(String ssid, String pass) {
    int timer = 0;  // elapsed time

    WiFi.begin(ssid.c_str(), pass.c_str());

    Printer::toSerialSL("\nConnecting to network");

    while(WiFi.status() != WL_CONNECTED) {
        delay(WAITSEC);
        timer++;

        Printer::toSerialSL(" . ");

        if (timer == TIMEOUT) {
            Printer::toSerialNL("Attempt to connect timeout");
            break;
        }
    }

    Printer::toSerialNL("");

    if (WiFi.status() == WL_CONNECTED) {
        Printer::toSerialSL("Connected to WiFi network with IP Address: ");
        Printer::toSerialNL(WiFi.localIP().toString());
        status = true;
    }
    else {
        Printer::toSerialNL("Network connection failed");
        status = false;
    }
}

bool WClient::online() {
    return status;
}