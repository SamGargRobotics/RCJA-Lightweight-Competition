#include <light_system.h>
#include <tssp_system.h>
#include <drive_system.h>
#include <camera.h>
#include <PID.h>
#include <orbit.h>
#include <pins.h>
#include <common.h>
#include <MPU.h>
#include <initialize.h>

class Tssp_system tssp = Tssp_system();
Light_System ls = Light_System();
Drive_system motors = Drive_system();
PID compass_correct(PID_p, PID_i, PID_d, PID_abs_max);
Orbit orbit;
MPU compass = MPU();
initialize config = initialize();

float compassVal = 0; //constant value of MPU
float targetValue = 0; //target value of the MPU
float ballDirection = 0; //direction of ball (tssps)
float moveDir = 0; //direction to move (after orbit library calculation)
float ballSpeedNum = 0; //tssp strength !!! CURRENTLY COMMENTED OUT
bool flag1 = 0;
float moveSpeed = 0;
int ballStr = 0;
int lineAvoidance = 0;
double correction = 0;

void initialize::calculate_final_movement() {
  if (ls.isLineAvoidance == true) {
    motors.update(moveSpeed, lineAvoidance, 0, correction);
  } else {
    motors.update(moveSpeed, moveDir, 0, correction);
  }
}
void initialize::reading_values() {
  compass.update();
  ballDirection = tssp.read();
  compassVal = compass.heading;
  targetValue = compass.targetVal;
  ballStr = tssp.tsspStrength;
}
void initialize::initialize_sensors() {
  ls.init();
  tssp.init();
  motors.init();
  Serial.begin(9600);
  compass.init();
  compass.findTargetVal();
}
void initialize::printing() {
  Serial.print(moveSpeed);
  Serial.print(" ");
  Serial.print(ballStr);
  Serial.println();
}
void initialize::logic() {
  moveDir = orbit.calculate_Direction3(ballDirection);
  lineAvoidance = ls.lineAvoidance();
  moveSpeed = orbit.calculate_Speed(ballStr, ballDirection);
  correction = compass_correct.update(compass.heading > 180 ? compass.heading - 360 : compass.heading, 0);
}

void setup() {
  config.initialize_sensors();
}

void loop() {
  config.reading_values();
  config.logic();
  config.calculate_final_movement();
  config.printing();
}