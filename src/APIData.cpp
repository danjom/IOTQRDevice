#include <APIData.h>

void APIData::saveSettings(String data[]) {
    network[SSID] = data[0];
    network[PASS] = data[1];
    settings[DEVICEID] = data[2];
    settings[GROUPXDS] = data[3];
    settings[APILOGIN] = data[4];
    settings[VERSION] = data[5];
    settings[CURRENCY] = data[6];
    settings[LANGUAGE] = data[7];
}

String *APIData::getWiFiData() {
    return network;
}

String *APIData::getAuthData() {
    return settings;
}