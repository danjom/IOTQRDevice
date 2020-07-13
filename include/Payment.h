#include <Project.h>
#include <Options.h>
#include <Digits.h>

#ifndef PAYMENT_H
#define PAYMENT_H

extern Display display;

class Payment {
    public:
        Payment();
        void show();
        void check();
    private:
        char input;
        Digits digits;
        void charge();
        void redeem();
        void recent();
        void getKey();
        void select();
        void verify();
        void confirm();
};

#endif