#include <Project.h>
#include <APIData.h>
#include <WClient.h>

#ifndef CONNECT_H
#define CONNECT_H

extern APIData params;

class Connect {
    public:
        Connect();
        void connect();
        bool getStatus();

    private:
        bool status;
};

#endif