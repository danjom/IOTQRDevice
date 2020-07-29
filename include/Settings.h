#include <Common.h>
#include <Memory.h>
#include <Network.h>
#include <APIData.h>

#ifndef SETTINGS_H
#define SETTINGS_H

extern APIData params;
extern Network network;
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

        void writePassword(String pass);
        void writeSettings(String sets);

    private:
        void checkReading(String msg);
        
        enum RunLevel {RESET, LOGIN, NETWORK, VERIFY, READY};
        RunLevel states[5] = {RESET, LOGIN, NETWORK, VERIFY, READY};

        RunLevel state;
        
        Memory storage;
        String password;
        String settings;

        const byte EEPROM_SIZE = 1;
        const byte STATE_STORE = 0;
        const char SEPARATOR = ',';
        const String RUN_PATH = "/runlevel.txt";
        const String PWD_PATH = "/devauth.txt";
        const String CFG_PATH = "/settings.txt"; 
};

#endif