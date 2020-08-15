#include <Settings.h>

const byte STATE_STORE = 0;
const char SEPARATOR = ',';
const String RUN_PATH = "/runlevel.txt";
const String PWD_PATH = "/devauth.txt";
const String CFG_PATH = "/settings.txt";
const String LANG_PATH = "/strings.json";

Settings::Settings() {
    labels = 9;
}

void Settings::begin() {
    storage.begin();

    if (DEVICE_RESET) {
        storage.write(RUN_PATH, String(RESET));
        Printer::toSerialNL("Restart device manually");
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
        Printer::toSerialNL("Run level: RESET");
        resetSettings();
        break;
    
    case LOGIN:
        Printer::toSerialNL("Run level: LOGIN");
        setPassword();
        break;

    case NETWORK:
        Printer::toSerialNL("Run level: NETWORK");
        setSettings();
        break;

    case VERIFY:
        Printer::toSerialNL("Run level: VERIFY");
        readSettings();
        getLanguage();
        setLanguage();
        break;

    default:
        Printer::toSerialNL("Wrong reading from state");
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

void Settings::readSettings() {
    String reading = storage.read(CFG_PATH);
    uint8_t charIndex = 0;

    if (reading.length() > 0) {
        Printer::toSerialNL("Network settings found");

        for (int index = 0; index < 8; index++) {
            charIndex = reading.indexOf(SEPARATOR);
            variables[index] = reading.substring(0, charIndex);
            reading.remove(0, charIndex + 1);
            Printer::toSerialNL(String("Var at " + String(index) + ": " + variables[index]));
        }
    params.saveSettings(variables);
    }
    else {
        Printer::toSerialNL("Network settings not found");
    }
}

void Settings::readPassword() {
    password = storage.read(PWD_PATH);

    if (password.length() > 0) {
        Printer::toSerialNL("Device settings found");
        Printer::toSerialNL(String("Device password is " + password));
    }
    else {
        Printer::toSerialNL("Device settings not found");
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
    Printer::toSerialNL("Device settings cleared");
}

void Settings::clearSettings() {
    storage.clear(CFG_PATH);
    Printer::toSerialNL("Network settings cleared");
}

void Settings::resetSettings() {
    storage.write(RUN_PATH, String(LOGIN));
    clearPassword();
    clearSettings();
    restartDevice();
}

void Settings::restartDevice() {
    Printer::toSerialNL("Restarting device . . .");
    delay(3000);
    ESP.restart();
}

void Settings::getLanguage() {
    String langCode = variables[6];
    Printer::toSerialSL("LangCode: ");
    Printer::toSerialNL(langCode);

    if (langCode.equals("es-MX")) {
        language = "Spanish";
    }
    else if (langCode.equals("en-US")) {
        language = "English";
    }
}

void Settings::setLanguage() {
    String langData = storage.read(LANG_PATH);
    Printer::toSerialNL(langData);
    Printer::toSerialSL("Language: ");
    Printer::toSerialNL(language);

    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, langData);

    if (error) {
        Serial.print(F("Lang Json failed: "));
        Serial.println(error.c_str());
        return;
    }

    for (int index = 0; index < labels; index++) {
        Printer::toSerialNL(doc[language][index]);
        display.changeField(index, doc[language][index]);
    }
}