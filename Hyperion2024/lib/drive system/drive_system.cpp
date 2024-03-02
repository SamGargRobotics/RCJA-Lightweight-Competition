#include "drive_system.h"
#include <pins.h>

void Drive_system::init() {
    for (int i = 0; i < NUM_MOTORS; i++) {
        motors[i].init();
    }
}

// Define the pin configurations for each motor
 const int Drive_system::motor_pins[NUM_MOTORS][3] = {
     {MOTOR_1_PWM, MOTOR_1_A, MOTOR_1_B},  // Motor 1 pins: PWM_pin = 13, dir_a = 22, dir_b = 23
     {MOTOR_2_PWM, MOTOR_2_A, MOTOR_2_B},  // Motor 2 pins: PWM_pin = 12, dir_a = 24, dir_b = 25
     {MOTOR_3_PWM, MOTOR_3_A, MOTOR_3_B},  // Motor 3 pins: PWM_pin = 11, dir_a = 26, dir_b = 27
     {MOTOR_4_PWM, MOTOR_4_A, MOTOR_4_B}   // Motor 4 pins: PWM_pin = 10, dir_a = 28, dir_b = 29
 };