#include <Arduino.h>
#include <Timer.h>
#include <SPIFFS.h>

#ifndef NETWORK_H
#define NETWORK_H

class Network {
    public:
        Network() = default;
        void setupNetwork(String ssid, String password);
        void setupDevice(String deviceId, String apikey, String currency, 
                        String language, uint8_t version);
        
        void startClient();
        void startServer();
        void setupServer();
        void checkStatus();
        void setTimeout(int time);

        String getPassword();
        String getSettings();
    
    private:
        void addHeaders();

        int timeout;

        Timer timer;

        String password;
        String settings;
        String WiFiName;
        String WiFiPass;

        String apiVersion;
        String apiAuthKey;
        String apiDeviceId;
        String apiDeviceXd;
        String apiCurrency;
        String apiLanguage;
        
        String device = "POS Device";
        const String SERVER_URL = "https://yoy-valid8api.azurewebsites.net";
        const String SERVER_API = "/api/v";
        const String API_CHECKER = "/statuschecker/get";
        const String APPLICATION = "application/json";
};

#endif