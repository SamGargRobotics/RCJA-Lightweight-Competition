//Includes
#include <common.h>

//Objects
Tssp_system tssp_sys = Tssp_system(TSSP_PIN); //Creating Tssp System
Light_System ls_sys = Light_System(LIGHT_PIN); //Creating Light System
Drive_system drive_sys = Drive_system(); //Creating Drive System
bno::Adafruit_BNO055 compass; //Creating BNO
sensors_event_t direction; //Creating BNO

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