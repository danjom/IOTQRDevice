#include <Project.h>
#include <APIData.h>
#include <Memory.h>
#include <Network.h>
#include <ArduinoJson.h>

#ifndef SETTINGS_H
#define SETTINGS_H

extern APIData params;
extern bool DEVICE_RESET;

class Settings {
    public:
        Settings();
        void begin();
        void checkState();

        void readPassword();
        void readSettings();
        void setPassword();
        void setSettings();
        
        void clearPassword();
        void clearSettings();
        void resetSettings();
        void restartDevice();
    private:
        void getLanguage();
        void setLanguage();
        void getCurrency();
        void checkReading(String msg);
        void writePassword(String pass);
        void writeSettings(String sets);
        
        enum RunState {RESET, LOGIN, NETWORK, VERIFY, READY};
        RunState states[5] = {RESET, LOGIN, NETWORK, VERIFY, READY};

        RunState state;
        Memory storage;
        Network network; 
        
        String password;
        String settings;
        String language;
        String variables[8];

        int labels;
        uint8_t currency;
};

#endif