#include "Tssp_system.h"

Tssp_system::Tssp_system(int startPin) {
    for (int i = 0; i < NUM_TSSPS; i++) {
        tssps[i] = Tssp(startPin + i); // Create TSSP objects with pins ranging from startPin to startPin + 15
    }
}

void Tssp_system::init() {
    for (int i = 0; i < NUM_TSSPS; i++) {
        tssps[i].init(); // Initialize each TSSP object
    }
}
