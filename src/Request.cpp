#include <Request.h>
#include <WebData.h>
#include <WiFi.h>

Request::Request() {
    response = "";
}

String Request::makePayment(String json) {
    apiData = params.getAuthData();

    HTTPClient http;

    String endpoint = String(SERVER_URL + SERVER_API + apiData[VERSION] + API_PAYMENT);
    //Printer::toSerialNL(endpoint);
    Printer::toSerialNL(json);

    if(WiFi.status()== WL_CONNECTED){
        http.begin(endpoint.c_str());
        
        addHeaders(http);

        int httpResponse = http.POST(json);

        if (httpResponse == 200) {
            response = http.getString();
            Printer::toSerialSL("[ANSWR] ");
            Printer::toSerialNL(String(httpResponse));
        }
        else {
            response = http.getString();
            Printer::toSerialSL("[ERORR] ");
            Printer::toSerialNL(String(httpResponse));
            Printer::toSerialNL(response);
            LEVEL = RunLevel::ERROR;
        }
        http.end();
    }
    return response;
}

String Request::checkPayment(String code) {
    apiData = params.getAuthData();
    deviceID = apiData[DEVICEID];

    HTTPClient http;

    String endpoint = String(SERVER_URL + SERVER_API + apiData[VERSION]
                    + API_REQUEST + API_PAYDKEY + apiData[DEVICEID] + API_PAYREQC + code);

    if(WiFi.status()== WL_CONNECTED){
        http.begin(endpoint.c_str());
        
        addHeaders(http);

        int httpResponse = http.GET();

        if (httpResponse == 200) {
            response = http.getString();
            Printer::toSerialSL("[ANSWR] ");
            Printer::toSerialNL(String(httpResponse));
            Printer::toSerialNL(response);
        }
        else {
            response = http.getString();
            Printer::toSerialSL("[ERORR] ");
            Printer::toSerialNL(String(httpResponse));
            Printer::toSerialNL(response);
            LEVEL = RunLevel::ERROR;
        }
        http.end();
    }

    return response;
}

void Request::addHeaders(HTTPClient &http) {
    http.addHeader("Accept", APPLICATION);
    http.addHeader("Content-Type", APPLICATION);
    http.addHeader("X-Api-Key", apiData[APILOGIN]);
    http.addHeader("X-Discrim", apiData[GROUPXDS]);
    http.addHeader("Accept-Language", apiData[LANGUAGE]);
}