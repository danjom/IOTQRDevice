#include <Blinker.h>

#ifndef PROJECT_H
#define PROJECT_H

extern Blinker blinker;

class Project {
    public:
        Project() = default;
        void begin();
};

#endif