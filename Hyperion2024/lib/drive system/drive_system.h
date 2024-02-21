#ifndef DRIVE_SYSTEM_H
#define DRIVE_SYSTEM_H

#include <Arduino.h>
#include <Motor.h>

class Drive_system {
public:
    Drive_system(int PWM_pin, int dir_a, int dir_b); // Constructor
    void init();
private:
    static const int NUM_MOTORS = 4; // Number of motors
    static const int motor_pins[NUM_MOTORS][3]; // Pin configurations for each motor
    Motor motors[NUM_MOTORS]; // Array to store Motor objects
};

#endif
