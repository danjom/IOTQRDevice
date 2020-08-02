#include <Project.h>
#include <Memory.h>
#include <Network.h>

#ifndef SETTINGS_H
#define SETTINGS_H

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
        Network network; 
        
        String password;
        String settings;
};

#endif