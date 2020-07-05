#ifndef TIMER_H
#define TIMER_H

class Timer {
    public:
        Timer();
        Timer(unsigned int);
        bool check();

    private:
        unsigned long current;
        unsigned long previous;
        unsigned int timing;

};

#endif