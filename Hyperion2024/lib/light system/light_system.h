#ifndef LIGHT_SYSTEM_H
#define LIGHT_SYSTEM_H

#include <Arduino.h>

class Light_System {
public:
    Light_System(uint8_t startPin); // Constructor
    void init();
    void read();
private:
    static const int NUM_SENSORS = 16; // Number of Light Sensors
    uint8_t Pin;
    int lightData[NUM_SENSORS];
};

#endif
