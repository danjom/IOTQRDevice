#include <Memory.h>

void Memory::begin() {
    if(!SPIFFS.begin(true)){
      Printer::toSerialNL("An Error has occurred while mounting SPIFFS");
      return;
    }
}

void Memory::write(String path, String data) {
    File file = SPIFFS.open(path, FILE_WRITE);
    if(!file){
        Printer::toSerialNL("There was an error opening the file for writing");
        return;
    }

    if(file.print(data)) {
        Printer::toSerialNL("File was written");
    }
    else {
        Printer::toSerialNL("File write failed");
    }

    file.close();
}

String Memory::read(String path) {
    String content;

    File file = SPIFFS.open(path, FILE_READ);
    if (!file) {
        Printer::toSerialNL("Failed to open file for reading");
        content = "";
    }
    else {
        while (file.available()) {
            content.concat((char)file.read());
        }
    }
    Printer::toSerialNL(String("File Content: " + content));
    
    file.close();

    return content;
}

void Memory::clear(String path) {
    if (SPIFFS.exists(path)) {
        if (SPIFFS.remove(path)) {
            Printer::toSerialNL("File removed successfully");
        }
        else {
            Printer::toSerialNL("File remove operation failed");
        }
    }
    else {
        Printer::toSerialNL("Path does not exist. No files removed.");
    }
}