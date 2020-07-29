#include <Settings.h>

Settings::Settings() {
    storage = Memory();
}

void Settings::begin() {
    storage.begin();

    if (DEVICE_RESET) {
        storage.write(RUN_PATH, String(RESET));
        printer.toSerialNL("Restart device manually");
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
        printer.toSerialNL("Run level: NETWORK");
        setSettings();
        break;

    case VERIFY:
        printer.toSerialNL("Run level: VERIFY");
        readSettings();
        break;

    default:
        printer.toSerialNL("Wrong reading from state");
        break;
    }
}

void Settings::setPassword() {
    network.startServer("");
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
    network.setupDevice();

    while (state == NETWORK) {
        settings = network.getSettings();

        if (settings.length() > 0) {
            writeSettings(settings);
            storage.write(RUN_PATH, String(VERIFY));
            restartDevice();
        }
        delay(5000);
    }
    readSettings();
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
    String variables[8];
    String reading = storage.read(CFG_PATH);
    uint8_t charIndex = 0;

    if (reading.length() > 0) {
        printer.toSerialNL("Network settings found");

        for (int index = 0; index < 8; index++) {
            charIndex = reading.indexOf(SEPARATOR);
            // printer.toSerialNL(String("Reading: " + reading));
            // printer.toSerialNL(String("Char ix: " + String(charIndex)));
            variables[index] = reading.substring(0, charIndex);
            reading.remove(0, charIndex + 1);
            printer.toSerialNL(String("Var at " + String(index) + ": " + variables[index]));
        }
    params.saveSettings(variables);
    network.setTimeout(10000);
    network.setupClient();
    network.startClient();
    network.checkStatus();
    }
    else {
        printer.toSerialNL("Network settings not found");
    }
}

void Settings::writePassword(String pass) {
    storage.write(PWD_PATH, pass);
}

void Settings::writeSettings(String sets) {
    storage.write(CFG_PATH, sets);
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