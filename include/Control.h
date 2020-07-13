#include <Payment.h>

#ifndef CONTROL_H
#define CONTROL_H

extern Payment payment;

class Control {
    public:
        Control() = default;
        void begin();
        void check();
        void getKey();
        void select();

    private:
        char input;
};

#endif