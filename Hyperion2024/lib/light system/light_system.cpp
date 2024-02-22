#include "light_system.h"

Light_System::Light_System(uint8_t startPin) {
    Pin = startPin;
}

void Light_System::init() {
    for (int i = 0; i < NUM_SENSORS; i++) {
        pinMode(Pin + i, INPUT);
    }
}

void Light_System::read() {
    for (int i = 0; i < NUM_SENSORS; i++) {
        lightData[i] = analogRead(Pin + i);
    }
}
