#include <Common.h>
#include <Network.h>
#include <Memory.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <DNSServer.h>

AsyncWebServer server(80);
DNSServer dns;
HTTPClient http;

void Network::setupNetwork(String ssid, String password) {
    WiFiName = ssid;
    WiFiPass = password;
}

void Network::setupDevice(String devicexd, String apikey, String currency, 
                        String language, uint8_t version) {    
    apiDeviceXd = devicexd;
    apiAuthKey = apikey;
    apiCurrency = currency;
    apiLanguage = language;
    apiVersion = version;
}

void Network::startClient() {
    IPAddress ip;

    WiFi.begin(WiFiName.c_str(), WiFiPass.c_str());
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

void Network::startServer() {
    printer.toSerialNL("Setting Access Point . . .");
    WiFi.softAP(device.c_str(), NULL);

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

void Network::checkStatus() {
    String request = String(SERVER_URL + SERVER_API + apiVersion + API_CHECKER);

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
    http.addHeader("X-Api-Key", apiAuthKey);
    http.addHeader("X-Discrim", apiDeviceXd);
    http.addHeader("Accept-Language", apiLanguage);
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