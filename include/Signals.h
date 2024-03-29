#include <Blinker.h>

extern Blinker blinker;

#ifndef SIGNALS_H
#define SIGNALS_H

enum signals {SETUP, LOADING, READY, NETWORK, WRONG, CORRECT, REJECT, AwAIT, ERROR};

class Signals {
    public:
        Signals() = default;
        void display(int);
    private:
        int selection;
        void started();
        void loading();
        void network();
        void correct();
        void refused();
        void waiting();
        void failure();
        void invalid();
};

#endif