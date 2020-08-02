#include <Memory.h>

void Memory::begin() {
    if(!SPIFFS.begin(true)){
      printer.toSerialNL("An Error has occurred while mounting SPIFFS");
      return;
    }
}

void Memory::write(String path, String data) {
    File file = SPIFFS.open(path, FILE_WRITE);
    if(!file){
        printer.toSerialNL("There was an error opening the file for writing");
        return;
    }

    if(file.print(data)) {
        printer.toSerialNL("File was written");
    }
    else {
        printer.toSerialNL("File write failed");
    }

    file.close();
}

String Memory::read(String path) {
    String content;

    File file = SPIFFS.open(path, FILE_READ);
    if (!file) {
        printer.toSerialNL("Failed to open file for reading");
        content = "";
    }
    else {
        while (file.available()) {
            content.concat((char)file.read());
        }
    }
    printer.toSerialNL(String("File Content: " + content));
    
    file.close();

    return content;
}

void Memory::clear(String path) {
    if (SPIFFS.exists(path)) {
        if (SPIFFS.remove(path)) {
            printer.toSerialNL("File removed successfully");
        }
        else {
            printer.toSerialNL("File remove operation failed");
        }
    }
    else {
        printer.toSerialNL("Path does not exist. No files removed.");
    }
}