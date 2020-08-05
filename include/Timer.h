#include <Project.h>

#ifndef TIMER_H
#define TIMER_H

class Timer {
    public:
        Timer();
        Timer(unsigned long);
        bool check();
        void reset();
        void setTimer(unsigned long);

    private:
        unsigned long current;
        unsigned long previous;
        unsigned long interval;
};

#endif