#ifndef LIGHT_SYSTEM_H
#define LIGHT_SYSTEM_H

#include <Light_Sensor.h>

class Light_System {
public:
    Light_System(uint8_t startPin); // Constructor
    void init();
private:
    static const int NUM_SENSORS = 16; // Number of Light Sensors
    Light_Sensor sensors[NUM_SENSORS]; // Array to store Light Sensor objects
};

#endif
