#include <Project.h>
#include <Settings.h>
#include <Connect.h>
#include <Payment.h>

#ifndef RUNNER_H
#define RUNNER_H

class Runner {
    public:
        Runner();
        void begin();
        void check();
    private:
        Settings settings;
        Connect network;    
        Payment payment;  
};

#endif