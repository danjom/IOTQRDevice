#include <Network.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <DNSServer.h>

AsyncWebServer server(80);
DNSServer dns;
HTTPClient http;

void Network::setupClient() {
    netData = params.getWiFiData();
    apiData = params.getAuthData();
}

void Network::startClient() {
    IPAddress ip;

    WiFi.begin(netData[0].c_str(), netData[1].c_str());
    printer.toSerialSL("\nConnecting ");
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        printer.toSerialSL(". ");
        if (timer.check()) {
            break;
        }
    }
    printer.toSerialNL("");
    if (WiFi.status() == WL_CONNECTED) {
        ip = WiFi.localIP();
        printer.toSerialSL("Connected to WiFi network with IP Address: ");
        printer.toSerialNL(ip.toString());
    }
    else {
        printer.toSerialNL("[TIMEOUT] Network not connected");
    }
}

void Network::startServer(String password) {
    printer.toSerialNL("Setting Access Point . . .");
    WiFi.softAP(device.c_str(), password.c_str());

    IPAddress IP = WiFi.softAPIP();
    printer.toSerialSL("AP IP address: ");
    printer.toSerialNL(IP.toString());

    dns.start (53, "*", WiFi.softAPIP() );
}

void Network::setupServer() {
    String input = "";
    
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/index.html", "text/html");
    });

    server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/style.css", "text/css");
    });

    server.on("/fonts.css", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/fonts.css", "text/css");
    });

    server.on("/get", HTTP_GET, [&] (AsyncWebServerRequest *request) {
        if(request->hasParam("password")) {
            password = request->getParam("password")->value();
            printer.toSerialNL(String("Received value: " + password));

            if (password.length() > 0) {
                request->send(200, "text/html", "Device password set");
                server.end();
                printer.toSerialNL("Server closed");
                WiFi.disconnect();
                printer.toSerialNL("Hotspot closed");
            }
        }
    });
    server.begin();
    printer.toSerialNL("Server is running");
}

void Network::setupDevice() {
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/setup.html", "text/html");
    });

    server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/style.css", "text/css");
    });

    server.on("/fonts.css", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/fonts.css", "text/css");
    });

    server.on("/get", HTTP_GET, [&] (AsyncWebServerRequest *request) {
        int inputCount = request->params();
        printer.toSerialNL(String(inputCount));

        for(int i = 0; i < inputCount; i++) {
        
            AsyncWebParameter* p = request->getParam(i);
        
            printer.toSerialNL("Param name: " + p->name());
            printer.toSerialNL("Param value: " + p->value());
        
            printer.toSerialSL("------");

            settings.concat(p->value());
            settings.concat(',');
        }
        settings.remove(settings.lastIndexOf(','), 1);
        printer.toSerialNL(String("Settings: " + settings));
        server.end();
        printer.toSerialNL("Server closed");
        WiFi.disconnect();
        printer.toSerialNL("Hotspot closed");
    });
    
    server.begin();
    printer.toSerialNL("Server is running");
}

void Network::checkStatus() {
    String request = String(SERVER_URL + SERVER_API + apiData[VERSION] + API_CHECKER);
    printer.toSerialNL(request);

    if(WiFi.status()== WL_CONNECTED){
        http.begin(request.c_str());
        addHeaders();

        int httpResponseCode = http.GET();

        if (httpResponseCode == 200) {
            printer.toSerialNL(String(httpResponseCode));
            String payload = http.getString();
            printer.toSerialNL(payload);
        }
        else {
            printer.toSerialSL("Error code: ");
            printer.toSerialNL(String(httpResponseCode));
        }
        http.end();
    }
    else {
        printer.toSerialNL("[STATUS] API is not reachable");
    }
}


void Network::addHeaders() {
    http.addHeader("Accept", APPLICATION);
    http.addHeader("Content-Type", APPLICATION);
    http.addHeader("X-Api-Key", apiData[APILOGIN]);
    http.addHeader("X-Discrim", apiData[GROUPXDS]);
    http.addHeader("Accept-Language", apiData[LANGUAGE]);
}

void Network::setTimeout(int time) {
    timer.setTimer(time);
}

String Network::getPassword() {
    return password;
}

String Network::getSettings() {
    return settings;
}