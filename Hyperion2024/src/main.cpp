//Include init.h
#include <init.h>

//Run through once (Arduino Setup)
void setup()
{
  ls.init(); //Initializing Light Sensors
  tssp.init(); //Initializing Tssps
  motors.init(); //Intializing Drive System
  compass.setExtCrystalUse(true); //Initializing BNO
  Serial.begin(9600); //Intializing Serial
  while(!compass.begin()) {
    Serial.println("NOOOOOOOOOOOoo bno ded ;("); //Checking if BNO dies ;((
  }
}

//Run through continously (Arduino Loop)
void loop() 
{
  compass.getEvent(&direction); //getting direction through BNo (direction.orientation.x)
  compassVal = direction.orientation.x;
  ballDirection = tssp.read();
  if (compassVal < CIRCLE_DEGREES && compassVal > SEMI_CIRCLE_DEGREES) {
    compassVal -= CIRCLE_DEGREES;
  }
  //motors.run_all(orbit.calculate_Speed(tssp.tsspStrength), orbit.calculate_Direction(ballDirection), compass_correct.update(compassVal, 0)); //Run everything
  motors.run_all(0, 0, compass_correct.update(compassVal, 0)); //Test Compass Correction
  //last thing to happen - tell motors to run
}