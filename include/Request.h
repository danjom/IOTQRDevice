#include <Project.h>
#include <APIData.h>
#include <HTTPClient.h>

#ifndef REQUEST_H
#define REQUEST_H

extern APIData params;

class Request {
    public:
        Request();
        String makePayment(String json);
        String checkPayment(String json);
        String showRecentLog(String key);
    private:
        void addHeaders(HTTPClient &http);

        String response;
        String payload;
        String deviceID;

        String *apiData;
};

#endif