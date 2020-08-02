#include <Project.h>
#include <Digits.h>
#include <Display.h>
#include <KeyScan.h>
#include <Signals.h>
#include <Blinker.h>

// Included objects
#include <Requests.h>
#include <Timer.h>


#ifndef PAYMENT_H
#define PAYMENT_H

enum class PayCode {PURCHASE, EXCHANGE, HISTORY};

extern APIData params;
extern Display display;
extern KeyScan scanner;
extern Signals signal;
extern Blinker blinker;

class Payment {
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
        Requests request;
        

        String amount;
        char input;
};

#endif