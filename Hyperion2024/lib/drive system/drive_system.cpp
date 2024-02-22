#include "drive_system.h"

void Drive_system::init() {
    for (int i = 0; i < NUM_MOTORS; i++) {
        motors[i].init();
    }
}

// Define the pin configurations for each motor
 const int Drive_system::motor_pins[NUM_MOTORS][3] = {
     {13, 22, 23},  // Motor 1 pins: PWM_pin = 13, dir_a = 22, dir_b = 23
     {12, 24, 25},  // Motor 2 pins: PWM_pin = 12, dir_a = 24, dir_b = 25
     {11, 26, 27},  // Motor 3 pins: PWM_pin = 11, dir_a = 26, dir_b = 27
     {10, 28, 29}   // Motor 4 pins: PWM_pin = 10, dir_a = 28, dir_b = 29
 };