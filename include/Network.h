#include <Common.h>
#include <Timer.h>
#include <APIData.h>

#ifndef NETWORK_H
#define NETWORK_H

extern APIData params;

class Network {
    public:
        Network() = default;
        void startServer(String password);
        void setTimeout(int time);
        void setupServer();
        void setupDevice();
        void setupClient(); 
        void startClient();
        void checkStatus();

        String getPassword();
        String getSettings();

    private:
        void addHeaders();

        Timer timer;
        String password;
        String settings;

        String *netData;
        String *apiData;
    
        String device = "POS Device";

        int timeout;

        const String SERVER_URL = "https://yoy-valid8api.azurewebsites.net";
        const String SERVER_API = "/api/v";
        const String API_CHECKER = "/statuschecker/get";
        const String APPLICATION = "application/json";
};

#endif