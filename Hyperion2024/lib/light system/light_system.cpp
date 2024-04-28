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

int Light_System::lineAvoidance2() {
    for (int i = 0; i < NUM_SENSORS; i++) {
        if (lightData[i] >= line_avoidance_thresh) {
            positiveData[i] = 1;
        }
    } for (int i = 0; i < NUM_SENSORS; i++) {
        if (lightData[i] == 1) {
            firstSens = i+1;
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
} 
int Light_System::lineAvoidance() {
    bool countStatement = true; //true = forwards, false = backwards
    for (int i = 0; i < NUM_SENSORS; i++) {
        positiveData[i] = lightData[i] >= line_avoidance_thresh? 1 : 0;
    }
    if (positiveData[15] == 1) {
        countStatement = false;
        for (int i = NUM_SENSORS; i > 0; i--) {
            if (positiveData[i] != 1) {
                firstSens = i+2;
            }
        }
    } else {
        for (int i = 0; i < NUM_SENSORS; i++) {
            if (positiveData[i] == 1) {
                firstSens = i+1;
                break;
            }
        }
    }
    if (countStatement == false) {
        for (int i = 0; i < 16; i++) {
            if (positiveData[(firstSens+i) >= 16? firstSens+i-16 : firstSens+i] != 1) {
                lastSens = firstSens+i-16;
            }
        }
    } else {
        for (int i = 0; i < NUM_SENSORS; i++) {
            if (positiveData[firstSens+i] != 1) {
                lastSens = firstSens+i;
            }
        }
    }
    if (firstSens > lastSens) {
        sensDif = (firstSens - lastSens)/2;
        rsensDif = round(sensDif);
        midSens = lastSens + sensDif;
    } else {
        sensDif = (lastSens - firstSens)/2;
        rsensDif = round(sensDif);
        midSens = lastSens + sensDif;
    }
    fdegs = (midSens*22.5)-180;
    return fdegs;
}