#include <Project.h>
#include <Timer.h>
#include <ArduinoJson.h>

#ifndef REQUESTS_H
#define REQUESTS_H

extern APIData params;

class Requests {
    public:
        Requests();
        void setupClient();
        void checkStatus();
        void makePayment(float value);
        void checkPayment();
        void showRecentLog();

        String getRequest();

    private:
        void makePayload(float value);
        void saveResponse(String &json);

        String SERVER_URL;
        String SERVER_API;
        String API_CHECKER;
        String API_PAYMENT;
        String API_REQUEST;
        String API_PAYDKEY;
        String API_PAYREQC;
        String APPLICATION;

        String settings;
        String response;
        String payload;

        String *netData;
        String *apiData;

        int timeout;
};

#endif