#include <Arduino.h>

#ifndef Timer_h
#define Timer_h

class Timer {
    public:
        Timer(unsigned int);
        boolean check();

    private:
        unsigned long current;
        unsigned long previous;
        unsigned int timing;

};

#endif