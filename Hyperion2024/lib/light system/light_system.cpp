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
        setMuxChannel(i);
        lightData[i] = analogRead(LIGHT_PIN);
    }
}

void Light_System::setMuxChannel(int channel) {
    for (int i = 0; i < NUM_MUX; i++) {
        digitalWrite(muxList[i], channel%2);
        channel = int(channel / 2);
    }
}

int Light_System::lineAvoidance2() {
    for (int i = 0; i < NUM_SENSORS; i++) {
        positiveData[i] = (lightData[i] >= line_avoidance_thresh);
    }
    for (int i = 0; i < NUM_SENSORS; i++) {
        if (lightData[i] == 1) {
            firstSens = i+1;
        }
    }
    for (int i = 0; i < NUM_SENSORS; i++) {
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
int Light_System::lineAvoidance() { //change to do logic AFTER reading (not in the function)
    bool countStatement = true; //true = forwards, false = backwards
    for (int i = 0; i < NUM_SENSORS; i++) {
        positiveData[i] = (lightData[i] >= line_avoidance_thresh);
    }
    if (positiveData[15]) {
        countStatement = false;
        for (int i = NUM_SENSORS; i > 0; i--) {
            if (positiveData[i-1] != 1) {
                firstSens = i+1;
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
        for (int i = 0; i < NUM_SENSORS; i++) {
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
    midSens = (firstSens+lastSens)/2;
    if (firstSens < lastSens) {
        fdegs = ((midSens-1)*22.5)-180;
    } else {
        fdegs = ((midSens-1)*22.5);
    }
    return fdegs;
}