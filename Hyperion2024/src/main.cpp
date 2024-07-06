#include <light_system.h>
#include <tssp_system.h>
#include <drive_system.h>
#include <camera.h>
#include <PID.h>
#include <orbit.h>
#include <pins.h>
#include <common.h>
#include <MPU.h>


Tssp_system tssp = Tssp_system();
Light_System ls = Light_System();
Drive_system motors = Drive_system();
PID compass_correct(PID_p, PID_i, PID_d, PID_abs_max);
Orbit orbit;
MPU compass = MPU();


float compassVal = 0; //constant value of MPU
float targetValue = 0; //target value of the MPU
float ballDirection = 0; //direction of ball (tssps)
float moveDir = 0; //direction to move (after orbit library calculation)
float ballSpeedNum = 0; //tssp strength !!! CURRENTLY COMMENTED OUT
bool flag1 = 0;
int temp = 0;


void setup() {
  //ls.init();
  tssp.init();
  motors.init();
  Serial.begin(9600);
  compass.init();
}


void loop() {
  compass.findTargetVal(); //!! works
  compass.update(); //!! works
  ballDirection = tssp.read();
  moveDir = orbit.calculate_Direction(ballDirection);
  temp = orbit.calculate_Direction3(ballDirection);
  compassVal = compass.heading; //!! works
  targetValue = compass.targetVal; //!! works
  double correction = compass_correct.update(compass.heading > 180 ? compass.heading - 360 : compass.heading, 0);
  Serial.println(correction);
  // ballSpeedNum = orbit.calculate_Speed(tssp.tsspStrength); //getting tssp strength
  motors.update(100, ballDirection, 0, correction); //testing movement of robot according to ball //(dir) 57 and less works anything 58 and above is ded
  //PRINTING STUFF
  // Serial.print("ballDir: ");
  // Serial.print(ballDirection);
  // Serial.print(" ");
  // Serial.print("big: ");
  // Serial.print("");
  // //Serial.print(" ");
  // Serial.print("balls: ");
  // Serial.print(tssp.tsspNum);
  // Serial.println("");
}
//ege.com
//i like little boys