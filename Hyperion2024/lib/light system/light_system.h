#ifndef LIGHT_SYSTEM_H
#define LIGHT_SYSTEM_H

#include <Arduino.h>
#include <pins.h>
#include <common.h>

class Light_System {
public:
    Light_System() {}; // Constructor
    void init();
    void read();
    void setMuxChannel(int channel);
    int lineAvoidance2();
    int lineAvoidance();
private:
    static const int NUM_SENSORS = NUM_LS; // Number of Light Sensors
    static const int NUM_MUX = NUMBER_MUX;
    uint8_t pin;
    int pin_mux;
    int lightData[NUM_SENSORS];
    int muxList[4] = {LIGHT_PIN_DIGI_1, LIGHT_PIN_DIGI_2, LIGHT_PIN_DIGI_3, LIGHT_PIN_DIGI_4};
    bool positiveData[NUM_SENSORS] = {false};
    int firstSens = 0;
    int lastSens = 0;
    int difference = 0;
    int movementAngle = 0;
    int sensDif = 0;
    int rsensDif = 0;
    int midSens = 0;
    int fdegs = 0;
};

#endif
