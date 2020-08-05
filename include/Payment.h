#include <Project.h>
#include <APIData.h>
#include <Digits.h>
#include <Display.h>
#include <KeyScan.h>
#include <Signals.h>
#include <Blinker.h>
#include <Timer.h>

#ifndef PAYMENT_H
#define PAYMENT_H

extern APIData params;
extern Display display;
extern KeyScan scanner;
extern Signals signal;
extern Blinker blinker;

enum class PayCode {PURCHASE, EXCHANGE, HISTORY};

class Payment {
    enum class status {PAYMENT, READY};

    public:
        Payment() = default;
        void begin();
        void start(PayCode type);
    private:
        void select();
        void choose();

        void purchase();
        void exchange();
        void showRecent();
        
        void makePayment(String amount);
        void sendPayment(String amount);
        void checkPayment();

        Timer timer;
        Digits digits;
        PayCode payCode;
        String amount;
        char input;
        int status;
};

#endif