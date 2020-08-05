#include <Project.h>
#include <APIData.h>
#include <HTTPClient.h>

#ifndef APITEST_H
#define APITEST_H

extern APIData params;

class APITest {
    public:
        APITest();
        void begin();

    private:
        void checkStatus(HTTPClient &http);
        void addHeaders(HTTPClient &http);
        void getResponse(HTTPClient &http);

        String SERVER_URL;
        String SERVER_API;
        String API_CHECKER;
        String APPLICATION;
        String *apiData;

        bool APIReady;
        int attempts;
        int MAX_TRIES;
        int WAIT_TIME;
};

#endif