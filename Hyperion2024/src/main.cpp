#include <light_system.h> //Light system header file
#include <tssp_system.h> //tssp system header file
#include <drive_system.h> //motor system header file
#include <camera.h> //camera header file
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <imumaths.h>

Tssp_system tssp_sys = Tssp_system(30); //Creating Tssp System
Light_System ls_sys = Light_System(A0); //Creating Light System
Drive_system drive_sys = Drive_system(); //Initializing Drive System
bno::Adafruit_BNO055 compass;
sensors_event_t direction;

void setup() {
  ls_sys.init(); //Initializing Light Sensors
  tssp_sys.init(); //Initializing Tssps
  drive_sys.init(); //Intializing Drive System
  compass.setExtCrystalUse(true);
  Serial.begin(9600);
}

void loop() {
  compass.getEvent(&direction); //direction.orientation.x
}