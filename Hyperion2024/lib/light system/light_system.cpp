#include "light_system.h"

Light_System::Light_system(uint8_t startPin) {
    for (int i = 0; i < NUM_SENSORS; i++) {
        sensors[i] = Light_Sensor('A' + startPin + i); // Create Light Sensor objects with pins ranging from startPin to startPin + 15
    }
}

void Light_System::init() {
    for (int i = 0; i < NUM_SENSORS; i++) {
        sensors[i].init(); // Initialize each Light Sensor object
    }
}
