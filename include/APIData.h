#include <Arduino.h>

#ifndef APIDATA_H
#define APIDATA_H

enum WiFiData {SSID, PASS};
enum AuthData {DEVICEID, GROUPXDS, APILOGIN, VERSION, LANGUAGE, CURRENCY};

class APIData {
    public:
        APIData() = default;
        void saveSettings(String data[]);
        String *getWiFiData();
        String *getAuthData();
    private:
        String network[2];
        String settings[6];
};

#endif