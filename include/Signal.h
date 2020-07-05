#ifndef SIGNAL_H
#define SIGNAL_H

class Signal {
    public:
        Signal();
        Signal(uint16_t, uint8_t);
        void init();
        void show();
        void setColor(uint32_t);
        void setLevel(uint8_t);
        uint8_t getLevel();
};

#endif