#ifndef Display_h
#define Display_h

#include <string>

class Display {
    public:
        void changePage(int);
        void changeData(int, String);
        void writeEndBits();
};

#endif