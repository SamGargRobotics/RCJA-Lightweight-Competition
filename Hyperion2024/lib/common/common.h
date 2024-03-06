#include <light_system.h> //Light system header file
#include <tssp_system.h> //tssp system header file
#include <drive_system.h> //motor system header file
#include <camera.h> //camera header file
#include <Wire.h> //BNO File Header
#include <Adafruit_Sensor.h> //BNO File Header
#include <Adafruit_BNO055.h> //BNO File Header
#include <imumaths.h> //BNO File Header
#include <pins.h> //Pins master file

int MotorSpeeds[1][3] = {{100, 1, 0}};