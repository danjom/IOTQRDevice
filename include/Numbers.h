#include <Project.h>
#include <Display.h>
#include <Signals.h>
#include <KeyScan.h>
#include <Digits.h>

#ifndef NUMBERS_H
#define NUMBERS_H

class Numbers {
    public:
        Numbers();
        float getAmount();
    private:
        void setAmount();

        void keyDelete();
        void keyAccept();

        void handlerKey();
        void handlerBack();
        void handlerTrim();
        void handlerAdd();
        void handlerDot();
        void handlerPay();
        void handlerLED();

        enum status {SCAN, READY};

        Digits digits;

        int input;
        int status;
        float amount;

        char DELETE;
        char CONFIRM;
        
};

#endif