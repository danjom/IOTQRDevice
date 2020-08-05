#include <Project.h>
#include <APIData.h>
#include <HTTPClient.h>

#ifndef REQUEST_H
#define REQUEST_H

extern APIData params;

class Request {
    public:
        Request();
        void begin();
        String makePayment(String json);
        String checkPayment(String json);
        String showRecentLog(String json);
    private:
        void addHeaders(HTTPClient &http);

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

        int httpCode;
};

#endif