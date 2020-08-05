#include <Project.h>
#include <WiFi.h>

#ifndef WCLIENT_H
#define WCLIENT_H

class WClient {
    public:
        WClient();
        bool online();
        void startClient(String ssid, String pass);
        void setTimeout(unsigned long time);
    private:
        bool status;
        int WAITSEC;
        int TIMEOUT;
};

#endif