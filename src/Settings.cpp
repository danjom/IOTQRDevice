#include <Settings.h>

Settings::Settings() {
    storage = Memory();
}

void Settings::begin() {
    storage.begin();

    if (DEVICE_RESET) {
        storage.write(RUN_PATH, String(RESET));
        restartDevice();
    }
    else {
        checkState();
    }
}

void Settings::checkState() {
    String reading = storage.read(RUN_PATH);
    state = states[reading.toInt()];

    switch (state) {
    case RESET:
        printer.toSerialNL("Run level: RESET");
        resetSettings();
        break;
    
    case LOGIN:
        printer.toSerialNL("Run level: LOGIN");
        setPassword();
        break;

    case NETWORK:
        setSettings();
        printer.toSerialNL("Run level: NETWORK");
        break;
    default:
        printer.toSerialNL("Wrong reading from state");
        break;
    }
}

void Settings::setPassword() {
    network.startServer(password);
    network.setupServer();

    while (state == LOGIN) {
        password = network.getPassword();

        if (password.length() > 0) {
            writePassword(password);
            storage.write(RUN_PATH, String(NETWORK));
            restartDevice();
        }
        delay(5000);
    }
}

void Settings::setSettings() {
    readPassword();
    network.startServer(password);
    network.setupServer();
}

void Settings::readPassword() {
    password = storage.read(PWD_PATH);

    if (password.length() > 0) {
        printer.toSerialNL("Device settings found");
        printer.toSerialNL(String("Device password is " + password));
    }
    else {
        printer.toSerialNL("Device settings not found");
    }
}

void Settings::readSettings() {
    String variables[5];
    String reading = storage.read(CFG_PATH);
    uint8_t index = reading.indexOf(SEPARATOR);

    if (reading.length() > 0) {
        printer.toSerialNL("Network settings found");
        reading = reading.substring(0, index);
    }
    else {
        printer.toSerialNL("Network settings not found");
    }
}

void Settings::writePassword(String pass) {
    storage.write(PWD_PATH, pass);
}

void Settings::writeSettings() {

}

void Settings::clearPassword() {
    storage.clear(PWD_PATH);
    printer.toSerialNL("Device settings cleared");
}

void Settings::clearSettings() {
    storage.clear(CFG_PATH);
    printer.toSerialNL("Network settings cleared");
}

void Settings::resetSettings() {
    clearPassword();
    clearSettings();
    storage.write(RUN_PATH, String(LOGIN));
    restartDevice();
}

void Settings::restartDevice() {
    printer.toSerialNL("Restarting device . . .");
    delay(3000);
    ESP.restart();
}