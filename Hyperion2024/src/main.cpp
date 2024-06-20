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


void setup() {
  //ls.init();
  //tssp.init();
  // motors.init();
  Serial.begin(9600);
  compass.init();
}


void loop() {
  compass.findTargetVal();
  compass.update();
  // ballDirection = tssp.read();
  // moveDir = orbit.calculate_Direction(ballDirection);
  compassVal = compass.heading;
  targetValue = compass.targetVal;
  //ballSpeedNum = orbit.calculate_Speed(tssp.tsspStrength); //getting tssp strength
  //motors.run_all(50, moveDir, compass.heading); !!! //testing movement of robot according to ball
  // motors.run_all(100, 0, 0);
  //// PRINTING STUFF
  Serial.print("compVal: ");
  Serial.print(compassVal);
  Serial.print(" targetVal: ");
  Serial.print(targetValue);
  Serial.println("");
}
//ege.com
//i like little boys