#include <light_system.h> //Light system header file
#include <tssp_system.h> //tssp system header file
#include <drive_system.h> //motor system header file
#include <camera.h> //camera header file
#include <Wire.h> //BNO File Header
#include <Adafruit_Sensor.h> //BNO File Header
#include <Adafruit_BNO055.h> //BNO File Header
#include <imumaths.h> //BNO File Header
#include <pins.h> //Pins master file

Tssp_system tssp_sys = Tssp_system(tssp_Pin); //Creating Tssp System
Light_System ls_sys = Light_System(light_Pin); //Creating Light System
Drive_system drive_sys = Drive_system(); //Initializing Drive System
bno::Adafruit_BNO055 compass; //Initializing BNO
sensors_event_t direction; //Initializing BNO

void setup() {
  ls_sys.init(); //Initializing Light Sensors
  tssp_sys.init(); //Initializing Tssps
  drive_sys.init(); //Intializing Drive System
  compass.setExtCrystalUse(true); //Initializing BNO
  Serial.begin(9600); //Intializing Serial
}

void loop() {
  compass.getEvent(&direction); //direction.orientation.x
}