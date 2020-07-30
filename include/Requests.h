#include <Common.h>
#include <Timer.h>
#include <APIData.h>
#include <HTTPClient.h>

#ifndef REQUESTS_H
#define REQUESTS_H

extern APIData params;

class Requests {
    public:
        Requests();
        void setupClient();
        void startClient();
        void checkStatus();
        void makePayment(String jsonData);
        void checkPayment();
        void showRecentLog();
        void setTimeout(int time);

        String getSettings();
        String getPayload();
    private:
        void addHeaders();
        void addRequest();

        Timer timer;
        HTTPClient *http;
        String settings;
        String payload;

        String *netData;
        String *apiData;

        int timeout;

        const String SERVER_URL = "https://yoy-valid8api.azurewebsites.net";
        const String SERVER_API = "/api/v";
        const String API_CHECKER = "/statuschecker/get";
        const String API_PAYMENT = "/paymentRequest/post";
        const String API_REQUEST = "/paymentRequest/get?";
        const String API_PAYDKEY = "deviceKey=";
        const String API_PAYREQC = "&requestCode=";
        const String APPLICATION = "application/json";
};

#endif