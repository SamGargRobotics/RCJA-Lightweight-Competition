//Includes
#include <light_system.h> //Light system header file
#include <tssp_system.h> //tssp system header file
#include <drive_system.h> //motor system header file
#include <camera.h> //camera header file
#include <Wire.h> //BNO File Header
#include <Adafruit_Sensor.h> //BNO File Header
#include <Adafruit_BNO055.h> //BNO File Header
#include <imumaths.h> //BNO File Header
#include <pins.h> //Pins master file
#include <common.h> //Common master file

//Objects
Tssp_system tssp_sys = Tssp_system(TSSP_PIN); //Creating Tssp System
Light_System ls_sys = Light_System(LIGHT_PIN); //Creating Light System
Drive_system drive_sys = Drive_system(); //Creating Drive System
bno::Adafruit_BNO055 compass; //Creating BNO
sensors_event_t direction; //Creating BNO