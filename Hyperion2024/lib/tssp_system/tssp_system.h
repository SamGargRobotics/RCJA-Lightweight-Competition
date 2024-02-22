#ifndef TSSP_SYSTEM_H
#define TSSP_SYSTEM_H

#include <Arduino.h>

class Tssp_system {
public:
    Tssp_system(int startPin); // Constructor
    void init();
    void read();
private:
    static const int NUM_TSSPS = 16; // Number of TSSPs
    uint8_t Pin;
    int readTssp[NUM_TSSPS];
};

#endif
