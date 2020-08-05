#include <Project.h>
#include <APIData.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#ifndef REQUEST_H
#define REQUEST_H

extern APIData params;

class Request {
    public:
        Request();
        void begin();
        void makePayment(float value);
        void checkPayment();
        void showRecentLog();

        String getRequest();

    private:
        void makePayload(float value);
        void saveResponse(String &json);

        String SERVER_URL;
        String SERVER_API;
        String API_PAYMENT;
        String API_REQUEST;
        String API_PAYDKEY;
        String API_PAYREQC;
        String APPLICATION;

        String response;
        String payload;

        String *apiData;
};

#endif