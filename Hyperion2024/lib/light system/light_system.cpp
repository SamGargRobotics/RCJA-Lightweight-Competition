#include "light_system.h"
#include <common.h>

void Light_System::init() {
    for (int i = 0; i < NUM_MUX; i++) {
        pinMode(muxList[i], OUTPUT);
    }
    pinMode(LIGHT_PIN, INPUT);
}

void Light_System::read() {
    for (int i = 0; i < NUM_SENSORS; i++) {
        mux(i);
        lightData[i] = analogRead(Pin);
    }
}

void Light_System::mux(int muxPin) {
    for (int i = 0; i < NUM_MUX; i++) {
        digitalWrite(muxList[i], muxPin%2);
        muxPin = int(muxPin / 2);
    }
}

int Light_System::lineAvoidance() {
    for (int i = 0; i < NUM_SENSORS; i++) {
        if (lightData[i] >= line_avoidance_thresh) {
            positiveData[i] = 1;
        }
    } for (int i = 0; i < NUM_SENSORS; i++) {
        if (lightData[i] == 1) {
            firstSens = i+1
        }
    } for (int i = 0; i < NUM_SENSORS; i++) {
        if (lightData[firstSens+i] != 1) {
            lastSens = firstSens+i;
        }
    }
    if (lastSens < firstSens) {
        difference = lastSens - firstSens;
    } else {
        difference = firstSens - lastSens;
    }
    movementAngle = (difference*22.5)-180;
    return movementAngle;
} //promblem 1: It will think sensor 1 is the first sensor instead of sensor 9 due to the if statement at line 34.