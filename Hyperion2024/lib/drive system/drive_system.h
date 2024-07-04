#ifndef DRIVE_SYSTEM_H
#define DRIVE_SYSTEM_H

#include <Arduino.h>
#include <Motor.h>
#include <pins.h>

class Drive_system {
public:
    Drive_system() {};// Constructor
    void init();
    void run_all(int speed, int dir, int rotation);
    void ignoreChecking();
    void run_motors();
private:
    static const int NUM_MOTORS = 4; // Number of motors
    static const int motor_pins[NUM_MOTORS][3]; // Pin configurations for each motor
    Motor motors[NUM_MOTORS] = {Motor(motor_pins[0][0], motor_pins[0][1], motor_pins[0][2]), 
                                Motor(motor_pins[1][0], motor_pins[1][1], motor_pins[1][2]),
                                Motor(motor_pins[2][0], motor_pins[2][1], motor_pins[2][2]),
                                Motor(motor_pins[3][0], motor_pins[3][1], motor_pins[3][2])
                                };
    float motorSpeeds[NUM_MOTORS];
    float previousMotorSpeeds[NUM_MOTORS];
    float motorFace1 = MOTORFACE1*DEG_TO_RAD;
    float motorFace2 = MOTORFACE2*DEG_TO_RAD;
    float motorFace3 = MOTORFACE3*DEG_TO_RAD;
    float motorFace4 = MOTORFACE4*DEG_TO_RAD;
    float a[4] = {motorFace1, motorFace2, motorFace3, motorFace4};
    int largest = 0;
    int motorIgnore[NUM_MOTORS] = {0};
    int motorIgnore2[NUM_MOTORS] = {0};
    int flagCounter = 0;
    bool raah = false;
};

#endif