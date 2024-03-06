#include "Tssp_system.h"

Tssp_system::Tssp_system(int startPin) {
    startPin = Pin;
}

void Tssp_system::init() {
    for (int i = 0; i < NUM_TSSPS; i++) {
        pinMode(Pin + i, INPUT);
    }
}

void Tssp_system::read() {
    for (int y = 0; y < 256; y++) {
        for (int i = 0; i < NUM_TSSPS; i++) {
            if (y == 0 && i == 0) {
                readTssp[i] = 0;
            }
            readTssp[i] += digitalRead(Pin + i);
        }
    }
}