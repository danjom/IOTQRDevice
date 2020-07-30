#include <Project.h>
#include <APIData.h>
#include <Digits.h>
#include <Display.h>
#include <KeyScan.h>
#include <Signals.h>
#include <Blinker.h>
#include <Timer.h>
#include <Requests.h>
#include <ArduinoJson.h>

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
        Payment();
        void begin();
        void start(PayCode type);
    private:
        Timer timer;
        Digits digits;
        PayCode payCode;
        Requests *request;

        String amount;
        char input;
        
        void select();
        void choose();
        void getKey();

        void purchase();
        void exchange();
        void showRecent();
        
        void makePayment(String amount);
        void checkPayment();
};

#endif