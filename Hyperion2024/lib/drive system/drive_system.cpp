#include "drive_system.h"
#include <pins.h>
#include <math.h>
#include <common.h>

void Drive_system::init() {
    for (int i = 0; i < NUM_MOTORS; i++) {
        motors[i].init();
    }
}

void Drive_system::run_motors() {
    Serial.print("MotorSpeeds: ");
    for(int i = 0; i < NUM_MOTORS; i++) {
        motors[i].run(motorSpeeds[i]);
        Serial.print(motorSpeeds[i]);
        motorSpeeds[i] = previousMotorSpeeds[i];
        Serial.print(" ");
    }
    Serial.println("");
    delay(1000);
}

void Drive_system::ignoreChecking() {
    for(int i = 0; i < NUM_MOTORS; i++) {
        motorIgnore[i] = ((previousMotorSpeeds[i] < 0) && (motorSpeeds[i] > 0)) ? 1 : 0;
        motorIgnore2[i] = ((previousMotorSpeeds[i] > 0) && (motorSpeeds[i] < 0)) ? 1 : 0;
    }
    for(int i = 0; i < NUM_MOTORS; i++) {
        if(motorIgnore[i] == 1) {
            motorSpeeds[i] = MOTOR_IGNORE_MOVEMENT;
        }
        if(motorIgnore2[i] == 1) {
            motorSpeeds[i] = (-1*MOTOR_IGNORE_MOVEMENT);
        }
    }
    for(int i = 0; i < NUM_MOTORS; i++) {
        motorIgnore[i] = 0;
        motorIgnore2[i] = 0;
    }
    flagCounter = MOTOR_FLAG_COUNTER;
}

void Drive_system::run_all(int speed, int dir, int rotation) {
    if(dir == 90 || dir == 270) {
        raah = true;
    }
    for (int i = 0; i < NUM_MOTORS; i++) {
        motorSpeeds[i] = ANALOG_DIV_100*speed*cos(a[i] - (dir*DEG_TO_RAD))+rotation; //speed is 0-100 >:(
    }
    Serial.print("Before change: ");
    for(int i = 0; i < NUM_MOTORS; i++) {
        Serial.print(motorSpeeds[i]);
        Serial.print(" ");
    }
    Serial.println();
    largest = max(abs(motorSpeeds[0]), max(abs(motorSpeeds[1]), max(abs(motorSpeeds[2]), abs(motorSpeeds[3]))));
    for (int i = 0; i < NUM_MOTORS; i++) {
        motorSpeeds[i] = (motorSpeeds[i]/abs(largest))*ANALOG_DIV_100*speed;
    }
    for (int i  = 0; i < NUM_MOTORS; i++) {
        motorSpeeds[i] = int(motorSpeeds[i]);
    }
    if(raah == true) {
        motorSpeeds[0] *= -1;
        motorSpeeds[3] *= -1;
    }
    motorSpeeds[1] *= -1;
    motorSpeeds[3] *= -1;
    ignoreChecking();
    run_motors();
}

// Define the pin configurations for each motor
 const int Drive_system::motor_pins[NUM_MOTORS][3] = {
     {MOTOR_1_PWM, MOTOR_1_A, MOTOR_1_B},  // Motor 1 pins: PWM_pin = 13, dir_a = 22, dir_b = 23
     {MOTOR_2_PWM, MOTOR_2_A, MOTOR_2_B},  // Motor 2 pins: PWM_pin = 12, dir_a = 24, dir_b = 25
     {MOTOR_3_PWM, MOTOR_3_A, MOTOR_3_B},  // Motor 3 pins: PWM_pin = 11, dir_a = 26, dir_b = 27
     {MOTOR_4_PWM, MOTOR_4_A, MOTOR_4_B}   // Motor 4 pins: PWM_pin = 10, dir_a = 28, dir_b = 29
 };