#include "Tssp_system.h"
#include <pins.h>

void Tssp_system::init() {
    for (uint8_t i = 0; i < NUM_TSSPS; i++) {
        pinMode(tsspPins[i], INPUT);
    }
}

int Tssp_system::read() {
    // largest = 0;
    // tsspNum = 0;
    // addedAngles = 0;
    // tsspStrength = 0;
    // ballAngle = 0;
    // for(int i = 0; i < NUM_TSSPS; i++) {
    //     readTssp[i] = 0;
    // }
    for (int y = 0; y < 256; y++) {
        for (int i = 0; i < NUM_TSSPS; i++) {
            readTssp[i] += 1 - digitalRead(tsspPins[i]);
        }
        delayNanoseconds(300); //3/10 of a micro second
    }
    Serial.println(readTssp[1]);
    for (int i = 0; i < NUM_TSSPS; i++) {
        if (readTssp[i] > largest) {
            largest = readTssp[i];
            tsspNum = i;
        }
    }
    for (int i = 0; i < NUM_TSSPS; i++) {
        addedAngles += readTssp[i];
    }
    tsspStrength = addedAngles/NUM_TSSPS;
    ballAngle = tsspNum*30;
    return ballAngle;
}