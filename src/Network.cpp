#include <Network.h>
#include <Project.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <DNSServer.h>
#include <SPIFFS.h>

AsyncWebServer server(80);
DNSServer dns;

void Network::startServer(String password) {
    Printer::toSerialNL("Setting Access Point . . .");
    WiFi.softAP(device.c_str(), password.c_str());

    IPAddress IP = WiFi.softAPIP();
    Printer::toSerialSL("AP IP address: ");
    Printer::toSerialNL(IP.toString());

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
            Printer::toSerialNL(String("Received value: " + password));

            if (password.length() > 0) {
                request->send(200, "text/html", "Device password set");
                server.end();
                Printer::toSerialNL("Server closed");
                WiFi.disconnect();
                Printer::toSerialNL("Hotspot closed");
            }
        }
    });
    server.begin();
    Printer::toSerialNL("Server is running");
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
        Printer::toSerialNL(String(inputCount));

        for(int i = 0; i < inputCount; i++) {
        
            AsyncWebParameter* p = request->getParam(i);
        
            Printer::toSerialNL("Param name: " + p->name());
            Printer::toSerialNL("Param value: " + p->value());
        
            Printer::toSerialSL("------");

            settings.concat(p->value());
            settings.concat(',');
        }
        settings.remove(settings.lastIndexOf(','), 1);
        Printer::toSerialNL(String("Settings: " + settings));
        server.end();
        Printer::toSerialNL("Server closed");
        WiFi.disconnect();
        Printer::toSerialNL("Hotspot closed");
    });
    
    server.begin();
    Printer::toSerialNL("Server is running");
}

String Network::getPassword() {
    return password;
}

String Network::getSettings() {
    return settings;
}