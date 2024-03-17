//Include init.h
#include <init.h>

//Run through once (Arduino Setup)
void setup()
{
  ls.init(); //Initializing Light Sensors
  tssp.init(); //Initializing Tssps
  drive.init(); //Intializing Drive System
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
}