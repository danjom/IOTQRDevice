#ifndef TIMER_H
#define TIMER_H

class Timer {
    public:
        Timer() = default;
        Timer(unsigned int);
        bool check();
        void reset();
        void setTimer(unsigned int);

    private:
        unsigned long current;
        unsigned long previous;
        unsigned int interval;
};

#endif