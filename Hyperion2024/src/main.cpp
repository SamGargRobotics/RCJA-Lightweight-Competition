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
float ballDirection = 0; //direction of ball (tssps)
float MoveDir = 0; //direction to move (after orbit library calculation)
float ballSpeedNum = 0; //tssp strength !!! CURRENTLY COMMENTED OUT


void setup() {
  //ls.init();
  tssp.init();
  //motors.init();
  Serial.begin(9600);
  compass.init();
}


void loop() {
  ballDirection = tssp.read();
  MoveDir = orbit.calculate_Direction(ballDirection);
  compassVal = compass.update();
  //ballSpeedNum = orbit.calculate_Speed(tssp.tsspStrength); //getting tssp strength
  // motors.run_all(50, MoveDir, 0); !!! //testing movement of robot according to ball


  ////// PRINTING STUFF
  // Serial.print("food: ");
  // Serial.print(compassVal);
  // Serial.println("");
  // delayMicroseconds(3000000);
}