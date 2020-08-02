#include <Connect.h>

Connect::Connect() {
    status = false;
}

void Connect::connect() {
    WClient client;
    String *credentials = params.getWiFiData();
    String ssid = credentials[WiFiData::SSID];
    String pass = credentials[WiFiData::PASS];

    printer.toSerialNL(String("Stored SSID:" + ssid));
    printer.toSerialNL(String("Stored PASS:" + pass));
  
    client.startClient(ssid, pass);

    status = client.online();
}

bool Connect::getStatus() {
    return status;
}