#include <Project.h>
#include <APIData.h>
#include <Numbers.h>
#include <Request.h>
#include <ArduinoJson.h>
#include <Timer.h>

#ifndef PAYMENT_H
#define PAYMENT_H

enum class PayCode {PURCHASE, EXCHANGE, HISTORY};

extern APIData params;

class Payment {
    enum status {SCANNER, PAYMENT, READY};

    public:
        Payment();
        void start(PayCode type);
    private:
        void select();

        void purchase();
        void exchange();
        void showRecent();
        
        void makePayment();

        void paymentPayload();
        void paymentRequest();
        void paymentResponse();
        void paymentVerify();

        void getResponse();
        void getHTTPCode();

        Numbers numbers;
        Request request;
        Timer apiTimeout;

        String jsonData;
        String response;
        String deviceID;

        String message;
        String paycode;
        String complete;

        PayCode codeType;

        float amount;
        int server;
        int status;
        char input;
        unsigned long TIMEOUT;
        
};

#endif