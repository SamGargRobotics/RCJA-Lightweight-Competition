#ifndef TSSP_SYSTEM_H
#define TSSP_SYSTEM_H

#include "Tssp.h"

class Tssp_system {
public:
    Tssp_system(int startPin); // Constructor
    void init();
private:
    static const int NUM_TSSPS = 16; // Number of TSSPs
    Tssp tssps[NUM_TSSPS]; // Array to store TSSP objects
};

#endif
