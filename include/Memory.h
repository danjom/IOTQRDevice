#include <Project.h>
#include <SPIFFS.h>

#ifndef MEMORY_H
#define MEMORY_H

class Memory {
    public:
        Memory() = default;
        void begin();
        void write(String path, String data);
        void clear(String path);
        String read(String path);
};

#endif