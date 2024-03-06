//Include init.h
#include <init.h>

//Run through once (Arduino Setup)
void setup() {
  ls_sys.init(); //Initializing Light Sensors
  tssp_sys.init(); //Initializing Tssps
  drive_sys.init(); //Intializing Drive System
  compass.setExtCrystalUse(true); //Initializing BNO
  Serial.begin(9600); //Intializing Serial
  while(!compass.begin()) {
    Serial.println("NOOOOOOOOOOOoo bno ded ;(");
  }
}

//Run through continously (Arduino Loop)
void loop() {
  compass.getEvent(&direction); //direction.orientation.x
}