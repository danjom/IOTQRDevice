#include <Common.h>
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

        String getPassword();
        String getSettings();

    private:
        void addHeaders();
        void addRequest();

        String password;
        String settings;
        String device = "POS Device";
};

#endif