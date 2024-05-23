#include <light_system.h> //Light system header file
#include <tssp_system.h> //tssp system header file
#include <drive_system.h> //motor system header file
#include <camera.h> //camera header file
#include <Adafruit_BNO055.h> //BNO File Header
#include <PID.h> //PID master file
#include <orbit.h> //Orbit master file
#include <pins.h> //Pins master file
#include <common.h> //Common master file

Tssp_system tssp = Tssp_system(); // Creating IR ring System
Light_System ls = Light_System(); //Creating Light System
Drive_system motors = Drive_system(); //Creating Drive System
Adafruit_BNO055 compass; //Creating BNO
sensors_event_t direction; //Creating BNO
PID compass_correct(PID_p, PID_i, PID_d, PID_abs_max);
Orbit orbit;

float compassVal = 0;
float ballDirection = 0;

//Run through once (Arduino Setup)
void setup()
{
  //ls.init(); //Initializing Light Sensors
  //tssp.init(); //Initializing Tssps
  motors.init(); //Intializing Drive System
  //compass.setExtCrystalUse(true); //Initializing BNO
  Serial.begin(9600); //Intializing Serial
  //while(!compass.begin()) {
  //  Serial.println("NOOOOOOOOOOOoo bno ded ;("); //Checking if BNO dies ;((
  //}
}

//Run through continously (Arduino Loop)
// void loop() 
// {
//   compass.getEvent(&direction); //getting direction through BNo (direction.orientation.x)
//   compassVal = direction.orientation.x;
//   ballDirection = tssp.read();
//   if (compassVal < CIRCLE_DEGREES && compassVal > SEMI_CIRCLE_DEGREES) {
//     compassVal -= CIRCLE_DEGREES;
//   }
//   if (compassVal <= 20 && compassVal >= -20) {
//     motors.run_all(0, 0, compass_correct.update(compassVal, 0));
//     //motors.run_all(100, orbit.calculate_Direction2(ballDirection), compass_correct.update(compassVal, 0))
//   } else {
//     motors.run_all(0, 0, compass_correct.update(compassVal, 0));
//     //motors.run_all(orbit.calculate_Speed(tssp.tsspStrength), orbit.calculate_Direction2(ballDirection), compass_correct.update(compassVal, 0))
//   }
// }
// ###### ACTUAL CODE:::::::
// void loop() {
//   compass.getEvent(&direction); //getting direction through BNo (direction.orientation.x)
//   compassVal = direction.orientation.x;
//   ballDirection = tssp.read();
//   if (compassVal < CIRCLE_DEGREES && compassVal > SEMI_CIRCLE_DEGREES) {
//     compassVal -= CIRCLE_DEGREES;
//   }
//   if (ls.lineAvoidance() > 0) {
//     motors.run_all(100, ls.lineAvoidance(), 0);
//   } else {
//     if (compassVal <= 20 && compassVal >= -20) {
//       motors.run_all(0, 0, compass_correct.update(compassVal, 0));
//       //motors.run_all(100, orbit.calculate_Direction2(ballDirection), compass_correct.update(compassVal, 0))
//     } else {
//       motors.run_all(0, 0, compass_correct.update(compassVal, 0));
//       //motors.run_all(orbit.calculate_Speed(tssp.tsspStrength), orbit.calculate_Direction2(ballDirection), compass_correct.update(compassVal, 0))
//   }
//   }
// }
void loop() {
  motors.run_all(20, 0, 0);
}